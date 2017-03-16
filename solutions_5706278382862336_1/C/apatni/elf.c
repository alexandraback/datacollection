#include <stdio.h>
int findgen(double p, double q) {
	double a = p/q;
	int ans = 1;
	double high = 1;
	double low = 0;
	double mid;
	int i;
	int count=0;
	int changed=0;
	for(i=0; i<40; i++) {
		mid= (high + low) /2;
		if(a==mid) {
			break;
		}
		//printf("%lf\n", mid);
		if(a>mid) {
			low = mid;
			changed=1;
		}
		else {
			high = mid;
			if(!changed) ans++;
		}
		if(i==39) return -1;
	}
	return ans;
}
int main () {
	int t, i;
	scanf("%d", &t);
	double p,q;
	int ans;
	for(i=0; i<t; i++) {
		scanf("%lf / %lf",&p, &q);
		ans = findgen(p,q);
		printf("Case #%d: ",i+1);
		if(ans==-1) printf("impossible\n");
		else printf("%d\n", ans);
	}
}