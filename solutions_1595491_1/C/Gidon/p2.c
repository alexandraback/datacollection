#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char input[4000];
int scores[110];

int main(){
  char delims[] = " ";
  char numCases[10];
  fgets(numCases, 10, stdin);
  int n = atoi(numCases);

  for(int i =1;i<=n;i++){
    fgets(input, 4000, stdin);
    int possiblyGreater=0;
    int n = atoi(strtok( input, delims ));
    int stot = atoi(strtok( NULL, delims));
    int sleft = stot;
    int p = atoi(strtok( NULL, delims));
    int k=0;
    char* result = strtok( NULL, delims);
    while( result != NULL ) {
        scores[k] = atoi(result);
        k++;
        result = strtok( NULL, delims);
    }

    for(int k=0;k<n;k++){
      if(scores[k] > 3*p-3){
        possiblyGreater++;
      }
      else if((scores[k] == 3*p-3 || scores[k] == 3*p-4) && sleft>0 && p!=1){
        sleft--;
        possiblyGreater++;
      }
    }
    printf("Case #%d: %d\n", i, possiblyGreater);
  }
}
