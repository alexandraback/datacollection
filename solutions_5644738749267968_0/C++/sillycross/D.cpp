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

#define maxn 1010

double a[maxn], b[maxn];

void lemon()
{
	int n; scanf("%d",&n);
	rep(i,1,n) scanf("%lf",&b[i]);
	rep(i,1,n) scanf("%lf",&a[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	int cur=1, score=0;
	rep(i,1,n)
	{
		while (cur<=n && b[cur]<a[i]) cur++;
		if (cur<=n) { score++; cur++; }
	}
	
	printf("%d ",score);
	
	cur=1; score=0;
	rep(i,1,n)
	{
		while (cur<=n && a[cur]<b[i]) cur++;
		if (cur<=n) { score++; cur++; }
	}
	printf("%d\n",n-score);
}

int main()
{
	ios::sync_with_stdio(true);
	#ifndef ONLINE_JUDGE
		freopen("D.in","r",stdin);
	#endif
	int tcase; scanf("%d",&tcase);
	rep(nowcase,1,tcase) 
	{
		printf("Case #%d: ",nowcase);
		lemon();
	}
	return 0;
}

