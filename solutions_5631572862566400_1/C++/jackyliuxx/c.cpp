#include<bits/stdc++.h>
using namespace std;

int ans;

void gf(int x, int bg, int l, vector<int> &mxl, vector<int> &bf, vector<bool> &hs, vector<bool> &ggp) {
    if (bf[x] == bg) {
        ans = max(ans, l);
    } else if (hs[bf[x]]) {
        return;
    }
    hs[x] = true;
    mxl[x] = max(mxl[x], l);
    if (ggp[x]) {
        return;
    }
    gf(bf[x], bg, l + 1, mxl, bf, hs, ggp);
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int tsk = 1; tsk <= t; tsk++) {
        int n;
        cin >> n;
        vector<int> bf(n);
        for (int i = 0; i < n; i++) {
            cin >> bf[i];
            bf[i]--;
        }
        ans = 0;
        vector<int> mxl(n, 0);
        vector<bool> ggp(n, false);
        for (int i = 0; i < n; i++) {
            if (bf[bf[i]] == i) {
                ggp[i] = true;
            }
        }
        for (int i = 0; i < n; i++) {
            vector<bool> hs(n, false);
            gf(i, i, 1, mxl, bf, hs, ggp);
        }
        int pp = 0;
        for (int i = 0; i < n; i++) {
            if (bf[bf[i]] == i) {
                pp += mxl[i] + mxl[bf[i]];
            }
        }
        pp /= 2;
        ans = max(ans, pp);
        /*
        cout << "******" << endl;
        for (auto i : mxl) {
            cout << i << ' ';
        }
        cout << endl;
        */
        cout << "Case #" << tsk << ": " << ans << endl;
    }
}
