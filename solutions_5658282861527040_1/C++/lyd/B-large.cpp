#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

inline long long lowbit(long long n)
{
	return (n&(-n));
}

long long a,b,k;

long long cal(long long p,long long q,long long n)
{
	// bit
	long long lp = lowbit(p);
	long long lq = lowbit(q);
	long long ln = lowbit(n);
	// head
	long long mp = p-lp;
	long long mq = q-lq;
	long long mn = n-ln;
	// res
	long long res = 1;
	for(long long i=32;i>=0;i--)
	{
		long long si = 1;
		si = si<<i;
		// gu ding
		long long bit_p = (lp<=si)?((mp&si)>0 ? 1:2):3;
		long long bit_q = (lq<=si)?((mq&si)>0 ? 1:2):3;
		long long bit_n = (ln<=si)?((mn&si)>0 ? 1:2):3;
		long long cnt = 0;
		if( bit_n & 1 )
		{
			if( (bit_p&1) && (bit_q&1) ) cnt++;
		}
		if( bit_n & 2 )
		{
			if( bit_p&2 )
			{
				if( bit_q&1 ) cnt++;
				if( bit_q&2 ) cnt++;
			}
			if( bit_p&1 )
			{
				if( bit_q&2 ) cnt++;
			}
		}
		res *= cnt;
	}
	return res;
}

int main()
{
	int T;
	int ca = 1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&a,&b,&k);
		long long ans = 0;
		long long A = a;
		while(A)
		{
			long long B = b;
			while(B)
			{
				long long K = k;
				while(K)
				{
					ans += cal(A,B,K);
					K -= lowbit(K);
				}
				B -= lowbit(B);
			}
			A -= lowbit(A);
		}
		printf("Case #%d: %lld\n",ca++,ans);
	}
	return 0;
}

