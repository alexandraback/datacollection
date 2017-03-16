#include <iostream>
#include <cstdio>

using namespace std;

int a,b;
int ans;

int main() {
	int t,tt;
	scanf("%d",&t);
	for (tt=1;tt<=t;tt++) {
		ans=0;
		scanf("%d%d",&a,&b);
		if (a<=1&&b>=1) ans++;
		if (a<=4&&b>=4) ans++;
		if (a<=9&&b>=9) ans++;
		if (a<=121&&b>=121) ans++;
		if (a<=484&&b>=484) ans++;
		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}
