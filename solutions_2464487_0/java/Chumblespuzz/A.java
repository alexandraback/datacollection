package round.one.a;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class A
{

   public static void main(String[] args) throws FileNotFoundException
   {
      System.setOut(new PrintStream(new File("small.out")));
      Scanner scan = new Scanner(new File("small.in"));

      
      int numCases = scan.nextInt();
      for (int z = 1; z <= numCases; z++)
      {
         long r = scan.nextLong();
         long t = scan.nextLong();
         
         int count = 0;
         while (t > 0)
         {
            t -= ((r + (2 * count) + 1) * (r + (2 * count) + 1) - (r + (2 * count)) * (r + (2 * count)));
            if (t >= 0)
            {
               count++;
            }
         }
         
         System.out.println("Case #" + z + ": " + count);
      }
      
      scan.close();
   }

}

