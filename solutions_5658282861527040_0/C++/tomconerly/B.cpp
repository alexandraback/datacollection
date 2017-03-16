#include <bitset>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bitset<64> bA, bB, bK;

int64_t DP[40][2][2][2];

int64_t solve(int bit, bool ltA, bool ltB, bool ltK) {
  if (bit == -1) {
    return ltA && ltB && ltK ? 1 : 0;
  }
  auto& ans = DP[bit][ltA][ltB][ltK];
  if (ans != -1) {
    return ans;
  }
  ans = 0;
  for (int a = 0; a <= 1; a++) {
    for (int b = 0; b <= 1; b++) {
      if (a == 1 && !ltA && !bA[bit])
        continue;
      if (b == 1 && !ltB && !bB[bit])
        continue;
      if (a == 1 && b == 1 && !ltK && !bK[bit])
        continue;
      ans += solve(bit - 1, ltA || (a == 0 && bA[bit]),
                   ltB || (b == 0 && bB[bit]),
                   ltK || ((a == 0 || b == 0) && bK[bit]));
    }
  }
  return ans;
}

int main() {
  int T;
  cin >> T;
  for (int zz = 1; zz <= T; zz++) {
    int64_t A, B, K;
    cin >> A >> B >> K;
    bA = bitset<64>(A);
    bB = bitset<64>(B);
    bK = bitset<64>(K);
    for (int i = 0; i < 40; i++) {
      for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 2; k++) {
          for (int l = 0; l < 2; l++) {
            DP[i][j][k][l] = -1;
          }
        }
      }
    }
    int64_t ans = solve(39, false, false, false);
    cout << "Case #" << zz << ": " << ans << endl;
  }
}
