#include <cstdio>
#include <cassert>
#include <cstring>

using namespace std;

const int maxN = 32;

int nt;
int A, B, K;
long long f[maxN][2][2][2];

long long getF (int i, int fa, int fb, int fk) {
  if (i == -1) {
    return fa && fb && fk;
  }
  long long &res = f[i][fa][fb][fk];
  if (res != -1) {
    return res;
  }
  res = 0;
  int a = (A >> i) & 1;
  int b = (B >> i) & 1;
  int k = (K >> i) & 1;
  for (int aa = 0; aa < 2; ++aa) {
    for (int bb = 0; bb < 2; ++bb) {
      int ab = aa & bb;
      int nfa = fa, nfb = fb, nfk = fk;
      if (!fa) {
        if (aa < a) {
          nfa = 1;
        } else if (aa == a) {
          nfa = 0;
        } else {
          continue;
        }
      }
      if (!fb) {
        if (bb < b) {
          nfb = 1;
        } else if (bb == b) {
          nfb = 0;
        } else {
          continue;
        }
      }
      if (!fk) {
        if (ab < k) {
          nfk = 1;
        } else if (ab == k) {
          nfk = 0;
        } else {
          continue;
        }
      }
      res += getF (i - 1, nfa, nfb, nfk);
    }
  }
  return res;
}

int main () {
  assert (scanf ("%d", &nt) == 1);
  for (int tt = 1; tt <= nt; ++tt) {
    assert (scanf ("%d%d%d", &A, &B, &K) == 3);
    memset (f, -1, sizeof (f));
    printf ("Case #%d: %lld\n", tt, getF (maxN - 1, 0, 0, 0));
  }
  return 0;
}
