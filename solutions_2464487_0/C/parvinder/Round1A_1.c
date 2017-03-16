#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include <timath.h>

#define PI 3.141592

#define bool int
#define true 1
#define false 0
#define DEBUG 0

int main(int argc, char** argv)
{
  char buff[100];
  int test_cases = 0;
  int t, ctr, ctr2;
  int rad;
  int tot;
  FILE* pFile;
  int numRings = 0;
  float vol;

  pFile = fopen (argv[1],"r");
  if(pFile == NULL) {printf("file not opened\n");return;}
  fscanf (pFile, "%d", &test_cases);
#if DEBUG
printf("test cases = %d\n", test_cases);
#endif

  for(t = 0; t < test_cases; t++)
  {
   		numRings = 0;
    fscanf(pFile, "%d %d", &rad, &tot);
#if DEBUG
printf("rad = %d, tot = %d\n", rad, tot);

printf("req vol now %f\n", (PI * (rad+1) * (rad+1) - PI * rad * rad));
#endif

    while(tot >= ((rad+1) * (rad+1) - rad * rad))
{
 	     
        tot -= ((rad+1) * (rad+1) - rad * rad);
        rad += 2;
  //      printf("tot is %d, reqd =%d\n", tot, ((rad+1) * (rad+1) - rad * rad));

        numRings++;
}
    printf("Case #%d: %d\n", t + 1, numRings);

    fscanf(pFile, "%*[^\n]%*c");
  }
  fclose (pFile);
  return 0;
}
