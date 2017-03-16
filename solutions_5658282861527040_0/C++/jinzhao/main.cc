#include <cstdio>
#include <cstring>

using namespace std;

long long dp[40];
long long aa[40],bb[40],cc[40];
int a,b,k;

int main() {
	int t,tt,i;
	scanf("%d",&t);
	for (tt=1;tt<=t;tt++) {
		scanf("%d%d%d",&a,&b,&k);
		if ((k&1)==1) {
			dp[0]=(a&1)*(b&1);
			aa[0]=2*(b&1);
			bb[0]=2*(a&1);
			cc[0]=3;
		} else {
			dp[0]=0;
			aa[0]=bb[0]=0;
			cc[0]=0;
		}
		for (i=1;i<31;i++) {
			if ((k&1<<i)==0) {
				if ((b&1<<i)==0) aa[i]=2*aa[i-1];
				else aa[i]=aa[i-1]+2*cc[i-1];
				if ((a&1<<i)==0) bb[i]=2*bb[i-1];
				else bb[i]=bb[i-1]+2*cc[i-1];
				cc[i]=3*cc[i-1];
				dp[i]=dp[i-1];
				if ((a&1<<i)!=0&&(b&1<<i)==0) dp[i]+=aa[i-1];
				if ((b&1<<i)!=0&&(a&1<<i)==0) dp[i]+=bb[i-1];
				if ((a&1<<i)!=0&&(b&1<<i)!=0) dp[i]=aa[i-1]+bb[i-1]+cc[i-1];
			} else {
				if ((b&1<<i)==0) aa[i]=(1<<i+1)*(b&(1<<i)-1);
				else aa[i]=(1<<i+1)*(1<<i)+(1<<i)*(b&(1<<i)-1)+aa[i-1];
				if ((a&1<<i)==0) bb[i]=(1<<i+1)*(a&(1<<i)-1);
				else bb[i]=(1<<i+1)*(1<<i)+(1<<i)*(a&(1<<i)-1)+bb[i-1];
				cc[i]=3*(1<<i)*(1<<i)+cc[i-1];
				dp[i]=(a&(1<<i+1)-1)*(b&(1<<i+1)-1);
				if ((a&1<<i)!=0&&(b&1<<i)!=0) {
					dp[i]+=dp[i-1]-(a&(1<<i)-1)*(b&(1<<i)-1);
				}
			}
		}
		/*
		printf("dp[i]: ");
		for (i=0;i<5;i++) printf("%lld ",dp[i]);
		printf("\n");
		printf("aa[i]: ");
		for (i=0;i<5;i++) printf("%lld ",aa[i]);
		printf("\n");
		printf("bb[i]: ");
		for (i=0;i<5;i++) printf("%lld ",bb[i]);
		printf("\n");
		printf("cc[i]: ");
		for (i=0;i<5;i++) printf("%lld ",cc[i]);
		printf("\n");
		*/
		printf("Case #%d: %lld\n",tt,dp[30]);
	}
	return 0;
}
