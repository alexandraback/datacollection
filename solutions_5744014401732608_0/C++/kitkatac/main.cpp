

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pair_q;


long long f[100];
const long long maxn = 1e18 + 1;
void init() {
    f[1] = 1;
    long long sum = 1;
    for (int i = 2; i <= 70; i++) {
        f[i] = sum;
        sum += f[i];
        if (sum > maxn) {
            break;
        }
    }
}
int main(){

	//freopen("B-small-attempt2.in", "r", stdin);
	//freopen("B-small-attempt2.out", "w", stdout);
    int T;
    scanf ("%d", &T);
    init();
    for (int cas = 1; cas <= T; cas++) {
        long long b,m;
        cin >> b >> m;
        printf("Case #%d: ", cas);
        int ans[55][55];
        memset(ans, 0, sizeof(ans));
        int cur = 1;
        if (m > f[b]) {
			printf("IMPOSSIBLE\n");
            continue;
        }
        for (int i = b - 1; i >= 1 && cur <= b; i--, cur++) {
            if (f[cur] < m) {
                for (int j = i + 1; j <= b; j++) {
                    ans[i][j] = 1;
                }
            } else {
                ans[i][i+1] = 1;
            }
        }
        printf("POSSIBLE\n");
        for (int i = 1; i <= b; i++) {
            for (int j = 1; j <= b; j++) {
				printf("%d", ans[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
