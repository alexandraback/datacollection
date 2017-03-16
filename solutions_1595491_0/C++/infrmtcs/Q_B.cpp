#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define fi "B-small-attempt0.in"
#define fo "B-small-attempt0.out"
//#define fi "Q_B.INP"
//#define fo "Q_B.OUT"
#define nmax
#define INF 1000000000
using namespace std;

//VARIABLES
int m,n,k,res;
//MAIN
int main()
{
	int test,x;
       freopen(fi,"r",stdin);
       freopen(fo,"w",stdout);
       scanf("%d",&test);
       for (int tc=1;tc<=test;++tc)
       {
		scanf("%d%d%d",&n,&m,&k);
		res=0;
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&x);
			if (x%3==1) res+=(x/3+1>=k?1:0); else
			{
				if (x/3+(x%3)/2>=k) ++res; else
				if ((x/3+(x%3)/2+1>=k) && (m>0) && (x/3+(x%3)/2+1<=10) && (x/3+(x%3)/2-1>=0))
				{
					++res;--m;
				}
			}
		}
		printf("Case #%d: %d\n",tc,res);
	}
       return 0;
}
