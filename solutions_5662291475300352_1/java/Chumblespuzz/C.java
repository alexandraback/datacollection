package round.one.b;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

public class C
{
   static ArrayList<Hiker> hikers = new ArrayList<>();
   
   public static void main(String[] args) throws FileNotFoundException
   {
      System.setOut(new PrintStream(new File("small.out")));
      Scanner scan = new Scanner(new File("small.in"));

      int numCases = scan.nextInt();
      for (int z = 1; z <= numCases; z++)
      {
         hikers = new ArrayList<>();
         int numGroups = scan.nextInt();
         for (int i = 0; i < numGroups; i++)
         {
            long start = scan.nextInt();
            int hikersInGroup = scan.nextInt();
            long speed = scan.nextInt();
            for (int j = 0; j < hikersInGroup; j++)
            {
               hikers.add(new Hiker(start, speed + j));
            }
            
         }
         
         if (hikers.size() == 1)
         {
            System.out.println("Case #" + z + ": 0");
         }
         else
         {
            int best = hikers.size();
            for (int i = 0; i < hikers.size(); i++)
            {
               int numOverlap = 0;
               for (int j = 0; j < hikers.size(); j++)
               {
                  numOverlap += willOverlap(i, j);
               }
               best = Math.min(best, numOverlap);
            }
            System.out.println("Case #" + z + ": " + best);
         }
         
      }

      scan.close();
   }

   private static long willOverlap(int i, int j)
   {
      Hiker slow, fast;
      if (hikers.get(i).speed < hikers.get(j).speed)
      {
         slow = hikers.get(j);
         fast = hikers.get(i);
      }
      else
      {
         slow = hikers.get(i);
         fast = hikers.get(j);
      }
      
      if (slow.speed == fast.speed)
      {
         return 0;
      }
      else
      {
         long timeForSlowToComplete = (360 - slow.start) * slow.speed;
         
         long delta = fast.speed;
         long difference;
         if (fast.start < slow.start)
         {
            difference = 360 - fast.start + 360;
         }
         else
         {
            difference = 360 - fast.start + 360;
         }
         
         long timeForFastToCatchUp = difference * delta;
//         System.out.println(timeForSlowToComplete + " " + timeForFastToCatchUp);
         
         if (timeForSlowToComplete < timeForFastToCatchUp)
         {
            return 0;
         }
         else
         {
            long leftovers = timeForSlowToComplete - timeForFastToCatchUp;
            
            if (hikers.get(i).speed < hikers.get(j).speed)
            {
               return 1;
            }
            else
            {
               return 1 + leftovers / (delta * 360L);
            }
         
         }
      }
   }

}

class Hiker
{
   long start;
   long speed;
   
   public Hiker(long start, long speed)
   {
      this.start = start;
      this.speed = speed;
            
   }
}

