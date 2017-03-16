#include <stdio.h>
#include <assert.h>
#include <cstring>
#include <vector>
#include <set>
#include <list>

using namespace std;

int debug = 0;
int N;

int diamond = 0;

int inheritsFromBase[1000][1000];

int baseClasses[1000];

void addBaseClasses(int idx);

int main(int argc, char *argv[])
{
  int T;
  
  assert(scanf("%d", &T) == 1);

  for (int t = 1; t <= T; t++)
  {
    memset(inheritsFromBase, 0, sizeof(inheritsFromBase));
    diamond = 0;

    assert(scanf("%d", &N) == 1);

    assert(N <= 1000);

    for(int i = 0; i < N; i++)
    {
      int numClass;
      assert(scanf("%d", &numClass) == 1);

      for (int j = 0; j < numClass; j++)
      {
        int parent;
      
         assert(scanf("%d", &parent) == 1);

	 inheritsFromBase[i][parent-1] = 1;
	
        if (debug)
	  printf("class %d parent %d\n", j+1, parent);
      }
   }

    for(int i = 0; i < N; i++)
    {
      if (debug)
        printf("computing base classes for %d\n", i+1);

        memset(baseClasses, 0, sizeof(baseClasses));

        for (int j = 0; j < N; j++)
	{
	  if (i == j)
	    continue;

          if (inheritsFromBase[i][j])
	  {
             addBaseClasses(j); 
	  }
	}

    }


    printf ("Case #%d: ", t);

    if (diamond)
    {
      printf("Yes\n"); 
    }
    else
    {
      printf("No\n");
    }

    if (debug)
      printf("\n");

    fflush(stdout);
  }  
}

void addBaseClasses(int idx)
{
  if (debug)
    printf("   adding %d\n", idx + 1);

  baseClasses[idx]++;
 
  if (baseClasses[idx] > 1)
  {
    diamond = 1;

    if (debug)
      printf("   class %d inherited more than once\n", idx + 1);
  }

  for (int i = 0; i < N; i++)
  {
     if (inheritsFromBase[idx][i])
       addBaseClasses(i);
  }

}
