#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
#define EPS (1e-6)
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define REP(i, n) rep (i, n)
#define F first
#define S second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define min3(a,b,c) min((a),min((b),(c)))
#define min4(a,b,c,d) min((a),min3((b),(c),(d)))
#define SZ(a) (int)((a).size())
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define FLL(a,b) memset((a),b,sizeof(a))
#define CLR(a) memset((a),0,sizeof(a))
#define declare(a,it) __typeof(a) it=(a)
#define FOR(it,a) for(declare(a.begin(),it);it!=a.end();++it)
#define FORR(it,a) for(declare(a.rbegin(),it);it!=a.rend();++it)

template<typename T,typename U> ostream& operator<< (ostream& out, const pair<T,U>& val){return out << "(" << val.F << ", " << val.S << ")";}
template<class T> ostream& operator<< (ostream& out, const vector<T>& val){out << "{";rep(i,SZ(val)) out << (i?", ":"") << val[i];return out << "}";}
typedef double FP;
typedef complex<FP> pt;
typedef pt P;
typedef pair<pt,pt> line;
namespace std{
  bool operator<(const P&a,const P&b){
    if(abs(a.real()-b.real())>EPS)
      return a.real()<b.real();
    return a.imag()<b.imag();
  }
}
FP dot(P a,P b){return real(conj(a)*b);}
FP crs(P a,P b){return imag(conj(a)*b);}
P ortho(P a){return P(imag(a),-real(a));}
P ortho(line a){return ortho(a.S-a.F);}
P crspt(P a,P b,P c,P d){b-=a,d-=c;return a+b*crs(d,c-a)/crs(d,b);}
P crspt(line a,line b){return crspt(a.F,a.S,b.F,b.S);}
bool onl(P a1,P a2,P b){return abs(b-a1)+abs(b-a2)<abs(a1-a2)+EPS;}
bool onl(line a,P b){return onl(a.F,a.S,b);}
bool iscrs(line a,line b){P c=crspt(a,b);return onl(a,c)&&onl(b,c);}
void pkuassert(bool t){t=1/t;};
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={1,0,-1,0,-1,1,1,-1};
enum{TOP,BTM,LFT,RGT,FRT,BCK};
int dxdy2ce[]={RGT,FRT,LFT,BCK};
int s2i(string& a){stringstream ss(a);int r;ss>>r;return r;}
template<class T> T shift(T a,int b,int c,int d,int e){
  __typeof(a[0])t=a[b];
  a[b]=a[c];a[c]=a[d];a[d]=a[e];a[e]=t;return a;}
template<class T> T rgt(T a){return shift(a,TOP,LFT,BTM,RGT);}
template<class T> T lft(T a){return shift(a,TOP,RGT,BTM,LFT);}
template<class T> T frt(T a){return shift(a,TOP,BCK,BTM,FRT);}
template<class T> T bck(T a){return shift(a,TOP,FRT,BTM,BCK);}
line mkl(P a,P v){return line(a,a+v);}
FP lpdist(line a,P b){return abs(b-crspt(a,mkl(b,ortho(a))));}
FP spdist(line a,P b){
  P c(crspt(a,mkl(b,ortho(a))));
  return onl(a,c)?abs(b-c):min(abs(a.F-b),abs(a.S-b));
}
FP ssdist(line a,line b){
  return
    iscrs(a,b)?0.:
    min4(spdist(a,b.F),spdist(a,b.S),
         spdist(b,a.F),spdist(b,a.S));
}

int n;
int a[1000];
int b[1000];
int dec(){
  sort(a,a+n);
  sort(b,b+n);
  set<int> as,bs;
  rep(i,n) as.insert(a[i]);
  rep(i,n) bs.insert(b[i]);
  int ret=0;
  if(bs.count(1e5)){
    bs.erase(1e5);
    as.erase(as.begin());
  }
  
  FOR(it,as){
    if(*it > *bs.begin()){
      ++ret;
      bs.erase(*bs.begin());
    }else bs.erase(*bs.rbegin());
  }
  
  return ret;
}

int war(){
  sort(a,a+n);
  sort(b,b+n);

  set<int> k;
  rep(i,n)k.insert(b[i]);
  int ret = 0;
  rep(i,n){
    auto it = k.lower_bound(a[i]);
    if(it==k.end()) it=k.begin();
    if(*it < a[i]) ++ret;
    k.erase(it);
  }
  return ret;
}

int main(int argc, char *argv[])
{
  int t;
  cin >> t;
  rep(i,t){
    cin >> n;
    rep(i,n){
      double t;
      cin >> t;
      t *= 1e5;
      a[i]=t+EPS;
    }
    rep(i,n){
      double t;
      cin >> t;
      t *= 1e5;
      b[i]=t+EPS;
    }
    
    printf("Case #%d: %d %d\n",i+1,dec(),war());
  }
  return 0;
}
