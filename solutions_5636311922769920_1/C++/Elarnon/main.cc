#include <cstdio>

void solve(long K, long C, long S)
{
  if (C * S < K) {
    printf("IMPOSSIBLE\n");
    return;
  }

  long curpos = 0;
  while (curpos < K) {
    long nb = 0;
    for (long i = 0; i < C && curpos < K; ++i)
      nb = nb * K + curpos++;
    printf("%ld ", nb + 1);
  }
  printf("\n");
}

int main()
{
  long T;
  scanf("%ld ", &T);
  for (long i = 0; i < T; ++i) {
    long K, C, S;
    scanf("%ld %ld %ld ", &K, &C, &S);
    printf("Case #%ld: ", i+1);
    solve(K, C, S);
  }
  return 0;
}
