#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
  return ( *(int*)a - *(int*)b );
}

int main()

{
  int values[100][50];
  char buf[1000];
  int n;
  int intcnt[2501] = {0};
  FILE *in = fopen("in.txt", "r");
  int casen = 0;
  fgets(buf, 1000, in);
  while(fgets(buf, 1000, in)){
    n = atoi(buf);
    int i;
    int j;
    char *tmp;
    int maxval;
    for(i = 0; i < 2501; i++)
      intcnt[i] = 0;
    //Store the array.
    maxval = 0;
    for(i = 0; i < 2*n-1; i++){
      fgets(buf, 1000, in);
      tmp = strtok(buf, " ");
      j = 0;
      do{
	values[i][j] = atoi(tmp);
	j++;
	//Count how mant times the integer appears.
	intcnt[atoi(tmp)]++;
      }while((tmp = strtok(NULL, " ")));
      
    }
    //Look for missing pieces.
    int missing[100];
    for(i = 0; i < 100; i++)
      missing[i] = 0;
    int misscnt = 0;
    //If the piece is present, then it will
    //have a value of odd if 1 is missing.
    //This is because everything will be present even times.
    for(i = 0; i < 2501; i++)
      if(intcnt[i] %2 == 1)
	missing[misscnt++] = i;
    //Next, we need to look for this missing number.
    //Find the array and index in which it is located.
    /*    int foundr[100];
    int foundc[100];
    int foundrc = 0;
    int foundcc = 0;
    for(i = 0; i < n; i++){
      for(j = 0; j < n; j++){
	for(k = 0; k < misscnt; k++)
	  if(values[i][j] == missing[k]){
	    foundr[foundrc++] = i;
	    foundc[foundcc++] = j;
	  }
      }
      }*/
    //If this is a row, then the element will be in the kth column.
    //Thus, all missing pieces are a row.
    qsort(missing, misscnt, sizeof(int), compare);
    casen++;
    printf("Case #%d: ", casen);
    for(i = 0; i < n-1; i++){
      printf("%d ", missing[i]);
    }
    printf("%d\n", missing[i]);
  }
  return 0;
}
