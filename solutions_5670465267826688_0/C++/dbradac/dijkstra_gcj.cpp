#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX = 10005;

// par +, nepar -
// 1-2 = 1, 3-4 = i, 5-6 = j, 7-8 = k

int mat[4][4] = {2, 4, 6, 8,
                 4, 1, 8, 5,
                 6, 7, 1, 4,
                 8, 6, 3, 1 };

int Mnoz(int a, int b)
{
  int p1 = (a - 1) / 2, p2 = (b - 1) / 2;
  int rje = (mat[p1][p2] - 1) / 2;
  int pred = (a + b + mat[p1][p2]) % 2;

  return 2 * (rje + 1) - pred;
}

int ValS(char c)
{
  return 4 + 2 * (c - 'i');
}

int treba[2] = {4, 6};
char s[MAX];

int main()
{
  int tt;

  scanf("%d", &tt);

  for (int ii=1; ii<=tt; ii++) {
    int n;
    ll x;

    scanf("%d%lld%s", &n, &x, s);
    printf("Case #%d: ", ii);

    int tmp=2;
    for (int i=0; i<n; i++)
      tmp = Mnoz(tmp, ValS(s[i]));

    int poc = tmp;
    for (int i=0; i<(x+3)%4; i++)
      tmp = Mnoz(tmp, poc);

    if (tmp != 1) {
      printf("NO\n");
      continue;
    }

    int ind=0, st=2, da=0;
    for (int i=0; i<min(n*x, (ll) 25*MAX); i++) {
      st = Mnoz(st, ValS(s[i%n]));
      if (st == treba[ind]) {
        ind++;
        st = 2;
        if (ind == 2) {
          da = 1;
          break;
        }
      }
    }

    if (!da)
      printf("NO\n");
    else
      printf("YES\n");
  }

  return 0;
}

