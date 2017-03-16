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
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
const ll MOD=1e9+7;

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int T,n,t;
  cin>>T>>n>>t;
  vector<ll> re;
  for(int i=2;i<=10;++i){
    ll x=1;
    rep(j,n/2) x*=i;
    re.pb(x+1);
  }
  cout<<"Case #1:"<<endl;
  rep(i,t){
    rep(hoge,2){
      cout<<1;
      int x=i;
      rep(j,n/2-2){
	cout<<x%2;
	x/=2;
      }
      cout<<1;
    }
    rep(i,9) cout<<" "<<re[i];
    cout<<endl;
  }
  return 0;
}

/*
5,7,2,3
1417548224
105
  ll re=0;
  for(ll i=0;i<(1ll<<32);++i){
    int t=__builtin_popcountll(i);
    if(t%2&&t%3&&t%5&&t%7) ++re;
  }
  cout<<re<<endl;
  return 0;
  rep(d,32+1){
    for(ll i=(1<<d)-1;i<(1ll<<32); ){
      ++re;
    }
  }
  cout<<re<<endl;
 */
