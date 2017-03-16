#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char input[4000];

int main(){
  char delims[] = " ";
  char numCases[10];
  fgets(numCases, 10, stdin);
  int n = atoi(numCases);


  for(int i =1;i<=n;i++){
    fgets(input, 4000, stdin);
    int pairs=0;
    int a = atoi(strtok( input, delims ));
    int b = atoi(strtok( NULL, delims));
    int* counted = (int*) calloc(3000000, sizeof(int));
    for(int k=a; k<=b;k++){
      int current=k;
      if(counted[k]==0){

        int digits = (int) log10(k)+1;

        int exp = (int) pow(10,digits);
        int shifts=0;
        int found=0;

        while(shifts<digits){
          if(current<=b && current >=a && counted[current]==0){
            counted[current]=1;
            found++;
          }

          int factor=10;
          int trailing = current%factor;
          shifts++;

          while(trailing==0){
            factor*=10;
            trailing = current%factor;
            shifts++;
          }

          current = current / factor;

          current+=trailing*(exp / factor);
        }
        pairs+=((found-1)*found)/2;
      }
    }
    printf("Case #%d: %d\n", i, pairs);
  }
}
