import java.io.*; 
import java.util.*; 

public class ProblemC 
{
  
  public static void main (String [] args) throws IOException
  {
    Scanner in = new Scanner (new FileReader ("C-small-attempt1.in")); 
    PrintWriter out = new PrintWriter (new FileWriter ("cOut.txt")); 
    int asdf = in.nextInt ();
    for (int cases = 1; cases <= asdf; cases++)
    {
      int a = in.nextInt (); 
      int b = in.nextInt ();
      int n = Math.min (a, b); 
      int m = Math.max (a, b);
      int k = in.nextInt (); 
      if (n < 3)
      {
          out.println ("Case #" + cases + ": " + k);
      }
      else if (n == 3)
      {
        if ( k < 5)
          out.println ("Case #" + cases + ": " + k);
        else if ((k > 4 && k < 8) || (k > 5 && m == 3))
          out.println ("Case #" + cases + ": " + (k - 1));
        else if ((k > 7 && k < 11) || (k > 7 && m == 4))
          out.println ("Case #" + cases + ": " + (k - 2));
        else if ((k > 10 && k < 14) || (k  > 10 && m == 5))
          out.println ("Case #" + cases + ": " + (k - 3));
        else if (k == 14 || (k  > 14 && m == 6))
          out.println ("Case #" + cases + ": " + (k - 4));
      }
      else if (n == 4)
      {
        if (k < 5)
          out.println ("Case #" + cases + ": " + k);
        else if (k < 8)
          out.println ("Case #" + cases + ": " + (k - 1));
        else if (k < 10)
          out.println ("Case #" + cases + ": " + (k - 2));
        else if (k < 12)
          out.println ("Case #" + cases + ": " + (k - 3));
        else if (k < 14)
          out.println ("Case #" + cases + ": " + (k - 4));
        else if (k < 16 && m == 5)
          out.println ("Case #" + cases + ": " + (k - 5));
        else if (m == 5)
          out.println ("Case #" + cases + ": " + (k - 6));
        else
          out.println ("Case #" + cases + ": " + (k - 4));
      }
      else if (n == 5)
      {
        if (k < 5)
          out.println ("Case #" + cases + ": " + k);
        else if (k < 8)
          out.println ("Case #" + cases + ": " + (k - 1));
        else if (k < 10)
          out.println ("Case #" + cases + ": " + (k - 2));
        else if (k < 12)
          out.println ("Case #" + cases + ": " + (k - 3));
        else if (k < 13)
          out.println ("Case #" + cases + ": " + (k - 4));
        else if (k < 15)
          out.println ("Case #" + cases + ": " + (k - 5));
        else if (k < 17)
          out.println ("Case #" + cases + ": " + (k - 6));
        else if (k < 19)
          out.println ("Case #" + cases + ": " + (k - 7));
        else if (k < 21)
          out.println ("Case #" + cases + ": " + (k - 8));
        else
          out.println ("Case #" + cases + ": " + (k - 9));
      }
    }    
    in.close ();
    out.close ();
  }
}