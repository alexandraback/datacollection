//Grzegorz Prusak
#include <cstdio>

#define REP(i,n)    for(int i=0; i<(n); ++i)
#define FOR(i,p,k)  for(int i=(p); i<=(k); ++i)
#define FORD(i,p,k) for(int i=(p); i>=(k); --i)

typedef long long LL;

int between(int n, int B)
{
	int p = 1;
	for(int _n=n; _n>=10; _n/=10) p *= 10;

	int res = 0;
	for(int _n=n;;)
	{
		if(n<_n && _n<B) res++;
		_n = p*(_n%10)+_n/10;
		if(_n==n) break;
	}
	//printf("%d ",res);
	return res;
}

int main()
{
	int T; scanf("%d",&T);
	FOR(_,1,T)
	{
		int res = 0;
		int A,B; scanf("%d%d",&A,&B);
		FOR(n,A,B) res += between(n,B);
		printf("Case #%d: %d\n",_,res);
	}

	return 0;
}

