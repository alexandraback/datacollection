import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.io.PrintStream;
import java.io.FileOutputStream;
import java.util.Set;
import java.util.ArrayList;
public class Counter
{
  public static void main(String args[]) throws Exception
  { 
      BufferedReader input = null;
      PrintStream output = null;
      String currentLine;
      int testNo=0;
      int N=0;
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
                  N = Integer.parseInt(currentLine);
              }
              else
                  throw new IOException("Cannot get data");

          
              output.println("Case #"+ i +": " + count(N));
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
    
    private static int count(int N)
    {
        ArrayList<Integer> count=new ArrayList<Integer>();
        count.add(0);
        int c=0;
        
        HashSet<Integer> countH = new HashSet<Integer>();
        countH.addAll(count);
        while(!count.contains(N))
        {
            c++;
            ArrayList<Integer> newCount = new ArrayList<Integer>();
            for(int i=0;i<count.size();i++)
            {
                int addition = count.get(i)+1;
                int reverse = 0;
                int copy=count.get(i);
                while(copy!=0)
                {
                    reverse=reverse*10+copy%10;
                    copy/=10;
                }
                
                if(!countH.contains(reverse))
                    newCount.add(reverse);
                if(!countH.contains(addition))
                    newCount.add(addition);
            }
            count = newCount;
            countH.addAll(count);
        }
        return c;
    }
    
}
