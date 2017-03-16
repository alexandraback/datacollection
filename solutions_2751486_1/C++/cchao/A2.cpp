#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define M 1000100
char s[M];
int dp[M], sz;
int n, len;
char xd[] = "aeiou";
int f[128]={0};
int main(){
	for(int i = 0; xd[i]; ++i)f[xd[i]] = 1;
	int T;
	scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase){
		scanf("%s%d", s, &n);
		len = strlen(s);
		printf("Case #%d: ", kase);
		int now = 0;
		sz = 0;
		for(int i = 0; i < len; ++i){
			if(f[s[i]]==0) now++;
			else now = 0;
			if(now >= n){
				dp[sz++] = i;
			}
		}
		long long ans = 0;
		for(int i = 0; i < sz; ++i){
			long long lc,
				rc = (len - dp[i]);
			if(i) lc = (dp[i] - n + 1) - (dp[i-1] - n + 1);
			else lc = (dp[i] - n + 2);

//			printf("add %d*%d at %c\n", lc, rc, s[dp[i]]);
			ans += lc*rc;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
