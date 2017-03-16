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
#define ALL(a) (a).begin(),(a).end()
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


bool ok(int cst,int r,int c,int m){
  int syu[50]={};

  rep(i,r)rep(j,c){
    rep(k,8){
      int nx=i+dx[k];
      int ny=j+dy[k];
      if(nx<0 || ny<0 || nx>=r || ny>=c) continue;
      syu[i*c+j] |= 1 << (nx*c+ny);
    }
  }

  
  rep(i,r)rep(j,c){
    int p=i*c+j;
    if(cst&(1<<p)) continue;
    if(cst&syu[p]) continue;
    
    //cerr << "aft ok " << i << ' ' << j << endl;
    
    int vis = 0;
    queue<PI> q;
    q.push(mp(i,j));
    vis |= 1<<(i*c+j);
    while(!q.empty()){
      int cx = q.front().F;
      int cy = q.front().S;
      q.pop();
      int cp = cx*c+cy;
      if(cst&syu[cp]) continue;
      
      rep(k,8){
        int nx = cx + dx[k];
        int ny = cy + dy[k];
        if(nx<0 || ny<0 || nx>=r || ny>=c) continue;
        int np=nx*c+ny;
        if((vis&(1<<np)) || (cst&(1<<np))) continue;
        vis |= 1<<np;
        q.push(mp(nx,ny));
      }
    }
    
    //cerr << vis << ' ' << cst << ' ' << (vis&cst) << ' ' << (vis|cst) << endl;
    
    if((vis|cst) != (1<<(r*c))-1)
      return false;
    
    rep(x,r){
      rep(y,c){
        int p=x*c+y;
        cout <<(x==i&&y==j?'c':(cst&(1<<p)?'*':'.'));
      }
      cout << endl;
    }
    return true;
  }
  
  return false;
}

void solve(int ca){
  printf("Case #%d:\n",ca);
  int r,c,m;
  cin >> r >> c >> m;

  if(m==r*c-1){
    rep(i,r){
      rep(j,c)
        cout << (i|j?'*':'c');
      cout << endl;
    }
    return;
  }
  
  
  int cst = (1<<m) - 1;
  while(cst < (1<<(r*c))){

    if(ok(cst,r,c,m))
      return;
    
    int x = cst & -cst, y = cst + x;
    cst = ((cst & ~y) / x >> 1) | y;
  }

  puts("Impossible");
}

int main(int argc, char *argv[])
{

  int t;
  cin >> t;
  rep(i,t) solve(i+1);
  return 0;
}
