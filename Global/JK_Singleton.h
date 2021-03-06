
#ifndef _JK_SINGLETON_ED22DC7F_H_
#define _JK_SINGLETON_ED22DC7F_H_

#include "JK_Lock.h"
#include "JK_Assert.h"

template < typename T >
class JK_Singleton
{
public:
	JK_Singleton()
	{
		m_Lock.Lock();
		JK_ASSERT( !m_pInstance );
		//int offset = (int)(T*)1 - (int)(j_Singleton<T>*)(T*)1;
		//m_pSingleton = (T*)((int)this + offset );
		m_pInstance = (T*)this;
		m_Lock.Unlock();
	}

	~JK_Singleton()
	{
		JK_ASSERT( m_pInstance );
		m_pInstance = NULL;
	}


	static T& GetInstance()
	{
		JK_ASSERT( m_pInstance );
		return(*m_pInstance);
	}


	static T* GetInstancePtr()
	{
		JK_ASSERT( m_pInstance );
		return m_pInstance;
	}

private:
	static T* m_pInstance;
	JK_Lock m_Lock;
};

template< typename T > T* JK_Singleton<T>::m_pInstance = NULL;


#endif