#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct _state {
   int    array[2];
} state;


int main(){
   int numCases = 0;
   scanf("%d", &numCases);
   getchar();
   state caseList[numCases];

   int j = 0; 
   int i = 0;
   for(i = 0; i <= numCases-1; i++){
      scanf("%d", &caseList[i].array[0]);
      scanf("%d", &caseList[i].array[1]);
   }

   
   for (i = 0; i <= numCases-1; i++){
      int x = caseList[i].array[0];
      int y = caseList[i].array[1];

      printf("Case #%d: ", i+1);
      if (x > 0){
         for (j = 0; j < x; j++){
            printf("WE");
         } 
         if (y > 0){
            for (j = 0; j < y; j++){
               printf("SN");
            }
         } else {
            for (j = 0; j > y; j--){
               printf("NS");
            }
        }
     } else {
        for (j = 0; j > x; j--){
           printf("EW");
        } 
        if (y > 0){
           for (j = 0; j < y; j++){
              printf("SN");
           }
        } else {
           for (j = 0; j > y; j--){
              printf("NS");
          }
        }
    }
    printf("\n");
    }

   return 0;
}

