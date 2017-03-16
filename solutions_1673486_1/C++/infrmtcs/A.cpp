#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define fi "A-large.in"
#define fo "A-large.out"
//#define fi "A.INP"
//#define fo "A.OUT"
#define nmax 100000+5
using namespace std;
typedef double dd;
const dd INF=dd(1e16);
//VARIABLES
int m,n;
dd a[nmax],b[nmax],res;
//FUNCTION PROTOTYPES

void Init();
void Process(int tc);

//MAIN
int main()
{
	int test;
       freopen(fi,"r",stdin);
       freopen(fo,"w",stdout);
	scanf("%d",&test);
	for (int i=1;i<=test;++i)
	{
	       Init();
       	Process(i);
	}
       return 0;
}

//FUNCTIONS AND PROCEDURES
void Init()
{
	scanf("%d%d",&m,&n);
	for (int i=1;i<=m;++i) scanf("%lf",&a[i]);
}
void Process(int tc)
{
	res=INF;
	b[0]=dd(1);
	for (int i=1;i<=m;++i) b[i]=b[i-1]*a[i];
	for (int i=m;i>=1;--i) res=min(res,b[i]*dd((m-i)+(n-i+1))+(dd(1)-b[i])*dd((m-i)+(n-i+1)+(n+1)));
	res=min(res,dd(1+n+1));
	printf("Case #%d: %.6lf\n",tc,res);
}
