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
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
int C,D,V;
int ans;
int f[31], mask[31], val[31];
int res[31];
void dfs(int cur, int cnt, int sum){
    int i,j;
    if (sum == V){
        ans = min(ans, cnt);
        
        //cout << cnt << endl; for (i = 0; i < cnt; i++) printf("%d---\n", res[i]);
            
        return ;
    }
    if (cnt >= ans) return ;
    if (cur > V) return ;
    if (mask[cur] == 1){
        dfs(cur + 1, cnt, sum);
        return ;
    }
    
    int use[31], ut = 0;
    for (j = V; j>=0; j--)
        if (j-cur >=0 && f[j-cur] == 1 && f[j] == 0){
            f[j] = 1;
            use[ut++] = j;
        }
    res[cnt] = cur;
    dfs(cur + 1, cnt + 1, sum + ut);
    for (i = 0; i < ut; i++)
        f[use[i]] = 0;
    dfs(cur + 1, cnt, sum);
}
    
        
        
    
int main(){
    int N;
    cin >> N;
    for (int t = 1; t <= N; t++){
        cin >> C >> D >> V;
        memset(mask, 0, sizeof(mask));
        for (int i = 0; i < D; i++)
            scanf("%d", &val[i]), mask[val[i]]  = 1;
        memset(f,0,sizeof(f));
        f[0] = 1;
        for (int j = 0; j < D; j++)
        for (int i  = V; i > 0; i--)
            if (i - val[j] >= 0 && f[i - val[j]] == 1)
                f[i] = 1;
        int sum = 0;
        for (int i = 1; i <= V; i++)
        if (f[i]==1) sum ++;
        ans = V;
        dfs(1, 0, sum);
        printf("Case #%d: %d\n", t, ans);
    }
}
