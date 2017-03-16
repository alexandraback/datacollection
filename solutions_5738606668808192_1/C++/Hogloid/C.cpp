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
int n,J;
int want[]={1,1,3,2,3,2,7,2,3,2,3};
typedef vector<int> vi;
map<vi,vector<string>> dp[35];

vi mult(vi a){
  REP(j,11) a[j]=(a[j]*j)%want[j];
  return a;
}

void push(vector<string>& a,vector<string>& b,char add){
  int n=min((int)b.size(),J-(int)a.size());
  REP(i,n){
    a.pb(b[i]+add);
  }
}

int main(){
  int t;cin>>t;
  cin>>n>>J;

  dp[0][vi(11)].pb("");
  REP(i,n){
    for(auto& e:dp[i]){

      vi cur=mult(e.fr);
      REP(t,2){
        if((i==0 || i==n-1) && t==0) continue;
        REP(j,11) cur[j]=(cur[j]+t)%want[j];
        push(dp[i+1][cur],e.sc,'0'+t);
      }
    }
  }
  puts("Case #1:");
  dump(dp[n][vi(11)].size());
  for(auto e:dp[n][vi(11)]){
    cout<<e;
    for(int j=2;j<=10;++j) printf(" %d",want[j]);
    puts("");
  }
  return 0;
}



