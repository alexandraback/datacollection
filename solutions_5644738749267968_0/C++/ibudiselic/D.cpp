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
#include <sstream>

using namespace std;

const int MAXN = 1000+2;
int A[MAXN];
int norm(string s) {
    int nmul = 5-(int)s.size();
    istringstream is(s);
    int x;
    is >> x;
    assert(x > 0);
    for (int i=0; i<nmul; ++i) {
        x *= 10;
    }
    return x;
}

/*
int dp[2][MAXN];
int dwar(int n, const set<int> &B_) {
    vector<int> B(begin(B_), end(B_));
    memset(dp, 0, sizeof dp);
    for (int i=0; i<n; ++i) {
        int cur = i&1;
        int next = 1-cur;
        for (int start=0; start<=i; ++start) {
            int end = start+n-1-i;
            assert(end>=0 && end<n);
            int wins = dp[cur][start];
            dp[cur][start] = 0;
            dp[next][start] = max(dp[next][start], wins + (A[i]>B[end]));
            if (A[i] > B[start]) {
                dp[next][start+1] = max(dp[next][start+1], wins+1);
            }
        }
    }
    int sol = 0;
    for (int i=0; i<=n; ++i) {
        sol = max(sol, dp[n&1][i]);
    }
    return sol;
}
*/
int dwar_greedy(int n, set<int> B) {
    int win = 0;
    for (int i=0; i<n; ++i) {
        if (A[i] < *B.begin()) {
            B.erase(*B.rbegin());
        } else {
            B.erase(B.begin());
            ++win;
        }
    }
    return win;
}
int war(int n, set<int> B) {
    int wins = 0;
    for (int i=0; i<n; ++i) {
        auto p = B.lower_bound(A[i]);
        if (p == end(B)) {
            ++wins;
            B.erase(B.begin());
        } else {
            B.erase(p);
        }
    }
    return wins;
}

char buff[16];
void solve() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        scanf("%*d.%s", buff);
        A[i] = norm(string(buff));
    }
    set<int> B;
    for (int i=0; i<n; ++i) {
        scanf("%*d.%s", buff);
        B.insert(norm(string(buff)));
    }
    assert((int)B.size() == n);

    sort(A, A+n);

    cout << dwar_greedy(n, B) << ' ' << war(n, B);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t=1; t<=T; ++t) {
        cout << "Case #" << t << ": ";
        solve();
        cout << '\n';
    }
	return 0;
}
