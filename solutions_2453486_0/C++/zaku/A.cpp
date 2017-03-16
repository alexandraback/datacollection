#include <cstdio>
#include <cstring>
using namespace std;

void solve()
{
  static const int kMaxN = 6;
  static char mp[kMaxN][kMaxN];
  static int st[10][2] = { {0,0}, {1,0}, {2,0}, {3,0},
			   {0,0}, {0,1}, {0,2}, {0,3},
			   {0,0}, {0,3} };
  static int de[10][2] = { {0,1}, {0,1}, {0,1}, {0,1},
			   {1,0}, {1,0}, {1,0}, {1,0},
			   {1,1}, {1,-1} };

  int cnt = 0;
  for (int i = 0; i < 4; ++i) {
    scanf("%s", mp[i]);
    for (int j = 0; j < 4; ++j) 
      if (mp[i][j] == '.') ++cnt;
  }

  for (int i = 0; i < 10; ++i) {
    int x = 0, o = 0;
    int a = st[i][0], b = st[i][1];
    for (int j = 0; j < 4; ++j) {
      if (mp[a][b] == 'X' || mp[a][b] == 'T') ++x;
      if (mp[a][b] == 'O' || mp[a][b] == 'T') ++o;
      a += de[i][0]; b += de[i][1];
    }

    if (x == 4) { puts("X won"); return; }
    if (o == 4) { puts("O won"); return; }
  }

  if (cnt == 0)
    puts("Draw");
  else 
    puts("Game has not completed");
}

int main()
{
  int t;
  scanf("%d", &t);
  for (int l = 1; l <= t; ++l) {
    printf("Case #%d: ", l);
    solve();
  }
  return 0;
}
