#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

#define INPUT_FILE    "C-small-attempt0.in"
#define OUTPUT_FILE   "C-small-attempt0.out"
#define MIN(a, b)     ((a) > (b) ? (b) : (a))

int N;
vector<long> V;
map<long, long> M;    // M[sum] = submultime


bool Valid(long p1, long p2)
{
  int i;

  for (i = 0; i < N; ++i)
    if ((p1 & (1 << i)) && (p2 & (1 << i)))
    {
      // au un bit comun -> folosesc numere comune
      return false;
    };
  return true;
}

int solve()
{
  //sort(V.begin(), V.end());
  M.clear();

  int i, s, j;

  for (i = 1; i < (1 << N); ++i)
  {
    s = 0;
    for (j = 0; j < N; ++j)
    {
      if (i & (1 << j))
      {
        s += V[j];
      }
    }
    if (M.find(s) == M.end())
    {
      M[s] = i;
    }
    else
    {
      j = M[s];

      if (Valid(i, j))
      {
        // multimile cu bitii din i si j sunt disjuncte si au aceiasi suma -> sol
        int k;

        for (k = 0; k < N; ++k)
          if (i & (1 << k))
          {
            printf("%ld ", V[k]);
          }
        printf("\n");

        for (k = 0; k < N; ++k)
          if (j & (1 << k))
          {
            printf("%ld ", V[k]);
          }
        printf("\n");

        return 1;
      }
    }
  }
  return 0;
}


int main()
{
  freopen(INPUT_FILE, "rt", stdin);
  freopen(OUTPUT_FILE, "wt", stdout);

  int t;
  scanf("%d", &t);

  for (int i = 1; i <= t; ++i)
  {
    scanf("%d", &N);
    V.clear();

    for (int j = 0; j < N; ++j)
    {
      long x;
      scanf("%ld", &x);
      V.push_back(x);
    }

    printf("Case #%d:\n", i);

    if (!solve())
    {
      printf("Impossible\n");
    }
  }

  return 0;
}