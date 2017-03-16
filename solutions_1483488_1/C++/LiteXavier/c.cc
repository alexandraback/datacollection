#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

int hash[3000000];

long long getNum ( int n, int A, int B )
{
	long long ret = 0;
	char s[10];
	sprintf(s,"%d",n);
	int len = strlen(s);
	int pb = 1;
	for(int i = 0; i < len; i ++ )
		pb *= 10;
	int base = 10, dx, de;
	while( base < n )
	{
		dx = n % base;
		de = n / base;
		int m = dx * (pb/base) + de;
		if( n < m && m >= A && m <= B )
			if( hash[m] != n )
				ret ++, hash[m] = n;
		base *= 10;			
	}
	return ret;
}

int main ()
{
	int T, A, B;
	scanf("%d",&T);
	int cn = 0;
	while( ++cn <= T )
	{
		memset(hash,0,sizeof(hash));
		scanf("%d%d",&A,&B);
		long long res = 0;
		for(int i = A; i <= B; i ++)
		{
			res += getNum(i, A, B);
		}	
		printf("Case #%d: %lld\n", cn, res);
	}
	return 0;
}
