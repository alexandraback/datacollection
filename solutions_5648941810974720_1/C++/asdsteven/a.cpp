#include <cstdio>

char s[2001], t[128];
int a[10];

void solve() {
  scanf("%s", s);
  for (char c = 'A'; c <= 'Z'; c++)
    t[c] = 0;
  for (int i = 0; i < 10; i++)
    a[i] = 0;
  for (int i = 0; s[i]; i++)
    t[s[i]]++;
  a[0] = t['Z'];
  t['Z'] -= a[0];
  t['E'] -= a[0];
  t['R'] -= a[0];
  t['O'] -= a[0];
  a[8] = t['G'];
  t['E'] -= a[8];
  t['I'] -= a[8];
  t['G'] -= a[8];
  t['H'] -= a[8];
  t['T'] -= a[8];
  a[6] = t['X'];
  t['S'] -= a[6];
  t['I'] -= a[6];
  t['X'] -= a[6];
  a[7] = t['S'];
  t['S'] -= a[7];
  t['E'] -= a[7];
  t['V'] -= a[7];
  t['E'] -= a[7];
  t['N'] -= a[7];
  a[5] = t['V'];
  t['F'] -= a[5];
  t['I'] -= a[5];
  t['V'] -= a[5];
  t['E'] -= a[5];
  a[2] = t['W'];
  t['T'] -= a[2];
  t['W'] -= a[2];
  t['O'] -= a[2];
  a[4] = t['F'];
  t['F'] -= a[4];
  t['O'] -= a[4];
  t['U'] -= a[4];
  t['R'] -= a[4];
  a[3] = t['T'];
  t['T'] -= a[3];
  t['H'] -= a[3];
  t['R'] -= a[3];
  t['E'] -= a[3];
  t['E'] -= a[3];
  a[9] = t['I'];
  t['N'] -= a[9];
  t['I'] -= a[9];
  t['N'] -= a[9];
  t['E'] -= a[9];
  a[1] = t['O'];
  t['O'] -= a[1];
  t['N'] -= a[1];
  t['E'] -= a[1];
  for (int i = 0; i <= 9; i++)
    for (int j = 0; j < a[i]; j++)
      putchar(i + '0');
  putchar('\n');
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; i++) {
    printf("Case #%d: ", i);
    solve();
  }
}
