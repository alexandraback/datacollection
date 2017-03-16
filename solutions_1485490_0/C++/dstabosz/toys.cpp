#include <stdio.h>
#include <assert.h>
#include <cstring>
#include <vector>
#include <set>
#include <list>
#include <algorithm>

using namespace std;

int debug = 0;
int N, M;


int toyType[100];
long long toyCount[100];
int boxType[100];
long long boxCount[100];

long long Solve(int toyIdx, int boxIdx, int tType, long long toys,
                int bType, long long boxes, long long total, int level);

int main(int argc, char *argv[])
{
  int T;
  
  assert(scanf("%d", &T) == 1);

  for (int t = 1; t <= T; t++)
  {

    assert(scanf("%d %d", &N, &M) == 2);

//    assert(N <= 1000);

    for(int i = 0; i < N; i++)
    {
      long long a;
      int b;
      assert(scanf("%lld %d", &a, &b) == 2); 
      boxCount[i] = a;
      boxType[i] = b;
    }

    for(int i = 0; i < M; i++)
    {
      long long a;
      int b;
      assert(scanf("%lld %d", &a, &b) == 2); 
      toyCount[i] = a;
      toyType[i] = b;
    }

    long long val = Solve(0, 0, 0, 0, 0, 0, 0, 0);

    printf ("Case #%d: %lld\n", t, val);

    fflush(stdout);
  }  
}

void Indent(int lvl)
{

  for (int l = 0; l < lvl; l++)
  {
    printf("  ");
  }
}

long long Solve(int toyIdx, int boxIdx, int tType, long long toys,
                int bType, long long boxes, long long total, int level)
{
  long long count;

  if (debug)
  {
  Indent(level);
  printf("toys %d/%d/%lld boxes %d/%d/%lld\n", toyIdx, tType, toys, 
         boxIdx, bType, boxes);
  }

  while(1)
  {
    if (toys == 0)
    {
      if (debug)
      {
      Indent(level);
      printf("Get toys, toyIdx %d M %d\n", toyIdx, M);
      }

      if (toyIdx == M)
        break;

      tType = toyType[toyIdx];
      toys = toyCount[toyIdx];

      
      if (debug)
      {
      Indent(level);
        printf("Getting toys idx %d toyType %d count %lld\n", toyIdx, tType, toys);
	}

      toyIdx++;

    }

    if (boxes == 0)
    {
      if (boxIdx == N)
        break;

      bType = boxType[boxIdx];
      boxes = boxCount[boxIdx];


      if (debug)
      {
      Indent(level);
        printf("Getting boxes idx %d toyType %d count %lld\n", toyIdx, tType, toys);
	}

      boxIdx++;
    }

    if (tType == bType)
    {
      count = min(toys, boxes);
      total +=  count;
      toys -= count;
      boxes -= count;

      if (debug)
        printf("Boxed %lld toys type %d\n", count, tType);

      continue;
    }

    long long t1, t2;
    
    t1 = Solve(toyIdx, boxIdx, tType, 0, bType, boxes, total, level + 1);
    t2 = Solve(toyIdx, boxIdx, tType, toys, bType, 0, total, level + 1);

    return max(t1, t2);
  }

  return total;

}
