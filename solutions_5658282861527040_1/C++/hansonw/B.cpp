#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

vector<int> abits, bbits, kbits;
vector<int> makeBits(int N) {
  vector<int> bits;
  while (N) {
    bits.push_back(N & 1);
    N >>= 1;
  }
  return bits;
}

typedef long long ll;
ll dp[32][2][2][2];

ll go(int pos, int lta, int ltb, int ltk) {
  if (pos == -1) {
    return lta && ltb && ltk;
  }

  ll& ans = dp[pos][lta][ltb][ltk];
  if (ans != -1) return ans;

  ans = 0;
  int am = (pos < abits.size() ? lta || abits[pos] : 0);
  int bm = (pos < bbits.size() ? ltb || bbits[pos] : 0);
  for (int a = 0; a <= am; a++) 
    for (int b = 0; b <= bm; b++) {
      if (a && b && pos >= kbits.size()) continue;
      if (ltk || (a&b) <= kbits[pos]) {
        ans += go(
          pos-1,
          lta || (pos < abits.size() && a < abits[pos]),
          ltb || (pos < bbits.size() && b < bbits[pos]),
          ltk || (pos < kbits.size() && (a&b) < kbits[pos])
        );
      }
    }

  return ans;
}

int main() {
  int T; cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    int A, B, K; cin >> A >> B >> K;

    abits = makeBits(A);
    bbits = makeBits(B);
    kbits = makeBits(K);

    int mx = max(abits.size(), max(bbits.size(), kbits.size()));

    memset(dp, -1, sizeof dp);
    ll ans = go(mx-1, 0, 0, 0);

    printf("Case #%d: %lld\n", tt, ans);
  }
}
