#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

#define MP make_pair
#define PB push_back
#define FF first
#define SS second

#define FORN(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define FOREACH(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define MOD 1000000007
#define INF 2000000000

const int MAXN = 1010;
int bff[MAXN], visited[MAXN];

int T, n, maxn, maxd;

vector< vector<int> > rev;

vector<int> chains; vector<int> cycles;

void dfs(int u, int d) {
    visited[u] = 1;

    if (d > maxd) {
        maxn = u;
        maxd = d;
    }

    FORN(i, rev[u].size()) {
        int v = rev[u][i];
        if (!visited[v]) dfs(v, d+1);
    }
}

void printv(vector<int>& v) { FORN(i, v.size()) cout << v[i] << " "; cout << endl; }

int main() {
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        printf("Case #%d: ", tc); 
        
        scanf("%d", &n); 
        
        rev = vector< vector<int> >(n+1);
        chains = vector<int>();
        cycles = vector<int>();
        
        FOR1(i, n) {
            scanf("%d", &bff[i]);
            rev[bff[i]].PB(i);
        }

        memset(visited, 0, sizeof visited);

        FOR1(i, n) {
            if (visited[i] == 0 && bff[bff[i]] == i) {
                visited[i] = 1; visited[bff[i]] = 1;

                maxn = i; maxd = 0;
                dfs(i, 0);

                vector<int> chain1;
                while (maxn != i) { chain1.PB(maxn); maxn = bff[maxn]; } chain1.PB(i);

                maxn = bff[i]; maxd = 0;
                dfs(bff[i], 0);

                vector<int> chain2;
                while (maxn != bff[i]) { chain2.PB(maxn); maxn = bff[maxn]; } chain2.PB(bff[i]);

                FORN(i, chain1.size()) chains.PB(chain1[i]);
                FORD(i, chain2.size()) chains.PB(chain2[i]);
            }
        }

        FOR1(i, n) {
            if (visited[i] == 0) {
                vector<int> path; int curr = i;

                while (!visited[curr]) {
                    visited[curr] = 1;
                    path.PB(curr);
                    curr = bff[curr];
                }

                int start = curr; vector<int> cycle; cycle.PB(curr); curr = bff[curr];

                while (curr != start) {
                    cycle.PB(curr);
                    curr = bff[curr];
                }

                if (cycle.size() > cycles.size()) cycles = cycle;
                FORN(j, path.size()) dfs(path[j], 0);
            }
        }

        //printv(cycles);
        //printv(chains);

        cout << max(cycles.size(), chains.size()) << endl;
    }
    
    return 0;
}
