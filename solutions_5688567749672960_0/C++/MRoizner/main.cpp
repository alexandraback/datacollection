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
// #include <unordered_set>
#include <iomanip>

using namespace std;

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

#define forit(X,Y) for(typeof((Y).begin()) X = (Y).begin(); X != (Y).end(); ++X)

#define mplus(x, y) ((x) == -1 || (y) == -1) ? -1 : ((x) + (y))
#define mmax(x, y) ((x) == -1 || (y) == -1) ? -1 : max((x), (y))
#define mmin(x, y) ((x) == -1) ? (y) : ((y) == -1) ? (x) : min((x), (y))
#define checkbit(n, k) (((1L << (k)) & (n)) != 0)

#define debug(x) cerr << '>' << #x << ':' << x << endl;

typedef long long int64;

typedef vector <int> vi;
typedef vector < vi > vvi;


int64 reverse(int64 x) {
    int64 r = 0;
    while (x != 0) {
        r *= 10;
        int64 rem = x % 10;
        r += rem;
        x /= 10;
    }
    return r;
}

int64 bfs(int64 N) {
    queue<int64> q;
    map<int64, int64> res;

    q.push(1);
    res[1] = 1;
    
    while (true) {
        int64 x = q.front();
        q.pop();
        // debug(x);
        int64 r = res[x];
        if (x == N) return r;

        if (res.find(x + 1) == res.end()) {
            res[x + 1] = r + 1;
            q.push(x + 1);
        }
        int64 rx = reverse(x);
        if (res.find(rx) == res.end()) {
            res[rx] = r + 1;
            q.push(rx);
        }
    }
}

int64 bfs2(int64 N) {
    queue<int64> q;
    map<int64, int64> res;

    q.push(1);
    res[1] = 1;
    
    while (true) {
        int64 x = q.front();
        q.pop();
        // debug(x);
        int64 r = res[x];
        if (x == N) return r;

        if (res.find(x + 1) == res.end()) {
            res[x + 1] = r + 1;
            q.push(x + 1);
        }
        int64 rx = reverse(x);
        if (rx > x && res.find(rx) == res.end()) {
            res[rx] = r + 1;
            q.push(rx);
        }
    }
}


int main() {
    // for (int N = 1; N <= 100000; ++N) {
    //     if (bfs(N) != bfs2(N)) {
    //         cout << "AAA: " << N << endl;
    //     }
    // }
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        // debug(tt);
        int64 N;
        cin >> N;
        int64 res = bfs(N);
        cout << "Case #" << tt << ": " << res << endl;
    }
}
