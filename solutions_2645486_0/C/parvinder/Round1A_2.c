#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include <timath.h>

#define PI 3.141592

#define MIN(a,b) (((a)<(b))?(a):(b))
#define bool int
#define true 1
#define false 0
#define DEBUG 0

unsigned long max_en = 0;

int v[10];
int e, r, n;
unsigned int curr, max;

int get_max_recurr(int current_en, int pos)
{
    int i, j;
    int step = 0;
    int max = 0;
  //  printf("current_en = %d, pos");
    if(pos == 0) curr = max = 0;
    if(pos>=n)return 0;
    for(i = 0; i <= current_en; i++)
    {
        step = i * v[pos];
        step += get_max_recurr(MIN(current_en - i + r, e), pos+1);
        if(max<step)max=step;
    }
    return max;
}

void get_max()
{
    max_en = get_max_recurr(e, 0);
}

int main(int argc, char** argv)
{
  char buff[100];
  int test_cases = 0;
  int t, ctr, ctr2;
  FILE* pFile;

  pFile = fopen (argv[1],"r");
  if(pFile == NULL) {printf("file not opened\n");return;}
  fscanf (pFile, "%d", &test_cases);
#if DEBUG
printf("test cases = %d\n", test_cases);
#endif

  for(t = 0; t < test_cases; t++)
  {
   		e = r = n = 0;
   		memset(v, 0, 10 * sizeof(int));
    fscanf(pFile, "%d %d %d", &e, &r, &n);
#if DEBUG
printf("e= %d, r=%d, n=%d\n", e, r, n);
#endif
//        printf("\n");
   		for (ctr = 0; ctr < n; ctr++)
   		{
   		    fscanf(pFile, "%d", &v[ctr]);
 //  		    printf("%d ", v[ctr]);
        }
 //       printf("\n");
		get_max();
//        printf("MAX = %d\n", max_en);

    printf("Case #%d: %d\n", t + 1, max_en);

    fscanf(pFile, "%*[^\n]%*c");
  }
  fclose (pFile);
  return 0;
}
