#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define MP make_pair
#define F first
#define S second

const string I = "Impossible";
const int N = 55;

int tot = 0;
bool dp[N][N][N * N];
int par[N][N][N * N];
char c[N][N];

void rec(int row, int len, int sum)
{
    for (int i = 0; i < len; i++)
        c[row][i] = '.';
    if (row > 0)
        rec(row - 1, par[row][len][sum], sum - len);
    else
        assert(sum == len);
}

void solve(int test)
{
    cout << "Case #" << test << ":\n";
    int n, m, cnt;
    cin >> n >> m >> cnt;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= m; j++)
            for (int sum = 0; sum <= n * m; sum++)
                dp[i][j][sum] = false;
    if (n * m - cnt == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << (!i && !j ? 'c' : '*');
            cout << "\n";
        }
        return;
    }
    if (n == 1) {
        for (int i = 0; i < m; i++)
            if (i < cnt)
                cout << '*';
            else
                cout << (i == m - 1 ? 'c' : '.');
        cout << "\n";
        return;
    }
    if (m == 1) {
        for (int i = 0; i < n; i++) {
            if (i < cnt)
                cout << '*';
            else
                cout << (i == n - 1 ? 'c' : '.');
            cout << "\n";
        }
        return;
    }
    for (int i = 2; i <= m; i++)
        dp[0][i][i] = true;
    for (int row = 1; row < n; row++)
        for (int old = 2; old <= m; old++)
            for (int sum = 0; sum <= n * m; sum++) {
                if (!dp[row - 1][old][sum])
                    continue;
                int low = 2;
                if (row == 1)
                    low = max(low, old);
                for (int cur = low; cur <= old; cur++) {
                    dp[row][cur][sum + cur] = true;
                    par[row][cur][sum + cur] = old;
                }
            }
    for (int row = 1; row < n; row++)
        for (int cur = 2; cur <= m; cur++)
            if (dp[row][cur][n * m - cnt]) {
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < m; j++)
                        c[i][j] = '*';
                rec(row, cur, n * m - cnt);
                c[0][0] = 'c';
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++)
                        cout << c[i][j];
                    cout << "\n";
                }
                return;
            }
    tot++;
    cout << I << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cout.setf(ios::fixed);
    cout.precision(7);

    int t;
    cin >> t;
    for (int q = 1; q <= t; q++)
        solve(q);

    cerr << tot << endl;

    return 0;
}
