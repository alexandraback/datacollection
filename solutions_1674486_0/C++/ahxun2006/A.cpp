#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int N;
int M, deg[1005];
int adj[1005][11], nadj[1005];
int used[1005];

bool dfs(int at, int color) {
    used[at] = color;
    for (int i = 0; i < nadj[at]; ++i) {
        int v = adj[at][i];
        if (used[v] != color) {
            if (dfs(v, color)) return true;
        } else if (used[v] == color) {
            return true;
        }    
    }    
    return false;
}
    
int main() {
    freopen("A-small-attempt2.in", "r", stdin);
    freopen("A-small-attempt2.out", "w", stdout);
    int T, x;
    scanf("%d", &T);
    for (int caseId = 1; caseId <= T; ++caseId) {
        scanf("%d", &N);
        memset(used, 0, sizeof(used));
        memset(deg, 0, sizeof(deg));
        memset(nadj, 0, sizeof(nadj));
        for (int i = 1; i <= N; ++i) {
            scanf("%d", &M);
            for (int j = 0; j < M; ++j) {
                scanf("%d", &x);
                adj[x][nadj[x]++] = i;
                ++deg[i];
            }    
        }
        int color = 1;   
        bool ok = false; 
        for (int i = 1; i <= N; ++i) {
            if (deg[i] != 0) continue;
            if (dfs(i, color)) {
                ok = true;
                break;
            }    
            ++color;
        }    
        printf("Case #%d: %s\n", caseId, ok ? "Yes" : "No");  
    }    
    //while (1);
   // system("pause");
    return 0;
}    
