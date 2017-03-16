#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <cassert>
using namespace std;

void openFiles() {
#ifndef ONLINE_JUDGE
    //freopen("test.in", "rt", stdin);
    // freopen("C-small-attempt0.in", "rt", stdin);
    // freopen("C-small-attempt0.out", "wt", stdout);
    freopen("C-large.in", "rt", stdin);
    freopen("C-large.out", "wt", stdout);
    //freopen("test.out", "wt", stdout);
#endif
}

void solve() {
	int c, d, v; scanf("%d %d %d ", &c, &d, &v);
    vector<long long> D(d);
    for (int i = 0; i < d; i++) {
        cin >> D[i];        
    }   
    sort(D.begin(), D.end());
    long long mx = 0;
    int o = 0;
    for (int i = 0; i < d; i++) {
        while (D[i] > mx + 1) {
            long long r = mx + 1;
            mx = r * c + mx;
            o++;
        }
        mx = D[i] * c + mx;
    }
    while (v > mx) {
        mx = c * (mx + 1) + mx;
        o++;
    }
    cout << o << endl;
}

int main() {
    openFiles();
    int n; scanf("%d ", &n);
    for (int i = 0; i < n; i++) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}
