package round.one.c;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class B
{

   static String keyboard, target;
   static int S;
   static double expected, total, max;
   static int overlap;
   static double [][] memo;
   public static void main(String[] args) throws FileNotFoundException
   {
      System.setOut(new PrintStream(new File("small.out")));
      Scanner scan = new Scanner(new File("small.in"));

      int numCases = scan.nextInt();
      for (int z = 1; z <= numCases; z++)
      {
         int K = scan.nextInt();
         int L = scan.nextInt();
         S = scan.nextInt();
         
         keyboard = scan.next();
         target = scan.next();
         
         memo = new double[S][target.length()];
         for (double [] arr : memo)
         {
            Arrays.fill(arr, -1);
         }

         overlap = 0;
         for (int i = 1; i < target.length(); i++)
         {
            if (target.substring(0, target.length() - i).equals(target.substring(i, target.length())))
            {
               overlap = target.length() - i;
               break;
            }
         }
         
         int initial = S - L;
         double numBananas = 1 + initial / (target.length() - overlap);
         
         Map<String, Integer> keyMap = new HashMap<>();
         for (int i = 0; i < keyboard.length(); i++)
         {
            String letter = Character.toString(keyboard.charAt(i)); 
            keyMap.put(letter, keyMap.get(letter) == null ? 1 : keyMap.get(letter) + 1);
         }
         
         boolean canComplete = true;
         for (int i = 0; i < target.length(); i++)
         {
            String letter = Character.toString(target.charAt(i)); 
            if (!keyMap.containsKey(letter))
            {
               canComplete = false;
               break;
            }
         }
         
         if (canComplete)
         {
            expected = 0;
            total = 0;
            max = 0;
            System.out.println("Case #" + z + ": " + (numBananas - solve(0, 0)));
         }
         else
         {
            System.out.println("Case #" + z + ": 0.0");
         }
      }

      scan.close();
   }

   private static double solve(int index, int correct)
   {
      if (index == S)
      {
         return 0;
      }
      
      if (memo[index][correct] >= 0)
      {
         return memo[index][correct];
      }
      
      double expected = 0;
      double prob = 1.0 / ((double)keyboard.length());
      
      for (int i = 0; i < keyboard.length(); i++)
      {
         if (keyboard.charAt(i) == target.charAt(correct))
         {
            if (correct + 1 == target.length())
            {
               expected += prob * (1.0 + solve(index + 1, overlap));
            }
            else
            {
               expected += prob * (solve(index + 1, correct + 1));
            }
         }
         else
         {
            if (correct > 0 && keyboard.charAt(i) == target.charAt(0))
            {
               expected += prob * (solve(index + 1, 1));
            }
            else
            {
               expected += prob * solve(index + 1, 0);
            }
         }
      }
      
      memo[index][correct] = expected;
      return expected;
   }

}

