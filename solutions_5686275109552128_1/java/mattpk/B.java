import java.io.*;
import java.util.*;

public class B
{
  public static void main (String[] args) throws Exception
  {
  Scanner in = new Scanner(new File("B-large.in"));
// Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
    
    int n = in.nextInt();
    for(int t =0; t<n; t++)
    {
      int numDiners = in.nextInt();
      int[] set = new int[1001];
      int max = 1;
      for (int  x=0; x< numDiners; x++)
      {
        int get = in.nextInt();
        if (get>max) max = get;
        set[get]++;
      }
      
      int best = max;
      for (int x =2; x<= max; x++) // try all maximum values
      {
        // max is x.
        int localAns = x;
        for (int y =x+1; y<= max; y++) // add the number of moves needed to local max
        {
          if (set[y] >0)
          {
          localAns+= (((int)Math.ceil(y/(x*1.0)))*set[y])-set[y];
          }
        }
        best = Math.min(localAns,best);
        //System.out.println("Best for maax " + x+ ": "+ localAns);
      }
      
      String ans = ""+best;
      out.println("Case #" + (t+1) + ": " + ans);
      System.out.println("Case #" + (t+1) + ": " + ans);
    }
    
    
    in.close();
    out.close();
  }
}