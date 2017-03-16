#include <cstdio>
#include <algorithm>
using namespace std;
double c,f,X;
int ca;
double calc(int x)
{
	double ans = X / (x * f + 2);
	for(int i = 1; i <= x; ++i)
		ans += c / ((i - 1) * f + 2);
	return ans;
}
void solve()
{
	scanf("%lf%lf%lf",&c,&f,&X);
	double tmp,ret = 100000,ans = 100000;
	for(int i = 0; i <= 100000; ++i){
		tmp = calc(i);
		ans = min(tmp,ans);
		if(tmp > ret) break;
		ret = tmp;
	}
	printf("Case #%d: %.7lf\n",++ca,ans);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}

