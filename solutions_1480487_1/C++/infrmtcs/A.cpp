#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#define fi "A-large.in"
#define fo "A-large.out"
//#define fi "A.INP"
//#define fo "A.OUT"
#define nmax 1000+5
#define INF 1000000000
using namespace std;
typedef double dd;
const dd eps=dd(1e-12);
//VARIABLES
int n,a[nmax];
//FUNCTION PROTOTYPES

void Init();
void Process(int test);

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
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		a[0]+=a[i];
	}
}
bool Check(int k, dd x)
{
	dd S=dd(a[k])+dd(a[0])*x,y=0.0;
//	cout << S << endl;
	for (int i=1;i<=n;++i)
	if ((i!=k) && (dd(a[i])<S)) y+=(S-dd(a[i]))/dd(a[0]);
//	cout << x << " " << y << endl;
	return (x+y>1.0);
}
void Cal(int k)
{
	dd x=0.0,y=1.0,mid;
	while (fabs(x*100.0-y*100.0)>eps)
	{
		mid=(x+y)/2;
		if (Check(k,mid)) y=mid; else x=mid;
	}
	x*=100.0;
	printf("%.6lf ",x);
}
void Process(int test)
{
	printf("Case #%d: ",test);
	for (int i=1;i<=n;++i) Cal(i);
	putchar('\n');
}
