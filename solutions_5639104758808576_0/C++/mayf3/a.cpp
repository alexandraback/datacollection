#include <cstdio>

const int N = 2333;

int n;
char s[N];

int main(){
	int test;
	scanf("%d", &test);
	for(int cas = 1; cas <= test; cas++){
		scanf("%d %s", &n, s);
		int ans = 0, now = 0;
		for(int i = 0; i <= n; i++){
			if (s[i] == '0') continue;
			if (now < i){
				ans += i - now;
				now = i;
			}
			now += s[i] - '0';
		}
		printf("Case #%d: %d\n", cas, ans);
	}
}
