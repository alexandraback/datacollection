#include <iostream>

using namespace std;

void solve() {
  double c, f, x;
  cin >> c >> f >> x;
  double acc = 0;
  double best = 1e30;
  for(double k = 2;; k += f){
    if(x / k + c * acc < best){
      best = x / k + c * acc;
      acc += 1 / k;
    }else break;
  }
  cout << best;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(9);
  int t;
  cin >> t;
  for(int i = 1; i <= t; ++i){
    cout << "Case #" << i << ": ";
    solve();
    cout << '\n';
  }
}
