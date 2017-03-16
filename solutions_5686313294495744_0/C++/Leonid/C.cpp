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
#include <sstream>
#include <list>
using namespace std;

void openFiles() {
    // freopen("test.in", "rt", stdin);
    // freopen("test.out", "wt", stdout);
	freopen("C-small-attempt0.in", "rt", stdin);
	freopen("C-small-attempt0.out", "wt", stdout);
	// freopen("C-large.in", "rt", stdin);
	// freopen("C-large.out", "wt", stdout);
}

#define REP(i, n) for (int i = 0; i < (int)(n); i++)

inline bool bitzero(int n, int shift) {
    return ((n >> shift) & 1) == 0;
}

inline bool bitone(int n, int shift) {
    return ((n >> shift) & 1) == 1;
}

vector<string> tokenize(const string& line) {
    vector<string> tokens;
    stringstream ss(line);
    string s;
    while (ss >> s) tokens.push_back(s);
    return tokens;
}

void solve() {
	int n; scanf("%d ", &n);
    vector<string> w1(n), w2(n);
    REP(i, n) {
        string line;
        getline(cin, line);
        vector<string> tokens = tokenize(line);
        w1[i] = tokens[0];
        w2[i] = tokens[1];
    }
    
    int r = 0;
    REP(b, 1 << n) {
        set<string> d1, d2;
        REP(i, n) if (bitzero(b, i)) {
            d1.insert(w1[i]);
            d2.insert(w2[i]);
        }
        bool ok = true;
        int k = 0;
        REP(i, n) if (bitone(b, i)) {
            k++;
            if (!d1.count(w1[i]) || !d2.count(w2[i])) {
                ok = false;
                break;
            }
        }
        if (ok) r = max(r, k);
    }
    
    printf("%d\n", r);
}

int main() {
    openFiles();
    int n; scanf("%d ", &n);
    for (int i = 0; i < n; i++) {        
            printf("Case #%d: ", i + 1);
            cerr << i << endl;
            solve();
    }
    return 0;
}
