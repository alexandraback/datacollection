#include <stdio.h>
#include <cstring>

using namespace std;

int dp[1000000],n;
int a[20],b[20],po[20];

int getloc(int v,int x) {
	while (x) v /= 3,x--;
	return v % 3;
}

void getdp(int m) {
	if (dp[m] == -1) return;
	int stars = 0;
	for (int i = 0;i < n;i++) 
		stars += getloc(m,i);
	for (int i = 0;i < n;i++) {
		int t = getloc(m,i);
		if (t < 2 && b[i] <= stars) {
			int mm = m + (2 - t) * po[i];
			if (dp[mm] == -1 || dp[mm] > dp[m] + 1) 
				dp[mm] = dp[m] + 1;
		} else if (t < 1 && a[i] <= stars) {
			int mm = m + (1 - t) * po[i];
			if (dp[mm] == -1 || dp[mm] > dp[m] + 1) 
				dp[mm] = dp[m] + 1;
		}
	}
}

int main() {
	int T;
	scanf("%d",&T);
	po[0] = 1;
	for (int i = 1;i <= 11;i++) 
		po[i] = po[i-1] * 3;
	for (int cas = 1;cas <= T;cas++) {
		scanf("%d",&n);
		for (int i = 0;i < n;i++) 
			scanf("%d%d",&a[i],&b[i]);
		memset(dp,-1,sizeof(dp));
		dp[0] = 0;
		for (int i = 0;i < po[n]-1;i++) 
			getdp(i);
		printf("Case #%d: ",cas);
		if (dp[po[n]-1] == -1) printf("Too Bad\n");
		else printf("%d\n",dp[po[n]-1]);
	}
	return 0;
}
