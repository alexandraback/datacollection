#include <stdio.h>
#include <stdlib.h>

#define MAX_LEVEL 1000

void calc(int Smax, char *info)
{
  int invited = 0;
  int clapping = info[0] - '0';

  int i;
  for (i = 1; i <= Smax; i++) {
    int tmp_invited = 0;
    if(clapping < i) {
      tmp_invited = i - clapping;
    }
    clapping += tmp_invited + (info[i] - '0');
    invited += tmp_invited;
  }
  
  printf("%d", invited);
}

int main(int argc, char *argv[])
{
  int T;
  scanf("%d", &T);

  int i;
  for (i = 0; i < T; i++) {
    printf("Case #%d: ", i + 1);
    
    int Smax;
    char info[MAX_LEVEL + 1 + 1];
    scanf("%d %s", &Smax, info);
    calc(Smax, info);
    
    printf("\n");
  }

  
  return 0;
}

