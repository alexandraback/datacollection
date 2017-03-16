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
#include<cassert>
const int al=(1<<10)-1;
ll solve(ll x){
  int f=0;
  for(ll i=x;;i+=x){
    //cout<<i<<endl;
    for(ll j=i;j;j/=10) f|=1<<(j%10);
    if(f==al) return i;
    assert(i>=0);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  //rep(i,1000000) solve(i+1);
  int T;
  cin>>T;
  rep(testcase,T){
    int n;
    cin>>n;
    cout<<"Case #"<<testcase+1<<": ";
    if(n) cout<<solve(n)<<endl;
    else cout<<"INSOMNIA"<<endl;
  }
  
  /*cout<<"{0";
  rep(i,1000000)cout<<","<<solve(i+1);
  cout<<"}"<<endl;*/
  return 0;
}
