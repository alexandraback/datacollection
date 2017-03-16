#include <stdio.h>
#include <vector>
#include <algorithm>
#include <sys/resource.h>
#define MAXN 55
#define MAXT (MAXN*MAXN*2+1)
#define MAXV (MAXT*MAXN*2)

using namespace std;

const double eps=1e-9;
const double eeps=1e-11;

const int carlen=5;

int n;
int initlane[MAXN],st[MAXN],vel[MAXN];

int tcnt;
vector<double> tx;
bool danger[MAXN][MAXT];
int conflict[MAXT][MAXN][MAXN];

int vn,nvar;
vector<int> adj[MAXV];
vector<int> rdj[MAXV];
//bool must[2][MAXV];

int sccid[MAXV],order[MAXV],oid,sccn;
int visited[MAXV]={0},visid=0;

inline double posof(int i,double t) {
   return st[i]+vel[i]*t;
}
inline bool inside(double x,double l,double r) { return x>=l+eeps&&x<=r-eeps; }

inline int getvid(int i,int t) { return i*tcnt+t; }
inline int pos(int v) { return v; }
inline int neg(int v) { return v+nvar; }
inline int opp(int v) { return v<nvar?v+nvar:v-nvar; }

inline void gen() {
   tx.clear();
   tx.push_back(0.0);
   for(int _i=0;_i<n;_i++) {
      for(int _j=_i+1;_j<n;_j++) {
         int i=_i,j=_j;
         if(vel[i]<vel[j]) swap(i,j);
         int vi=vel[i],vj=vel[j];
         int si=st[i],sj1=st[j]-carlen,sj2=st[j]+carlen;
         if(vi==vj) continue;
         int dv=vi-vj;
         double t1=max((double)(sj1-si)/dv,0.0);
         double t1plus=max((double)(sj1-si)/dv+eps,0.0);
         double t2=max((double)(sj2-si)/dv,0.0);
         double t2plus=max((double)(sj2-si)/dv-eps,0.0);
         tx.push_back(t1);
         tx.push_back(t1plus);
         tx.push_back(t2);
         tx.push_back(t2plus);
      }
   }
   sort(tx.begin(),tx.end());
   tx.resize(unique(tx.begin(),tx.end())-tx.begin());
   tcnt=tx.size();
   for(int ti=0;ti<tcnt;ti++) {
      double t=tx[ti];
      for(int i=0;i<n;i++) {
         double x=posof(i,t);
         danger[i][ti]=0;
         for(int j=0;j<n;j++) {
            if(i==j) continue;
            double y1=posof(j,t)-carlen;
            double y2=y1+carlen*2;
            conflict[ti][i][j]=0;
            if(inside(x,y1,y2)) {
               danger[i][ti]=1;
               conflict[ti][i][j]=1;
            }
         }
         conflict[ti][i][i]=0;
      }
   }
   //for(int i=0;i<tcnt;i++)
      //printf(" %.20lf",tx[i]);puts("");
}

inline void append(int v,int u) {
   //printf("<%d(%d,%d) %d(%d,%d)>\n",v,v%nvar/tcnt,v%nvar%tcnt,u,u%nvar/tcnt,u%nvar%tcnt);
   adj[v].push_back(u);
   if(opp(v)!=u) adj[opp(u)].push_back(opp(v));
}

inline void construct(int till) {
   nvar=tcnt*n;
   vn=nvar*2;
   /*for(int i=0;i<nvar;i++)
      must[0][i]=must[1][i]=0;
   for(int i=0;i<n;i++)
      must[initlane[i]][getvid(i,0)]=1;*/
   for(int i=0;i<vn;i++) {
      adj[i].clear();
      rdj[i].clear();
   }
   for(int i=0;i<n;i++) {
      if(initlane[i]) append(neg(getvid(i,0)),pos(getvid(i,0)));
      else append(pos(getvid(i,0)),neg(getvid(i,0)));
   }
   for(int i=0;i<n;i++) {
      for(int t=0;t<till-1;t++) {
         if(danger[i][t]&&danger[i][t+1]) {
            append(pos(getvid(i,t)),pos(getvid(i,t+1)));
            append(neg(getvid(i,t)),neg(getvid(i,t+1)));
         }
      }
   }
   for(int t=0;t<till;t++) {
      for(int i=0;i<n;i++) {
         for(int j=i+1;j<n;j++) {
            if(conflict[t][i][j]) {
               append(pos(getvid(i,t)),neg(getvid(j,t)));
               append(neg(getvid(i,t)),pos(getvid(j,t)));
            }
         }
      }
   }
   for(int i=0;i<vn;i++)
      for(int j=0;j<adj[i].size();j++)
         rdj[adj[i][j]].push_back(i);
}

void dfs(int v) {
   //printf("(%d)",v);
   visited[v]=visid;
   for(int i=0;i<adj[v].size();i++) {
      int u=adj[v][i];
      if(visited[u]==visid) continue;
      dfs(u);
   }
   order[oid++]=v;
}

void rdfs(int v) {
   //printf("<%d>",v);
   visited[v]=visid;
   sccid[v]=sccn;
   for(int i=0;i<rdj[v].size();i++) {
      int u=rdj[v][i];
      if(visited[u]==visid) continue;
      rdfs(u);
   }
}

inline bool satisfiable() {
   oid=0;
   ++visid;
   for(int i=0;i<vn;i++)
      if(visited[i]<visid) dfs(i);
   sccn=0;
   ++visid;
   for(int i=vn-1;i>=0;i--) {
      int v=order[i];
      if(visited[v]==visid) continue;
      rdfs(v);
      sccn++;
   }
   //for(int i=0;i<nvar;i++)
      //printf("(%d,%d) ",sccid[pos(i)],sccid[neg(i)]); puts("");
   for(int i=0;i<nvar;i++)
      if(sccid[pos(i)]==sccid[neg(i)]) return 0;
   return 1;
}

inline bool valid(int till) {
   //puts("construct");
   construct(till);
   //puts("sat");
   return satisfiable();
}

inline void solve() {
   gen();
   int l=0,r=tcnt+1;
   while(l<r-1) {
      int m=(l+r)>>1;
      if(valid(m)) l=m;
      else r=m;
   }
   if(l==tcnt) puts("Possible");
   else printf("%.9lf\n",tx[l]);
}

int main(void)
{
   int t,cas=1;
   /* increae stack size */
   /*const arlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
   struct rlimit rl;
   int result;
   result = getrlimit(RLIMIT_STACK, &rl);
   if (result == 0)
   {
      if (rl.rlim_cur < kStackSize)
      {
         rl.rlim_cur = kStackSize;
         result = setrlimit(RLIMIT_STACK, &rl);
         if (result != 0)
         {
            fprintf(stderr, "setrlimit returned result = %d\n", result);
         }
      }
   }*/
   scanf("%d",&t);
   while(t--) {
      scanf("%d",&n);
      for(int i=0;i<n;i++) {
         char str[5];
         scanf("%s %d %d",str,vel+i,st+i);
         initlane[i]=(str[0]=='L'?0:1);
      }
      printf("Case #%d: ",cas++);
      solve();
   }
   return 0;
}
