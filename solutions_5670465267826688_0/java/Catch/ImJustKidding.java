import java.io.*;
import java.util.*;

public class ImJustKidding
{
  Value multiply (char row, char column)
      {
        if (row == '1' || column == '1')
          return (new Value (column, true));
        if (row == 'i')
        {
          if (column == '1')
            return (new Value ('i', true));
          if (column == 'i')
            return (new Value ('1', false));
          if (column == 'j')
            return (new Value ('k', true));
          if (column == 'k')
            return (new Value ('j', false));
        }
        if (row == 'j')
        {
          if (column == '1')
            return (new Value ('j', true));
          if (column == 'i')
            return (new Value ('k', false));
          if (column == 'j')
            return (new Value ('1', false));
          if (column == 'k')
            return (new Value ('i', true));
        }
        if (row == 'k')
        {
          if (column == '1')
            return (new Value ('k', true));
          if (column == 'i')
            return (new Value ('j', true));
          if (column == 'j')
            return (new Value ('i', false));
          if (column == 'k')
            return (new Value ('1', false));
        }
        return (new Value ('?', false));
      }
class Value
    {
      char value;
      boolean positive = true;
      public Value (char value, boolean pos)
      {
        this.value = value;
        positive = pos;
      }
    }
public ImJustKidding ()throws IOException
{
  BufferedReader input = new BufferedReader (new FileReader ("C-small-attempt1.in"));
    PrintWriter output = new PrintWriter (new FileWriter ("output.txt"));
    int count = Integer.parseInt (input.readLine ());
    
      
    
    for (int x = 1; x <= count; x ++)
    {
      String [] variables = input.readLine ().split (" ");
      int len = Integer.parseInt (variables [0]);
      int repeated = Integer.parseInt (variables [1]);
      String text = "";
      String holderText = input.readLine ();
      for (int z = 0; z < repeated; z ++)
        text += holderText;
      boolean check = true;
      char prevValue=' ';
      boolean pos = true;
      int position = 0;
      for (int counter = 0; counter < text.length(); counter ++)
      {
        if (check)
        {
          prevValue = text.charAt (counter);
          check = false;
        }
        else
        {
          Value derp = multiply (prevValue, text.charAt (counter));
          prevValue = derp.value;
          if (!derp.positive)
            pos = !pos;
        }
        if (pos)
        {
          if (position == 0 && prevValue == 'i')
          {
            check = true;
            position ++;
          }
          else if (position == 1 && prevValue == 'j')
          {
            check = true;
            position ++;
          }
        }
      }
      if (pos && position == 2 && prevValue == 'k')
        output.println ("Case #" + x + ": " + "YES");
      else
        output.println ("Case #" + x + ": " + "NO");
    }
    output.close ();
}
  public static void main (String [] args) throws IOException
  {
    ImJustKidding i = new ImJustKidding ();
  }
}