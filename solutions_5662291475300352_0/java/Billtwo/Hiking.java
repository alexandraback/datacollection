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
import java.lang.Math;
public class Hiking
{
  public static void main(String args[]) throws Exception
  { 
      BufferedReader input = null;
      PrintStream output = null;
      String currentLine;
      int testNo=0;
      int N=0;
      int[] D=null,H=null,M=null;
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
                  N=Integer.parseInt(currentLine);
                  D = new int[N];
                  H = new int[N];
                  M = new int[N];
              }
              
              for(int j=0;j<N;j++)
              {
                  if((currentLine=input.readLine())!=null)
                  {
                      String[] items = currentLine.split(" ");
                      D[j] = Integer.parseInt(items[0]);
                      H[j] = Integer.parseInt(items[1]);
                      M[j] = Integer.parseInt(items[2]);
                  }
                  else
                      throw new IOException("Cannot get data");
              }

          
              output.println("Case #"+ i +": " + hike(D,H,M));
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
    
    private static int hike(int[] D, int[] H, int[] M)
    {
        int totalNo=0;
        for(int i=0;i<H.length;i++)
        {
            totalNo+=H[i];
        }
        int[] degree=new int[totalNo];
        int[] minute=new int[totalNo];
        int count=0;
        for(int i=0;i<H.length;i++)
        {
            for(int j=0;j<H[i];j++)
            {
                degree[count+j]=D[i];
                minute[count+j]=M[i]+j;
            }
            count+=H[i];
        }
        
        if(sameSpeed(minute))
            return 0;
        
        double highest=Double.MAX_VALUE;
        int highestNo=-1;
        double lowest=0;
        int lowestNo=-1;
        for(int i=0;i<totalNo;i++)
        {
            if(minute[i]>lowest)
            {
                lowest=minute[i];
                lowestNo=i;
            }
            if(minute[i]<highest)
            {
                highest=minute[i];
                highestNo=i;
            }
        }
        int finishL = (int)Math.floor(((double)360-(double)degree[lowestNo])/((double)360/(double)minute[lowestNo]));
        int finishH = (int)Math.floor(((double)360-(double)degree[highestNo])/((double)360/(double)minute[highestNo]));

        
        int encounterL=0;
        double[] rounds = new double[totalNo];
        int[] position = new int[totalNo];
        for(int i=0;i<totalNo;i++)
        {
            if(i!=lowestNo)
            {
                int degreeS=(int)Math.floor(finishL*((double)360/(double)minute[i]));
                rounds[i]=degreeS/360;
                position[i]=(degreeS+degree[i])%360;
                if(rounds[i]<1&&position[i]>=degree[i])
                    encounterL++;
                if(rounds[i]>1)
                {
                    encounterL+=((int)rounds[i]-1);
                    if(position[i]<degree[i])
                        encounterL++;
                }
            }
        }
        
        for(int i=0;i<totalNo;i++)
        {
            rounds[i]=0;
            position[i]=0;
        }
        
        int encounterH=0;
        for(int i=0;i<totalNo;i++)
        {
            if(i!=highestNo)
            {
                int degreeS=(int)Math.floor(finishH*((double)360/(double)minute[i]));
                rounds[i]=degreeS/360;
                position[i]=(degreeS+degree[i])%360;
                if(rounds[i]<1&&position[i]>=degree[i])
                    encounterH++;
                if(rounds[i]>1)
                {
                    encounterH+=((int)rounds[i]-1);
                    if(position[i]<degree[i])
                        encounterH++;
                }
            }
        }
        return encounterL>encounterH ? encounterH : encounterL;
    }
    
    private static boolean sameSpeed(int[] minute)
    {
        int same = minute[0];
        for(int i=1;i<minute.length;i++)
            if(same!=minute[i])
                return false;
        return true;
    }
}
