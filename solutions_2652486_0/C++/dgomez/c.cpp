#include <iostream>
using namespace std;

const int maxn = 3;
const int maxk = 7;
const int maxp = 79000;
int n, m, k;
int v[maxn];
int w[maxk];
int dp[maxn][maxp];

bool validSingle(int i, int kk) {
    if (i == n) {
        return kk == 1;
    }

    int& ans = dp[i][kk];
    if (ans != -1) {
        return (bool) ans;
    }

    ans = 0;
    if (validSingle(i + 1, kk)) {
        ans = 1;
    }
    if ((kk % v[i] == 0) && validSingle(i + 1, kk / v[i])) {
        ans = 1;
    }

    return (bool) ans;
}

bool valid() {
    int i;
    for (i = 0; i < k; i++) {
        memset(dp, -1, sizeof dp);
        if (!validSingle(0, w[i])) {
            return false;
        }
    }

    return true;
}

void printAns() {
    int i;

    for (i = 0; i < n; i++) {
        cout << v[i];
    }
    cout << endl;
}

bool generate(int i) {
    if (i == n) {
        if (valid()) {
            printAns();
            return true;
        }

        return false;
    }

    int j;
    for (j = 2; j <= m; j++) {
        v[i] = j;

        if (generate(i + 1)) {
            return true;
        }
    }

    return false;
}

int main() {
    int t, tt, i, j, r;

    cin >> t;
    for (tt = 0; tt < t; tt++) {
        cin >> r >> n >> m >> k;

        cout << "Case #" << (tt + 1) << ":" << endl;
        for (i = 0; i < r; i++) {
            for (j = 0; j < k; j++) {
                cin >> w[j];
            }

            generate(0);
        }
    }

    return 0;
}
