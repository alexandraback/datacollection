import java.util.*;
import java.io.*;

public class p21
{
  static int ans=1000;
  public static void main (String[]args)throws IOException
  {
    Scanner s=new Scanner (new File("B-large.in"));
    PrintWriter out=new PrintWriter(new FileWriter("out.txt"));
    //Scanner s=new Scanner (System.in);
    
    int cases=s.nextInt();
    for (int n=0;n<cases;n++)
    {
      int max=0;
      int people=s.nextInt();
      ArrayList<Integer>pan=new ArrayList<Integer>();
      for (int x=0;x<people;x++)
      {
        pan.add(s.nextInt());
      }
      Collections.sort(pan);
      max=pan.get(pan.size()-1);
      int []best=new int [max];
      best[0]=max;
      ans=best[0];
      
      //System.out.println (pan);
      for (int x=1;x<max;x++)
      {
        int count=0;
        for (int y=pan.size()-1;y>=0;y--)
        {
          if (pan.get(y)>x)
          {
            if ((pan.get(y)-x)%x==0)
              count+=(pan.get(y)-x)/x;
            else
              count+=(pan.get(y)-x)/x+1;
          }
          else
            break;
        }
        best[x]=x+count;
      }
      
      for (int x=0;x<max;x++)
      {
        ans=Math.min(ans,best[x]);
      }
      
      out.println ("Case #"+(n+1)+": "+ans+" ");
      System.out.println ("Case: #"+(n+1)+": "+ans+" ");
    }
    out.close();
  }
}