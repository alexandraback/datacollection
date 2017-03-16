#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FO(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORV(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define debug cout << "YES" << endl

using namespace std;

typedef pair<int,int>II;
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s);}
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}

const long double PI = 2*acos(0.0);
const long double eps = 1e-15;
const int infi = 1e9;
const LL Linfi = 1e18;
const LL MOD = 1000000007;
const int c1 = 31;
const int c2 = 37;
#define maxn 1005

int n, m, t, u, v, ans, ans2;
int depth[maxn], ok[maxn], max_depth;
int num[maxn], low[maxn], xet[maxn], x[maxn], tin = 0, num_scc = 0;
vector<int> adj[maxn], adj2[maxn];
stack<int> S;

void getDepth(int u, int tmp){
    //cout << u << " " << tmp << endl;
    max_depth = max(max_depth, tmp);
    ok[u] = 1;
    FO(i,0,adj2[u].size()){
        int v = adj2[u][i];
        if(ok[v] == 0) {
            getDepth(v, tmp+1);
        }
    }
}

void find2path(int xx, int yy){
    memset(ok, 0, sizeof(ok));
    ok[xx] = 1; ok[yy] = 1;
    max_depth = 0;
    getDepth(xx, 0);
    int tmp = max_depth; //cout << max_depth << endl;

    max_depth = 0;
    getDepth(yy, 0);
    tmp += max_depth; //cout << max_depth << endl;
    //cout << xx << " " << yy << "  " << tmp << endl;

    ans += 2 + tmp;
}

void DFS(int u) {
    low[u] = num[u] = ++tin;
    S.push(u);
    FO(i,0,adj[u].size()) {
        int v = adj[u][i];
        if(xet[v] == 0) {
            if (num[v] == 0) {
                DFS(v);
                low[u] = min(low[u], low[v]);
            }
            else low[u] = min(low[u], num[v]);
        }
    }
    if (low[u] == num[u]) {
        num_scc++;
        vector<int> VV;
        while(1){
            VV.pb(S.top());
            xet[S.top()] = 1;
            if(S.top() == u) {
                S.pop(); break;
            }
            S.pop();
        }

        if(VV.size() == 2){
            int xx = VV[0], yy = VV[1];
            find2path(xx, yy);
            //cout << xx << " " << yy << "  " << depth[xx] << " " << depth[yy] << endl;
        }
        else if(VV.size() >= 3) ans2 = max(ans2, (int)VV.size());
        //cout << VV.size() << endl;
        //FO(i,0,VV.size()) cout << VV[i] << " "; cout << endl;
    }
}

void solve(){
    ans = 0; ans2 = 0;
    FOR(i,1,n) { adj[i].clear(); adj2[i].clear(); }
    tin = 0, num_scc = 0;
    while(!S.empty()) S.pop();
    memset(num, 0, sizeof(num));
    memset(low, 0, sizeof(low));

    FOR(i,1,n) adj[i].pb(x[i]);
    FOR(i,1,n) adj2[x[i]].pb(i);

    memset(xet, 0, sizeof(xet));
    FOR(i,1,n) if(xet[i] == 0) DFS(i);

    cout << max(ans, ans2) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif
    int sotest;
    cin >> sotest;
    FOR(test,1,sotest){
        cin >> n;
        FOR(i,1,n) cin >> x[i];
        cout << "Case #" << test << ": ";
        solve();
    }



    return 0;
}
