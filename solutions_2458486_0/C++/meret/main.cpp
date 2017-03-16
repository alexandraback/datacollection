#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FORE(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SZ(x) (int)(x).size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

int initial[205];

vector<int> chests[205];
int key[205];
bool used[205];

int n;

bool visited[205];

void dfs(int x) {
    visited[x] = true;
    FORE (it, chests[x]) {
        for (int i = 1; i <= n; ++i) {
            if (key[i] == *it && !used[i] && !visited[i]) {
                dfs(i);
            }
        }
    }
}

bool check() {
    static int got[205];
    memcpy(got, initial, sizeof(got));
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            FORE (it, chests[i]) {
                ++got[*it];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            if (got[key[i]]-- == 0) {
                return false;
            }
        }
    }
    ZERO(visited);
    for (int i = 1; i <= n; ++i) {
        if (initial[key[i]] > 0 && !used[i] && !visited[i]) {
            dfs(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!used[i] && !visited[i]) {
            return false;
        }
    }
    return true;
}

void alg() {
    for (int i = 0; i < 205; ++i) {
        chests[i].clear();
    }
    ZERO(used);
    ZERO(initial);
    ZERO(key);
    int k;
    cin >> k >> n;
    for (int i = 1; i <= k; ++i) {
        int a;
        cin >> a;
        ++initial[a];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> key[i] >> k;
        for (int j = 1; j <= k; ++j) {
            int a;
            cin >> a;
            chests[i].PB(a);
        }
    }
    if (!check()) {
        cout << " IMPOSSIBLE" << endl;
        return;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!used[j] && initial[key[j]] > 0) {
                --initial[key[j]];
                FORE (it, chests[j]) {
                    ++initial[*it];
                }
                used[j] = true;
                if (check()) {
                    cout << " " << j;
                    break;
                }
                used[j] = false;
                FORE (it, chests[j]) {
                    --initial[*it];
                }
                ++initial[key[j]];
            }
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int d;
    cin >> d;
    for (int i = 1; i <= d; ++i) {
        cout << "Case #" << i << ":";
        alg();
    }
}
