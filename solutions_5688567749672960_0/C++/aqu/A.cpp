#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <climits>
#include <map>

using namespace std;

const long long int inf = LLONG_MAX;
static const long long limit = 1e6+2;
static long long cache[limit];

long long reverse(long long N) {
  long long result = 0;

  while (N) {
    result *= 10;
    result += N%10;
    N /= 10;
  }

  return result;
}

long long doit(long long N) {

  for (long long i = 2; i < N; ++i) {
    long long rev = reverse(i);
    if (rev > limit) continue;
    cache[i] = min(cache[i], cache[i-1]+1);
    cache[rev] = min(cache[rev], cache[i]+1);
  }

  return N;
}

int main() {
  int T;
  cin >> T;
  cache[1] = 1;
  for (long long i = 1; i < limit-1; ++i)
    cache[i] = i;

  doit(limit);

  for (int t = 1; t <= T; ++t) {
    long long N;
    cin >> N;
    printf("Case #%d: %lld\n", t, cache[N]);
  }
}

