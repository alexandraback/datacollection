import java.io.*; 
import java.util.*; 

public class ProblemB 
{  
  static int n;
  static String [] input;
  
  public static int construct (int [] config, int depth)
  {
    if (depth == n)
    {
      return check (config);
    }
    int counter = 0;
    for (int x = 0; x < n; x++)
    {
     // System.out.print (x);
      if (!contains (config, x))
      {
       // System.out.println (" " + Arrays.toString (config));
        config [depth] = x;
        counter += construct (config, depth + 1);
        config [depth] = -1;
      }
    }
    return counter;
  }
  public static int check (int [] config)
  {
    String train = "";
    for (int x = 0; x < n; x++)
    {
      train += input[config[x]];
    }
    for (int x = 97; x < 123; x++)
    {
      if (train.indexOf (x) != -1)
      {
        for (int y = train.indexOf (x) + 1; y < train.length (); y++)
        {
          int temp = train.indexOf (x, y);
          if (temp == -1)
            break;
           if (temp - y != 0)
           {
             return 0;
           }
        }
      }
    }
    return 1;
  }
  
  public static boolean contains (int [] config, int y)
  {
    for (int x = 0; x < n; x++)
    {
      if (config[x] == y)
        return true;
    }
    return false;
  }
  public static void main (String [] args) throws IOException
  {
    Scanner in = new Scanner (new FileReader ("B-small-attempt0.in")); 
    PrintWriter out = new PrintWriter (new FileWriter ("bOut.txt")); 
    int asdf = in.nextInt ();
    for (int cases = 1; cases <= asdf; cases++)
    {
      System.out.println (cases);
      n = in.nextInt ();
      in.nextLine ();
      String temp = in.nextLine (); 
      input = temp.split (" "); 
      int [] config = new int [n];
      Arrays.fill (config, -1);
      out.println ("Case #" + cases + ": " + construct (config, 0)); 
    }    
    in.close ();
    out.close ();
  }
}