package round.one.b;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
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
         ArrayList<Hiker> hikers = new ArrayList<>();
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
            Hiker slow, fast;
            if (hikers.get(0).speed < hikers.get(1).speed)
            {
               slow = hikers.get(1);
               fast = hikers.get(0);
            }
            else
            {
               slow = hikers.get(0);
               fast = hikers.get(1);
            }
            
            if (slow.speed == fast.speed)
            {
               System.out.println("Case #" + z + ": 0");
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
//               System.out.println(timeForSlowToComplete + " " + timeForFastToCatchUp);
               
               if (timeForSlowToComplete < timeForFastToCatchUp)
               {
                  System.out.println("Case #" + z + ": 0");
               }
               else
               {
                  System.out.println("Case #" + z + ": 1");
               }
            }
         }
         
      }

      scan.close();
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

