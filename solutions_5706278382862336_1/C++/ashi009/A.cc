#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int CASE = 1; CASE <= T; CASE++) {
    long long p, q;
    char ch;
    cin >> p >> ch >> q;
    string n;
    while (p) {
      p <<= 1;
      n += '0' + p / q;
      p = p % q;
      if (n.size() > 64) {
        n.clear();
        break;
      }
    }
    cout << "Case #" << CASE << ": ";
    if (!n.empty())
      cout << (find(n.begin(), n.end(), '1') - n.begin()) + 1 << endl;
    else
      cout << "impossible" << endl;
  }
  return 0;
}
