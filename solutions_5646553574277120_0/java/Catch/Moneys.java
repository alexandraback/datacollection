import java.io.*;
import java.util.*;
//May 10, 2015
public class Moneys 
{
  public static void main (String [] args) throws IOException
  {
    BufferedReader input = new BufferedReader (new FileReader ("C-small-attempt1.in"));
    PrintWriter output = new PrintWriter (new FileWriter ("output.txt"));
    int count = Integer.parseInt(input.readLine ());
    
    for (int counter = 1; counter <= count; counter ++)
    {
      String [] variables = input.readLine ().split (" ");
      String [] denominations = input.readLine ().split (" ");
      
      int maxNumberOfUse = Integer.parseInt (variables [0]);
      int numberOfDenominations = Integer.parseInt (variables [1]);
      int maxNumberReqd = Integer.parseInt (variables [2]);
      ArrayList <Integer> currentDenominations = new ArrayList <Integer> ();
      
      for (int x = 0; x < numberOfDenominations; x ++)
        currentDenominations.add (new Integer (denominations [x]));
      
      int total = 0;
      
      if (currentDenominations.get (0) != 1)
      {
        currentDenominations.add (0, 1);
        total ++;
      }
      int previousMax = maxNumberOfUse;
      for (int x = 1; x < currentDenominations.size (); x ++)
      {
        //System.out.println (x + ", " + currentDenominations.get (x - 1) + ", " + currentDenominations.get (x) + ", " + previousMax);
        if (currentDenominations.get (x) > previousMax + 1)
        {
          currentDenominations.add (x, previousMax + 1);
          total ++;
        }
        else
          ;
        previousMax += currentDenominations.get (x) * maxNumberOfUse;
        if (previousMax >= maxNumberReqd)
          break;
      }
      while (previousMax < maxNumberReqd)
      {
        currentDenominations.add (previousMax + 1);
        previousMax += currentDenominations.get (currentDenominations.size () - 1);
        total ++;
      }/*
      for (int x = 0; x < currentDenominations.size (); x ++)
        System.out.print (currentDenominations.get (x) + ", ");
      System.out.println ();*/
      output.println ("Case #" + counter + ": " + total);
    }
    output.close ();
  }
}