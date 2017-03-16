package Round1A;

import java.io.*;
import java.util.*;

public class B
{
   static Map<Entry, Integer> memo;
   static int [][] stars;
   static String ideal;
   public static void main(String[] args) throws IOException
   {

      Scanner scan = new Scanner(new File("b_small.in"));
      System.setOut(new PrintStream(new File("b_small.out")));

      int numCases = scan.nextInt();
      for (int z = 1; z <= numCases; z++)
      {
         int numLevels = scan.nextInt();
         stars = new int[numLevels][2];
         String start = "";
         ideal = "";
         memo = new HashMap<Entry, Integer>();
         for (int i = 0; i < numLevels; i++) 
         {
            stars[i][0] = scan.nextInt();
            stars[i][1] = scan.nextInt();
            start += "0";
            ideal += "2";
         }
         int result = brute(start, 0);
//         
//         int totalStars = 0;
//         boolean [][] completed = new boolean[numLevels][2];
//         int result = 0;
//         while (totalStars < numLevels * 2) 
//         {
//            boolean isTwo = false;
//            int chosenIndex = -1;
//            int chosenDiff = -1;
//            for (int j = 0; j < numLevels; j++) 
//            {
//               if (!completed[j][0] && !completed[j][1] && stars[j][1] <= totalStars)
//               {
//                  completed[j][0] = true;
//                  completed[j][1] = true;
//                  totalStars++;
//                  chosenIndex = j;
//                  chosenDiff = 1;
//                  break;
//               }
//               else if (completed[j][0] && !completed[j][1] && stars[j][1] <= totalStars)
//               {
//                  completed[j][1] = true;
//                  chosenIndex = j;
//                  chosenDiff = 1;
//                  isTwo = true;
//               }
//               else if (!isTwo && !completed[j][0] && stars[j][0] <= totalStars) 
//               {
//                  if (chosenIndex == -1)
//                  {
//                     chosenIndex = j;
//                     chosenDiff = 0;
//                  }
//                  else if (stars[chosenIndex][1] < stars[j][1])
//                  {
//                     chosenIndex = j;
//                     chosenDiff = 0;
//                  }
//               }
//            }
//            if (chosenIndex == -1)
//            {
//               result = -1;
//               break;
//            }
//            else
//            {
//               completed[chosenIndex][chosenDiff] = true;
//               totalStars++;
//               result++;
//            }
//         }
         if (result >  10 * numLevels)
            System.out.println("Case #" + z + ": Too Bad");
         else
            System.out.println("Case #" + z + ": " + result);
         
      }

      scan.close();

   }
   
   static int brute(String visited, int get)
   {
      if (visited.equals(ideal))
         return 0;
      
      Entry cur = new Entry(visited, get);
      if (memo.get(cur) != null)
         return memo.get(cur);

      int min = Integer.MAX_VALUE / 10;
      for (int i = 0; i < visited.length(); i++)
      {
         if (visited.charAt(i) == '0')
         {
            if (stars[i][0] <= get)
            {
               if (stars[i][1] <= get)
               {
                  String sub = visited.substring(0, i) + "2" + 
                        visited.substring(i+1, visited.length());
                  min = Math.min(min, 1 + brute(sub, get+2));
               }
               else
               {
                  String sub = visited.substring(0, i) + "1" + 
                        visited.substring(i+1, visited.length());
                  min = Math.min(min, 1 + brute(sub, get+1));
               }
            }
         }
         if (visited.charAt(i) == '1')
         {
            if (stars[i][1] <= get)
            {
               String sub = visited.substring(0, i) + "2" + 
                     visited.substring(i+1, visited.length());
               min = Math.min(min, 1 + brute(sub, get+1));
            }
         }
      }
      memo.put(cur, min);
      return min;
      
   }
}

class Entry
{
   public String visited;
   public int numStars;
   
   public Entry(String visited, int numStars)
   {
      this.visited = visited;
      this.numStars = numStars;
   }
   
   @Override
   public boolean equals(Object o)
   {
      Entry e = (Entry)o;
      return e.visited.equals(this.visited) && e.numStars == this.numStars;
   }
   
   @Override 
   public int hashCode()
   {
      return visited.hashCode() + numStars;
   }
   
}

