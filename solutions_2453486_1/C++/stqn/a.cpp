#include <cstdio>

char nextChar() { char c; scanf(" %c", &c); return c; }
int nextInt() { int tmp; scanf("%d", &tmp); return tmp; }

int win[10] = { 0xf, 0xf0, 0xf00, 0xf000, 0x1111, 0x2222, 0x4444, 0x8888, 0x1248, 0x8421 };

int t = 0;

void solve()
{
  try {
    int X = 0, O = 0;
    for (int i = 0; i < 16; ++i) {
      char c = nextChar();
      if (c == 'T')
        X |= 1 << i, O |= 1 << i;
      else if (c == 'X')
        X |= 1 << i;
      else if (c == 'O')
        O |= 1 << i;
    }
    for (int i = 0; i < 10; ++i)
      if (!(win[i] & ~X))
        throw "X won";
      else if (!(win[i] & ~O))
        throw "O won";
    if ((X | O) == 0xffff)
      throw "Draw";
    else
      throw "Game has not completed";
  } catch (char *s) {
    printf("Case #%d: %s\n", ++t, s);
  }
}

int main()
{
  int T = nextInt();
  while (T --> 0)
    solve();

  return 0;
}
