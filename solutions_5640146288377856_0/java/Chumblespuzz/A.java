package round.one.c;

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
         int R = scan.nextInt();
         int C = scan.nextInt();
         int W = scan.nextInt();
         
         int result = C % W == 0 ? C / W + W - 1 : C / W + W;
         
         
         System.out.println("Case #" + z + ": " + result);
      }

      scan.close();
   }

}

