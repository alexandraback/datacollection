#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define all(c) (c).begin(), (c).end()
const int inf = (1<<28);

int main() {
  int t; cin >> t;
  for(int cs=1; cs<=t; cs++) {
    int n; cin >> n;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    int total=0; rep(i,n) total+=v[i];
    vector<double> ans(n);
    
    rep(i, n) {
      double lb=v[i], ub=inf;
      rep(k, 100) {
        double m = (lb+ub)/2.0;
        double x = 0.0;
        rep(j, n) {
          if(v[j]>=m || i==j) continue;
          x+=(m-v[j])/total;
        }
        if(x>1.0) ub=m;
        else if(m>=v[i]+(1-x)*total) ub=m;
        else lb=m;
      }
      ans[i]=(lb-v[i])/total;
    }
    
    printf("Case #%d:", cs);
    rep(i, n) printf(" %.8lf", ans[i]*100);
    printf("\n");
  }
  return 0;
}
