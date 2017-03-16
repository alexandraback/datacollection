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
#define MOD 0
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
const int DY[]={0,1,0,-1},DX[]={1,0,-1,0};

struct XY{int x,y;
	XY(int _X=0,int _Y=0){x=_X;y=_Y;}
	bool operator == (const XY &p) const{return x==p.x && y==p.y;}
	bool operator < (const XY &p) const{if(x!=p.x) return x<p.x; return y<p.y;}
	XY operator + (const XY &p) const{return XY(x+p.x,y+p.y);}
	XY operator - (const XY &p) const{return XY(x-p.x,y-p.y);}
	XY operator - () const{return XY(-x,-y);}
	ll norm() const{return (ll)x*x+(ll)y*y;}
};

double a[112345];
int main()
{
	int t,T,A,B,i;
	double corr,exp,ans;

	FIN
	FOUT

	a[0]=1;
	INP(t)
	f1(T,t)
	{
		INP(A) INP(B)
		f1(i,A) scanf("%lf",&a[i]);

		ans=B+2;
		corr=1;
		ff(i,0,A)
		{
			corr*=a[i];
			exp=2*(A-i)+B-A+1+(1-corr)*(B+1);
			if(exp<ans) ans=exp;
		}
		printf("Case #%d: %.8f\n",T,ans);
	}
	return 0;
}
