#include <cstdio>
#include <cstring>
int tc, tcn, n, sum,re;
char s[1009];

void solve(){
	scanf("%d", &tc);
	while (tc--){
		scanf("%d %s", &n, s);
		
		sum = re = 0;

		for (int i = 0; i <= n; i++){
			if (s[i] == '0')
				continue;
			if (sum < i){
				re += i - sum;
				sum += i - sum;
			}
			sum += s[i] - '0';

		}
		printf("Case #%d: %d\n", ++tcn, re);
	}
}

int main(void){
	//freopen("A-small-attempt0.in", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}