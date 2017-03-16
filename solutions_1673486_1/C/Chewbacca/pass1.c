#include <stdio.h>
#include <assert.h>

int main(void) {
  int number_of_cases, case_number;
  scanf("%d", &number_of_cases);
  for(case_number=1; case_number<=number_of_cases; case_number++) {
    int already, total_type;
    double d1, e, optimal;
    scanf("%d%d", &already, &total_type);
    /* First attempt, typing enter */
    optimal = 2 + total_type;
    d1=1;
    for(int i=already-1; i>=0; i--) {
      scanf("%lf",&e);
      /* Typing backspace i times */
      d1*=e;

      e = i+i+total_type-already+1 + (1+total_type)*(1-d1);
      if(e<optimal) optimal=e;
    }
    printf("Case #%d: %.6f\n", case_number, optimal);

  }
}
  
