#include <stdio.h>

double chances[100010];

int main() {

   int numTests, test, i;

   scanf("%d", &numTests);
   
   for (test = 1; test <= numTests; test++) {
      int a, b;
      double minKeys;
      double keepTyping;
      double allCorrect;
      
      scanf("%d %d", &a, &b);

      allCorrect = 1.0;
      for (i = 0; i < a; i++) {
         scanf("%lf", &chances[i]);
         allCorrect *= chances[i];
      }

      keepTyping = allCorrect * (b - a + 1);
      keepTyping += (1.0 - allCorrect) * (2*b - a + 2);

//      printf("All Correct: %lf\n", allCorrect);
      
      minKeys = keepTyping;

//      printf("KeepTyping: %lf\n", keepTyping);
      
      double curPressBackspace;
      double curCorrect = 1.0;

      for (i = 0; i < a; i++) {
         curCorrect *= chances[i];

         curPressBackspace = curCorrect * ((a - i - 1)*2 + b - a + 1);
         curPressBackspace += (1.0 - curCorrect) * ((a - i - 1)*2 + b - a + b + 2);

//         printf("PressBackspace %d: %lf\n", i, curPressBackspace);
         
         if (curPressBackspace < minKeys) {
            minKeys = curPressBackspace;
         }
      }

      double enterRightAway;
      enterRightAway = 2 + b;
      if (enterRightAway < minKeys) {
         minKeys = enterRightAway;
      }

//      printf("Enter: %lf\n", enterRightAway);
      
      printf("Case #%d: %lf\n", test, minKeys);
   }

   return 0;
}
