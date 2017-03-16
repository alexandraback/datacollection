#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

int T;

int D;
int P[1000];

bool comp(int l, int r) { return l > r; }

int solve() {
    sort(P, P + D, comp);
    int p_max = P[0];
    int ans = INT_MAX;

    for (int i = 1; i <= p_max; i++) {
        int t = 0;

        for (int j = 0; j < D; j++) {
            t += P[j] / i + (P[j] % i == 0 ? 0 : 1) - 1;
        }

        ans = min(ans, t + i);
    }

    return ans;
}

int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        for (int j = 0; j < 1000; j++) { P[j] = 0; }

        scanf("%d", &D);
        for (int j = 0; j < D; j++) {
            scanf("%d", &P[j]);
        }

        printf("Case #%d: %d\n", i, solve());
    }
    return 0;
}

