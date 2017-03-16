#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1234567;
char s[maxn];
bool m[12345];
bool is[maxn];

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	m['a'] = m['e'] = m['i'] = m['o'] = m['u'] = true;
	int t, c, n, l, ans;
	scanf("%d", &t);
	for(c = 1; c <= t; c++) {
		scanf("%s%d", s, &n);
		l = strlen(s);
		for(int i = 0; i < l; i++)
			is[i] = !m[s[i]];
		ans = 0;
		for(int i = 0; i < l; i++) {
			for(int j = i; j < l; j++) {
				int cnt = 0;
				bool last = false;
				for(int k = i; k <= j; k++) {
					if(is[k] && last) {
						cnt++;
					} else {
						cnt = 0;
					}
					if(is[k] && !last) {
						last = true;
						cnt = 1;
					}
					if(cnt >= n) {
						ans++;
						break;
					}
				}
			}
		}
		printf("Case #%d: %d\n", c, ans);
	}
	return 0;
}
