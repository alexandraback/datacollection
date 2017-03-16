package round1a;

import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class A
{
   public static void main(String[] args) throws Exception
   {
      System.setOut(new PrintStream(new File("a.out")));
      Scanner scan = new Scanner(new File("a.in"));
      int numCases = scan.nextInt();
      for (int z = 1; z <= numCases; z++)
      {
         String in = scan.next();
         String result = in.substring(0, 1);
         char left = in.charAt(0);
         for (int i = 1; i < in.length(); i++) { 
            if (in.charAt(i) >= left) { 
               left = in.charAt(i);
               result = Character.toString(in.charAt(i)) + result;
            } else { 
               result += Character.toString(in.charAt(i));
            }
         }
         System.out.println("Case #" + z + ": " + result);
      }
      scan.close();
   }
}
