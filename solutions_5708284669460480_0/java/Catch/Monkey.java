import java.io.*;
import java.util.*;
//May 10, 2015
public class Monkey 
{
  public static void main (String [] args) throws IOException
  {
    BufferedReader input = new BufferedReader (new FileReader ("B-small-attempt1.in"));
    PrintWriter output = new PrintWriter (new FileWriter ("output.txt"));
    int count = Integer.parseInt(input.readLine ());
    
    for (int counter = 1; counter <= count; counter ++)
    {
      String [] variables = input.readLine ().split (" ");
      
      int keyboard = Integer.parseInt (variables [0]);
      int wordLength = Integer.parseInt (variables [1]);
      int textSize = Integer.parseInt (variables [2]);
      String keyboardVals = input.readLine ();
      String targetWord = input.readLine ();
      
      boolean possible = true;
      if (wordLength > textSize)
        possible = false;
      
      for (int x = 0; x < targetWord.length(); x ++)
      {
        boolean temp = true;
        for (int y = 0; y < keyboardVals.length(); y ++)
          if (targetWord.charAt (x) == keyboardVals.charAt (y))
          temp = false;
        if (temp)
          possible = false;
      }
      if (possible)
      {
        
        int overlap = 0;
        for (int x = 1; x < targetWord.length(); x ++)
        {
          if (targetWord.substring (0, targetWord.length() - x).equals (targetWord.substring (x, targetWord.length())))
            overlap = targetWord.length() - x;
        }
        //System.out.println (overlap);
        int numberToBring = 0;
        if (overlap != 0)
          numberToBring = (int)Math.floor (((textSize*1.0 - (targetWord.length () - overlap)) / (1.0*overlap)));
        else
          numberToBring = (int)Math.floor (textSize*1.0 / (1.0*targetWord.length()));
        //System.out.println (numberToBring);
        
        
        double chance = 0.0;
        Monkey monkey = new Monkey (keyboardVals, targetWord, textSize);
        int bananas = monkey.totalBananas ("", 0);
        System.out.println (bananas + ", " + monkey.counter);
        chance = numberToBring - bananas*1.0 / monkey.counter * 1.0;
        output.println ("Case #" + counter + ": " + chance);
      }
      else
      {
        output.println ("Case #" + counter + ": " + "0.0");
      }
    }
    output.close ();
  }
  String keyboardVals;
  String targetWord;
  int textSize;
  public Monkey (String one, String two, int three)
  {
    keyboardVals = one;
    targetWord = two;
    textSize = three;
  }
  int counter = 0;
  public int totalBananas (String soFar, int depth)
  {
    int bananas = 0;
    for (int x = 0; x < keyboardVals.length (); x ++)
    {
      if (depth!= textSize)
        bananas += totalBananas (soFar + keyboardVals.charAt (x), depth + 1);
      else
      {
        counter ++;
        for (int count = 0; count < soFar.length () - targetWord.length () + 1; count ++)
          if ((soFar.substring (count, targetWord.length () + count)).equals (targetWord))
          bananas ++;
      }
    }
    return bananas;
  }
}