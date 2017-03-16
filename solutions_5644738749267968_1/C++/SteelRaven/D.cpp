#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solveWar(int n, const vector < double > & naomis, const vector < double > & kens) {
  int nPtr = n - 1;
  int kPtr = n - 1;
  int cnt = 0;
  int res = 0;
  while(nPtr >= 0 && kPtr >= 0){
    if(naomis[nPtr] > kens[kPtr]){
      if(cnt == 0) ++res;
      else --cnt;
      --nPtr;
    }else{
      ++cnt;
      --kPtr;
    }
  }
  cout << res;
}

void solveDeceitfulWar(int n, const vector < double > & naomis, const vector < double > & kens) {
  int nPtr = 0;
  int kPtr = 0;
  int res = 0;
  while(nPtr < n && kPtr < n){
    if(naomis[nPtr] < kens[kPtr]){
      ++nPtr;
    }else{
      ++res;
      ++kPtr;
      ++nPtr;
    }
  }
  cout << res;
}

void solve() {
  int n;
  cin >> n;
  vector < double > naomis(n);
  vector < double > kens(n);
  for(int i = 0; i < n; ++i)
    cin >> naomis[i];
  for(int i = 0; i < n; ++i)
    cin >> kens[i];
  sort(naomis.begin(), naomis.end());
  sort(kens.begin(), kens.end());
  solveDeceitfulWar(n, naomis, kens);
  cout << ' ';
  solveWar(n, naomis, kens);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for(int i = 1; i <= t; ++i){
    cout << "Case #" << i << ": ";
    solve();
    cout << '\n';
  }
}
