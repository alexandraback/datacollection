package round.one.b;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class A
{

   static int [] motes;
   public static void main(String[] args) throws FileNotFoundException
   {
      System.setOut(new PrintStream(new File("small.out")));
      Scanner scan = new Scanner(new File("small.in"));

      int numCases = scan.nextInt();
      for (int z = 1; z <= numCases; z++)
      {
         int initialSize = scan.nextInt();
         int N = scan.nextInt();
         motes = new int[N];
         for (int i = 0; i < N; i++)
            motes[i] = scan.nextInt();
         
         Arrays.sort(motes);
         int result = magic(initialSize, 0);
         
         System.out.println("Case #" + z + ": " + result);
      }

      scan.close();
   }

   private static int magic(int size, int n)
   {
      if (n == motes.length)
         return 0;
      
      if (size > motes[n])
      {
         return magic(size + motes[n], n+1);
      }
      
      if (size == 1)
      {
         return motes.length;
      }
      
      return Math.min(motes.length - n, 1 + magic(size + (size - 1), n));
   }

}

