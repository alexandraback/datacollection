#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int n, m, T;

struct Node {
    int key;
    ll count;
};

Node box[102], toy[102];
ll cans, ans;

void dfs(int bc, ll bleft, int tc, ll tleft) {
    if (bc > n || tc > m) {
        if (cans > ans)
            ans = cans;
        return ;
    }
    
    if (box[bc].key == toy[tc].key) {
        //equal
        cans += min(bleft, tleft);
        
        if (bleft > tleft) 
            dfs(bc, bleft - tleft, tc + 1, toy[tc+1].count);
        else if (bleft < tleft)
             dfs(bc + 1, box[bc+1].count, tc, tleft - bleft);
        else
            dfs(bc + 1, box[bc+1].count, tc + 1, toy[tc+1].count);
            
        cans -= min(bleft, tleft);     
        
    }else {
        // not equal
        
        // discard current toy
        dfs(bc, bleft, tc + 1, toy[tc+1].count);
        
        // discard current box
        dfs(bc + 1, box[bc+1].count, tc, tleft);
    }
}




int main() {
    freopen("C-small-attempt2.in", "r", stdin);
    freopen("C-small-attempt2.out", "w", stdout);
    scanf("%d", &T);
    for (int k = 1; k <= T; k++) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%I64d %d", &box[i].count, &box[i].key);
//            printf("Cur %d %I64d\n", i, box[i].count);
        }
        for (int i = 1; i <= m; i++) 
            scanf("%I64d %d", &toy[i].count, &toy[i].key);
        cans = 0; ans = 0;
        dfs(1, box[1].count, 1, toy[1].count);
        printf("Case #%d: %I64d\n", k, ans);
    }

//    system("pause");
    return 0;
}
