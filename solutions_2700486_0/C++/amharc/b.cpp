#include <cstdio>
#include <cmath>

long long count_blocks_upto(int lev) {
  long long blk = 0;
  for(int i = 0; i <= lev; ++i) {
    blk += 4 * i + 1;
  }

  return blk;
}

double newton[1000005];

void gen_newton(int N) {
  newton[0] = pow(2, -N);
  for(int i = 1; i <= N / 2; ++i)
    newton[i] = newton[i - 1] * (N - i + 1) / i;

  for(int i = N / 2 + 1; i <= N; ++i)
    newton[i] = newton[N - i];
}

double testcase() {
  int X, Y, N;
  scanf("%d%d%d", &N, &X, &Y);

  if(X < 0)
    X = -X;

  int lev = (X + Y) / 2;

  if(count_blocks_upto(lev - 1) >= N)
    return 0;
  if(count_blocks_upto(lev) <= N)
    return 1;

  if(X == 0)
    return 0;

  N -= count_blocks_upto(lev - 1);
  gen_newton(N);

  double res = 0;

  for(int right = 0; right <= N; ++right) {
    int cnt = right;

    if(right > 2 * lev)
      cnt = 2 * lev;

    if(N - right > 2 * lev)
      cnt += N - right - 2 * lev;

    if(cnt > Y)
      res += newton[right];
  }
  
  return res;
}

int main() {
  int T;
  scanf("%d", &T);
  for(int i = 1; i <= T; ++i) {
    double res = testcase();
    printf("Case #%d: %.8lf\n", i, res);
  }
}
