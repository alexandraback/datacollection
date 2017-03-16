#include <algorithm>
#include <ios>
#include <iostream>
#include <istream>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#define debug(x) do { cerr << #x << " = " << x << endl; } while(0)

using namespace std;

void solve(int tid) {
  string s; cin >> s;
  vector<char> sol{s[0]};
  for (size_t i = 1; i < s.size(); ++i) {
    if (s[i] >= sol[0]) {
      sol.insert(sol.begin(), s[i]);
    } else {
      sol.push_back(s[i]);
    }
  }

  string result{sol.begin(), sol.end()};
  cout << "Case #" << tid << ": " << result << endl;
}

int main() {
  cout.precision(8); cout.setf(ios_base::showpoint);
  int t; cin >> t;

  for (int i = 1; i <= t; ++i) {
    solve(i);
  }

  return 0;
}
