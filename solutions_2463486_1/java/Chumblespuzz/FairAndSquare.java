
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class FairAndSquare
{

   static boolean [] siv;
   static int [] answer;
   static Set<Long> found;
   static long [] ans;
   
   public static void main(String[] args) throws FileNotFoundException
   {
      System.setOut(new PrintStream(new File("small.out")));
      Scanner scan = new Scanner(new File("small.in"));
      
      ans = new long [] {
            1L,
            4L,
            9L,
            121L,
            484L,
            10201L,
            12321L,
            14641L,
            40804L,
            44944L,
            1002001L,
            1234321L,
            4008004L,
            100020001L,
            102030201L,
            104060401L,
            121242121L,
            123454321L,
            125686521L,
            400080004L,
            404090404L,
            10000200001L,
            10221412201L,
            12102420121L,
            12345654321L,
            40000800004L,
            1000002000001L,
            1002003002001L,
            1004006004001L,
            1020304030201L,
            1022325232201L,
            1024348434201L,
            1210024200121L,
            1212225222121L,
            1214428244121L,
            1232346432321L,
            1234567654321L,
            4000008000004L,
            4004009004004L
      };

      int numCases = scan.nextInt();
      for (int z = 1; z <= numCases; z++)
      {
         found = new HashSet<>();
         
         long lower = (scan.nextLong());
         long upper = (scan.nextLong());
         
         siv = new boolean[(int)(Math.sqrt(upper)) + 2];
         
         System.out.print("Case #" + z + ": ");
         
         System.out.println(solveFairAndSquare(upper) - solveFairAndSquare(lower-1));
      }
   }
    
   public static long solveFairAndSquare(long num)
   {
      long count = 0;
      
      for (long a : ans)
      {
         count += num >= a ? 1 : 0;
      }
//      
//      found.add(Long.valueOf(1));
//      
//      if (num == 0)
//         return 0;
//      
//      long cur = 1;
//      long pow = cur * cur;
//      while (pow <= num)
//      {
//         if (!siv[(int)cur] && isPalindrome(cur) && isPalindrome(pow))
//         {
//            System.out.println(pow + "L,");
//            count++;
//         }
//         
//         cur++;
//         pow = cur * cur;
//      }
////      System.out.println("total " + count);
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

