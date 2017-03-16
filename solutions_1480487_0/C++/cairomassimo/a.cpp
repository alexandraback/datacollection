#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <ctime>

#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>

using namespace std;

#ifdef DEBUG
#include <cassert>
#define dprintf(...)
#else
#define NDEBUG
#include <cassert>
#define dprintf(...) fprintf(stderr, __VA_ARGS__)
#endif

int t, T;

int N;
const int N_MAX = 10, N_DIM = N_MAX + 10;

int S[N_DIM];

const int S_MAX = 100;

double sol[N_DIM];

int sorted[N_DIM];
int psum;

void make_solution()
{
  int sum = 0;
  for(int i = 1; i <= N; i++)
    {
      sum += S[i];
      sorted[i] = S[i];
    }
  sort(sorted+1, sorted+N+1);

  psum = 0;

  double level = 0.0;
  

  for(int i = 1; i <= N; i++)
    {
      psum += sorted[i];

      double l = ((double) psum) / i + ((double) sum) / i;

      if(sorted[i] >= l)
	break;
      level = l;
    }

  dprintf("level: %lf\n", level);

  for(int i = 1; i <= N; i++)
    {
      sol[i] = (level - S[i]) / ((double) sum) * 100.0;

      if(sol[i] < 0)
	sol[i] = 0.0;
    }
}

void reset()
{
}

void read_input()
{
  scanf("%d", &N);
  for(int i = 1; i <= N; i++)
    {
      scanf("%d", &S[i]);
    }
}

void print_output()
{
  printf("Case #%d:", t);

  for(int i = 1; i <= N; i++)
    {
      printf(" %lf", sol[i]);
    }

  printf("\n");
}

int main()
{
  scanf("%d", &T);

  for(t = 1; t <= T; t++) {
    read_input();
    make_solution();
    print_output();
  }
}
