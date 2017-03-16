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

int n,a[300],sum;
double b[300];

bool survive(int who,double portion)
{
	int i;
	double need;

	b[who]=a[who]+sum*portion;
	portion=1-portion;
	f1(i,n) if(who!=i)
	{
		if(a[i]>b[who]) continue;
		need=double(b[who]-a[i])/sum;
		if(need>portion) return true;
		portion-=need;
	}
	return sum<1e-9;
}

int main()
{
	int T,t,i,j;
	double l,r,m;

	FIN
	FOUT

	INP(t)
	f1(T,t)
	{
		sum=0;
		INP(n)
		f1(i,n) INP(a[i])
		f1(i,n) sum+=a[i];


		printf("Case #%d: ",T);
		f1(i,n)
		{
			l=0; r=1;
			while(r-l>1e-10)
			{
				m=(l+r)/2;
				if(survive(i,m))
					r=m;
				else
					l=m;
			}
			printf("%.7f ",(l+r)/2*100);
		}
		printf("\n");
	}
	return 0;
}
