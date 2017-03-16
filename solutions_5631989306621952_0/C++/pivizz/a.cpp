#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;
using U = uint64_t; using I = int64_t; using UU = pair<U, U>; using II = pair<I, I>; using VI = vector<I>; using VU = vector<U>;

string solve(string& S) {
  string n;
  char b = 'A';
  for (char c : S) {
    if (c >= b)
      n = string(1, c) + n;
    else
      n = n + string(1, c);
    b = max(b, c);
  }
  return n;
}

int main() {
  U T;
  cin >> T;
  for (U i = 0; i < T; i++) {
    string S;
    cin >> S;
    cout << "Case #" << i+1 << ": " << solve(S) << endl;
  }
  return 0;
}
