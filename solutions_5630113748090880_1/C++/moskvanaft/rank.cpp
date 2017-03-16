#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  size_t N;
  cin >> N;
  for (size_t k = 1; k <= N; ++k) {
    size_t n;
    cin >> n;
    vector<int> v(2501);
    for (size_t i = 0; i < n*(2*n-1); ++i) {
      size_t x;
      cin >> x;
      ++v[x];
    }
    cout << "Case #" << k << ":";
    for (size_t i = 1; i <= 2500; ++i) {
      if (v[i]%2) {
	cout << ' ' << i;
      }
    }
    cout << endl;
  }
}
