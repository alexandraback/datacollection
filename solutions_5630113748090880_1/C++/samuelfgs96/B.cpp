#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ForC(i, n) for (int i = 0; i < int(n); i++)
#define ForD(i, n) for (int i = int(n-1); i >= 0; i--)

using namespace std;
const double PI = acos(-1.0);

typedef long long ll;
typedef pair<int, int> pii;

int heights[2550];
int main (void) {
	int t;
	scanf("%d", &t);
	for (int cases = 1; cases <= t; cases++) {
		memset (heights, 0, sizeof heights);
		int n; scanf("%d", &n);
		int N = n + n - 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < n; j++) {
				int x; scanf("%d", &x);
				heights[x]++;
			}
		}
		printf("Case #%d:", cases);
		for (int k = 0; k < 2550; k++) {
			if (heights[k] % 2) printf(" %d", k);
		}
		printf("\n");
	}
	return 0;
}
