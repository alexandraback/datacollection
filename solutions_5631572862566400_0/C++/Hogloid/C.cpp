#define DEB
#include<bits/stdc++.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifdef DEB
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }

typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
  template<class S,class T>
  ostream &operator <<(ostream& out,const pair<S,T>& a){
    out<<'('<<a.fr<<','<<a.sc<<')';
    return out;
  }
}

//const int INF=5e8;
int n;
int mig[1005];
vector<int> rg[1005];

int vis[1005];
int findcycle(int v,int d,int R){
  if(vis[v]){
    if(v==R) return d;
    return 0;
  }
  vis[v]=1;
  return findcycle(mig[v],d+1,R);
}

int getdep(int v,int p){
  int res=0;
  for(auto to:rg[v]){
    if(to==p) continue;
    chmax(res,getdep(to,v)+1);
  }
  return res;
}


int main(){
  int t;cin>>t;
  for(int setn=1;setn<=t;++setn){
    cin>>n;
    REP(i,n) rg[i].clear();
    REP(i,n){
      cin>>mig[i];
      --mig[i];
      rg[mig[i]].pb(i);
    }

    int res=0;
    REP(i,n){
      CLR(vis);
      chmax(res,findcycle(i,0,i));
    }
    int cy2=0;
    REP(i,n) if(mig[mig[i]]==i) ++cy2;
    cy2>>=1;

    vector<int> half;
    REP(i,n){
      int u=i,v=mig[i];
      if(mig[v]==u && u<v){
        int U=getdep(u,v),V=getdep(v,u);
        half.pb(U+V+2);
        chmax(res,U+V+cy2*2);
      }
    }
    sort(ALL(half),greater<int>());
    if(half.size()>=2){
      chmax(res,half[0]+half[1]);
    }
    printf("Case #%d: %d\n",setn,res);
  }




  return 0;
}



