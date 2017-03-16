// @author kelvin
// #includes {{{
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
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
    printf("%d ",head);
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
typedef pair<string,string> pss;
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

#define MAXN 2050

#define MAXVN (MAXN*3+2) // define as needed: # of nodes in graph
const int dist_inf = MAXVN; //has to be appropriately initialized: at least MAXVN for example
const int flow_inf = MAXVN; //has to be appropriately initialized: at least 10^8 for example

class Arc {
   public:
      int to,revind;
      int flow,cap;
      Arc(int _to,int _revind,int _cap):to(_to),revind(_revind),cap(_cap),flow(0) {}
};

class DinicFlow {
   public:
      /* initialize the following using constructor and append */
      int vn,src,sink;
      vector<Arc> adj[MAXVN];
      /* helper variables */
      int dist[MAXVN];
      int ql,qr,que[MAXVN];
      int iter[MAXVN];
      /* primary functions */
      DinicFlow(int _vn,int _src,int _sink):vn(_vn),src(_src),sink(_sink) {}
      void append(int v,int u,int c) {
         int vid=adj[v].size(),uid=adj[u].size();
         adj[v].push_back(Arc(u,uid,c));
         adj[u].push_back(Arc(v,vid,0));
      }
      void bfs_layer() {
         ql=qr=0;
         for(int i=0;i<vn;i++)
            dist[i]=dist_inf;
         que[qr++]=src;
         dist[src]=0;
         while(ql<qr) {
            int v=que[ql++];
            for(int i=0;i<adj[v].size();i++) {
               int u=adj[v][i].to;
               int res=adj[v][i].cap-adj[v][i].flow;
               if(dist[u]<dist_inf) continue;
               if(!res) continue;
               que[qr++]=u;
               dist[u]=dist[v]+1;
            }
         }
      }
      int dfs_push(int v,int a) {
         if(v==sink) return a;
         int pushed=0;
         for(int &i=iter[v];i<adj[v].size();i++) {
            int u=adj[v][i].to;
            int res=adj[v][i].cap-adj[v][i].flow;
            if(dist[u]!=dist[v]+1) continue;
            if(!res) continue;
            int ri=adj[v][i].revind;
            int pf=dfs_push(u,min(a-pushed,res));
            adj[v][i].flow+=pf;
            adj[u][ri].flow-=pf;
            pushed+=pf;
            if(pushed==a) break;
         }
         return pushed;
      }
      int push_flow() {
         bfs_layer();
         for(int i=0;i<vn;i++)
            iter[i]=0;
         return dfs_push(src,flow_inf);
      }
      int maxflow() {
         // O(mn^2) in general graph
         // good complexity in bipartite / unit-capcity graph
         int f=0;
         while(1) {
            int pf=push_flow();
            if(!pf) break;
            f+=pf;
         }
         return f;
      }
      /* selective functions */
      vector<pii> mincut() {
         // must run maxflow() first
         // will return the mincut "closest" to src
         bfs_layer();
         vector<pii> cut;
         for(int v=0;v<vn;v++) {
            for(int i=0;i<adj[v].size();i++) {
               int u=adj[v][i].to;
               if(dist[v]<dist_inf&&dist[u]==dist_inf) cut.push_back(make_pair(v,u));
            }
         }
         return cut;
      }
      vector<int> srccut() {
         bfs_layer();
         vector<int> vs;
         for(int v=0;v<vn;v++)
            if(dist[v]<dist_inf) vs.push_back(v);
         return vs;
      }
      vector<int> sinkcut() {
         bfs_layer();
         vector<int> vs;
         for(int v=0;v<vn;v++)
            if(dist[v]==dist_inf) vs.push_back(v);
         return vs;
      }
      bool mincut_is_isolated_sink() {
         // return whether cut is {sink} -- {V\sink}
         // useful for handling binary search problems where you don't
         // want the sink to be the only node at one side of the cut
         return sinkcut().size()==1;
      }
};


int idn,idn2;
map<string,int> idmap,idmap2;
vector<pii> ed;

inline void init() {
    idmap.clear();
    idmap2.clear();
    idn=idn2=0;
}
inline int getid(string s) {
    if(idmap.find(s)==idmap.end()) {
        idmap[s]=idn++;
    }
    return idmap[s];
}
inline int getid2(string s) {
    if(idmap2.find(s)==idmap2.end()) {
        idmap2[s]=idn2++;
    }
    return idmap2[s];
}

int solve() {
    int ln=idn;
    int rn=idn2;
    int vn=ln+rn+2;
    int src=0;
    int sink=vn-1;
    DinicFlow df(vn,src,sink);
    for(auto e: ed)
        df.append(e.F+1,e.S+ln+1,1);
    for(int i=0;i<ln;i++)
        df.append(src,i+1,1);
    for(int i=0;i<rn;i++)
        df.append(i+ln+1,sink,1);
    int f = df.maxflow();
    int sol = (int)ed.size()-(ln+rn-f);
    return sol;
}

int main(void)
{
    int t;
    RI(t);
    for(int cas=1; cas<=t; cas++) {
        int en;
        string a,b;
        RI(en);
        init();
        ed.clear();
        for(int i=0;i<en;i++) {
            cin >> a >> b;
            ed.PB(MP(getid(a),getid2(b)));
        }
        printf("Case #%d: %d\n",cas,solve());
    }
    return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread
