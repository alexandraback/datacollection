package round.one.a;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class B
{

   static int maxEnergy, recovery, numActivities;
   static int [] activities;
   static int [][] memo;
   public static void main(String[] args) throws FileNotFoundException
   {
      System.setOut(new PrintStream(new File("small.out")));
      Scanner scan = new Scanner(new File("small.in"));
      
      

      int numCases = scan.nextInt();
      for (int z = 1; z <= numCases; z++)
      {
         maxEnergy = scan.nextInt();
         recovery = scan.nextInt();
         
         numActivities = scan.nextInt();
         activities = new int[numActivities];
         for (int i = 0; i < numActivities; i++)
         {
            activities[i] = scan.nextInt();
         }
         
         memo = new int[numActivities][maxEnergy+1];
         for (int [] arr : memo)
         {
            Arrays.fill(arr, -1);
         }
         
         int result = magic(0, maxEnergy);
         System.out.println("Case #" + z + ": " + result);
      }

      scan.close();
   }

   private static int magic(int activity, int energy)
   {
      if (activity >= activities.length)
      {
         return 0;
      }
      
      if (memo[activity][energy] >= 0)
      {
         return memo[activity][energy];
      }
      
      int best = 0;
      for (int spent = 0; spent <= energy; spent++)
      {
         best = Math.max(best, spent * activities[activity] + 
               magic(activity + 1, Math.min(maxEnergy, energy - spent + recovery)));
      }
      
      memo[activity][energy] = best;
      
      return best;
   }

}

