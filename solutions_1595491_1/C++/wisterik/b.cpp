#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

#define rep(i,n) for(int i = 0; i < n; i++)
#define SZ(v) ((int)(v).size())
#define pb push_back
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef vector<int> vi;

int solve(int n, int s, int p, vi v){

  int ans = 0;
  int can = 0;
  
  rep(i,n){
    int x = v[i];
    if(x == 0) ans += p == 0;
    else if(x == 1) ans += p <= 1;
    else if(x >= 29) ans++;
    else {
      int m = x%3;
      int y,z;
      if(m == 0){
        y = x/3+1;
        z = x/3;
      }
      else if(m == 1){
        y = x/3+1;
        z = x/3+1;
      }
      else {
        y = x/3+2;
        z = x/3+1;
      }
      if(y >= p && z >= p) { ans++; }
      else if (y < p && z < p) { continue; }
      else { can++; }
    }
  }

  return ans + min(s, can);
}

int main(){

  int t;
  cin >> t;

  rep(i,t){
    int n,s,p;
    cin >> n >> s >> p;
    vi v(n);
    rep(j,n) cin >> v[j];

    int ans = solve(n,s,p,v);

    cout << "Case #" << i+1 << ": " << ans << endl;
  }
  return 0;

}
