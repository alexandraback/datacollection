#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>

#define rep(i,n) for(int i = 0; i < n; i++)
#define SZ(v) ((int)(v).size())
#define pb push_back
#define all(v) (v).begin(), (v).end()

#define trace(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef vector<int> vi;

int a,b;
vector<double> p;


double solve(int i){
  double x = 1;
  rep(j, i){
    x *= p[j];
  }

  return b-i+1 + (b+1) * (1-x);
}

int main(){

  int t;
  cin >> t;

  rep(i,t){
    cin >> a >> b;
    p = vector<double>(a);
    rep(j,a) cin >> p[j];

    double ans = b+2;

    for(int j = 0; j <= a; j++){
      double tmp = solve(a-j) + j;
      //trace(tmp);
      ans = min(ans, tmp);
    }

    cout << fixed << setprecision(8);
    cout << "Case #" << i+1 << ": " << ans << endl;
  }
  return 0;

}
