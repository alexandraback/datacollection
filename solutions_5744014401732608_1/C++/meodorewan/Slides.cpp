#include <bits/stdc++.h>

#define reset(a, b) memset(a, b, sizeof(a))
#define REP(i, a) for (int i = 0; i < a.size(); i++)

using namespace std;

const int N = 111;
const int INF = 1000000007;

int n;
long long M, pw[N];
int ans[N][N];

void connect(int mx){
    for (int i = n ; i >= n - mx; i--)
        for (int j = i - 1; j >= n - mx; j--)
            ans[j][i] = 1;
    if (n - mx > 1)
        ans[1][n - mx] = 1;
}

void solve(int testCase) {
    printf("Case #%d: ", testCase);

    reset(ans, 0);
    cin >> n >> M;

    int mx = n - 2;
    if (M > pw[mx]){
        cout << "IMPOSSIBLE\n";
        return;
    }
    for (int i = 55; i >= 0; i--)
        if (pw[i] <= M) {
            connect(i + 1);
            M -= pw[i];
            break;
        }
    for (int i = 55; i >= 0; i--)
        if (pw[i] <= M) {
            ans[1][n - i - 1] = 1;
            M -= pw[i];
        }
    cout << "POSSIBLE\n";
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            printf("%d", ans[i][j]);
        printf("\n");
    }
}

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);

    pw[0] = 1;
    for (int i = 1; i <= 55; i++)
        pw[i] = pw[i - 1] * 2;

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
        solve(i);
}
