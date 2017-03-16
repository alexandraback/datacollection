#include<bits/stdc++.h>
using namespace std;
#define FWD(i, a, b) for(int i = (a); i < (b); i++)
typedef pair<int, int> PII;
typedef long long LL;
#define st first
#define nd second
struct {
  int D;
  LL M;
} hikers[2];
int main(){
  int T;
  ios_base::sync_with_stdio(0);
  cin >> T;
  FWD(t, 1, T+1){
    int n_hikers = 0;
    int n;
    cin >> n;
    FWD(i,0,n){
      int D, M, H;
      cin >> D >> H >> M;
      FWD(j, 0, H){
        hikers[n_hikers].D = D;
        hikers[n_hikers].M = M + (LL)j;
        n_hikers++;
      }
    }
    int res;
    if(n_hikers == 1){
      res = 0;
    } else {
      if(n_hikers != 2) {res = -1; goto done;}
      if(hikers[0].M == hikers[1].M) {res = 0; goto done;}
      if(hikers[0].M > hikers[1].M) swap(hikers[0], hikers[1]);
      
      
      LL d0 = hikers[0].D - 360;
      LL d1 = hikers[1].D;
      LL m0 = hikers[0].M;
      LL m1 = hikers[1].M;
#define VAR(x) #x << " " << x << " "
      //cout << VAR(d0) << VAR(d1) << VAR(m0) << VAR(m1) << endl;
      if(d0 * (m1-m0) + (d1-d0)*m1 > 360 * (m1-m0)) res = 0;
      else res = 1;
      
      
      
    }
  done:
    cout << "Case #" << t << ": " << res << endl;
  }

}
