#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>

using namespace std;

#define REP(i, n) for(int i = 0; i < (n); ++i)

const int N = 1001;

int T, n;
vector<int> g[N];
bool f[N][N];
int used[N];

bool fd;

void dfs(int k)
{
    if(fd) return;
    used[k]++;
    if(used[k] == 2) {
        fd = true;
        return ;
    }
    REP(l, g[k].size()){
        int j = g[k][l];
        dfs(j);
    }
}

int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    scanf("%d", &T);
    REP(t, T){
        memset(f, 0, sizeof(f));
        scanf("%d", &n);
        REP(i, n){
            g[i].clear();
            int m, tmp;
            scanf("%d", &m);
            while(m--){
                scanf("%d", &tmp);
                tmp--;
                g[i].push_back(tmp);
                assert(!f[i][tmp]);
                f[i][tmp] = 1;
                assert(tmp != i);
            }
        }
        string res = "No";
        REP(i, n) {
            memset(used, 0, sizeof(used));
            fd = false;
            dfs(i);
            if(fd) {
                res = "Yes";
                break;
            }
        }
        printf("Case #%d: %s\n", t + 1, res.c_str());
    }
    return 0;
}
