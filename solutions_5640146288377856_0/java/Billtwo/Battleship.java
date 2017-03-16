import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.io.PrintStream;
import java.io.FileOutputStream;
public class Battleship
{
  public static void main(String args[]) throws Exception
  { 
      BufferedReader input = null;
      PrintStream output = null;
      String currentLine;
      int testNo=0;
      int R=0,C=0,W=0;
      
      try
      {
          
          input = new BufferedReader(new FileReader(args[0]));
          output = new PrintStream(new FileOutputStream(args[1]));
          if((currentLine=input.readLine())!=null)
          {
              testNo=Integer.parseInt(currentLine);
          }
          
          for(int i=1;i<=testNo;i++)
          {
              if((currentLine=input.readLine())!=null)
              {
                  String[] items = currentLine.split(" ");
                  R=Integer.parseInt(items[0]);
                  C=Integer.parseInt(items[1]);
                  W=Integer.parseInt(items[2]);
              }
              else
                  throw new IOException("Cannot get data");
          
              output.println("Case #"+ i +": " + play(R,C,W));
          }
      }
      catch (Exception e)
      {
          System.err.println(e);
      }
      finally
      {
          try
          {
              input.close();
              output.close();
          }
          catch (Exception e)
          {
              System.err.println(e);
          }
      }
  }
    
    private static int play(int R,int C, int W)
    {
        int turn=0;
        turn += (C/W)*R;
        turn+=W;
        turn+=(C%W==0 ? -1:0);
        return turn;
    }
}
