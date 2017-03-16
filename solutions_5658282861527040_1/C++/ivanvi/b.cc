#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

#define BIT(a, b) (((a) >> (b)) & (1))

LL F[32][2][2][2];

LL dp(int pos, int flag_a, int flag_b, int flag_c, int a, int b, int c);

int main(void) {
  int t;
  int case_cnt = 1;
  scanf("%d", &t);
  while (t--) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    a--;
    b--;
    c--;
    memset(F, -1, sizeof(F));
    LL res = dp(30, 1, 1, 1, a, b, c);
    printf("Case #%d: %lld\n", case_cnt++, res); 
  }
  return 0;
}

LL dp(int pos, int flag_a, int flag_b, int flag_c, int a, int b, int c) {
  if (pos < 0) return 1;
  if (F[pos][flag_a][flag_b][flag_c] != -1) return F[pos][flag_a][flag_b][flag_c];

  LL res = 0;
  for (int i = 0; i < ((flag_a && !BIT(a, pos)) ? 1 : 2); i++)
  for (int j = 0; j < ((flag_b && !BIT(b, pos)) ? 1 : 2); j++) {
    int x = (i & j);
    if (flag_c == 1 && !BIT(c, pos) && x == 1) continue;
    int flag = (flag_c == 1 && BIT(c, pos) > x) ? 0 : flag_c;
    res += dp(pos - 1, (BIT(a, pos) && i == 0) ? 0 : flag_a, (BIT(b, pos) && j == 0) ? 0 : flag_b, flag, a, b, c);
  }

  return F[pos][flag_a][flag_b][flag_c] = res;
}

