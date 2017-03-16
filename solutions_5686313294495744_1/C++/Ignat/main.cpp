#ifdef DEBUG_OUTPUT
#include "debug_output.h"
#else
#define PRINT(x)
#define PRINT_CONT(x)
#define PRINT_MSG(x)
#endif

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <memory.h>
#include <set>
#include <unordered_set>
#include <map>
#include <cstdio>
#include <cassert>
using namespace std;


// Enlarge MSVS stack size
#pragma comment(linker, "/STACK:16777216")

#define pb push_back
#define all(c) c.begin(), c.end()
#define mp(x, y) make_pair(x, y)
#define sz(x) static_cast<int>(x.size())
typedef long long int64;

template<class T> T sqr(const T& t) {return t * t;}
template<class T> T abs(const T& t) {return ((t > 0) ? (t) : (-t));}

void initialize()
{
    freopen("large.in", "r", stdin);
    freopen("large.out", "w", stdout);
}

bool dfs(int v, const vector<vector<int>>& edges, vector<bool>& visited, vector<int>& forward, vector<int>& backward) {
    visited[v] = true;
    for (int i = 0; i < edges[v].size(); ++i) {
        int u = edges[v][i];
        if (backward[u] != -1 && visited[backward[u]]) {
            continue;
        }
        if (backward[u] == -1 || dfs(backward[u], edges, visited, forward, backward)) {
            backward[u] = v;
            forward[v] = u;
            return true;
        }
    }
    return false;
}

int main()
{
    initialize();

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        cerr << "TEST: " << tt << endl;
        int t;
        cin >> t;
        vector<pair<string, string>> topics;
        for (int i = 0; i < t; ++i) {
            string a, b;
            cin >> a >> b;
            topics.pb(mp(a, b));
        }

        std::vector<string> first;
        std::vector<string> second;
        for (const auto& topic : topics) {
            first.pb(topic.first);
            second.pb(topic.second);
        }

        sort(all(first));
        sort(all(second));
        first.erase(unique(all(first)), first.end());
        second.erase(unique(all(second)), second.end());

        int n = first.size();
        int m = second.size();
        vector<vector<int>> edges(n);
        for (int i = 0; i < topics.size(); ++i) {
            int firstIndex = lower_bound(all(first), topics[i].first) - first.begin();
            int secondIndex = lower_bound(all(second), topics[i].second) - second.begin();
            edges[firstIndex].pb(secondIndex);
        }


        int size = 0;
        vector<int> backward(m, -1);
        vector<int> forward(n, -1);
        for (int i = 0; i < n; ++i) {
            vector<bool> visited(n, false);
            if (forward[i] == -1) {
                if (dfs(i, edges, visited, forward, backward)) {
                    size += 1;
                }
            }
        }

        int edgesCoverSize = size + (n - size) + (m - size);
        int res = topics.size() - edgesCoverSize;

        cout << "Case #" << tt << ": " << res << endl;
    }
    
    return 0;
}
