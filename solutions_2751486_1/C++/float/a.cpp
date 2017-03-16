#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

char str[1000010];
long long dp[1000010];

int main()
{
	int cas, cas_n, L;
	long long ans;
	int count;
	scanf("%d", &cas_n);
	for(cas=1; cas<=cas_n; cas++) {
		scanf("%s %d", str, &L);
		ans = 0;
		count = 0;
		dp[0] = 0;
		for(int i=0; str[i]; i++) {
			switch(str[i]) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				count = 0;
				break;
			default:
				count++;
				break;
			}
			if(count >= L) {
				dp[i + 1] = i - L + 2;
			}
			else {
				dp[i + 1] = dp[i];
			}
			ans += dp[i + 1];
		}
		printf("Case #%d: %lld\n", cas, ans);
	}
	return 0;
}
