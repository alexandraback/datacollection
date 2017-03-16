#include <cstdio>
#include <array>

template<int k>
bool allseen(const std::array<bool, 10>& seen) {
  return seen[k] && allseen<k-1>(seen);
}

template<>
bool allseen<0>(const std::array<bool, 10>& seen) {
  return seen[0];
}

void solve(long N)
{
  if (N == 0) {
    printf("INSOMNIA\n");
    return;
  }

  std::array<bool, 10> seen {};

  long nb = N;
  while (true) {
    long temp = nb;
    while (temp) {
      seen[temp % 10] = true;
      temp /= 10;
    }
    // if (seen[0] && seen[1] && seen[2] && seen[3] && seen[4] && seen[5] && seen[6] && seen[7] && seen[8] && seen[9]) {
    if (allseen<9>(seen)) {
      printf("%ld\n", nb);
      return;
    }
    nb += N;
  }
}

int main()
{
  long T;
  scanf("%ld ", &T);
  for (long i = 0; i < T; ++i) {
    long N;
    scanf("%ld ", &N);
    printf("Case #%ld: ", i+1);
    solve(N);
  }
  return 0;
}
