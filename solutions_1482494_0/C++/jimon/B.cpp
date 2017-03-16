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

int T,n;
int main(){
  cin >> T;
  REP(times,1,T+1){
    cin >> n;
    vec a1(n), a2(n), stars(n,0);
    rep(i,n){ scanf("%d%d", &a1[i], &a2[i]); }

    int ans = 0, star = 0;
    rep(_count,n<<1){
      bool flag = false;
      rep(i,n)if( stars[i] < 2 && a2[i] <= star ){
        ans++;
        star += 2 - stars[i];
        stars[i] = 2;
        flag = true;
      }
      if( flag ){ continue; }
      int idx = -1;
      rep(i,n)if( stars[i] < 1 && a1[i] <= star ){
        if( idx == -1 || a2[idx] < a2[i] ){ idx = i; }
      }
      if( idx != -1 ){
        ans++;
        star++;
        stars[idx] = 1;
      }
    }

    bool success = true;
    rep(i,n)if(stars[i] != 2 ){ success = false; }

    printf("Case #%d: ",times);
    if( success ){
      cout << ans << endl;
    } else {
      cout << "Too Bad" << endl;
    }
  }
  return 0;
}


