import java.io.*;
import java.util.*;

public class NOmino
{
  public static void main (String [] args) throws IOException
  {
    BufferedReader input = new BufferedReader (new FileReader ("D-small-attempt2.in"));
    PrintWriter output = new PrintWriter (new FileWriter ("output.txt"));
    int count = Integer.parseInt(input.readLine ());
    
      
    
    for (int counter = 1; counter <= count; counter ++)
    {
      String [] variables = input.readLine ().split (" ");
      int x = Integer.parseInt (variables [0]);
      int r = Integer.parseInt (variables [1]);
      int c = Integer.parseInt (variables [2]);
      
      if (x >= 7)
      {
        output.println ("Case #" + counter + ": RICHARD");
      }
      else if ((x == 2 && r == 1 && c % 2 == 0) || (x == 2) && c == 1 && r%2 == 0)
      {
        output.println ("Case #" + counter + ": GABRIEL");
      }
      else if ((x == 2 && r == 1 && c % 2 == 1) || (x == 2) && c == 1 && r%2 == 1)
      {
        output.println ("Case #" + counter + ": RICHARD");
      }
      else
      {
        boolean yep = false;
        int smaller = r;
        if (smaller > c)
          smaller = c;
        for (int checker = 0; checker < x/2; checker ++)
        {
          if (!yep &&((checker +1> smaller && x - checker >= smaller)||(checker +1>= smaller && x - checker > smaller)))
          {
            output.println ("Case #" + counter + ": RICHARD");
            yep = true;
          }
        }
        if (!yep)
        {
          if (r*c % x == 0)
            output.println ("Case #" + counter + ": GABRIEL");
          else
            output.println ("Case #" + counter + ": RICHARD");
        }
      }
      
      
      
      
    }
    output.close ();
  }
}