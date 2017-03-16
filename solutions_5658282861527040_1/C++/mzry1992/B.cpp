#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int A, B, K;
long long mem[31][2][2][2];
long long DP(int pos, int ua, int ub, int uk) {
  if (pos == 31) {
    return 1;
  }
  if (mem[pos][ua][ub][uk] >= 0) {
    return mem[pos][ua][ub][uk];
  }

  long long &ans = mem[pos][ua][ub][uk];
  ans = 0;

  int nowPos = 30 - pos;

  int edA = (ua == 1) ? ((A >> nowPos) & 1) : 1; 
  int edB = (ub == 1) ? ((B >> nowPos) & 1) : 1;
  int edK = (uk == 1) ? ((K >> nowPos) & 1) : 1;

  for (int a = 0; a <= edA; a++) {
    for (int b = 0; b <= edB; b++) {
      int k = (a & b);
      if (k <= edK) {
        ans += DP(pos + 1, (ua == 1) && (a == ((A >> nowPos) & 1)), 
                           (ub == 1) && (b == ((B >> nowPos) & 1)),
                           (uk == 1) && (k == ((K >> nowPos) & 1)));
      }
    }
  }
  return ans;
}

int main() {
  freopen("B-large.in", "r", stdin);
  freopen("B-large.out", "w", stdout);
  int totCas;
  scanf("%d", &totCas);
  for (int cas = 1; cas <= totCas; cas++) {
    scanf("%d%d%d", &A, &B, &K);
    A--;
    B--;
    K--;
    memset(mem, -1, sizeof(mem));
    printf("Case #%d: %lld\n", cas, DP(0, 1, 1, 1));
  }
	return 0;
}

