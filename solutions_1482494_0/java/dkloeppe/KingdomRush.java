import java.util.*;
public class KingdomRush {
   public static void main(String[] args) {
      Scanner scan = new Scanner(System.in);
      int numCases, numLevels, numTimes, numStars, currentIndex;
      int[][] stars;
      boolean possible, done, first; 
      numCases = scan.nextInt();
      for (int i = 1; i <= numCases; i++) {
         numLevels = scan.nextInt();
         stars = new int[numLevels][2];
         for (int j = 0; j < numLevels; j++) {
            stars[j][0] = scan.nextInt();
            stars[j][1] = scan.nextInt();
         }
         numTimes = 0;
         possible = true;
         done = false;
         numStars = 0;
         while (!done) {
            for(int j = 0; j < numLevels; j++) {
               if (stars[j][0] != -1 && stars[j][1] != -1) {
                  if (stars[j][0] <= numStars && stars[j][1] <= numStars) {
                     numStars += 2;
                     numTimes += 1;
                     stars[j][0] = stars[j][1] = -1;
                     j = 0;
                  }
               }
            }
            for(int j = 0; j < numLevels; j++) {
               if (stars[j][0] == -1 && stars[j][1] != -1 && stars[j][1] <= numStars) {
                  numStars += 1;
                  numTimes += 1;
                  stars[j][1] = -1;
                  j = 0;
               }
            }
            for(int j = 0; j < numLevels; j++) {
               if (stars[j][0] != -1 && stars[j][1] != -1) {
                  if (stars[j][0] <= numStars && stars[j][1] <= numStars) {
                     numStars += 2;
                     numTimes += 1;
                     stars[j][0] = stars[j][1] = -1;
                     j = 0;
                  }
               }
            }
            for(int j = 0; j < numLevels; j++) {
               if (stars[j][0] == -1 && stars[j][1] != -1 && stars[j][1] <= numStars) {
                  numStars += 1;
                  numTimes += 1;
                  stars[j][1] = -1;
                  j = 0;
               }
            }
            first = true;
            currentIndex = 0;
            for(int j = 0; j < numLevels; j++) {
               if (stars[j][0] != -1 && stars[j][1] != -1) {
                  if (stars[j][0] <= numStars && first) {
                     currentIndex = j;
                     first = false;
                  } 
                  if (stars[j][0] <= numStars && stars[j][1] > stars[currentIndex][1]) {
                     currentIndex = j;
                  }
               }
            }
            if (first) {
               done = true;
               for (int j = 0; j < numLevels; j++) {
                  if (stars[j][1] != -1) {
                     done = false;
                  }
               }
               if(!done) {
                  possible = false;
                  done = true;
               }
            }
            if (!done) {
               stars[currentIndex][0] = -1;
               numStars++;
               numTimes++;
            } 
         }
         if(possible)
            System.out.printf("Case #%d: %d\n", i, numTimes);
         else
            System.out.printf("Case #%d: Too Bad\n", i);
      }
   }
}
