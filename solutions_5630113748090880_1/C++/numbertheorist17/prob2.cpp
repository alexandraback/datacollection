#include <bits/stdc++.h>
using namespace std;

const int MAXN = 60;

int n, t;

int main(void) {
    if (fopen("b-small.in", "r")) {
        freopen("b-small.in", "r", stdin);
        freopen("b-small.out", "w", stdout);
    }
    if (fopen("b-large.in", "r")) {
        freopen("b-large.in", "r", stdin);
        freopen("b-large.out", "w", stdout);
    }
    cin >> t;
    for (int ii = 1; ii <= t; ii++) {
        cin >> n;
        map<int,int> m;
        for (int i = 0; i < 2 * n - 1; i++) {
            int a;
            for (int j = 0; j < n; j++) {
                cin >> a;
                m[a]++;
            }
        }
        printf("Case #%d: ", ii);
        vector<int> ans;
        for (auto& v: m) {
            if (v.second % 2 == 1) ans.push_back(v.first);
        }
        for (int i = 0; i < ans.size(); i++) {
            printf("%d", ans[i]);
            if (i == (int)ans.size() - 1) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}
