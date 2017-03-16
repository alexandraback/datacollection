#include <cstdio>

using namespace std;

char s[1005];

int main(int argc, char const *argv[])
{
	freopen("iLA.in", "r", stdin);
	freopen("oLA.txt", "w", stdout);
	int tc, T, l, i, ans, st;
	scanf("%d", &T);
	for(tc = 1; tc <= T; tc++) {
		scanf("%d%s", &l, s);
		ans = 0; st = 0;
		for(i = 0; i <= l; i++) {
			if(s[i] == '0') continue;
			if(st < i) {
				ans = ans + (i - st);
				st = i;
			}
			st = st + (s[i] - '0');
		}
		printf("Case #%d: %d\n", tc, ans);
	}
	return 0;
}