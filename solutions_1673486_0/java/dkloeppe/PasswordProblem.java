import java.util.*;
public class PasswordProblem {
   public static void main(String[] args) {
      Scanner scan = new Scanner(System.in);
      int numCases, numCharsTyped, passwordLen;
      double numKeystrokes, currentKeystrokes, prob;
      double[] probCorrect;

      numCases = scan.nextInt();
      for (int i = 1; i <= numCases; i++) {
         numCharsTyped = scan.nextInt();
         passwordLen = scan.nextInt();
         probCorrect = new double[numCharsTyped];
         for (int j = 0; j < numCharsTyped; j++) {
            probCorrect[j] = scan.nextDouble();
         }
         numKeystrokes = passwordLen + 2;
         for(int j = 0; j < numCharsTyped; j++) {
            prob = 1.0;
            currentKeystrokes = 0.0;
            for (int k = 0; k < probCorrect.length - j; k++)
               prob *= probCorrect[k];
            currentKeystrokes = (prob*(passwordLen-numCharsTyped+(2*j)+1))+((1.0-prob)*(2*passwordLen-numCharsTyped+(2*j)+2));
            if (currentKeystrokes < numKeystrokes)
               numKeystrokes = currentKeystrokes;
         }
         System.out.printf("Case #%d: %f\n", i, numKeystrokes);
      }
   }
}
