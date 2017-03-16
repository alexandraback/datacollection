#include <bits/stdc++.h>

using namespace std;

int k, c, s;

void solve() {
  for (int i=1;i<=s;i++) cout << i<< " ";
}

int main() {
  ios_base::sync_with_stdio(false);
  freopen("D-small-attempt1.in", "r", stdin);
  freopen("ki.txt", "w", stdout);
  int t;
  cin >> t;
  for (int i=0;i<t;i++) {
    cin >> k>>c>>s;
    cout << "Case #" << i+1<<": ";
    solve();
    cout<<endl;
  }
  return 0;
}
