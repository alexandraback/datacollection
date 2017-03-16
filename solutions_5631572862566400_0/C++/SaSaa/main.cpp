#include <bits/stdc++.h>
using namespace std;
//#define int long long
typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;
#define X first
#define Y second
#define all(o) o.begin(), o.end()
#define endl '\n'
#define IOS ios::sync_with_stdio(0), cin.tie(0)
#define bp __builtin_popcount
//////////////////////
const int maxn = 1000 + 10;
bool mark[maxn], good[maxn], rg[maxn];
int ans = 0;
int dp[maxn], a[maxn];
vector<int>adj[maxn], in[maxn], to[maxn];
vector<int>ts;
void dfs(int v){
    if(mark[v]) return;
    mark[v] = 1;
    for(int u : adj[v])
        dfs(u);
    ts.push_back(v);
}
void reset(){
    memset(dp, 0, sizeof dp);
    ans = 0;
    memset(good, 0, sizeof dp);
    memset(rg, 0, sizeof dp);
    memset(mark, 0, sizeof mark);
    ts.clear();
    for(int i=0; i<maxn; i++){
        to[i].clear();
        in[i].clear();
        adj[i].clear();
    }
}
void doo(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        a[i]--;
    }
    for(int i=0; i<n; i++){
        vector<int>v;
        memset(mark, 0, sizeof mark);
        int cur = i;
        mark[cur] = 1;
        v.push_back(cur);
        cur = a[cur];
        while(!mark[cur]){
            v.push_back(cur);
            mark[cur] = 1;
            cur = a[cur];
        }
        if(v.size() == 2){
            rg[i] = 1;
            rg[a[i]] = 1;
            continue;
        }
        if(cur == i){
            ans = max(ans, int(v.size()) );
            continue;
        }
        if(cur != v[v.size() - 2]) continue;
        good[i] = 1;
        if(v.size() != 3){
            adj[i].push_back(a[i]);
            to[a[i]].push_back(i);
            //cout << "JE" << i << " " << a[i] << endl;
        }
        else{
            in[a[i]].push_back(i);
        }
    }
    memset(mark, 0, sizeof mark);
    for(int i=0; i<n; i++){
        if(good[i]){
            dfs(i);
        }
    }
    reverse(all(ts));
    for(int i : ts){
        if(!good[i]) continue;
        dp[i] = 1;
        for(int j : to[i])
            dp[i] = max(dp[i], dp[j] + 1);
    }
    int jav = 0;
    for(int i=0; i<n; i++){
        if(rg[i]) jav++;
        if(in[i].size() == 0) continue;
        int mx = 0;
        for(int j : in[i])
            mx = max(mx, dp[j]);
        jav += mx;
    }
    cout << max(jav, ans) << endl;
}
main(){
    IOS;
    freopen("CS.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T = 1;
    cin >> T;
    for(int i=0; i<T; i++){
        cout << "Case #" << i+1 << ": ";
        reset();
        doo();
    }
}
