#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
int cnts[2555];

int main(){
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++){
		memset(cnts, 0, sizeof(cnts));
		int n; scanf("%d", &n);
		for (int i = 0; i < 2 * n - 1; i++){
			for (int j = 0; j < n; j++){
				int x; scanf("%d", &x);
				cnts[x]++;
			}
		}
		int y = 0;
		printf("Case #%d:", cas);
		for (int i = 1; i <= 2500; i++) {
			if (cnts[i] % 2 == 1)
				printf(" %d", i);
		}
		puts("");
	}
}