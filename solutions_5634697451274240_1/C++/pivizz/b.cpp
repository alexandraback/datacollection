#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

int solve(const string& s) {
  char state = '+';
  int flips = 0;
  for (char c : s) {
    if (c == state) continue;
    if (c == '-')
      flips++;
    state = c;
  }
  return 2 * flips - (state == '-' ? 1 : 0);
}

int main(int argc, char* argv[]) {
  uint64_t T;
  fstream f(argv[1]);
  f >> T;
  for (int i = 0; i < T; i++) {
    string s;
    f >> s;
    std::reverse(s.begin(), s.end());
    cout << "Case #" << (i+1) << ": " << solve(s) << endl;
  } 
  return 0;
}
