import java.io.*; 
import java.util.*; 

public class ProblemB 
{
    public static int and (int c, int y)
    {
      int total = 0;
      String a = Integer.toString (c, 2);
      String b = Integer.toString (y, 2);
      for (int x = 0; x < Math.min (a.length (), b.length ()); x++)
      {
        
        // System.out.println (a.charAt (a.length () - 1 - x) + " " + b.charAt (b.length () - 1 - x) + " " + a.charAt (a.length () - 1));
         if (a.charAt (a.length () - 1 - x) == b.charAt (b.length () - 1 - x) && a.charAt (a.length () - 1 - x) == '1')
         {
           total += (int)(Math.pow (2, x));
         }
      }
      return total;
    }
  
    public static void main (String [] args) throws IOException
    {
      Scanner in = new Scanner (new FileReader ("B-small-attempt0.in")); 
      PrintWriter out = new PrintWriter (new FileWriter ("bOut.txt")); 
      int asdf = in.nextInt ();
      for (int cases = 1; cases <= asdf; cases++)
      {
        int a = in.nextInt (); 
        int b=  in.nextInt ();
        int k = in.nextInt (); 
        int total = 0; 
        
        if (a > b)
        {
          int temp = b; 
          b = a; 
          a = temp; 
        }
        total += Math.min (a, k) * b; 
        if (Math.min (a, k) == k)
          total += (a - k) * k;
          for (int x = k; x < a; x++)
          {
            for (int y = k; y < b; y++)
            {
              int temp = and (x, y);
              if (temp < k)
              {
                total ++;
                //System.out.println (x + " " + y);
              }
            }
        }
        out.println ("Case #" + cases + ": " + total);
        
      }    
      in.close ();
      out.close ();
    }
}
