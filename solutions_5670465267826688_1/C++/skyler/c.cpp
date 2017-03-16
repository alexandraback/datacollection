#include <stdio.h>

#define MAX 233333

int n, len;
long long m;
char s[MAX];
int pre[MAX];
int mulTable[5][5] = {
  {},
  {0, 1, 2, 3, 4},
  {0, 2, -1, 4, -3},
  {0, 3, -4, -1, 2},
  {0, 4, 3, -2, -1},
};

bool isSingleChar() {
  for (int i = 1; i < n; i++) {
    if (s[i] != s[0]) {
      return false;
    }
  }
  return true;
}

bool judge() {
  bool visi = false, flag = false;
  for (int i = 0; i < len - 1; i++) {
    if (pre[i] == 4) {
      flag = true;
      if (visi) return true;
    }
    if (pre[i] == 2) {
      visi = true;
    }
  }
  return false;
}

bool notEqual() {
  if (pre[len - 1] == -1) return !(m % 2);
  if (pre[len - 1] != 1) return !(m % 4 == 2);
  return true;
}

int mul(int x, int y) {
  int sign = 1;
  if (x < 0) x = -x, sign = -sign;
  if (y < 0) y = -y, sign = -sign;
  return sign * mulTable[x][y];
}

void preAdd(int l, int r) {
  len = 0;
  for (int i = 0; i < l + 1; i++) {
    for (int j = 0; j < n; j++) {
      if (!len) {
        pre[len] = s[j] - 'g';
      } else {
        pre[len] = mul(pre[len - 1], s[j] - 'g');
      }
      len++;
    }
  }
  if (r) len++;
}

int exp(int x, long long p) {
  if (x == 1) return 1;

  p = p % 4;
  if (p == 1) return x;
  if (p == 2) return -1;
  if (p == 3) return -x;
  else return 1;
}

void Debug() {
  for (int i = 0; i < n + 2; i++) {
    printf("%d ", pre[i]);
  }
  puts("");
  puts("");
}

bool solve1() {
  if (isSingleChar()) return false;
  preAdd(0, m - 1);
  if (pre[len - 1] != -1) return false;
  return judge();
}

bool solve() {
  if (isSingleChar()) return false;
  preAdd(0, 0);
  if (notEqual()) return false;

  for (int i = 0; i <= 4; i++) {
    if ((long long)i > m - 1) continue;

    long long j = (m - 1 - (long long)i);
    if (j > 4) {
      j %= 4;
      if (!j) j += 4;
    }

    preAdd(i, j);

    if (judge()) return true;
  }

  return false;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; i++) {
    scanf("%d%lld", &n, &m);
    scanf("%s", s);
    printf("Case #%d: %s\n", i, solve() ? "YES" : "NO");
  }
  return 0;
}
