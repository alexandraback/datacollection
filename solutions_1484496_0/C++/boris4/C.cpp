#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAX_N = 20;
const int MAX_V = 100005;

int n;
int a[MAX_N];

int s[MAX_N * MAX_V];

int main() {
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int tests; scanf("%d", &tests);
	for (int testId = 1; testId <= tests; ++testId) {
		printf("Case #%d:\n", testId);
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		memset(s, -1, sizeof(s));
		bool found = false;
		for (int mask = 1; mask < 1 << n; ++mask) {
			int sum = 0;
			for (int i = 0; i < n; ++i)
				if ((mask >> i) & 1)
					sum += a[i];
			if (s[sum] != -1) {
				int x = mask ^ (mask & s[sum]);
				int y = s[sum] ^ (mask & s[sum]);
				for (int i = 0; i < n; ++i)
					if ((x >> i) & 1)
						printf("%d ", a[i]);
				printf("\n");
				for (int i = 0; i < n; ++i)
					if ((y >> i) & 1)
						printf("%d ", a[i]);
				printf("\n");
				found = true;	
				break;
			}
			s[sum] = mask;
		}
		if (!found) printf("Impossible\n");
	}
	return 0;
}