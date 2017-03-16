import java.util.*;
import java.io.*;
import java.text.DecimalFormat;

public class p2 
{
  static double ans=0;
  static int l;
  static double m;
  static String target;
  static int max=0;
  static int si;
  public static void main (String[]args)throws IOException
  {
    Scanner s=new Scanner (new File("B-small-attempt0 (3).in"));
    //Scanner s=new Scanner (new File("in.txt"));
    PrintWriter out=new PrintWriter(new FileWriter("out.txt"));
    //Scanner s=new Scanner (new File("in.txt"));  
    int cases=s.nextInt();
    DecimalFormat df = new DecimalFormat("#.#######");
    for (int tt=0;tt<cases;tt++)
    {
      ans=0;
      max=0;
      int k=s.nextInt();
      l=s.nextInt();
      si=s.nextInt();
      m=(double)1/(double)Math.pow(k,si);
      char[] bet=s.next().toCharArray();
      target=s.next();
      recurse("",bet);
      out.println ("Case #"+(tt+1)+": "+ df.format(max-ans));
      System.out.println ("Case #"+(tt+1)+": "+df.format(max-ans));
    }
    out.close();
    s.close();
  }
  
  public static void recurse(String a,char[]bet)
  {
    if (a.length()<si)
    {
      for (int x=0;x<bet.length;x++)
      {
        recurse(a+bet[x],bet);
      }
    }
    else
    {
      ans+=(double)count(a)*m;
      return;
    }
  }
  public static int count(String a)
  {
    int count=0;
    for (int x=0;x+target.length()<=a.length();x++)
    {
      if (a.substring(x,x+target.length()).equals(target))
        count++;
    }
    max=Math.max(count,max);
    return count;
  }
}