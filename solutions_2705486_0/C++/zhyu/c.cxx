#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 521196;
const int M = 111;

char dict[N+100][M];
int l[N+100];
int dp[M];

inline void init() {
	FILE * f;
	f = fopen("garbled_email_dictionary.txt", "r");
	for(int i=0;i<N;i++) {
		fscanf(f, "%s", dict[i]);
		l[i]=strlen(dict[i]);
	}
}

int main() {
	init();
	int t;
	char s[111];
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++) {
		scanf("%s",s+1);
		int n=strlen(s+1);
		fill(dp,dp+n+1,n);
		dp[0]=0;
		for(int i=1;i<=n;i++) {
			int flag=0;
			for(int j=0;j<N;j++) {
				if(l[j]>i) continue;
				flag=0;
				for(int k=0;k<l[j];k++) {
					int dist=abs(dict[j][k]-s[i-l[j]+k+1]);
					if(dist && dist<5) {
						flag=-1;
						break;
					}
					flag+=(dist!=0);
				}
				if(flag<0) continue;
				dp[i]=min(dp[i],dp[i-l[j]]+flag);
				if(dp[i]==0) {
					break;
				}
			}
		}
		printf("Case #%d: %d\n", cas,dp[n]);
	}
	return 0;
}
