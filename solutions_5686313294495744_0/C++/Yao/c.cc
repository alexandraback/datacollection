#include<stdio.h>
#include<string.h>

char s[16][2][1024];
int a[2][16];
int dp[1<<16];
char str[1024];

int main() {
	int N,cs=0,i,j,k,n;
	for(scanf("%d",&N);N--;) {
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%s %s",s[i][0],s[i][1]);
		memset(a,0,sizeof(a));
		for(i=0;i<2;i++) for(j=0;j<n;j++) {
			for(k=0;k<n;k++) if (!strcmp(s[j][i],s[k][i])) a[i][j]|=1<<k;
		}
		memset(dp,0,sizeof(dp));
		for(i=0;i<(1<<n);i++) {
			for(j=0;j<n;j++) if (!(i&(1<<j))) {
				if ((i&a[0][j])!=0 && (i&a[1][j])!=0) {
					if (dp[i]+1>dp[i|(1<<j)]) dp[i|(1<<j)]=dp[i]+1;
				}
			}
		}
		printf("Case #%d: %d\n",++cs,dp[(1<<n)-1]);
	}
	return 0;
}
