#include <cstdio>
#include <algorithm>

using namespace std;

int T;
double C,F,X;

int main() {
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&T);
	for(int cs=1;cs<=T;++cs) {
		printf("Case #%d: ", cs);
		scanf("%lf%lf%lf",&C,&F,&X);

		double cooky = 2;
		double ans = X / cooky;
		double cur = 0;
		for(int i=1;i<=100000;++i) {
			ans = min(ans, cur + C / cooky + X / (cooky + F));
			cur = cur + C / cooky;
			cooky += F;
		}
		printf("%.10lf\n",ans);
	}
}