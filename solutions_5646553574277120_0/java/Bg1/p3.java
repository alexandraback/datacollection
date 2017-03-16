import java.util.*;
import java.io.*;

public class p3 
{
  static int v;
  public static void main (String[]args)throws IOException
  {
    Scanner s=new Scanner (new File("C-small-attempt0 (1).in"));
    //Scanner s=new Scanner (new File("in.txt"));
    PrintWriter out=new PrintWriter(new FileWriter("out.txt"));
    //Scanner s=new Scanner (new File("in.txt"));
    int ans=0;
    int cases=s.nextInt();
    for (int tt=0;tt<cases;tt++)
    {
      ans=0;
      int c=s.nextInt();
      int d=s.nextInt();
      v=s.nextInt();
      int []denom=new int[30];
      Arrays.fill (denom,99999);
      boolean[]pos=new boolean[v+1];
      Arrays.fill (pos,false);
      for (int x=0;x<d;x++)
        denom[x]=s.nextInt();
      
      recurse(pos,"",denom,d);
      
      while (!done(pos))
      {
        int max=0;
        int maxpos=0;
        for (int x=1;x<=30;x++)
        {
          Arrays.sort (denom);
          if (contain(denom,x))continue;
          else
          {
            int temp=count(pos,x);
            if (temp>max)
            {
              max=temp;
              maxpos=x;
            }
          }
        }
        denom[d]=maxpos;
        recurse(pos,"",denom,d+1);
   //     System.out.println (maxpos);
        d++;
        ans++;
//        System.out.println ();
//              for (int x=1;x<v+1;x++)
//        System.out.println(pos[x]);
//              System.out.println ();
      }
      
//      for (int x=1;x<v+1;x++)
//        System.out.println(pos[x]);
      
      out.println ("Case #"+(tt+1)+": "+ans);
      System.out.println ("Case: #"+(tt+1)+": "+ans);
    }
    out.close();
    s.close();
  }
  public static void recurse(boolean[] good,String a, int[] denom,int d)
  {
    if (a.length()<d)
    {
      recurse(good,a+"y",denom,d);
      recurse(good,a+"n",denom,d);
    }
    else
    {
      int sum=0;
      for (int x=0;x<a.length();x++)
      {
        if (a.charAt(x)=='y')
          sum+=denom[x];
      }
      if (sum<=v)
        good[sum]=true;
      return;
    }
  }
  public static boolean done(boolean []arr)
  {
    for (int x=1;x<arr.length;x++)
    {
      if (!arr[x])return false;
    }
    return true;
  }
  public static int count (boolean[]good,int k)
  {
    int count=0;
    boolean[]copy=new boolean[good.length];
    for (int x=0;x<good.length;x++)
    {
      copy[x]=good[x];
    }
    for (int x=0;x+k<=v;x++)
    {
      copy[x+k]=true;
    }
    for (int x=1;x<good.length;x++)
    {
      if (copy[x])count++;
    }
    return count;
  }
  public static boolean contain (int []d,int k)
  {
    for (int x=0;x<d.length;x++)
    {
      if (d[x]==k)return true;
    }
    return false;
  }
}