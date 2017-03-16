#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define SZ(v) ((int)(v).size())
#define FOR(i, a, b) for (typeof(a) i = (a); i < (b); ++i)
#define FORD(i, a, b) for(typeof(a) i = (a);i >= (b); --i)
#define FOREACH(iter, v) for (typeof((v).begin()) iter = (v).begin(); iter != (v).end(); ++iter)
#define REP(i, n) FOR(i, 0, n)

using namespace std;

#define SMALL 1

int T, n, m[1005], to;
map<int, vector<int> > edge;
bool used[1005][1005];

bool dfs(int from, int to)
{
    if (from == to) return true;

    REP(i,m[from]) if (!used[from][edge[from][i]]) {
        used[from][edge[from][i]] = true;
        //cout << "from = " << from << " next = " << edge[from][i] << " to = " << to << endl;
        bool found = dfs(edge[from][i], to);
        if (found) return true;
    }
    return false;
}

int main()
{

#if SMALL
    freopen("A-small-attempt2.in", "r", stdin);
    freopen("A-small.out", "w", stdout);
#else
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
#endif


    scanf("%d", &T);
    for (int tc = 1; tc <= T; ++tc) {
        scanf("%d", &n);
        edge.clear();

        REP(i,n) {
            scanf("%d", &m[i]);
            REP(j,m[i]) {
                scanf("%d", &to);
                edge[i].push_back(to-1);
            }
        }
        bool ok = false;
        REP(i,n) {
            REP(j,n) if (i != j)
            {
                memset(used, false, sizeof(used));
                bool b1 = dfs(i,j);
                //cout << i << " " << j << " b1 = " << b1 << endl;
                bool b2 = dfs(i,j);
                //cout << i << " " << j << " b2 = " << b2 << endl;
                if (b1 && b2) {ok = true; break;}
            }
            if (ok) break;
        }
        printf("Case #%d: %s\n", tc, ok ? "Yes" : "No");
    }
    return 0;
}
