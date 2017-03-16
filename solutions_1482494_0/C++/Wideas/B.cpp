#include<iostream>
using namespace std;

const int maxn = 1000 * 2;

struct node {
    int a, b;
};
node node[maxn];
int a[maxn], b[maxn];
int f[maxn];
int T, n;

void init() {
    memset(f, 0, sizeof (f));
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
}

void solve() {
    int cnt = 0, ans = 0, last = -1;
    bool flag;
    while (cnt > last) {
        last = cnt;
        flag = true;
        while (flag) {
            flag = false;
            for (int i = 0; i < n; i++) {
                if (cnt >= a[i] && cnt >= b[i] && f[i] != 2) {
                    cnt += (2 - f[i]);
                    f[i] = 2;
                    ans++;
                    flag = true;
                }
            }
        }
        int xp = -1, tMax = 0;
        for (int i = 0; i < n; i++)
            if (cnt >= a[i] && cnt < b[i] && f[i] == 0 && b[i] > tMax) {
                tMax = b[i];
                xp = i;
            }
        if (xp != -1) {
            f[xp] = 1;
            cnt++;
            ans++;
        }
    }
    if (cnt != 2 * n) cout << "Too Bad" << endl;
    else cout << ans << endl;
}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    cin >> T;
    for (int test = 1; test <= T; test++) {
        cout << "Case #" << test << ": ";
        init();
        solve();
    }
    return 0;
}
