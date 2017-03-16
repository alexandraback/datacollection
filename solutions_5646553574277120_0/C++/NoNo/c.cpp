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
int a[110], n, m, k, i, j;
int vis[110];
int main(){
    int T, cas = 0;
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    cin>>T;
    while(T--){
        scanf("%d%d%d", &n, &m, &k);
        for(i = 0; i < m; i++)
            scanf("%d", &a[i]);
        mem(vis, 0);
        int sum = 0;
        for(i = 0; i < (1 << m); i++){
            int s = 0;
            for(j = 0; j < m; j++)
            if ((1 << j) & i) s += a[j];
            if (s > k) continue;
            if (s != 0 && vis[s] == 0) {sum++;vis[s] = 1;}
        }
        int ans =0;
        while(sum < k){
            int now;
            for(i = 1; i <= k; i++)
                if (!vis[i]) {
                    now = i;
                    ans++;
                    sum++;
                    break;
                }
            vis[now] = 1;
            a[m++] = now;
            for(i = 0; i < (1 << m); i++){
                int s = 0;
                for(j = 0; j < m; j++)
                if ((1 << j) & i) s += a[j];
                if (s > k) continue;
                if (s != 0 && vis[s] == 0) {sum++;vis[s] = 1;}
            }
        }
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}

