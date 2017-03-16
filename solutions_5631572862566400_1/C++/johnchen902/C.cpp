#include <stdio.h>
#include <algorithm>
#include <vector>

int n;
int f[1000];
std::vector<int> g[1000];

int dfs(int x, int exclude = -1) {
    int ans = 1;
    for(int c : g[x])
        if(c != exclude)
            ans = std::max(ans, dfs(c) + 1);
    return ans;
}

int solve() {
    for(int i = 0; i < 1000; i++) g[i].clear();
    for(int i = 0; i < n; i++) g[f[i]].push_back(i);

    int case1ans = 0;
    // case 1: single cycle
    for(int start = 0; start < n; start++) {
        int turtle = start, rabbit = start;
        do {
            turtle = f[turtle];
            rabbit = f[f[rabbit]];
        } while(turtle != rabbit);
        // cycle found
        int len = 0;
        do {
            len++;
            rabbit = f[rabbit];
        } while(turtle != rabbit);
        case1ans = std::max(case1ans, len);
    }
    // case 2: several "starting from a pair of bff"
    int case2ans = 0;
    for(int i = 0; i < n; i++)
        if(f[f[i]] == i)
            case2ans += dfs(i, f[i]);
    
    return std::max(case1ans, case2ans);
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        scanf("%d", &n);
        for(int j = 0; j < n; j++)
            scanf("%d", f + j), f[j]--;
        printf("Case #%d: %d\n", i, solve());
    }
}

