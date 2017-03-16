#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1010
using namespace std;

int T, n; 
char s[N], a[N], b[N];

int main() {
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d", &T);
	for (int k = 1; k <= T; k++) {
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		a[1] = s[1];
		for (int i = 2; i <= n; i++) if (s[i] >= a[1]) {
			for (int j = i + 1; j >= 2; j--) a[j] = a[j - 1];
			a[1] = s[i];
		} else a[i] = s[i];
		printf("Case #%d: ", k);
		for (int i = 1; i <= n; i++) printf("%c", a[i]);
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
}