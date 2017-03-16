#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}


int N;
string S[1000],T[1000];
int A[1000],B[1000];


const int MAX_V=2000;
vint G[MAX_V];
int V;
int match[MAX_V];
bool used[MAX_V];
void init(){
    rep(i,MAX_V)G[i].clear();
}
void add_edge(int u,int v){
    G[u].pb(v);
    G[v].pb(u);
}
bool dfs(int v){
    used[v]=true;
    for(int i=0;i<G[v].size();i++){
        int u=G[v][i],w=match[u];
        if(w<0||!used[w]&&dfs(w)){
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}
int bipartite_matching(){
    int res=0;
    memset(match,-1,sizeof(match));
    for(int v=0;v<V;v++){
        if(match[v]<0){
            memset(used,0,sizeof(used));
            if(dfs(v)){
                res++;
            }
        }
    }
    return res;
}

void solve(int ca){
    cout<<"Case #"<<ca+1<<": ";
    cin>>N;
    vector<string>ss,ts;
    rep(i,N){
        cin>>S[i]>>T[i];
        ss.pb(S[i]);
        ts.pb(T[i]);
    }
    sort(all(ss));sort(all(ts));
    ss.erase(unique(all(ss)),ss.end());
    ts.erase(unique(all(ts)),ts.end());
    init();
    V=ss.size()+ts.size();
    rep(i,N){
        A[i]=lower_bound(all(ss),S[i])-ss.begin();
        B[i]=lower_bound(all(ts),T[i])-ts.begin();
        add_edge(A[i],ss.size()+B[i]);
    }

    int tmp=V-bipartite_matching();
    cout<<N-tmp<<endl;
}

signed main(){
    int T;cin>>T;
    rep(i,T)solve(i);
    return 0;
}
