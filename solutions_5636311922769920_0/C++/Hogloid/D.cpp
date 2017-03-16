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

lint pw[105];
int main(){
  int T;
  cin>>T;
  REP(setn,T){
    printf("Case #%d:",setn+1);
    int k,c,S;cin>>k>>c>>S;
    pw[0]=1;
    REP(i,c) pw[i+1]=pw[i]*k;
    int need=(k+c-1)/c;
    if(S<need) puts(" IMPOSSIBLE");
    else{
      REP(i,need){
        lint res=0;
        REP(j,c) if(i*c+j<k) res+=(i*c+j)*pw[j];
        printf(" %lld",res+1);
      }
      puts("");
    }
  }
  return 0;
}



