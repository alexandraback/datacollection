#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1002;
const int INF = 0x3f3f3f3f;

int a[MAXN], b[MAXN];
int f[MAXN][MAXN * 2];
int n;
int passed_a[MAXN], passed_b[MAXN];

int main() {
	int t;
	scanf("%d", &t);
	for (int c = 1; c <= t; ++c) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d", a + i, b + i);
		}

		for (int i = 1; i <= n; ++i)
			for (int j = i+1; j <= n; ++j)
				if (b[i] > b[j] || b[i] == b[j] && a[i] > a[j]) {
					swap(a[i], a[j]);
					swap(b[i], b[j]);
				}
		
		int answer = 0;
		memset(passed_a, 0, sizeof(passed_a));
		memset(passed_b, 0, sizeof(passed_b));
		int star = 0;
		for (int i = 1; i <= n; ++i) {
			while (star < b[i]) {
				int j;
				for (j = n; j > 0; --j) {
					if (!passed_a[j] && !passed_b[j] && star >= a[j]) break;
				}
				if (!j) break;
				passed_a[j] = 1;
				star++;
				answer++;
			}
			if (star < b[i]) { answer = INF; break; }
			if (passed_a[i]) star += 1;
			else star += 2;
			answer++;
			passed_b[i] = 1;
		}
		
		printf("Case #%d: ", c);
		if (answer == INF) printf("Too Bad\n");
		else printf("%d\n", answer);
	}
}

