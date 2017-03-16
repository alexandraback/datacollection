#ifdef DEBUG_OUTPUT
#include "debug_output.h"
#else
#define DEBUG(x)
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
    freopen("2.in", "r", stdin);
    freopen("_.out", "w", stdout);
}

const int MAX = 1000 + 10;
vector<int> reb[MAX], breb[MAX];
int color[MAX];

bool dfs(int u, int c) {
    //cerr << u << " " << c << endl;
    color[u] = c;
    bool ok = false;
    for (int i = 0; i < reb[u].size(); ++i) {
        int v = reb[u][i];
        if (color[v] == c) {
            ok = true;
        }
        else if (dfs(v, c)) {
            ok = true;
        }
    }
    return ok;
}

int main()
{
    initialize();

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        for (int i = 0; i < MAX; ++i) {
            reb[i].clear(); 
            breb[i].clear(); 
        }
        memset(color, 0, sizeof(color));

        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int s;
            cin >> s;
            for (int j = 0; j < s; ++j) {
                int u;
                cin >> u;
                u -= 1;
                reb[i].pb(u);
                breb[u].pb(i);
            }
        }

        bool ok = false;
        int c = 1;
        for (int i = 0; i < n; ++i) {
            if (!breb[i].empty()) continue;
            if (color[i] != 0) continue;
            if (dfs(i, c++)) ok = true;
        }
        printf("Case #%d: %s\n", tt, ok ? "Yes" : "No");
    }
    
    return 0;
}
