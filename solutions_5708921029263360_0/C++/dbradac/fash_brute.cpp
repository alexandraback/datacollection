#include <cstdio>
#include <ctime>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAXS = 3;
const double TL = 2.0;

struct str {
  int a, b, c;
};

int ima[MAXS][MAXS][MAXS];
int p[3];
int kk;
vector <str> R;
vector <str> T;

int Ok(int a, int b, int c)
{
  int br = 1;
  for (int i=0; i<p[2]; i++)
    br += ima[a][b][i];

  if (br > kk)
    return 0;

  br = 1;
  for (int i=0; i<p[1]; i++)
    br += ima[a][i][c];

  if (br > kk)
    return 0;

  br = 1;
  for (int i=0; i<p[0]; i++)
    br += ima[i][b][c];

  if (br > kk)
    return 0;

  return 1;
}

void Vrti()
{
  if (T.size() > R.size())
    R = T;

  for (int i=0; i<20; i++) {
    int a = rand() % p[0];
    int b = rand() % p[1];
    int c = rand() % p[2];

    if (!ima[a][b][c] && Ok(a, b, c)) {
      ima[a][b][c] = 1;
      T.push_back(str{a, b, c});
      Vrti();
      ima[a][b][c] = 0;
      T.pop_back();
      break;
    }
  }
}

int main()
{
  int brt;

  scanf("%d", &brt);

  for (int br=1; br<=brt; br++) {
    double cl = (double) clock() / CLOCKS_PER_SEC;
    scanf("%d%d%d", &p[0], &p[1], &p[2]);
    scanf("%d", &kk);

    R.clear();
    for (; (double) clock() / CLOCKS_PER_SEC - cl < TL; )
      Vrti();

    printf("Case #%d: %d\n", br, (int) R.size());
    for (auto it : R)
      printf("%d %d %d\n", it.a + 1, it.b + 1, it.c + 1);

    TRACE(br);
  }


  return 0;
}

