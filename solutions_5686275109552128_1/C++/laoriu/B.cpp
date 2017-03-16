#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000 + 10;
const int INF = (int)(1e9);

int a[MAXN];
int f[MAXN][MAXN];

void init() {
    int n = 1000;
    f[1][0] = INF;
    for(int i = 2; i <= n; i++) {
        f[i][0] = INF;
        for(int j = 1; j <= n; j++) {
            f[i][j] = f[i - 1][j - 1];
            for(int x = 1; x < i; x++) {
                int y = i - x;
                f[i][j] = min(f[i][j], f[x][j] + f[y][j] + 1);
            }
        }
    }
}

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B.out", "w", stdout);

    init();
    int test;
    cin >> test;
    for(int tc = 1; tc <= test; tc++) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        int result = INF, amax = 0;
        for(int i = 1; i <= n; i++) amax = max(amax, a[i]);
        for(int i = 1; i <= amax; i++) {
            int x = i;
            for(int j = 1; j <= n; j++) x += f[a[j]][i];
            result = min(result, x);
        }
        cout << "Case #" << tc << ": " << result << endl;
    }
}
