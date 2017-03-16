#include <bits/stdc++.h>

using namespace std;

#define upto(i,n) for (int i = 0; i<n; ++i)

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MAX = 1000;
const ll MOD = 1000000007;



void solve() {
  int r,c,w;
  cin >> r >> c >> w;

  int res = 0;
  res = c/w * r;
  
  res += c%w==0? w-1 :w ;

  cout << res << endl;

}

int main() {
  int t;

  cin >> t;
  for ( int tc = 1; tc<=t; ++tc) {
    cout << "Case #" << tc<< ": ";
    solve();
  }
  return 0;
}
