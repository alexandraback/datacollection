//Done by Ferran Alet

#include<bits/stdc++.h>

#define INF 2147483647
#define LINF 1000000000000000000LL
#define EPS 1e-9
#define debug(x) cerr << #x << " = " << x << endl
#define Debug(v) cerr << #v << " = "; for(int wow=0;wow<v.size();++wow) cerr<<v[wow]<<' '; cerr<<endl
#define DEBUG(M) cerr << #M <<":"<<endl; for(int iM=0;iM<M.size();++iM) { for(int jM=0;jM<M[iM].size();++jM) cerr<<M[iM][jM]<<' '; cerr<<endl;} cerr<<endl
#define FOR(x,y) for(int x=0;x<y;x++)
#define FORS(x,y) for(int x=0;x<int(y.size());++x)
#define FORU(x,y) for(int x=1;x<=y;x++)
#define RFOR(x,y) for(int x=y-1;x>=0;--x)
#define DRI(x) int x; cin>>x
#define DRII(x,y) int x,y; cin>>x>>y
#define DRIII(x,y,z) int x,y,z; cin>>x>>y>>z
#define PB push_back
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<string> VS;
typedef map<int,int> MII;
typedef MII::iterator iMII;
typedef vector<PII > VP;
typedef vector<VP> VVP;

int bfs( VVI &g, VI &p, int a,int b){
   int n=g.size();
   p= VI (n,-1);
   VI flow(n,INF);
   queue<int> q;
   q.push(a);
   while(!q.empty()){
      int pos=q.front();
      q.pop();
      if(pos==b) return flow[b];
      FOR(i,n) {
         if(g[pos][i]>0 && p[i]==-1){ //Encara no l'he tocat i hi puc fer arribar flow
            p[i]=pos;
            flow[i]=min(flow[pos],g[pos][i]);
            q.push(i);
         }
      }
   }
   return 0;
}

int max_flow( VVI &g, int a, int b){
   int n=g.size();
   int flow=0; //flow total
   VI p(n,-1); //vector de pares
   for (int f=bfs(g,p,a,b);f>0;f=bfs(g,p,a,b)){
      flow+=f;
      for(int i=b;i!=a;i=p[i]){
         g[i][p[i]]+=f;
         g[p[i]][i]-=f;
      }
   }
   return flow;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//  freopen(".out","w",stdout);
//  freopen(".in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("C-large-sol-2.out","w",stdout);
    freopen("C-large.in","r",stdin);
    DRI(casos);
    FORU(cas,casos){
        debug(cas);
        DRI(n);
        VS A(n),B(n);
        FOR(i,n) cin>>A[i]>>B[i];
        map<string, int> M;
        map<string, int> CM;
        int cont = 0;
        vector<PII> v(n);
        FOR(i,n){
            CM[A[i]]++;
            if(M.find(A[i])==M.end()){
                M[A[i]] = cont++;
            }
            v[i].first = M[A[i]];
            if(M.find(B[i]+'$')==M.end()){
                M[B[i]+'$'] = cont++;
            }
            v[i].second= M[B[i]+'$'];
            CM[B[i]+'$']++;
        }
        int m  = cont;
        VVI g(m);
        FOR(i,n){
            g[M[B[i]+'$']].push_back(M[A[i]]);
            g[M[A[i]]].push_back(M[B[i]+'$']);
        }
        /*FOR(i,m){
            cerr<<i<<": ";
            Debug(g[i]);
        }*/
        VVI G(m+2,VI(m+2));
        FOR(i,n) {
            G[M[A[i]]][M[B[i]+'$']] +=1;
            G[M[B[i]+'$']][M[A[i]]] +=1;
        }
        set<string> S;
        FOR(i,n){
            //cerr<<i<<' '<<A[i]<<' '<<B[i]+'$'<<endl;
            //cerr<<i<<' '<<M[A[i]]<<' '<<M[B[i]+'$']<<endl;
            if(S.count(A[i])==0){
                G[m][M[A[i]]] =CM[A[i]]-1;
                G[M[A[i]]][m] =CM[A[i]]-1;
                S.insert(A[i]);
            }
            if(S.count(B[i]+'$')==0){
                S.insert(B[i]+'$');
                G[m+1][M[B[i]+'$']] =CM[B[i]+'$']-1;
                G[M[B[i]+'$']][m+1] =CM[B[i]+'$']-1;
            }


        }
        cerr<<"PREFLOW"<<endl;
        cout <<"Case #"<<cas<<": "<<max_flow(G,m,m+1)<<endl;
    }
}
