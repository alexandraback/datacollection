#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a,n;
int data[110];
int dp[110];
int ans;

int main() {
	int t,tt,i;
	scanf("%d",&t);
	for (tt=1;tt<=t;tt++) {
		scanf("%d%d",&a,&n);
		for (i=1;i<=n;i++) {
			scanf("%d",&data[i]);
		}
		sort(data+1,data+n+1);
		if (a!=1) {
			ans=n;
			dp[0]=0;
			for (i=1;i<=n;i++) {
				dp[i]=dp[i-1];
				while (a<=data[i]) {
					dp[i]++;
					a+=a-1;
				}
				a+=data[i];
				ans=min(ans,dp[i]+n-i);
			}
		} else {
			ans=0;
			for (i=1;i<=n;i++)
				if (data[i]!=0) ans++;
		}
		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}
