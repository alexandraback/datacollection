#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <bitset>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <map>
#include <queue>
#include <stack>
#include <assert.h>
#include <iomanip>

using namespace std;

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

#define mplus(x, y) ((x) == -1 || (y) == -1) ? -1 : ((x) + (y))
#define mmax(x, y) ((x) == -1 || (y) == -1) ? -1 : max((x), (y))
#define mmin(x, y) ((x) == -1) ? (y) : ((y) == -1) ? (x) : min((x), (y))

#define checkbit(n, k) (((1L << (k)) & (n)) != 0)

#define forit(X,Y) for(typeof((Y).begin()) X = (Y).begin(); X != (Y).end(); ++X)

#define debug(x) cerr << "> " << #x << ": " << (x) << endl;

typedef long long int64;

typedef vector <int> vi;
typedef vector < vi > vvi;

bool try_kuhn(vector<vector<int>>& edges, vector<bool>& used, int v, vector<int>& back) {
    if (used[v]) return false;
    used[v] = true;
    for (int i = 0; i < edges[v].size(); ++i) {
        int to = edges[v][i];
        if (back[to] == -1 || try_kuhn(edges, used, back[to], back)) {
            back[to] = v;
            return true;
        }
    }
    return false;
}

int foo(vector<string>& left, vector<string>& right) {
    vector<string> leftWords, rightWords;

    vector<vector<int>> edges;

    int N = left.size();
    for (int i = 0; i < N; ++i) {
        int u1 = 0;
        while (u1 < leftWords.size() && leftWords[u1] != left[i])
            ++u1;
        if (u1 == leftWords.size()) {
            leftWords.push_back(left[i]);
            edges.push_back(vector<int>());
        }
        int u2 = 0;
        while (u2 < rightWords.size() && rightWords[u2] != right[i])
            ++u2;
        if (u2 == rightWords.size()) {
            rightWords.push_back(right[i]);
        }
        edges[u1].push_back(u2);
    }

    int n1 = edges.size();
    int n2 = rightWords.size();
    vector<bool> used(n1);
    vector<int> back(n2, -1);
    for (int v = 0;  v < n1; ++v) {
        used.assign(n1, false);
        try_kuhn(edges, used, v, back);
    }

    int res = n1 + n2;
    for (int i = 0; i < n2; ++i) {
        if (back[i] != -1) {
            --res;
        }
    }
    return N - res;
}

int main() {
     // freopen("input.txt", "rt", stdin);
    // freopen("output.txt", "wt", stdout);

	int testCount;
    cin >> testCount;

    for (int testNumber = 1; testNumber <= testCount; ++testNumber) {
        int n;
        cin >> n;
        vector<string> left(n), right(n);
        for (int i = 0; i < n; ++i)
            cin >> left[i] >> right[i];
        auto res = foo(left, right);
        cout << "Case #" << testNumber << ": " << res << endl;
    }

    return 0;
}
