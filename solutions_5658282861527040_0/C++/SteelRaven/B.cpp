#include <iostream>

using namespace std;

void solve() {
  long long a, b, k;
  cin >> a >> b >> k;
  long long res = 0;
  for(int i = 0; i < a; ++i)
    for(int j = 0; j < b; ++j)
      if((i & j) < k) ++res;
  cout << res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tests;
  cin >> tests;
  for(int test = 1; test <= tests; ++test){
    cout << "Case #" << test << ": ";
    solve();
    cout << '\n';
  }
}
