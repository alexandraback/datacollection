// Copyright
// @author: Ruben S. Andrist
// @date: 2015-05-10
// @email: andrist@gmail.com

#include <cassert>
#include <cstdio>
#include <cmath>

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

template <class T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  out << "[";
  bool first = true;
  for (auto &x : v) {
    if (first) first=false;
    else out << ", ";
    cout << x;
  }
  return out << "]";
}

int main() {
  int T=0;
  assert(scanf("%d", &T) == 1);
  for (int t=1; t<=T; t++) {
    printf("Case #%d: ", t);

    int R=0, C=0, W=0;
    assert(scanf(" %d %d %d", &R, &C, &W)==3);

    // first we must remove all other rows. The optimal strategy for little
    // brother is always to put the ship on the last row remaining possible.
    int moves = 0;
    if (R>1) {
      moves += (R-1) * int(C/W);
      R = 1;
      // printf("%d * %d = %d for other rows\n", R-1, C/W, moves);
    }

    // now we must get the ship guessing right
    if (C>=2*W) {
      moves += int(C/W)-1;
      // printf("%d to reduce C to %d (for a sure hit)", int(C/W)-1, (int(C/W)-1)*W);
      C -= (int(C/W)-1)*W;
    }

    if (W==1) {
      // special case for with of 1, if we hit it immediately sinks
      // (don't need to figure out the length).
      moves += 1;
    } else if (W==C) {
      // if the ship just fits in the remaining fields, no need to figure
      // out its length.
      moves += W;
    } else {
      // otherwise we will miss once more to find the exact position.
      moves += W+1;
    }

    printf("%d\n", moves);
  }

  return 0;
}

// vim: set ff=unix ai tw=80 ts=2 sts=2 sw=2 et:
