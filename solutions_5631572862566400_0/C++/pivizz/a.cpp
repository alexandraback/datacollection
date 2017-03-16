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
using VUU = vector<UU>;

U solve(const VU& bff) {
  U N = bff.size();
  map<UU, U> m2;
  set<U> f;
  U r1 = 0;
  U r2 = 0;
  for (U i = 0; i < N; i++)
  {
    f.insert(bff[i]);
  }

  
  for (U i = 0; i < N; i++) {
    U x = i;
    U blast = N+1;
    set<U> prev;
    prev.insert(x);
    while (prev.count(bff[x]) == 0) {
      prev.insert(bff[x]);
      blast = x;
      x = bff[x];
    } 

    if (blast == bff[x]) {
      UU pr = UU(x, bff[x]);
      if (m2[pr] < prev.size()) {
        r2 += prev.size() - m2[pr];
        m2[pr] = prev.size();
      }
    } else if (bff[x] == i) {
      r1 = max(r1, (U)prev.size());
    }
  }

  return max(r1, r2 - m2.size());
}


int main() {
  U T;
  cin >> T;
  for (U i = 0; i < T; i++) {
    U N;
    cin >> N;
    VU bff(N);
    for (U j = 0; j < N; j++) { cin >> bff[j]; bff[j]--; }
    cout << "Case #" << i+1 << ": " << solve(bff) << endl;
  }
  return 0;
}
