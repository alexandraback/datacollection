#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int t; cin >> t;
  for (int test = 1; test <= t; ++test) {
    int smax; string s;
    cin >> smax >> s;
    vector<int> counts;
    for (int i = 0; i <= smax; ++i) {
      counts.push_back(s[i] - '0');
    }
    int additional = 0;
    int clapping = 0;
    for (int i = 0; i <= smax; ++i) {
      while (clapping < i) { additional++; clapping++; }
      clapping += counts[i];
    }

    cout << "Case #" << test << ": " << additional << endl;
  }
  return 0;
}