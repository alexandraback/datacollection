//Grzegorz Prusak
#include <cstdio>
#include <algorithm>

#define REP(i,n) for(int i=0; i<(n); ++i)
#define FOR(i,p,k) for(int i=(p); i<=(k); ++i)

template<typename T> void checkmin(T &a, T b){ if(a>b) a = b; }

typedef long long LL;

enum { n_max = 1000000 };

int A[n_max];

int main()
{
	int t; scanf("%d",&t);
	FOR(_,1,t)
	{
		LL a;
		int n; scanf("%lld%d",&a,&n);
		REP(i,n) scanf("%d",A+i);
		std::sort(A,A+n);
		int best = n;
		int g = 0;
		if(a>1) REP(i,n)
		{
			while(a<=A[i])
			{
				a = 2*a-1;
				g++;
			}
			a += A[i];
			checkmin(best,g+n-i-1);
		}
		printf("Case #%d: %d\n",_,best);
	}

	return 0;
}

