
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class FairAndSquare
{

   static boolean [] siv;
   static Set<Long> found;
   
   public static void main(String[] args) throws FileNotFoundException
   {
      System.setOut(new PrintStream(new File("small.out")));
      Scanner scan = new Scanner(new File("small.in"));

      int numCases = scan.nextInt();
      for (int z = 1; z <= numCases; z++)
      {
         found = new HashSet<>();
         
         long lower = (scan.nextLong());
         long upper = (scan.nextLong());
         
         siv = new boolean[(int)(Math.sqrt(upper)) + 1];
         
         System.out.print("Case #" + z + ": ");
         
         System.out.println(solveFairAndSquare(upper) - solveFairAndSquare(lower-1));
      }
   }
    
   public static long solveFairAndSquare(long num)
   {
      long count = 0;
      
      found.add(Long.valueOf(1));
      
      if (num == 0)
         return 0;
      
      int cur = 1;
      long pow = cur * cur;
      while (pow <= num)
      {
         if (!siv[cur] && isPalindrome(cur) && isPalindrome(pow))
         {
            count++;
         }
         
         cur++;
         pow = cur * cur;
      }
//      System.out.println("total " + count);
      return count;
   }

   private static boolean isPalindrome(long val)
   {
      String stringVal = val + "";
      
      for (int i = 0; i < stringVal.length() / 2; i++)
      {
         if (stringVal.charAt(i) != stringVal.charAt(stringVal.length() - i - 1))
         {
            return false;
         }
      }
      
      return true;
   }

}

