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
	freopen("C-small-attempt0.in", "rt", stdin);
	freopen("C-small-attempt0.out", "wt", stdout);
#endif
}

#define REP(i, n) for (int i = 0; i < (n); i++)

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os<<"[";for(int i=0;i<v.size();i++)os<<" "<<v[i];os<<" ]";
    return os;
}

void solve() {
	int n; scanf("%d ", &n);
    vector<int> bf(n);
    REP(i, n) {
        scanf("%d ", &bf[i]);
        bf[i]--;
    }
    /* Search for cycles. */
    vector<int> incycle(n);
    int maxcycle = 0;
    REP(i, n) if (incycle[i] == 0) {
        int cyclelen = 1;
        vector<int> vis(n);
        int x = bf[i];
        for (; x != i && !vis[x]; x = bf[x]) {
            cyclelen++;
            vis[x] = 1;
        }
        if (x == i) {
            maxcycle = max(maxcycle, cyclelen);
            REP(j, n) if (vis[j]) incycle[j] = cyclelen;
            incycle[i] = cyclelen;            
        }
    }

    vector<vector<int> > v(n);
    REP(i, n) if (incycle[i] == 0) {
        int pathlen = 1;
        vector<int> vis(n);
        int x = bf[i];
        for (; x != i && !incycle[x]; x = bf[x]) {
            pathlen++;
        }
        v[x].push_back(pathlen);
    }
    REP(i, n) sort(v[i].rbegin(), v[i].rend());

    vector<int> processed(n);
    int r = 0;
    REP(i, n) if (!processed[i] && incycle[i] == 2) {
        if (v[i].size() > 0) r += v[i][0];
        if (v[bf[i]].size() > 0) r += v[bf[i]][0];
        processed[bf[i]] = 1;
        r += 2;
    }
    printf("%d\n", max(maxcycle, r));
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
