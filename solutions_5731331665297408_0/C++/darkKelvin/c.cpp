// @author kelvin
// #includes {{{
#include <bits/stdc++.h>
using namespace std;
// }}}
// #defines {{{
#define MP(x,y) make_pair(x,y)
#define PB(x) push_back(x)
#define POP() pop_back()
#define F first
#define S second
#define PR printf
void RI() {}
template<typename... T>
void RI(int& head,T&... tail) {
    scanf("%d",&head);
    RI(tail...);
}
void PRI(int x) {
    printf("%d\n",x);
}
template<typename... Args>
void PRI(int head,Args... tail) {
    fprintf(stderr,"%d ",head);
    PRI(tail...);
}
#define RF(x) scanf("%lf",&(x))
#define RS(x) scanf("%s",x)
#define DPRI(x) fprintf(stderr,"<"#x"=%d>\n",x)
#define DPRII(x,y) fprintf(stderr,"<"#x"=%d, "#y"=%d>\n",x,y)
#define DPRIII(x,y,z) fprintf(stderr,"<"#x"=%d, "#y"=%d, "#z"=%d>\n",x,y,z)
#define DPRIIII(x,y,z,w) fprintf(stderr,"<"#x"=%d, "#y"=%d, "#z"=%d "#w"=%d>\n",x,y,z,w)
#define DPRF(x) fprintf(stderr,"<"#x"=%lf>\n",x)
#define DPRS(x) fprintf(stderr,"<"#x"=%s>\n",x)
#define DPRMSG(x) fprintf(stderr,#x"\n")
#define DPRPII(x) fprintf(stderr,"<"#x"=(%d,%d)>\n",x.F,x.S)
typedef pair<int,int> pii;
// }}}
// #functions {{{
pii operator+(const pii &a,const pii &b) { return MP(a.F+b.F,a.S+b.S); }
pii operator-(const pii &a,const pii &b) { return MP(a.F-b.F,a.S-b.S); }
pii& operator+=(pii &a,const pii &b) { a.F+=b.F; a.S+=b.S; return a; }
pii& operator-=(pii &a,const pii &b) { a.F-=b.F; a.S-=b.S; return a; }
template <class T,class U>
bool cmp_second(const pair<T,U> &a,const pair<T,U> &b) { return a.second<b.second; }
template <class T>
T gcd(T a,T b) { a=abs(a); b=abs(b); while(b) { T t=b; b=a%b; a=t; } return a; }
template <class T>
pair<T,T> ext_gcd(T a,T b) {
   T a0=1,a1=0,b0=0,b1=1;
   if(a<0) { a=-a; a0=-1; }
   if(b<0) { b=-b; b1=-1; }
   while(b) {
      T t,q=a/b;
      t=b; b=a-b*q; a=t;
      t=b0; b0=a0-b0*q; a0=t;
      t=b1; b1=a1-b1*q; a1=t;
   }
   return MP(a0,a1);
}
inline int sg(int x) { return x?(x>0?1:-1):0; }
inline string concatenate_strings(vector<string> ss) {
   string s;
   for(int i=0;i<ss.size();i++)
      s+=ss[i];
   return s;
}
template <class T>
inline vector<T> read_from_string(string s) {
   vector<T> ret; stringstream ss(s,stringstream::in);
   while(1) { T x; ss>>x; ret.push_back(x); if(ss.eof()) break; }
   return ret;
}
// }}}

#define MAXN 55

int n,m;
int remap[MAXN];
string postal[MAXN];
set<int> adj[MAXN];

bool visited[MAXN],vv[MAXN];
// bool inset[MAXN];
int indeg[MAXN];
set<int> ns;
int nxt;
vector<int> seq;
vector<int> stk;

void trav(int v) {
    vv[v]=1;
    for(auto u:adj[v]) {
        if(visited[u]) continue;
        if(vv[u]) continue;
        trav(u);
    }
}

bool check(int u) {
    memset(vv,0,sizeof(vv));
    int ind;
    for(ind=stk.size()-1;ind>=0;ind--) {
        int v=stk[ind];
        if(adj[v].find(u)!=adj[v].end()) break;
    }
    if(ind<0) return 0;
    //for(int v=1;v<=n;v++)
    for(int i=0;i<=ind;i++) {
        int v=stk[i];
        if(!vv[v]) trav(v);
    }
    for(int v=1;v<=n;v++)
        if(!visited[v]&&!vv[v]) return 0;
    return 1;
}

void dfs(int v) {
    //DPRI(v);
    //inset[v]=1;
    visited[v]=1;
    seq.PB(v);
    stk.PB(v);
    ns.erase(v);
    for(auto u: adj[v]) {
        if(!indeg[u]&&!visited[u]) ns.insert(u);
        indeg[u]++;
    }
    /*auto it=adj[v].begin();
    while(1) {
        int u=check(v);
        if(!u) break;
        while(it!=adj[v].end()&&visited[*it]) it++;
        if(it!=adj[v].end()&&!visited[*it]) dfs(*it);
    }
    while(ns.size()) {
        //printf("%d:",v);
        //for(auto it: ns)
        //    printf(" %d",it); puts("");
        nxt=*(ns.begin());
        if(adj[v].find(nxt)!=adj[v].end()) dfs(nxt);
        else {

        }
    }*/
    while(ns.size()) {
        int u;
        for(u=1;u<=n;u++)
            if(!visited[u]&&check(u)) break;
        if(adj[v].find(u)==adj[v].end()) break;
        else dfs(u);
    }
    for(auto u: adj[v]) {
        indeg[u]--;
        if(!indeg[u]&&ns.find(u)!=ns.end()) ns.erase(u);
    }
    //inset[v]=0;
    stk.POP();
}

void solve() {
    //DPRMSG(solve);
    memset(visited,0,sizeof(visited));
    memset(indeg,0,sizeof(indeg));
    ns.clear();
    seq.clear();
    dfs(1);
    for(auto v: seq)
        printf("%s",postal[v].c_str());
    puts("");
}

int main(void)
{
    int t,cas;
    RI(t);
    for(cas=1;cas<=t;cas++) {
        RI(n,m);
        vector<pair<string,int>> arr;
        for(int i=1;i<=n;i++) {
            cin >> postal[i];
            arr.PB(MP(postal[i],i));
            adj[i].clear();
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++)
            remap[arr[i].S]=i+1;
        sort(postal+1,postal+n+1);
        for(int i=0;i<m;i++) {
            int v,u;
            RI(v,u);
            v=remap[v];
            u=remap[u];
            adj[v].insert(u);
            adj[u].insert(v);
            //printf(">> %s %s\n",postal[v].c_str(),postal[u].c_str());
        }
        printf("Case #%d: ",cas);
        solve();
    }
    return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread

