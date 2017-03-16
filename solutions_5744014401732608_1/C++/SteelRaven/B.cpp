#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
  long long b, m;
  cin >> b >> m;
  if(m > 1ll << (b - 2)){
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  cout << "POSSIBLE" << endl;
  vector < string > ans(b, string(b, '0'));
  for(int i = 1; i < b; ++i)
    for(int j = i + 1; j < b; ++j)
      ans[i][j] = '1';
  for(long long i = 0; i + 2 < b; ++i){
    if(m & (1ll << i)) ans[0][b - 2 - i] = '1';
  }
  if(m & (1ll << (b - 2))){
    for(int i = 1; i < b; ++i)
      ans[0][i] = '1';
  }
  for(int i = 0; i < b; ++i)
    cout << ans[i] << endl;
}

int main() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; ++i){
    cout << "Case #" << i << ": ";
    solve();
  }
}
