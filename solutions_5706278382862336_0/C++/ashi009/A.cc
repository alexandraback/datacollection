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
    set<long long> met;
    string n;
    int count = 0;
    while (p) {
      // if (met.find(p) != met.end()) {
      //   n.clear();
      //   break;
      // }
      p <<= 1;
      n += '0' + p / q;
      // met.insert(p);
      p = p % q;
      count++;
      if (count > 60) {
        n.clear();
        break;
      }
    }
    cout << "Case #" << CASE << ": ";
    if (n.size())
      cout << (find(n.begin(), n.end(), '1') - n.begin()) + 1 << endl;
    else
      cout << "impossible" << endl;
  }
  return 0;
}
