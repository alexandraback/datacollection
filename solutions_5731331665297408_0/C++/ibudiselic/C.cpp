#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const int MAXN = 55;
bool G[MAXN][MAXN];
bool ok(const vector<int> &order) {
    vector<int> S;
    S.push_back(order[0]);
    for (int i=1; i<(int)order.size(); ++i) {
        int next = order[i];
        while (S.size()>0 && !G[S.back()][next]) {
            S.pop_back();
        }
        if (S.size() == 0) {
            return false;
        }
        S.push_back(next);
    }
    return true;
}
string solve() {
    int n, m;
    cin >> n >> m;
    vector<string> codes(n);
    for (int i=0; i<n; ++i) {
        cin >> codes[i];
    }
    memset(G, 0, sizeof G);
    for (int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        G[a][b] = G[b][a] = 1;
    }
    vector<int> order(n);
    for (int i=0; i<n; ++i) {
        order[i] = i;
    }
    string sol = string(1, char('9'+1));
    do {
        /*
        for (int i=0; i<n; ++i) {
            cerr << codes[order[i]];
        }
        cerr << " ==> ";
        */
        if (ok(order)) {
            //cerr << " ok!\n";
            string cand;
            for (int i=0; i<n; ++i) {
                cand += codes[order[i]];
            }
            sol = min(sol, cand);
        /*} else {
            cerr << " fail!\n";*/
        }
    } while (next_permutation(begin(order), end(order)));
    return sol;
}

int main() {
    int T;
    cin >> T;
    cerr << T << " cases total\n";
    for (int t=1; t<=T; ++t) {
        string sol = solve();
        cout << "Case #" << t << ": " << sol << '\n';
        cerr << "Case #" << t << ": " << sol << '\n';
    }
	return 0;
}
