#include <bits/stdc++.h>
#define maxN 1000000

using namespace std;

int x[40];
bool fr[40];
int n, k, d, even, m;
int res[40];
long long hash[501];

bool not_dup() {    
    int a[50];
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= m; i++)
        a[x[i]] = 1;
    long long so = 0, mu = 1;
    
    for (int i = n-1; i >= 2; i--) {
        so += a[i] * mu;
        mu *= 2;
    }

    
    
    for (int i = 0; i < d; i++)
        if (hash[i] == so) return false;
    hash[d] = so;
    return true;
}

void output() {
    memset(res, 0, sizeof(res));
    for (int i = 1; i <= m; i++)
        res[x[i]] = 1;
    cout << "1";
    for (int i = 1; i <= n-2; i++)
        cout << res[i];
    cout << "1 ";
    cout << "3 2 3 2 7 2 3 2 3" << endl;
}

void dq(int i) {
    if (d == k) return;
    for (int j = 1; j <= n - 2; j++)
        if (fr[j])
            if (even == 0 || (even == 1 && j % 2 == 0) ||
                             (even == -1 && j % 2 == 1)) {
                if (d == k) return;
                x[i] = j;
                fr[j] = false;
                if (j % 2 == 0) even--;
                else even++;

                if (i == m) {
                    if (not_dup()) {
                        d++;
                        output();
                        if (d == k) return;
                    }
                } else dq(i+1);

                fr[j] = true;
                if (j % 2 == 0) even++;
                else even--;
            }
}

int main() {
    freopen("C-large.in", "r", stdin);
    freopen("CoinJam.out", "w", stdout);

    int t;
    cin >> t;

    cin >> n >> k;

    d = 0; even = 0;
    memset(x, 0, sizeof(x));
    memset(fr, true, sizeof(fr));
    cout << "Case #1:" << endl;
    for (int i = 1; i <= n / 6; i++) {
        m = i * 6 - 2;
        dq(1);
    }
}



