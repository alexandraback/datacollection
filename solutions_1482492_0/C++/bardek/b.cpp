#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

#define fru(j,n) for(int j=0;j<n;++j)
#define tr(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
#define x first
#define y second

using namespace std;

typedef pair<int,int> pii;
typedef long long LL;
typedef double D;

const int MAXN = 1001;

D POZ[MAXN][2],A,d,eps=1e-9;

D licz()
{
	D x0=POZ[0][1];
	if(x0+eps>d) 	return sqrt((2*d)/A);
	D v0=(POZ[1][1]-x0)/(POZ[1][0]-POZ[0][0]);
	D delta = v0*v0+2.0*A*POZ[0][1];
	D tspot=(v0+sqrt(delta))/A;
	D ton=(d-x0)/v0;//on na mecie
	if(tspot >ton) return sqrt((2*d)/A);
	return ton;
}

void solve()
{
	int n,a;
	scanf("%lf%d%d",&d,&n,&a);
	fru(i,n) fru(j,2) scanf("%lf",&POZ[i][j]);
	fru(i,a)
	{
		scanf("%lf",&A);
		printf("%.6lf\n",licz());
	}

}

int main()
{
	int o;
	scanf("%d",&o);
	fru(oo,o)
	{
		 printf("Case #%d:\n",oo+1);
		 solve();
	}
    return 0;
}
