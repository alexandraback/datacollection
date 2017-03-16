#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int p_max = 0;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p_max = max(p_max, p[i]);
    }
    
    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());

    int ans = p_max;
    for (int i = 1; i < p_max; ++i) {
        int lans = i;
        for (int j = 0; j < n && p[j] > i; ++j) {
            lans += (p[j] - i - 1) / i + 1;
        }
        ans = min(ans, lans);
    }
    
    cout << ans;
}

int main() {
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        printf("Case #%d: ", i + 1);
        solve();
        printf("\n");
    }
}
