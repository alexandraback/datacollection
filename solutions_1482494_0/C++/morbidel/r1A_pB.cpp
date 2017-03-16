#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define INPUT_FILE    "B-small-attempt0.in"
#define OUTPUT_FILE   "B-small-attempt0.out"
#define MIN(a, b)     ((a) > (b) ? (b) : (a))

struct level
{
  int s1, s2;
  int pos;
};
vector<level> S;
bool Done[1000][2];

bool compare1(const level &a, const level &b)
{
  return (a.s1 < b.s1) || (a.s1 == b.s1 && a.s2 > b.s2);    // daca pot ataca mai multe la level 1, le atac pe alea cu mai multe stele pt lev 2. asta pt ca pe cele cu putine am sanse sa le atac direct
}

bool compare2(const level &a, const level &b)
{
  return (a.s2 < b.s2) || (a.s2 == b.s2 && a.s1 < b.s1);
}

int solve()
{
  int i, n = S.size();
  bool sol = false;

  memset(Done, 0, sizeof(Done));

  for (i = 0; i < n; ++i)
  {
    if (S[i].s1 == 0 || S[i].s2 == 0)
    {
      sol = true;
      break;
    }
  }

  if (!sol)
  {
    return -1;
  }

  int games = 0;
  int stars = 0;
  int finished = 0;

  while (true)
  {
    bool again = false;
    // caut daca pot face direct 2 stele la vreunele. Daca da, le fac in ordine crescatoare

    sort(S.begin(), S.end(), compare2);
    for (i = 0; i < n; ++i)
      if (S[i].s2 <= stars && !Done[S[i].pos][1])
      {
        Done[S[i].pos][1] = true;
        stars += (Done[S[i].pos][0] ? 1 : 2);
        ++games;
        ++finished;

        again = true;
      };

    sort(S.begin(), S.end(), compare1);
    // nu mai am ce nivele sa termin cu 2 stele, incerc la 1 stea, in ordine crescatoare
    for (i = 0; i < n; ++i)
      if (!Done[S[i].pos][1] && !Done[S[i].pos][0] && S[i].s1 <= stars)
      {
        Done[S[i].pos][0] = true;
        ++stars;
        ++games;

        again = true;

        // ma opresc la primul facut, poate poate reusesc la lev 2 acum
        break;
      }

      if (!again)
        break;
  }

  // mai e vreunul neterminat?
  for (i = 0; i < n; ++i)
    if (!Done[i][1])
    {
      return -1;
    };
  
  return games;
}

int main()
{
  freopen(INPUT_FILE, "rt", stdin);
  freopen(OUTPUT_FILE, "wt", stdout);

  int t, n;

  scanf("%d", &t);

  for (int i = 1; i <= t; ++i)
  {
    scanf("%d", &n);

    S.clear();
    for (int j = 0; j < n; ++j)
    {
      level l;

      scanf("%d %d", &l.s1, &l.s2);
      l.pos = j;
      S.push_back(l);
    }

    printf("Case #%d: ", i);
    int res = solve();

    if (res == -1)
    {
      printf("Too Bad\n");
    }
    else
    {
      printf("%d\n", res);
    }
  }

  return 0;
}