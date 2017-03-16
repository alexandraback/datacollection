#include <cstdio>
#include <cstring>
using namespace std;
int T, n;
char str[1111];
int main() {
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d", &n);
		scanf("%s", str);
		int res = 0, rc = 0;
		for (int i = 0; i <= n; i++) {
			if (str[i] == '0')
				continue;
			if (rc < i) {
				res += i - rc;
				rc = i;
			}
			rc += str[i] - '0';
		}
		printf("Case #%d: %d\n", i, res);
	}
	return 0;
}
