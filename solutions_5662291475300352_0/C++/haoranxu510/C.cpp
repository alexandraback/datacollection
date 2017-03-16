#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define SIZE(x) (int((x).size()))
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
#define repd(i,r,l) for (int i=(r); i>=(l); i--)
#define rept(i,c) for (typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

#ifndef ONLINE_JUDGE
#define debug(x) { cerr<<#x<<" = "<<(x)<<endl; }
#else
#define debug(x) {}
#endif

#define eps 1e-9

int s[10], o[10];
double a[10];

void lemon()
{
	int m=0;
	int n; scanf("%d",&n);
	rep(i,1,n)
	{
		int d,h,x; scanf("%d%d%d",&d,&h,&x);
		rep(j,1,h)
		{
			m++; s[m]=x; x++;
			o[m]=d;
		}
	}
	if (m==1)
	{
		printf("0\n");
		return;
	}
	a[1]=(360-o[1])/360.0*s[1], a[2]=(360-o[2])/360.0*s[2];
	if (a[1]>a[2]) swap(o[1],o[2]), swap(s[1],s[2]), swap(a[1],a[2]);
	if (a[2]+eps>=a[1]+s[1])
	{
		printf("1\n");
	}
	else  printf("0\n");
}

int main()
{
	ios::sync_with_stdio(true);
	#ifndef ONLINE_JUDGE
		freopen("C.in","r",stdin);
	#endif
	int tcase; scanf("%d",&tcase);
	rep(nowcase,1,tcase) 
	{
		printf("Case #%d: ",nowcase);
		lemon();
	}
	return 0;
}

