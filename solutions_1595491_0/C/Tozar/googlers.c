/*
 * Author: Jeremy Meador
 *  Dancing With Googlers
 */ 


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define DEBUG 0
#define printd if (DEBUG) printf //Don't forget curly braces

int result(int dancerCount, int surprises, int scoreToBeat)
{
  int j, winners = 0;
  printd("%d %d %d\n", dancerCount, surprises, scoreToBeat);
  for (j=0;j<dancerCount;j++)
  {
    int score;
    scanf("%d", &score);
    if ((score+2)/3 >= scoreToBeat && score >= scoreToBeat)
      winners++;
    else if ((score+4)/3 >= scoreToBeat && score >= scoreToBeat)
    {
      if (surprises > 0)
      {
        surprises--;
        winners++;
      }
    }
  }
  return winners;
}

int main()
{
  int count, j;
  scanf("%d", &count);
  for (j=0;j<count;j++)
  {
    int d, s, b;
    scanf("%d %d %d ", &d, &s, &b);
    printf("Case #%d: %d\n",j+1, result(d, s, b));
  }
}



