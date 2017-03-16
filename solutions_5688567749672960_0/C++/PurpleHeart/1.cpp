#include <cstdio>
#include <cstring>

int N, T;
int dp[1000005];

int smin(int a, int b){
	if(a == -1) return b;
	if(b == -1) return a;
	return (a < b) ? a : b;
}

int rev(int x){
	int ret = 0;
	while(x){
		ret = ret * 10 + x % 10;
		x = x / 10;
	}
	return ret;
}

void pre(){
	memset(dp, 255, sizeof(dp)); 
	for(int i = 1; i <= 10; ++i)
		dp[i] = i;
	for(int i = 11; i <= 1000000; ++i){
		for(int j = 1; j < i; ++j) dp[i] = smin(dp[i], dp[j] + (i - j));
		if(i % 10 != 0){
			int j = rev(i);
			if(j < i) dp[i] = smin(dp[i], dp[j] + 1);
		} else {
			printf("OK: %d\n", i);
		}
	}
}

int main(){
	pre();
	printf("ok");
	// pause
	char ch;
	scanf("%c", &ch);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for(int xx = 1; xx <= T; ++xx){
		scanf("%d", &N);
		printf("Case #%d: %d\n", xx, dp[N]);
	}
	//for(int i = 0; i <= 100000; ++i) printf("%d,", dp[i]);
	
}
