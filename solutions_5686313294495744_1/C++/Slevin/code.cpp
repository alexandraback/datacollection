#include <cassert>
#include <complex>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <sstream>
#include <utility>
#include <cmath>

#include <algorithm>
#include <bitset>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include <memory.h>
using namespace std;

#define Pi 3.141592653589793
#define all(c) (c).begin(), (c).end()
typedef long long ll;

template <typename T>
int numbits(T n) {
    return n ? 1 + numbits(n & (n - 1)) : 0;
}

class timer {
public:
    timer() : t_(clock()) {}
    void restart() { t_ = clock(); }
    float elapsed() { return float(clock() - t_) / CLOCKS_PER_SEC; }
private:
    clock_t t_;
};

void run();

int main() {
#ifdef LOCAL_HOST
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    timer t;
#endif
    run();
#ifdef LOCAL_HOST
    // printf("\nElapsed time: %.9f\n", t.elapsed());
#endif
    return 0;
}

int visited[2051];
bool dfs(vector< vector< pair<int, int> > >& graph, map< pair<int, int>, int>& cap, int v) {
    if (v == 2050) {
        return true;
    }
    if (visited[v]) {
        return false;
    }
    visited[v] = 1;
    for (int i = 0; i < graph[v].size(); ++i) {
        pair<int, int>& edge = graph[v][i];
        int next = edge.first;
        if (cap[make_pair(v, next)] > 0) {
            cap[make_pair(v, next)]--;
            cap[make_pair(next, v)]++;
            if (dfs(graph, cap, edge.first)) {
                return true;
            }
            cap[make_pair(next, v)]--;
            cap[make_pair(v, next)]++;
        }
    }
    return false;
}

void run() {
    int T; cin >> T;

    for (int cs = 0; cs < T; ++cs) {
        vector< vector< pair<int, int> > > edges(2051);
        map< pair<int, int>, int> cap;
        map<string, int> m1;
        map<string, int> m2;
        int n; cin >> n;
        for (int i = 0; i < n; ++i) {
            string str1, str2;
            cin >> str1 >> str2;
            if (!m1.count(str1)) {
                m1[str1] = m1.size();
            }
            if (!m2.count(str2)) {
                m2[str2] = m2.size();
            }
            int id1 = m1[str1];
            int id2 = m2[str2] + 1024;
            edges[id1].push_back(make_pair(id2, 0));
            edges[id2].push_back(make_pair(id1, 0));
            cap[make_pair(id1, id2)] = 1;
            cap[make_pair(id2, id1)] = 0;
        }
        for (int i = 0; i < m1.size(); ++i) {
            edges[2049].push_back(make_pair(i, 1));
            cap[make_pair(2049, i)] = 1;
        }
        for (int i = 0; i < m2.size(); ++i) {
            edges[i + 1024].push_back(make_pair(2050, 1));
            cap[make_pair(i + 1024, 2050)] = 1;
        }
        int flow = 0;
        memset(visited, 0, sizeof(visited));
        while (dfs(edges, cap, 2049)) {
            memset(visited, 0, sizeof(visited));
            flow++;
        }
        int res = n - flow - (m1.size() + m2.size() - 2 * flow);
        cout << "Case #" << cs + 1 << ": " << res << endl;
    }
}
