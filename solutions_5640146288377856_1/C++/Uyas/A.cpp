#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int answer, R, C, W;

void readin() {
    cin >> R >> C >> W;
}

int f[22][22][22];
bool g[22][22][22];

int miss(int n) { return n / W; }

void hehe(int n, int l, int r) {
    //cout << n << " " << l << " " << r  << endl;
    if (g[n][l][r]) return;
    g[n][l][r] = 1;
    f[n][l][r] = 12345;
    if (n < W) {
        f[n][l][r] = -11111;
        return;
    }
    if (l > 0 && r > 0 && r - l + 1 == W) {
        f[n][l][r] = 0;
        return;
    }
    if (l == 0 && r == 0) {
        for (int i = 1; i <= n; ++i) {
            // hit i
            hehe(n, i, i);
            int p1 = f[n][i][i] + 1;
            // miss, but thing on the left
            hehe(i - 1, 0, 0);
            int p2 = f[i - 1][0][0] + miss(n - i) + 1;
            // miss, on the right
            hehe(n - i, 0, 0);
            int p3 = f[n - i][0][0] + miss(i - 1) + 1;
            int here = max(p1, max(p2, p3));
            f[n][l][r] = min(f[n][l][r], here);
        }
    } else {
        for (int i = max(r - W + 1, 1); i < l; ++i) {
            // hit 
            hehe(n, i, r);
            int p1 = f[n][i][r] + l - i;
            // miss
            hehe(n - i, l - i, r - i);
            int p2 = f[n - i][l - i][r - i] + 1;
            int here = max(p1, p2);
            f[n][l][r] = min(f[n][l][r], here);
        }
        for (int i = min(l + W - 1, n); i > r; --i) {
            hehe(n, l, i);
            int p1 = f[n][l][i] + i - r;
            hehe(i - 1, l, r);
            int p2 = f[i - 1][l][r] + 1;
            int here = max(p1, p2);
            f[n][l][r] = min(f[n][l][r], here);
        }
    }
    //cout << n << " " << l << " " << r << " : " << f[n][l][r] << endl;
}

void work() {
    memset(f, 0, sizeof f);
    memset(g, 0, sizeof g);
    answer = (R - 1) * miss(C);
    hehe(C, 0, 0);
    answer += f[C][0][0];
}

int main() {
    int tasks; cin >> tasks;
    for (int cas = 1; cas <= tasks; ++cas) {
        readin();
        work();
        cout << "Case #" << cas << ": " << answer << endl;
    }
    return 0;
}
