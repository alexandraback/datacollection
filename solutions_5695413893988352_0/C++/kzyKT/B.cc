#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(),(c).end()
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define iter(c) __typeof((c).begin())
#define tr(it,c) for(iter(c) it=(c).begin();it!=(c).end();it++)
#define mem(a) memset(a,0,sizeof(a))
#define pd(a) printf("%.10f\n",a)
#define pb(a) push_back(a)
#define in(a) insert(a)
#define pi M_PI
#define R cin>>
#define F first
#define S second
#define C class
#define ll long long
#define ln cout<<'\n'
#define _(_1,_2,_3,N,...)N
#define pr(...) _(__VA_ARGS__,pr3,pr2,pr1)(__VA_ARGS__)
template<C T>void pr1(T a){cout<<a;ln;}
template<C T,C T2>void pr2(T a,T2 b){cout<<a<<' '<<b;ln;}
template<C T,C T2,C T3>void pr3(T a,T2 b,T3 c){cout<<a<<' '<<b<<' '<<c;ln;}
template<C T>void PR(T a,int n){rep(i,n){if(i)cout<<' ';cout<<a[i];}ln;}
bool check(int n,int m,int x,int y){return x>=0&&x<n&&y>=0&&y<m;}
const ll MAX=1000000007,MAXL=1LL<<60,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
typedef pair<int,int> P;

string S(int x){
  stringstream ss;
  string s;
  ss << x;
  ss >> s;
  return s;
}
                
void Main() {
  int T;
  R T;
  REP(tt,1,T+1) {
    string s,t;
    cin >> s >> t;
    int n=s.size();
    int M=MAX;
    string s2="",t2="";
    rep(x,1000) {
      string xx=S(x);
      if(xx.size()>n) continue;
      while(xx.size()<n) xx='0'+xx;
      bool ff=1;
      rep(i,n) {
        if(s[i]!='?'&&xx[i]!=s[i]) ff=0;
      }
      if(!ff) continue;
      rep(y,1000) {
        bool f=1;
        string yy=S(y);
        if(yy.size()>n) continue;
        while(yy.size()<n) yy='0'+yy;
        rep(i,n) {
          if(t[i]!='?'&&yy[i]!=t[i]) f=0;
        }
        if(!f) continue;
        if(M>abs(x-y)) {
          M=abs(x-y);
          s2=xx;
          t2=yy;
        } else if(M==abs(x-y)) {
          if(s2>xx) {
            s2=xx;
            t2=yy;
          } else if(s2==xx && t2>yy) t2=yy;
        }
      }
    }
    cout << "Case #" << tt << ": " << s2 << " " << t2 << endl;
  }
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  Main();return 0;
}
