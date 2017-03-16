#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<unordered_map>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
//template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
//template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
const ll MOD=1e9+7;
const ll INF=1e18+10;

void MN(pll &a,pll b,ll s=1,ll x=0,ll y=0){
  b.X+=x; b.Y+=y;
  if(a.X<0 || abs(a.X-a.Y)>abs(b.X-b.Y)){
    a=b;
    return;
  }
  if(abs(a.X-a.Y)==abs(b.X-b.Y)) a=min(a,b);
}
void MX(pll &a,pll b,ll s=1,ll x=0,ll y=0){
  b.X+=x; b.Y+=y;
  if(a.X<0 || abs(a.X-a.Y)<abs(b.X-b.Y)){
    a=b;
    return;
  }
  if(abs(a.X-a.Y)==abs(b.X-b.Y)) a=min(a,b);
}

pll dp[22][2][2]; //(<,>)*(min,max)

pll solve(string a,string b){
  rep(i,22){
    dp[i][0][0]=pll(-1,0);
    dp[i][0][1]=pll(-1,0);
    dp[i][1][0]=pll(-1,0);
    dp[i][1][1]=pll(-1,0);
  }
  int n=a.size();
  rep(k,2)rep(l,2) dp[n][k][l]=pll(0,0);
  ll pw=1;
  rrep(d,n){
    rep(i,10)if(a[d]=='?' || a[d]-'0'==i)
      rep(j,10)if(b[d]=='?' || b[d]-'0'==j){
	rep(x,2)rep(y,2){
	  if(dp[d+1][x][y].X<0) continue;
	  if(i<j){
	    MN(dp[d][0][0],dp[d+1][x][y],x,i*pw,j*pw);
	    MX(dp[d][0][1],dp[d+1][x][y],x,i*pw,j*pw);
	  }else if(i>j){
	    MN(dp[d][1][0],dp[d+1][x][y],!x,i*pw,j*pw);
	    MX(dp[d][1][1],dp[d+1][x][y],!x,i*pw,j*pw);
	  }else{
	    if(y)MX(dp[d][x][y],dp[d+1][x][y],0,i*pw,j*pw);
	    else MN(dp[d][x][y],dp[d+1][x][y],0,i*pw,j*pw);
	  }
	}
      }
    pw*=10;
  }
  //rep(i,n){rep(j,2)rep(k,2)cout<<dp[i][j][k];cout<<endl;}
  pll p=dp[0][0][0],q=dp[0][1][0];
  if(p.X<0) return q;
  if(q.X<0) return p;
  if(p.Y-p.X == q.X-q.Y) return min(p,q);
  if(p.Y-p.X < q.X-q.Y) return p;
  return q;
}

int main(){
  //ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int T;
  cin>>T;
  rep(test,T){
    string a,b;
    cin>>a>>b;
    
    cout<<"Case #"<<test+1<<": ";
    pll p=solve(a,b);
    //cout<<p;
    printf("%0*lld %0*lld\n",a.size(),p.X,b.size(),p.Y);
  }
  return 0;
}
