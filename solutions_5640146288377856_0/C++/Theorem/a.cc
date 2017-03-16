#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <limits>
using namespace std;


void solve(int CASE) {
  int R, C, W;
  cin >> R >> C >> W;

  uint64_t moves = 0;
  uint64_t jumps = C/W;

  moves += jumps * (R-1);

  moves += jumps + W;
  if ((C%W) == 0) moves--;

  cout << "Case #" << CASE << ": " << moves << endl;
}

int main() {
  uint64_t T;

  cin >> T;

  for (uint64_t i = 1; i <= T; i++) {
    solve(i);
  }

  return 0;
}
