#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <numeric>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 220;
int T, K, N, buff_a, buff_b, need[MAXN];
vector<int> graph[MAXN];
vector<int>::iterator it;

struct state {
    int visited;
    vector<int> keys, order;
    vector<int> vis;

    state() {
        visited = 0;
        vis.assign(MAXN, 0);
        keys.clear();
        order.clear();
    }
};

int main(void) {
    freopen("i.in", "r", stdin);
    freopen("o.ot", "w", stdout);
    int i, j, test = 1;
    cin >> T;

    for (i = 1; i <= 25; i++) {
        cout << "Case #" << test++ << ": IMPOSSIBLE\n";
    }

    for ( ; T--; ) {
        cin >> K >> N;

        for (i = 0; i < MAXN; i++) {
            graph[i].clear();
            need[i] = -1;
        }

        vector<int> base(K);

        for (i = 0; i < K; i++) {
            cin >> base[i];
        }

        for (i = 0; i < N; i++) {
            cin >> buff_a >> buff_b;
            need[i] = buff_a;
            for (j = 0; j < buff_b; j++) {
                int tmp; cin >> tmp;
                graph[i].push_back(tmp);
            }
        }

        state b;
        b.keys = base;

        queue<state> q; q.push(b);

        set<vector<int> > ans;

        while(!q.empty()) {
            state now = q.front(); q.pop();

            if(now.visited == N) {
                ans.insert(now.order);
                continue;
            }

            for (i = 0; i < N; i++) if(!now.vis[i]) {
                it = find(now.keys.begin(), now.keys.end(), need[i]);
                if(it != now.keys.end()) {
                    state other;
                    other.keys = now.keys;
                    other.order = now.order;
                    other.vis = now.vis;
                    other.visited = now.visited;
                    other.vis[i] = 1;
                    other.visited += 1;
                    other.keys.insert(other.keys.begin(), graph[i].begin(), graph[i].end());
                    other.order.push_back(i + 1);
                    it = find(other.keys.begin(), other.keys.end(), need[i]);
                    other.keys.erase(it);
                    q.push(other);
                }
            }
        }
        cout << "Case #" << test++ << ": ";
        if(ans.empty()) {
            cout << "IMPOSSIBLE";
        } else {
            vector<int> s = *ans.begin();

            for (i = 0; i < s.size(); i++) {
                cout << s[i] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
