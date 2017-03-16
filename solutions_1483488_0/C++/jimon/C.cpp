// include {{{
#include <cstdio>
#include <iostream>
//#include <sstream>
#include <string>
#include <vector>
//#include <deque>
#include <stack>
#include <queue>
//#include <map>
#include <set>
#include <algorithm>
#include <cmath>
//#include <complex>
// }}}
using namespace std;
// macro {{{
typedef long long ll;
typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<(n);++i)
#define REP(i,j,k) for(int i=j;i<(k);++i)
#define foreach(it,v) for(typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ALL(c) (c).begin(),(c).end()
#define priority_queue_greater(T) priority_queue< T, vector<T>, greater<T> >
// }}}

int T;
int a,b;
int main(){
  cin >> T;
  REP(times,1,T+1){
    cin >> a >> b;
    vec v(2000001,0);
    ll ans = 0;
    for(int n=b; a<=n; n--){
      ans += v[n];
      int d = 0;  for(int _n=n;_n;){d++;_n/=10;}
      int dd = 1; REP(i,1,d){ dd *= 10; }
      int now = n;
      set<int> s;
      REP(i,1,d){
        int t = now % 10;
        now = now / 10 + t * dd;
        //cout << n <<":"<< now << endl;
        if( t && a <= now && now <= b ){
          s.insert(now);
        }
      }
      foreach(it,s){ v[*it]++; }
    }
    cout <<"Case #"<<times<<": "<< ans << endl;
  }
  return 0;
}


