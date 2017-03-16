#include <stdio.h>
#include <algorithm>

using namespace std;

double p[100100];
int a,b;

int main() {
	int T;
	scanf("%d",&T);
	for (int cas = 1;cas <= T;cas++) {
		scanf("%d%d",&a,&b);
		for (int i = 1;i <= a;i++) scanf("%lf",&p[i]);
		double P = 1, ans = b+2;
		for (int i = 1;i <= a;i++) {
			double tmp = P * (a-i+1+(b-i+1)+1) + (1-P) * (a-i+1+(b-i+1)+1+b+1);
			if (tmp < ans) ans = tmp;
			P = P * p[i];
		}
		ans = min(ans,P * (b-a+1) + (1-P) * (2*b-a+2));
		printf("Case #%d: %.6lf\n",cas,ans);
	}
	return 0;
}
