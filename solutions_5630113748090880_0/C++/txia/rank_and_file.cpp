#include <iostream>
#include <set>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    int n, m;
    cin >> n;
    set<int> s;
    for (int j = 0; j < n*(2*n-1); ++j) {
      cin >> m;
      auto it = s.find(m);
      if (it == s.end())
        s.insert(m);
      else
        s.erase(it);
    }
    cout << "Case #" << i << ":";
    for (auto m : s) {
      cout << " " << m; 
    }
    cout << endl;
  }
}
