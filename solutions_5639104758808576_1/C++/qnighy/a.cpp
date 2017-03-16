// C++11
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int T; scanf("%d", &T);
  for(int tci = 0; tci < T; ++tci) {
    int Smax;
    char S[1002];
    scanf("%d %1001s", &Smax, S);
    int maxval = 0;
    int sum = 0;
    for(int i = 0; i <= Smax; ++i) {
      maxval = max(maxval, i-sum);
      sum += S[i]-'0';
    }
    printf("Case #%d: %d\n", tci+1, maxval);
  }
  return 0;
}
