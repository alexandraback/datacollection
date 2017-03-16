import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.io.PrintStream;
import java.io.FileOutputStream;
import java.lang.Math;
public class Monkey
{
  public static void main(String args[]) throws Exception
  { 
      BufferedReader input = null;
      PrintStream output = null;
      String currentLine;
      int testNo=0;
      int K=0,L=0,S=0;
      String KS,LS;
      
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
                  K=Integer.parseInt(items[0]);
                  L=Integer.parseInt(items[1]);
                  S=Integer.parseInt(items[2]);
              }
              else
                  throw new IOException("Cannot get data");
          
              if((currentLine=input.readLine())!=null)
              {
                  KS=currentLine;
              }
              else
                  throw new IOException("Cannot get data");

              if((currentLine=input.readLine())!=null)
              {
                  LS=currentLine;
              }
              else
                  throw new IOException("Cannot get data");

              output.println("Case #"+ i +": " + type(K,L,S,KS,LS));
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
    
    private static double type(int K, int L, int S, String KS, String LS)
    {
        char[] KC=KS.toCharArray();
        char[] LC=LS.toCharArray();
        int[] LTimes=new int[LC.length];
        
        for(int i=0;i<LC.length;i++)
        {
            LTimes[i]=0;
            for(int j=0;j<KC.length;j++)
            {
                if(KC[j]==LC[i])
                    LTimes[i]++;
            }
            if(LTimes[i]==0)
                return 0;
        }
        
//        double[] LP=new double[LC.length];
//        for(int i=0;i<LP.length;i++)
//        {
//            LP[i]=(double)LTimes/(double)K;
//        }
//        char[] max = new char[S];
//        int position=0;
//        double probability=0;
//        for(int i=0;i<S;i++)
//        {
//            
//        }
        
        ArrayList<String> all=new ArrayList<String>();
        for(int i=0;i<Math.pow(K,S);i++)
        {
            char[] newSC = new char[S];
            for(int j=0;j<S;j++)
            {
                newSC[j]=KC[(i/(int)Math.pow(K,j))%K];
            }
            all.add(new String(newSC));
//            int currentSize=all.size();
//            System.out.println(currentSize);
//            for(int j=0;j<K;j++)
//            {
//                for(int k=0;k<currentSize;k++)
//                {
//                    all.add(all.get(k)+Character.toString(KC[j]));
//                }
//            }
//            for(int j=currentSize-1;j>=0;j--)
//            {
//                all.remove(all.get(j));
//            }
        }
        
        int max=-1;
        int total=0;
        for(int i=0;i<all.size();i++)
        {
            int banana = reward(all.get(i),S,LS,L);
            if(banana>max)
                max=banana;
            total+=banana;
        }
        double average = (double)total/(double)all.size();
        return max-average;
    }
    
    private static int reward(String SS,int S,String LS,int L)
    {
        int banana=0;
        for(int i=0;i<=S-L;i++)
        {
            if(SS.startsWith(LS,i))
                banana++;
        }
        return banana;
    }
}
