//Grzegorz Prusak
#include <cstdio>
#include <algorithm>

#define REP(i,n) for(int i=0; i<(n); ++i)
#define FOR(i,p,k) for(int i=(p); i<=(k); ++i)
#define FORD(i,p,k) for(int i=(p); i>=(k); --i)

template<typename T> void checkmin(T &a, T b){ if(a>b) a = b; }

typedef long long LL;

double B(int n, int y, int l)
{
	//printf("(%d %d)\n",n,y);
	if(y+l<=n) return 1;
	double s = 0, v = 1, a = 0, aa = 0;
	int j = 0;
	FORD(i,n,0)
	{
		aa += v;
		if(i<l && j<l) a += v;
		if(i<l && i>=y && j<l) s += v;
		v *= i/double(++j);
	}
	return s/aa+(1-a/aa)/2;
}

int main()
{
	int t; scanf("%d",&t);
	FOR(_,1,t)
	{
		int n,x,y; scanf("%d%d%d",&n,&x,&y);
		int l = (std::abs(x)+y); y++;
		n -= (l-1)*l/2;
		double p = 0;
		//printf("n = %d; y = %d\n",n,y);
		if(n>0)
		{
			if(n>=2*l+1) p = 1;
			else if(x)
			{
				//if(n>l){ int d = n-l; y -= d; l -= d; n -= 2*d; }
				//if(y<=0) p = 1;
				//else
				//{
					p = B(n,y,l);
					//REP(i,n) p /= 2;
				//}
			}
		}
		printf("Case #%d: %.7lf\n",_,p);
	}

	return 0;
}

