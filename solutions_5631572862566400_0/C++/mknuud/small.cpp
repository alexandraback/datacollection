#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

bool valid(const vector<uint>& F, const vector<uint>& chain, uint len) {
  assert(len > 0 && len <= chain.size());
  for (uint i = 0; i < len; i++) {
    uint left = (i == 0 ? (len - 1) : (i - 1));
    uint right = (i + 1 < len ? i + 1 : 0);
    uint ci = chain[i];
    uint Fci = F[ci];
    if (Fci != chain[left] && Fci != chain[right]) {
      return false;
    }
  }
  return true;
}

void dw(uint caseNo) {
  uint N;
  cin >> N;

  vector<uint> F;
  for (uint i = 0; i < N; i++) {
    uint Fi;
    cin >> Fi;
    F.push_back(Fi - 1);
  }

  vector<uint> perm;
  for (int i = 0; i < N; i++) {
    perm.push_back(i);
  }

  uint ans = 0;
  do {
    uint len = perm.size();
    while (!valid(F, perm, len)) {
      len--;
      if (len == 0 || len < ans) {
        break;
      }
    }
    ans = max(ans, len);
  } while (next_permutation(perm.begin(), perm.end()));

  cout << "Case #" << caseNo << ": " << ans << endl;
}

int main() {
  uint T;
  cin >> T;
  for (uint t = 0; t < T; t++) {
    dw(t + 1);
  }
  return 0;
}
