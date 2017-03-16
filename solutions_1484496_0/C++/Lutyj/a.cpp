#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 20;

long long S[MAXN];
int N, n1, s1[MAXN], n2, s2[MAXN];
long long sum;

bool rec(int d)
{
  if (n1 > 0 && sum == 0) {
    long long res = 0;

    printf("\n");
    for (int i = 0; i < n1; ++i) { printf("%d ", S[s1[i]]); res += S[s1[i]]; }
    printf("\n");
    for (int i = 0; i < n2; ++i) { printf("%d ", S[s2[i]]); res -= S[s2[i]]; }
    printf("\n");

    //printf("%lld\n", res);
    return true;
  }

  if (d >= N) return false;

  s1[n1++] = d; sum -= S[d];
  if (rec(d+1)) return true;
  --n1; sum += S[d];

  s2[n2++] = d; sum += S[d];
  if (rec(d+1)) return true;
  --n2; sum -= S[d];

  if (rec(d+1)) return true;

  return false;
}

int main()
{
  int T; scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);

    for (int i = 0; i < N; ++i) scanf("%lld", &S[i]);

    printf("Case #%d:", t+1); sum = 0; n1 = 0; n2 = 0;
    if (!rec(0)) printf(" Impossible\n");
  }

  return 0;
}
