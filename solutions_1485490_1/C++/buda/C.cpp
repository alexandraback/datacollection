#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <map>

using namespace std;

struct State {
    int i, j;
    long long remi, remj;
    State(int i_, int j_, long long remi_, long long remj_): i(i_), j(j_), remi(remi_), remj(remj_) {}
};
bool operator<(const State &a, const State &b) {
    if (a.i != b.i) {
        return a.i < b.i;
    } else if (a.j != b.j) {
        return a.j < b.j;
    } else if (a.remi != b.remi) {
        return a.remi < b.remi;
    } else {
        return a.remj < b.remj;
    }
}
long long A[100], B[100];
int aT[100], bT[100];

void get_it(int &n, long long *val, int *type) {
    int next = 0;
    int last_t = -1;
    long long v;
    int t;
    for (int i=0; i<n; ++i) {
        cin >> v >> t;
        if (t == last_t) {
            val[next-1] += v;
        } else {
            last_t = t;
            type[next] = t;
            val[next] = v;
            ++next;
        }
    }
    n = next;
}

int m, n;
map<State, long long> dp;
long long go(int i, int j, long long remi, long long remj) {
    if (remi == 0) {
        if (i+1 == m) {
            return 0;
        } else {
            return go(i+1, j, A[i+1], remj);
        }
    }
    if (remj == 0) {
        if (j+1 == n) {
            return 0;
        } else {
            return go(i, j+1, remi, B[j+1]);
        }
    }
    const State state(i, j, remi, remj);
    if (dp.count(state)) {
        return dp[state];
    }
    long long &ret = dp[state];
    if (aT[i] == bT[j]) {
        long long add = min(remi, remj);
        ret = add + go(i, j, remi-add, remj-add);
    } else {
        ret = max(go(i, j, remi, 0), go(i, j, 0, remj));
    }
    
    return ret;
}
int main() {
    cin.sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) {
        cin >> m >> n;
        get_it(m, A, aT);
        get_it(n, B, bT);
        dp.clear();
        cout << "Case #" << t << ": " << go(0, 0, A[0], B[0]) << '\n';
    }
	return 0;
}
