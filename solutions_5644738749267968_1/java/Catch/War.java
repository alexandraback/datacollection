import java.io.*;
import java.util.*;

public class War
{
  public static void main (String [] args) throws Exception
  {
    BufferedReader read = new BufferedReader (new FileReader ("D-large.in"));
    PrintWriter print = new PrintWriter (new FileWriter ("output.txt"));
    int iterations = Integer.parseInt (read.readLine ());
    for (int count = 1; count <= iterations; count ++)
    {
      int numberOfBlocks = Integer.parseInt (read.readLine ());
      String [] naomiString = read.readLine ().split (" ");
      String [] kenString = read.readLine ().split (" ");
      double [] naomi = new double [numberOfBlocks];
      double [] ken = new double [numberOfBlocks];
      for (int x = 0; x < numberOfBlocks; x ++)
      {
        naomi [x] = Double.parseDouble (naomiString[x]);
        ken [x] = Double.parseDouble (kenString[x]);
      }
      Arrays.sort (naomi);
      Arrays.sort (ken);
      //Deceitful war
      int lowestNaomi = 0;
      int currentKen = numberOfBlocks - 1;
      int highestNaomi = numberOfBlocks - 1;
      int naomiDeceitPoints = 0;
      while (currentKen >= 0)
      {
        if (naomi [highestNaomi] > ken [currentKen])
        {
          naomiDeceitPoints ++;
          highestNaomi --;
          currentKen --;
        }
        else if (naomi [highestNaomi] < ken [currentKen])
        {
          currentKen --;
          lowestNaomi ++;
        }
        else
        {
          System.out.println ("Error");
        }
      }
      print.print ("Case #" + count + ": " + naomiDeceitPoints);
      //Normal War
      int naomiNormalPoints = 0;
      int currentNaomiBlock = numberOfBlocks - 1;
      int highestKenBlock = numberOfBlocks - 1;
      int lowestKenBlock = 0;
      for (int x = numberOfBlocks - 1; x >= 0; x --)
      {
        if (naomi [x] > ken [highestKenBlock])
        {
          naomiNormalPoints ++;
          lowestKenBlock ++;
        }
        else if (naomi [x] < ken [highestKenBlock])
        {
          highestKenBlock --;
        }
      }
      /*int otherCasePoints = 0;
      for (int x = 0; x < numberOfBlocks; x ++)
      {
        if (naomi [x] > ken [x])
          otherCasePoints ++;
      }
      if (otherCasePoints > naomiNormalPoints)
        System.out.println ("Eff");
      else
        System.out.println ("k");*/
      print.println (" " + naomiNormalPoints);
    }
    print.close ();
  }
}