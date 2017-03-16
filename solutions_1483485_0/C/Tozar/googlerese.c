/*
 * Author: Jeremy Meador
 * Problem: 
 *
 */


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define DEBUG 1
#define printd if (DEBUG) printf

char cipher[26] =     {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};  

void translate()
{
  char c;
  scanf("%c", &c);
  while (c != '\n')
  {
    if (c == ' ')
      printf(" ");
    else
    {
      int index = c - 'a';
      if (index >=0 && index <= 26)
      {
        printf("%c", cipher[index]);
      }
    }
    scanf("%c", &c);
  }
}

int main()
{
  int count, j;
  scanf("%d\n", &count);
  for (j=0;j<count;j++)
  {
    printf("Case #%d: ",j+1);
    translate();
    printf("\n");
  }
}



