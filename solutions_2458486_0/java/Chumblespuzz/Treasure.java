
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Treasure
{

   static List<Integer> [] keyContents;
   static int [] keyType;
   static int [] startKeys;
   static int chestsToOpen;
   static int[][] keyCounts;
   static String [] memo;
   
   public static void main(String[] args) throws FileNotFoundException
   {
      System.setOut(new PrintStream(new File("small.out")));
      Scanner scan = new Scanner(new File("small.in"));

      int numCases = scan.nextInt();
      for (int z = 1; z <= numCases; z++)
      {
         startKeys = new int[201];
         
         int numStartKeys = scan.nextInt();
         chestsToOpen = scan.nextInt();
         
         for (int i = 0; i < numStartKeys; i++)
         {
            startKeys[scan.nextInt()]++;
         }
         
         
         keyType = new int[chestsToOpen];
         keyContents = new List[chestsToOpen];
         
         memo = new String[1 << chestsToOpen];
         for (int i = 0; i < memo.length; i++)
            memo[i] = "-1";
         
         for (int i = 0; i < chestsToOpen; i++)
         {
            keyType[i] = scan.nextInt();
            keyContents[i] =  new ArrayList<>();
            
            int numKeys = scan.nextInt();
            for (int j = 0; j < numKeys; j++)
            {
               keyContents[i].add(scan.nextInt());
            }
         }
       
         String best = solve(0);
         
         System.out.print("Case #" + z + ": ");
         System.out.println(best == null ? "IMPOSSIBLE" : best.substring(0, best.length()));
      }
   }

   private static String solve(int visited)
   {
      if (visited == ((1 << chestsToOpen) - 1))
      {
         return "";
      }
      
      if (memo[visited] == null || !memo[visited].equals("-1"))
      {
         return memo[visited];
      }
      
      int [] keyCounts = getKeyCount(visited);
      
      String best = null;
      for (int i = 0; i < chestsToOpen; i++)
      {
         if ((visited & (1 << i)) == 0)
         {
            String curBest = null;
            
            if (keyCounts[keyType[i]] > 0)
            {
               curBest = solve(visited | (1 << i));
            }
            
            if (curBest != null)
            {
               best = (i + 1) + " " + curBest;
               break;
            }
         }
      }
      memo[visited] = best;
      
      return best;
   }

   private static int [] getKeyCount(int config)
   {
      int [] keys = new int[201];
      for (int i = 0; i < chestsToOpen; i++) 
      {
         if ((config & (1 << i)) > 0)
         {
            keys[keyType[i]]--;
            for (int j = 0; j < keyContents[i].size(); j++)
            {
               keys[keyContents[i].get(j)]++;
            }
         }
      }
      
      for (int i = 0; i < keys.length; i++)
      {
         keys[i] += startKeys[i];
         if (keys[i] <  0) System.out.println("WTF");
      }
      
      return keys;
   }

}

