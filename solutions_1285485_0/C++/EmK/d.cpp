// compile with "g++ XXX.cc -mno-cygwin -O2" in Cygwin

#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<numeric>
#include<functional>
#include<complex>
#include<bitset>

using namespace std;
#define BET(a,b,c) ((a)<=(b)&&(b)<(c))
#define FOR(i,n) for(int i=0,i##_end=(int(n));i<i##_end;i++)
#define FOR3(i,a,b) for(int i=a,i##_end=b;i<i##_end;i++)
#define FOR_EACH(it,v) for(__typeof(v.begin()) it=v.begin(),it_end=v.end() ; it != it_end ; it++)
#define SZ(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define MP make_pair
#define CLS(x,val) memset((x) , val , sizeof(x)) 
typedef long long ll_t;
typedef long double ld_t;
typedef vector<int> VI; 
typedef vector<VI> VVI;
typedef complex<int> xy_t;

template<typename T> void debug(T v , string delimiter = "\n")
{ for(__typeof(v.begin()) it=v.begin(),it_end=v.end() ; it != it_end ; it++) cout << *it << delimiter; cout << flush ;}

long long gcd (long long s , long long t) { return t ? gcd(t,s%t) : s ; }

int main() {
  int t,case_no=1;
  cin>>t;
  while(t--){
    ll_t ans=0;

    int H,W,D;
    cin>>H>>W>>D;
    vector<string> dat(H);
    FOR(i,H) cin>>dat[i];
    int px,py;
    FOR(i,H) FOR(j,W) if(dat[i][j]=='X') { px = j; py = i; }
    int dy1 = (py-1)*2+1;
    int dy2 = (H-2-(py))*2+1;
    int dx1 = (px-1)*2+1;
    int dx2 = (W-2-(px))*2+1;
    //cout<<dy1<<" "<<dy2<<" "<<dx1<<" "<<dx2<<endl;
    set<pair<int,int> > dup;
    for(int a=-60;a<=60;a++){
      for(int b=-60;b<=60;b++) if(a||b){
          int x=0,y=0;
          if(a>0) {
            y += (a/2) * (dy1 + dy2);
            if(a%2) y += dy2;
          }else if(a<0){
            y -= (-a/2) * (dy1 + dy2);
            if(a%2) y -= dy1;
          }
          if(b>0){
            x += (b/2) * (dx1 + dx2);
            if(b%2) x += dx2;
          }else if(b<0){
            x -= (-b/2) * (dx1 + dx2);
            if(b%2) x -= dx1;
          }
          int d2 = x*x+y*y;
          if(d2 <= D*D) {
            int g = gcd(abs(x),abs(y));
            x /= g ;
            y /= g;
            if(dup.count(MP(x,y))==0){
              //cout<<a<<" "<<b<<" "<<x<<" "<<y<<endl;
              dup.insert(MP(x,y));
              ans++;
            }


          }
      }
    }
    printf("Case #%d: %I64d\n" , case_no++ , ans);
  }
  return 0 ;
}

