#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <assert.h>

//#pragma warning(disable:4996)
using namespace std;

#define TIME fprintf(stderr,"\n-----------\ntime : %.2f sec\n",double(clock())/CLOCKS_PER_SEC);
#define EXIT exit(0);
#define FIN freopen("input.txt","r",stdin);
#define FOUT freopen("output.txt","w",stdout);
#define INP(_X) scanf("%d",& _X);
#define OUT(_X) printf("%d ",_X);
#define LINE printf("\n");
#define DOUT(_X) fprintf(stderr,"%d ",_X);
#define DLINE fprintf(stderr,"\n");

#define M 55
#define MOD 1000000
#define ADD(_X,_Y) _X=(_X+_Y)%MOD;

#define abs(_Z) (((_Z)<0)?-(_Z):(_Z))
#define f0(_X,_Y) for(_X=0;_X<_Y;++_X)
#define f1(_X,_Y) for(_X=1;_X<=_Y;++_X)
#define ff(_X,_Y,_Z) for(_X=_Y;_X<=_Z;++_X)
#define fF(_X,_Y,_Z) for(_X=_Y;_X<_Z;++_X)
#define pb push_back
#define sz(_X) _X.size()
typedef long long ll;
const double PI=atan2(1.,0);

__int64 a[505],s,ans;
int d[55][1000003];
map<__int64,int> h;

int main()
{
	int t,T,i,j,n,m,ans1,ans2;

	FIN
	FOUT

	INP(t)
	f1(T,t)
	{
		INP(n)
		f1(i,n) scanf("%I64d",&a[i]);
		//sort(a+1,a+n+1);
		//if(n>50) n=50;
		////m=n*1000000000000i64;
		//m=20*100000;

		//d[0][0]=1;
		//f0(i,n)
		//{
		//	f0(j,m) d[i+1][j]=0;
		//	f0(j,m)
		//	{
		//		ADD(d[i+1][(j+a[i+1])%MOD],d[i][j]);
		//		ADD(d[i+1][j],d[i][j]);
		//	}
		//}
		h.clear();
		ans=20*10e6; ans1=0;
		f0(i,1048576)
		{
			s=0;
			f0(j,20) if(i&(1<<j)) s+=a[j+1];
			if(s<ans)
			{
				if(h.find(s)!=h.end())
					ans=s, ans1=h[s], ans2=i;
				else
					h[s]=i;
			}
		}
		printf("Case #%d:\n",T);
		if(ans1)
		{
			f0(j,20) if(ans1&(1<<j)) printf("%d ",a[j+1]); printf("\n");
			f0(j,20) if(ans2&(1<<j)) printf("%d ",a[j+1]); printf("\n");
		}
		else printf("Impossible\n");
	}
	return 0;
}
