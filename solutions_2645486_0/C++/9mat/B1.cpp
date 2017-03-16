#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <utility>
#include <vector>
#include <iterator>
#include <map>
#include <set>
#include <algorithm>
#include <list>

#define FOR(i,n) for(int i = 0, n_ = (n); i<n_; i++)
#define ITER(it, lst) for(typeof((lst).begin()) it = (lst).begin(); it != (lst).end(); ++it)

using namespace std;

inline void updatemax(int &a, int b) { if(a<b) a = b; }
inline void updatemin(int &a, int b) { if(a>b) a = b; }

#define MAXE 6
#define MAXN 12

int C[MAXN][MAXE];
int N, R, E, v[MAXN];

void prepare(){
  FOR(k,N+1) FOR(e, E+1) C[k][e] = -1;
  C[0][E] = 0;
}

long dp(int k, int e){
  if(k==0 || C[k][e] > 0) return C[k][e];
  if(e==E){
    FOR(j, R+1) for(int e1 = E+j-R; e1<=E; e1++) {
      if(e1<j || dp(k-1,e1) < 0) continue;
      updatemax(C[k][e], dp(k-1,e1) + v[k]*j);
    }
    return C[k][e];
  }
  FOR(j, E+R-e+1){
    int e1 = e+j-R;
    if(e1<j || e1 > E || dp(k-1,e1) < 0) continue;
    updatemax(C[k][e], dp(k-1,e1) + v[k]*j);
  }
  return C[k][e];
}

int main(){
  int T;
  cin>>T;

  FOR(t,T){
    cin>>E>>R>>N;
    FOR(k,N) cin>>v[k+1];
    prepare();
    dp(N, R);
    cout<<"Case #"<<t+1<<": "<<C[N][R]<<endl;
  }
  return 0;
}
