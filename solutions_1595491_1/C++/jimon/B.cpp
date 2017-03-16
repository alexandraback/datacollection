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
#define ALL(c) (c).rbegin(),(c).rend()
#define priority_queue_greater(T) priority_queue< T, vector<T>, greater<T> >
// }}}

int T,n,s,p;
int main(){
  cin >> T;
  REP(times,1,T+1){
    cin >> n >> s >> p;
    vec a(n);
    rep(i,n){ scanf("%d",&a[i]); }

    sort(ALL(a));
    int ans = 0;
    rep(i,n){
      int b = ceil( a[i] / 3.0 );
      if( p <= b ){ ans++; }
      else if( s && b+1 == p && 1 < a[i] && a[i]%3!=1 ){ s--; ans++; }
    }
    cout <<"Case #"<< times <<": " << ans << endl;
  }
  return 0;
}


