#define DINGER_GISBAR
#include <bits/stdc++.h>
using namespace std;
const long long MOD = static_cast<int>(1e9) + 7;
//{{{TEMPLATE_BEGIN
#include <unistd.h>
using namespace std::rel_ops;
#ifdef ZEROKUGI
#include <dumper.hpp>
#define dump(x) dumper::dumper(cerr, __LINE__, (#x), (x), 50, 1, 1)
#define tick(...) dumper::tick(__VA_ARGS__)
#pragma message "Compiling " __FILE__
#else
#define dump(x)
#define tick(...)
#endif
typedef long long lint;
typedef unsigned long long ulint;
typedef long double ldouble;
typedef vector<int> vint;
#define rep(i,n) for(int i=0,i##_len=static_cast<int>(n);i<i##_len;i++)
#define all(c) begin(c),end(c)
#define perm(c) sort(all(c));for(bool c##p=1;c##p;c##p=next_permutation(all(c)))
#define uniquenize(v) (v).erase(unique(all(v)), end(v))
#define size(c) (int)((c).size())
#define cauto const auto&
#define memset(x,y) memset(x,y,sizeof(x))
#define popcount __builtin_popcount
#define gcd __gcd
inline lint bit(int x){return 1LL<<x;}
template<class T>inline bool chmin(T&a,const T&b){return a>b?a=b,1:0;}
template<class T>inline bool chmax(T&a,const T&b){return a<b?a=b,1:0;}
template<class T>inline pair<vector<T>,char>operator*(const vector<T>&v,const char&c)
{return make_pair(v, c);}
template<class T>inline istream&operator>>(istream&is,vector<T>&v){
#ifdef ZEROKUGI
if(v.empty()){cerr<<"Error L"<<__LINE__<<": vector size is zero."<<endl;
exit(EXIT_FAILURE);}
#endif
for(auto&x:v)is>>x;return is;}
template<class T>inline ostream&operator<<(ostream&os,const pair<vector<T>,char>&v)
{bool t=0;for(const T&x:v.first){if(t)os<<v.second;os<<x;t=1;}return os;}
template<class T>inline ostream&operator<<(ostream&os,vector<T>&v){return os<<v*' ';}
struct before_main{before_main()
{cin.tie(0);ios::sync_with_stdio(0);cout<<fixed<<setprecision(20);tick(0,0);};}__before_main;
//}}}TEMPLATE_END

struct SCC{
    int V;
    vector<vector<int>> G, rG;
    vector<int> used, cmp, vs;

    SCC(int v):V(v), G(V), rG(V), used(V), cmp(V){}

    void add_edge(int from, int to){
        G[from].push_back(to);
        rG[to].push_back(from);
    }

    void dfs(int v){
        used[v] = true;
        for(int i = 0; i < size(G[v]); i++){
            if(!used[G[v][i]]) dfs(G[v][i]);
        }
        vs.push_back(v);
    }

    void rdfs(int v, int k){
        used[v] = true;
        cmp[v] = k;
        for(int i = 0; i < size(rG[v]); i++){
            if(!used[rG[v][i]]) rdfs(rG[v][i], k);
        }
    }

    vector<int> tsort(){
        fill(begin(used), end(used), 0);
        vs.clear();
        for(int v = 0; v < V; v++){
            if(!used[v]) dfs(v);
        }

        fill(begin(used), end(used), 0);
        int k = 0;
        for(int i = size(vs)-1; i >= 0; i--){
            if(!used[vs[i]]) rdfs(vs[i], k++);
        }
        return cmp;
    }
};


int nxt[1111], par[1111], gs[1111];
int dp[1111], anc[1111], dp2[1111];
void solve(){
    int n; cin >> n;
    SCC G(n);
    rep(i, n){
        int w; cin >> w;
        G.add_edge(w-1, i);
        nxt[w-1] = i;
        par[i] = w-1;
    }

    vector<int> cmp = G.tsort();
    //vector<int> cmp = G.cmp;
    vector<pair<int, int>> hoge;
    rep(i, size(cmp)) hoge.push_back({cmp[i], i});
    sort(all(hoge));
    vector<int> ord;
    rep(i, size(hoge)) ord.push_back(hoge[i].second);


    int ans = 0;
    rep(i, n){
        vector<int> idx;
        rep(j, n) if(i == cmp[j]) idx.push_back(j);

        int group_size = size(idx);
        chmax(ans, group_size);
        for(int j: idx){
            gs[j] = group_size;
        }
    }

    //dump(ord); dump(cmp);
    memset(dp, 0);
    memset(dp2, 0);
    memset(anc, -1);

    for(int i: ord){
        if(gs[i] == 2){
            anc[i] = i;
            dp2[i] = dp[i] = 1;
        }
        if(gs[i] == 1){
            if(anc[par[i]] == -1) continue;
            anc[i] = anc[par[i]];
            dp[i] = dp[par[i]]+1;
            chmax(dp2[anc[i]], dp[i]);
        }
    }

    int ans2 = 0;
    for(int i: ord){
        if(gs[i] == 2){
            ans2 += dp2[i];
        }
    }
    cout << max(ans, ans2) << endl;
    //cout << ans << " "  << ans2 << endl;
}

int main(){
    int t; cin >> t;
    for(int T = 1; T <= t; T++){
        cout << "Case #" << T << ": ";
        solve();
    }
}

