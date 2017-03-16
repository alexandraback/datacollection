package round.one.b;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.security.acl.LastOwnerException;
import java.util.Arrays;
import java.util.Scanner;

public class C
{
   static int [][] memo;
   static String [] dictionary;
   static String email;
   public static void main(String[] args) throws FileNotFoundException
   {
      System.setOut(new PrintStream(new File("small.out")));
      Scanner scan = new Scanner(new File("small.in"));

      Scanner dscan = new Scanner(new File("garbled_email_dictionary.txt"));
      dictionary = new String[521196];
      for (int i = 0; i < dictionary.length; i++)
         dictionary[i] = dscan.next();
      dscan.close();

      Arrays.sort(dictionary);
      
      int numCases = scan.nextInt();
      for (int z = 1; z <= numCases; z++)
      {
         email = scan.next();
         
         memo = new int[email.length()][6];
         for (int [] arr : memo)
            Arrays.fill(arr, -1);
         
         int result = magic(0, 0);
         
         System.out.println("Case #" + z + ": " + result);
      }

      scan.close();
   }

   static int remainingResult;
   private static int magic(int letter, int remaining)
   {
      if (letter == email.length())
      {
         return 0;
      }
      if (memo[letter][remaining] >= 0)
      {
         return memo[letter][remaining];
      }
      
      int best = Integer.MAX_VALUE / 10;
      
      for (String word : dictionary)
      {
         int diff = verifyWord(word, letter, remaining);
         if (diff >= 0)
         {
            best = Math.min(best, diff + magic(letter + word.length(), remainingResult));
         }
      }
      
      memo[letter][remaining] = best;
      
      return best;
   }

   private static int verifyWord(String word, int letter, int remaining)
   {
      if (word.length() + letter > email.length())
      {
         return -1;
      }
      
      int total = 0;
      for (int i = 0; i < word.length(); i++)
      {
         if (word.charAt(i) != email.charAt(letter + i))
         {
            if (remaining > 0)
            {
               return -1;
            }
            else
            {
               remaining = 4;
               total++;
            }
            
         }
         else
         {
            remaining = Math.max(0, remaining-1);
         }
      }
      remainingResult = remaining;
      
      return total;
   }

}

