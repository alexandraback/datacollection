import java.io.*;
import java.util.*;

public class Pancakes
{
  public static void main (String [] args) throws IOException
  {
    BufferedReader input = new BufferedReader (new FileReader ("B-small-attempt2.in"));
    PrintWriter output = new PrintWriter (new FileWriter ("output.txt"));
    int count = Integer.parseInt (input.readLine ());
    for (int x = 1; x <= count; x ++)
    {
      int length = Integer.parseInt (input.readLine ());
      String [] variables = input.readLine ().split (" ");
      int currentTime = Integer.MAX_VALUE;
      double maxDiv = 0;
      for (int counter = 0; counter < length; counter ++)
           if (maxDiv < Integer.parseInt (variables [counter]))
             maxDiv = Integer.parseInt (variables [counter]);
      double divCounter = maxDiv;
      int lowestTime = Integer.MAX_VALUE;
      do
      {
        currentTime = 0;
        for (int counter = 0; counter < length; counter ++)
          if (Double.parseDouble (variables [counter]) > divCounter)
          currentTime += Math.ceil (Double.parseDouble (variables [counter]) / divCounter)-1;
        currentTime += divCounter;
        if (lowestTime - currentTime > 0)
          lowestTime = currentTime;
        divCounter --;
      }
      while (divCounter != 0);
      output.println ("Case #" + x + ": " + lowestTime);
    }
    output.close ();
  }
}