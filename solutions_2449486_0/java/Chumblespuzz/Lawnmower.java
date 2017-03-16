
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class Lawnmower
{

   public static void main(String[] args) throws FileNotFoundException
   {
      System.setOut(new PrintStream(new File("small.out")));
      Scanner scan = new Scanner(new File("small.in"));

      int numCases = scan.nextInt();
      for (int z = 1; z <= numCases; z++)
      {
         int height = scan.nextInt();
         int width = scan.nextInt();
         
         int [][] lawn = new int[height][width];
         for (int i = 0; i < height; i++)
         {
            for (int j = 0; j < width; j++)
            {
               lawn[i][j] = scan.nextInt();
            }
         }
         
         boolean valid = true;
         for (int i = 0; i < height; i++)
         {
            for (int j = 0; j < width; j++)
            {
               int val = lawn[i][j];
               
               boolean canHorizontal = true;
               for (int k = 0; k < width; k++)
               {
                  canHorizontal = canHorizontal && val >= lawn[i][k];
               }
               
               boolean canVertical = true;
               for (int k = 0; k < height; k++)
               {
                  canVertical = canVertical && val >= lawn[k][j];
               }
               
               valid = valid && (canHorizontal || canVertical);
            }
         }
         
         System.out.print("Case #" + z + ": ");
         
         System.out.println(valid ? "YES" : "NO");
      }
   }

}

