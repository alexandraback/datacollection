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

int lv1[M],lv2[M];
int main()
{
	int t,T,n,i,rest,star,flag,ans;

	FIN
	FOUT

	lv2[0]=-1;

	INP(t)
	f1(T,t)
	{
		INP(n)
		f1(i,n)
		{
			INP(lv1[i])
			INP(lv2[i])
		}
		rest=n*2; star=0; ans=0;
		while(rest)
		{
			do
			{
				flag=0;
				f1(i,n)
				{
					if(lv2[i]>=0 && lv2[i]<=star)
					{
						++ans;
						if(lv1[i]>=0) rest-=2, star+=2, lv1[i]=-1;
						else rest-=1, star+=1;
						lv2[i]=-1;
						flag=1;
					}
				}
			} while(flag);

			if(!rest) break;
			flag=0;
			f1(i,n) if(lv1[i]>=0 && lv1[i]<=star && lv2[i]>lv2[flag]) flag=i;
			if(!flag){rest=-1;break;}
			
			++ans;
			lv1[flag]=-1; ++star; --rest;
		}
		if(rest<0) printf("Case #%d: Too Bad\n",T);
		else printf("Case #%d: %d\n",T,ans);
	}
	return 0;
}
