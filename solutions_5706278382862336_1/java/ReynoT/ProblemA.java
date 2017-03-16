import java.io.*; 
import java.util.*; 

public class ProblemA 
{
  
  public static void main (String [] args) throws IOException
  {
    Scanner in = new Scanner (new FileReader ("A-large.in")); 
    PrintWriter out = new PrintWriter (new FileWriter ("aOut.txt")); 
    int asdf = in.nextInt ();
    for (int cases = 1; cases <= asdf; cases++)
    {
      String [] input = in.next ().split ("/");
      long p = Long.parseLong (input[0]);
      long q = Long.parseLong (input[1]);
      double f = (double)(p)/(double)(q);
      f = f * Math.pow (2, 40);
      long n = (long)f;
      if ((double)n != f)
      {
           out.println ("Case #" + cases + ": impossible");
           continue;
      }
      String fs = Long.toString (n, 2);
      int answer = fs.indexOf ('1');
      answer += 41 - fs.length ();
      out.println ("Case #" + cases + ": " + answer); 
    }    
    in.close ();
    out.close ();
  }
}