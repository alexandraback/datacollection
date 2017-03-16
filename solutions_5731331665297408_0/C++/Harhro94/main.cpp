// Author: Harhro94 [Harutyunyan Hrayr]
#pragma comment(linker, "/STACK:66777216")
#define _CRT_SECURE_NO_WARNINGS
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <bitset>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
using namespace std;

typedef long long LL;
typedef long double LD;
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()

const int N = 9;
int n, m;
vector<int> G[N];

int main()
{
#ifdef harhro94
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define task "london"
    freopen(task".in", "r", stdin);
    freopen(task".out", "w", stdout);
#endif

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        printf("Case #%d: ", t);
        scanf("%d%d", &n, &m);
        vector<string> zip(n);
        for (int i = 0; i < n; ++i) G[i].clear();
        for (int i = 0; i < n; ++i) cin >> zip[i];
        for (int j = 0; j < m; ++j)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            --u, --v;
            G[u].pb(v);
            G[v].pb(u);
        }
        vector<int> p(n);
        for (int i = 0; i < n; ++i) p[i] = i;
        string best = "z";
        bool used[9];
        do {
            bool ok = true;

            memset(used, false, sizeof used);
            used[p[0]] = true;
            for (int to : G[p[0]]) used[to] = true;
            for (int i = 1; i < n; ++i)
            {
                int u = p[i];
                if (!used[u])
                {
                    ok = false;
                    break;
                }
                for (int to : G[u]) used[to] = true;
            }

            if (ok)
            {
                string cur = "";
                for (int i = 0; i < n; ++i) cur += zip[p[i]];
                if (cur < best) best = cur;
            }

        } while (next_permutation(all(p)));

        printf("%s\n", best.c_str());
    }

#ifdef harhro94
    cerr << fixed << setprecision(3) << "\nExecution time = " << clock() / 1000.0 << "s\n";
#endif
    return 0;
}