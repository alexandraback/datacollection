package round.one.c;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class C
{

   public static void main(String[] args) throws FileNotFoundException
   {
      System.setOut(new PrintStream(new File("small.out")));
      Scanner scan = new Scanner(new File("small.in"));

      int numCases = scan.nextInt();
      for (int z = 1; z <= numCases; z++)
      {
         int C = scan.nextInt();
         int D = scan.nextInt();
         int V = scan.nextInt();
         
         boolean[] found = new boolean[V + 1];
         for (int i = 0; i < D; i++)
         {
            int denom = scan.nextInt();
            boolean[] newFound = Arrays.copyOf(found, found.length);
            for (int j = 0; j < found.length; j++)
            {
               if (found[j] && j + denom <= V)
               {
                  newFound[j+denom] = true;
               }
            }
            found = newFound;
            found[denom] = true;
         }
         
         int result = 0;
         for (int i = 1; i <= V; i++)
         {
            if (!found[i])
            {
               result++;
               found[i] = true;
               boolean[] newFound = Arrays.copyOf(found, found.length);
               for (int j = i; j < found.length; j++)
               {
                  if (!found[j] && j + i <= V)
                  {
                     found[j+i] = true;
                  }
               }
               newFound = found;
            }
         }
         
         System.out.println("Case #" + z + ": " + result);
      }

      scan.close();
   }

}

