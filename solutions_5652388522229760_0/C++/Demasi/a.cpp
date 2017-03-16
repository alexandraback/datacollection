#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <vector>

using namespace std;

int main() {
  int T;
  long long N;

  scanf("%d", &T);
  for(int caso = 1; caso <= T; caso++) {
    scanf("%lld", &N);

    if (N == 0) {
      printf("Case #%d: INSOMNIA\n", caso);
      continue;
    }

    vector<int> f(10, 0);
    int c = 0;
    long long last = N;

    for(int i = 1; c < 10; i++) {
      long long x = (long long)i*N;
      last = x;
      while(x > 0) {
        if (!f[x%10]) c++;
        f[x%10] = 1;
        x /= 10;
      }
    }

    printf("Case #%d: %lld\n", caso, last);
  }
  return 0;
}

