#include <stdio.h>

double c,f,x;
int t;

int main() {
	scanf("%d",&t);
	for(int Case = 1;Case <= t;Case++) {
		scanf("%lf %lf %lf",&c,&f,&x);
		double ans = x/2,t = 0,r = 2,l = -1.0;
		for(int i=1;1;i++) {
			t += c / r;
			r += f;
			double k = t + x/r;
			if(k >= l && l >= 0) {
				break;
			}else if(k < ans) {
				ans = k;
			}
			l = k;
		}
		printf("Case #%d: %.7lf\n",Case,ans);
	}
	return 0;
}
