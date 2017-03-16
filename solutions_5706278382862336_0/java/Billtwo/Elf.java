import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
public class Elf
{
  public static void main(String args[]) throws Exception
  { 
    BufferedReader input = null;
    PrintWriter output = null;
    String currentLine;
    int noOfTests, P, Q;
    String result;
    try
    {
      if(args.length != 2)
        throw new IllegalArgumentException
          ("2 arguents must be given: input file and output file.");

      input = new BufferedReader(new FileReader(args[0]));
      output = new PrintWriter(new FileWriter(args[1]));

      if((currentLine=input.readLine())!=null)
        noOfTests = Integer.parseInt(currentLine);
      else
        throw new IOException("Cannot get the number of tests.");

      for(int i=1;i<noOfTests+1;i++)
      {
        System.out.println("Dealing Case"+i);
        String[] row;
        if((currentLine=input.readLine())!=null)
        {
          row=currentLine.split("/");
          P=Integer.parseInt(row[0]);
          Q=Integer.parseInt(row[1]);
        }
        else
          throw new IOException("Cannot get data");

        result = part(P,Q);
        output.println("Case #" + i + ": " + result);  
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

 private static String part(int P, int Q)
 {
   int gen=1;
   while(true)
   {
     if(gen>=40)
       return "impossible";
     if(2*P>=Q)
     {
       for(int i=0;i<(40-gen);i++)
       {
         if((P*Math.pow(2,i))%Q==0)
           break;
         if(i==(39-gen))
           return "impossible";
       }
       return Integer.toString(gen);
     }
     else
     {
       if(Q%2==0)
         Q /= 2;
       else
         P *= 2;
       gen++;
     }
   }
 }
}
