#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <iostream>
#define rep(i,l,r) for(int i = l;i <= r;++ i)
using namespace std;
double r,t;
int T;

void solve()
{
    scanf("%lf%lf",&r,&t);
	double delta = (2.0 * r - 1.0) * (2.0 * r - 1.0) + 8.0 * t;
	delta = sqrt(delta);
	double ans = (double)(1 - 2 * r + delta) / 4.0;
	if(ans < 1.0) puts("1");
	else printf("%.lf\n",ans);
}
int main()
{
	//freopen("input","r",stdin); freopen("output","w",stdout);
    scanf("%d",&T);
	rep(tm,1,T){
	   printf("Case #%d: ",tm);
	   solve();
	}
	return 0;
}
