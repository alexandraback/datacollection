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
#include <numeric>
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

int T,a,b;
double p;
int main(){
  cin >> T;
  REP(times,1,T+1){
    cin >> a >> b;
    int half = a / 2;
    double ans = b + 2;
    double now = 1;
    rep(i,a){
      cin >> p;
      if( half <= i ){
        int cnt = (a-i) * 2 + (b-a) + 1;
        //cout <<"d "<< now * cnt + (1-now) * (cnt+b+1) << endl;
        ans = min(ans, now * cnt + (1-now) * (cnt+b+1));
      }
      now *= p;
    }
    //cout <<"d "<<now * (b-a+1) + (1-now) * (b-a+1+b+1) << endl;
    ans = min(ans, now * (b-a+1) + (1-now) * (b-a+1+b+1) );
    printf("Case #%d: %.6lf\n",times,ans);
  }
  return 0;
}


