package round1a;

import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class C
{
   static int N;
   static int [] bff;
   static int start;
   static int last;
   static int highestLoop = 0;
   static int [] endCaps;
   public static void main(String[] args) throws Exception
   {
      System.setOut(new PrintStream(new File("a.out")));
      Scanner scan = new Scanner(new File("a.in"));
      int numCases = scan.nextInt();
      for (int z = 1; z <= numCases; z++)
      {
         highestLoop = 0;
         int N = scan.nextInt();
         bff = new int[N];
         for (int i = 0; i < N; i++) 
         {
            bff[i] = scan.nextInt() - 1;
         }
         
         endCaps = new int[N];
         
         for (start = 0; start < N; start++) 
         {
            last = 0;
            boolean []seen = new boolean[N];
            
            search(start, seen, 0);
         }
         int sumOfSegments = 0;
         for (int i = 0; i < endCaps.length; i++)
         {
            sumOfSegments += endCaps[i];
         }
            
         System.out.println("Case #" + z + ": " + Math.max(sumOfSegments, highestLoop));
      }
      scan.close();
   }
   private static void search(int pos, boolean[] seen, int score)
   {
      seen[pos] = true;
      if (seen[bff[pos]])
      {
         if (bff[pos] == last)
         {
            endCaps[pos] = Math.max(endCaps[pos], score);
            return;
         }
         if (bff[pos] == start)
         {
            highestLoop = Math.max(highestLoop, score + 1);
            return;
         }
         else
         {
            return;
         }
      }
      last = pos;
      search(bff[pos], seen, score + 1);
   }
}
