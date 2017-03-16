#include <stdio.h>

int t,a,b,k;

int main() {
	scanf("%d",&t);
	for(int Case = 1; Case <= t; Case++) {
		int ans = 0;
		scanf("%d%d%d",&a,&b,&k);
		for(int i=0;i<a;i++) {
			for(int j=0;j<b;j++) {
				if((i&j) < k) {
					ans++;
				}
			}
		}
		printf("Case #%d: %d\n",Case,ans);
	}
	return 0;
}
