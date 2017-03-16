#include <bits/stdc++.h>
#define maxx 100005
#define inf 2000000000
#define mod 1000000007
#define pii pair<int,int>
#define piii pair<pii,pii>
#define pli pair<long long,int>
#define f first
#define s second
#define in(x) scanf("%d",&x)
#define IN(x) scanf("%lld",&x)
#define inch(x) scanf("%s",x)
#define indo(x) scanf("%lf",&x)
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int t, n, ans, max_depth;
int path[1003], used[1003];
vector<int>g[1003];

void dfs(int node, int k){
    used[node] = k;
    int to = path[node];
    if(!used[to])
        dfs(to, k);
    else{
        if(used[to] == k){
            int cycle = 1;
            for(int j = path[to]; j != to; j = path[j])
                cycle++;
            ans = max(ans, cycle);
            return;
        }
        else
            return;
    }
}
void depth(int node, int par, int dis){
    max_depth = max(max_depth, dis);
    for(int i = 0; i < g[node].size(); i++){
        int to = g[node][i];
        if(to != par)
            depth(to, node, dis + 1);
    }
}
int main()
{
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for(int cases = 1; cases <= t; cases++){
        cin >> n;
        for(int i = 1; i <= n; i++)
            g[i].clear();
        for(int i = 1; i <= n; i++){
            cin >> path[i];
            g[path[i]].pb(i);
        }
        memset(used, 0, sizeof(used));
        ans = 0;
        for(int i = 1; i <= n; i++)
            if(!used[i])
                dfs(i, i);

        memset(used, 0, sizeof(used));
        int tricky = 0;
        for(int i = 1; i <= n; i++)
            if(!used[i] && path[path[i]] == i){
                max_depth = 0;
                depth(i, path[i], 1);
                tricky += max_depth;
                max_depth = 0;
                depth(path[i], i, 1);
                tricky += max_depth;
                used[i] = used[path[i]] = 1;
            }
        ans = max(ans, tricky);
        cout << "Case #" << cases << ": ";
        cout << ans << endl;
    }

    return 0;
}
