import java.io.*;
import java.util.*;

public class B2{
  static int[][] costs = new int[1001][1001];
  
  public static int getCost (int splitFrom, int splitTo){
    if (splitFrom <= splitTo){
      return 0;
    }
    if (costs[splitFrom][splitTo] != 0){
      return costs[splitFrom][splitTo];
    }
    
    //System.out.println ("splitting " + splitFrom + " to " + splitTo);
    
    costs[splitFrom][splitTo] = 1000;
    //System.out.println (splitFrom);
    for (int i = 1; i <= splitFrom/2; i++)
      costs[splitFrom][splitTo] = Math.min (getCost(i, splitTo) + getCost (splitFrom - i, splitTo) + 1, costs[splitFrom][splitTo]);
    //System.out.println (splitFrom);
    return costs[splitFrom][splitTo];
  }
  
  public static void main (String[] args) throws IOException {
    Scanner in = new Scanner (new FileReader ("B-large.in"));
    PrintWriter out = new PrintWriter ("B.out");
    int cases = in.nextInt();
    for (int casenum = 1; casenum <= cases; casenum++){
      int[] pancakes = new int[1001];
      int max = 0;
      int d = in.nextInt();
      for (int i = 0; i < d; i++){
        int size = in.nextInt();
        max = Math.max (size, max);
        pancakes[size]++;
      }
      
      int time = 1000;
      for (int i = 1; i <= max; i++){
        int test = i;
        for (int j = 1; j <= max; j++){
          if (pancakes[j] != 0)
            test += pancakes[j]*getCost(j, i);
        }
        time = Math.min (time, test);
      }
      
      out.println ("Case #" + casenum + ": " + time);
    }
    out.close();
    in.close();
  }
}