#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
  int T, R, C, W;
  int i, t;
  FILE* file = fopen(argv[1], "r");

  fscanf(file, "%d\n", &T);

  for(i=0; i<T; i++){
    fscanf(file, "%d %d %d\n", &R, &C, &W);
    if(((float)C/(float)W) != C/W)
      t = (C/W) +1;
    else
      t = (C/W);
    printf("Case #%d: %d\n", i+1, (t*R)+(W-1));
  }

  fclose(file);

  return 0;
}
