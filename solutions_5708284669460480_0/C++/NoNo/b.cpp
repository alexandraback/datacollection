#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <stack>

#define lld long long
#define INF 2100000000
#define eps 1e-8
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int, int>
#define lb lower_bound
#define ub upper_bound

using namespace std;
char s[20], p[20], r[20];
int n, m, k, l, ms;
int sum,ans;
void dfs(int x){
    if (x == k){
        sum++;
        int i, j, u = 0, cc = 0;
        for(i = 0; i + l <= k; i++){
            int f = 1;
            for(j = 0; j < l; j++)
            if (r[i + j] != p[j]) f = 0;
            cc +=  f;
            ans += f;
        }
        ms = max(ms, cc);
        return;
    }
    for(int i = 0; i < n; i++){
        r[x] = s[i];
        dfs(x + 1);
    }
}

int main(){
    int T, cas = 0;
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    cin>>T;
    while(T--){
        scanf("%d%d%d", &n, &m, &k);
        scanf("%s", s);
        scanf("%s", p);
        printf("Case #%d: ", ++cas);
        l = strlen(p);
//        cout<<l<<"  "<<k<<endl;
        if (l > k){
            printf("0.0\n");
            continue;
        }
        sum = ans = 0;
        ms = 0;
        dfs(0);
//        cout<<ans<<endl;
        printf("%.7f\n", 1.0 * ms - 1.0 * ans / (1.0 * sum));
    }
    return 0;
}
