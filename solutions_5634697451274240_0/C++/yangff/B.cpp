#include <cstdio>
#include <cstring>

char buf[255];
bool s[255];

int main(){
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);

	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++){
		scanf("%s", buf); int cnt = 0;
		int n = strlen(buf);
		for (int i = 0; i < n; i++) {
			s[i] = buf[i] == '+';
		}
		for (int r = n - 1; r >= 0; r--) {
			if (s[r] == 0) {
				for (int i = 0; i <= r; i++)
					s[i] = !s[i];
				cnt ++;
			}
		}
		printf("Case #%d: %d\n", cas, cnt);
	}
}