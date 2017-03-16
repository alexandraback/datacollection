package round.one.b;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.LinkedList;
import java.util.Scanner;

public class A
{

   static boolean [] visited = new boolean[1000001];
   static int [] best = new int[1000001];
   public static void main(String[] args) throws FileNotFoundException
   {
      System.setOut(new PrintStream(new File("small.out")));
      Scanner scan = new Scanner(new File("small.in"));

      calculateBest();
      int numCases = scan.nextInt();
      for (int z = 1; z <= numCases; z++)
      {
         System.out.println("Case #" + z + ": " + best[scan.nextInt()]);
      }

      scan.close();
   }
   
   private static int calculateBest()
   {
      LinkedList<Pair> list = new LinkedList<>();
      list.add(new Pair(1, 1));
      visited[1] = true;
      while (!list.isEmpty())
      {
         Pair pair = list.pop();
         best[pair.value] = pair.count; 
         
         int plusOne = pair.value + 1;
         int flipped = flip(pair.value);
         
//         System.out.println(pair.value + " " + plusOne + " " + flipped);
         
         if (plusOne < visited.length && !visited[plusOne])
         {
            visited[plusOne] = true;
            list.add(new Pair(plusOne, pair.count + 1));
         }
         
         if (flipped < visited.length && !visited[flipped])
         {
            visited[flipped] = true;
            list.add(new Pair(flipped, pair.count + 1));
         }
      }
      
      return 0;
   }

   private static int flip(int value)
   {
      String str = value + "";
      return Integer.parseInt(new StringBuilder(str).reverse().toString());
   }

}

class Pair
{
   int value;
   int count;
   
   public Pair(int value, int count)
   {
      this.value = value;
      this.count = count;
            
   }
}

