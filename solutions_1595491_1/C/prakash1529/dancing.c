/******************************************************************************
 * DANCING WITH GOOGLERS
 * ***************************************************************************/
#include<stdio.h>
int main() {
  int T;
  scanf("%d", &T);
  int test_count = 1;
  while(T--) {
    int S, N, P;
    int definite_count, indefinite_count;
    definite_count = indefinite_count = 0;
    scanf("%d", &N);
    scanf("%d", &S);
    scanf("%d", &P);
    int def_bound = (3*P - 2);
    int indef_bound = (3*P - 4); 
    int ti;
    printf("Case #%d: ", test_count++);
    if(P==0) {
      def_bound = 0;
      indef_bound = 0;
    } else if(P==1) {
      indef_bound = 1;
    }
    while(N--) {
      scanf("%d", &ti);
      if(ti >= def_bound) {
        definite_count++;
      } else if(ti >= indef_bound ) {
        indefinite_count++;
      } 
    }
    if(indefinite_count >= S) {
      printf("%d\n", (definite_count + S));
     } else { 
       printf("%d\n", (definite_count+indefinite_count));
     }
  }
}
