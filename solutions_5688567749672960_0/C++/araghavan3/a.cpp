#include <iostream>
#include <queue>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <stack>
#include <iomanip>

#define FOR(i,x,y) for(int i =(int)(x); i<(int)(y); i++)
#define REP(i, N) FOR(i, 0, N)
#define SZ(x) (int)x.size()

using namespace std;

typedef vector<int> vin;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvin;

typedef long long LL;
typedef unsigned long long ULL;

int N;
bool visited[1000001];
int cache[1000001];
int reverse(int n) {
    int p = n;
    int r = 0;
    while (p > 0) {
        r = r * 10 + (p % 10);
        p /= 10;
    }
    return r;
}

struct node {
    int moves;
    int k;
};

int solve(int n) {
    queue<node> q;
    set<int> visited;
    q.push({ 1, 1 });

    while (!q.empty()) {
        node n = q.front(); q.pop();
        if (n.k == N) return n.moves;
        int r = reverse(n.k);
        if (visited.find(n.k) != visited.end()) continue;
        visited.insert(n.k);
        if (!(r <= n.k || r > N))
            q.push({ n.moves + 1, r });
        q.push({ n.moves + 1, n.k + 1 });
    }
    return -1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(visited, false, sizeof(visited));
    memset(cache, -1, sizeof(cache));
    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> N;
        cout << "Case #" << i << ": " << solve(1) << "\n";
    }
    //cout << reverse(11) << endl;
    return 0;
}

