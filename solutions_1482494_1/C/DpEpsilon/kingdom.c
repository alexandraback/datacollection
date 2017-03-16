#include <stdio.h>
#include <stdlib.h>

typedef struct _level {
   int star1, star2;
   int levelDone;
} level;

level levels[1010];

int compar(const void* a, const void* b) {
   if (((level*)a)->star2 > ((level*)b)->star2) {
      return 1;
   } else if (((level*)a)->star2 == ((level*)b)->star2) {
      return 0;
   } else {
      return -1;
   }
}

int main() {
   int test, numTests;
   int i;
   scanf("%d", &numTests);
   
   for (test = 1; test <= numTests; test++) {
      int numLevels;
      int curLevels;
      int curStars;
      int gotStar;
      scanf("%d", &numLevels);
      
      for (i = 0; i < numLevels; i++) {
         scanf("%d %d", &levels[i].star1, &levels[i].star2);
         levels[i].levelDone = 0;
      }
      qsort(levels, numLevels, sizeof(level), &compar);
      
      curStars = 0;
      curLevels = 0;
      while (curStars < numLevels * 2) {
         gotStar = 0;
         for (i = 0; i < numLevels; i++) {
            if (levels[i].star2 <= curStars) {
               switch (levels[i].levelDone) {
               case 0:
                  curStars += 2;
                  curLevels++;
                  levels[i].levelDone = 2;
                  gotStar = 1;
                  break;
               case 1:
                  curStars += 1;
                  curLevels++;
                  levels[i].levelDone = 2;
                  gotStar = 1;
                  break;
               default:
                  break;
               }
            }
            if (gotStar) {
               break;
            }
         }

         if (!gotStar) {
            for (i = numLevels - 1; i >= 0; i--) {
               if (levels[i].star1 <= curStars && levels[i].levelDone == 0) {
                  levels[i].levelDone = 1;
                  gotStar = 1;
                  curStars += 1;
                  curLevels++;
                  break;
               }
            }
         }
         
         if (!gotStar) {
            curLevels = -1;
            break;
         }
      }
      if (curLevels == -1) {
         printf("Case #%d: Too Bad\n", test);
      } else {
         printf("Case #%d: %d\n", test, curLevels);
      }
   }
   
   
   return EXIT_SUCCESS;
}
