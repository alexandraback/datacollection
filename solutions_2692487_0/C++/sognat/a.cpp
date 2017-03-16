#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;

const int MAXN = 100;
LL sizes[MAXN+1];
int N;
LL A, B;
int result;
int new_res;

int main() {
  int T;
  scanf("%d", &T);

  for (int Z = 1; Z <= T; Z++) {
    scanf("%lld%d", &A, &N);

    for (int i = 0; i < N; i++) {
      scanf("%lld", &sizes[i]);
    }
    sort(sizes, sizes+N);

    result = N;
    new_res = 0;

    for (int i = 0; i < N; i++) {
      B = sizes[i];
      while (A <= B && A > 1) {
        A += A-1;
        new_res++;
      }
      if (A > B) {
        A += B;
        result = min(result, new_res + N-i-1);
      }
    }

    printf("Case #%d: %d\n", Z, result);
  }
  return 0;

}
