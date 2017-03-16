import java.util.*;
import java.io.*;

public class p321
{
  static boolean ans=false;
  public static void main (String[]args)throws IOException
  {
    Scanner s=new Scanner (new File("C-small-attempt3.in"));
    //Scanner s=new Scanner (new File("in.txt"));
    PrintWriter out=new PrintWriter(new FileWriter("out.txt"));
    //Scanner s=new Scanner (System.in);
    
    int cases=s.nextInt();
    for (int n=0;n<cases;n++)
    {
      ans=false;
      int l=s.nextInt();
      int xy=s.nextInt();
      String toAdd=s.next();
      String word="";
      StringBuilder str = new StringBuilder(); 
      for (int x=0;x<xy;x++)
        str.append(toAdd);
      word=str.toString();
      if (word.length()<3||l==1)
      {
      }
      else
      {      
        int pos=-1;
        int sign=0;
        String l1="1";
        for (int x=0;x<word.length()-2;x++)
        {
          l1=multiply(l1,word.substring(x,x+1));
          if (l1.length()>1)
          {
            sign++;
            l1=l1.substring(1);
          }
          if (l1.equals("i")&&sign%2==0)
          {
            pos=x;
            break;
          }
        }
        l1="1";
        sign=0;
        if (pos!=-1)
        {
          for (int x=pos+1;x<word.length()-1;x++)
          {
            l1=multiply(l1,word.substring(x,x+1));
            if (l1.length()>1)
            {
              sign++;
              l1=l1.substring(1);
            }
            if (l1.equals("j")&&sign%2==0)
            {
              pos=x;
              break;
            }
          }
        }
        l1="1";
        sign=0;
        if (pos!=-1)
        {
          for (int x=pos+1;x<word.length();x++)
          {
            l1=multiply(l1,word.substring(x,x+1));
            if (l1.length()>1)
            {
              sign++;
              l1=l1.substring(1);
            }          
          }
          if (l1.equals("k")&&sign%2==0)
          {
            ans=true;
          }
          
        }
      }
      if (ans)
      {
        out.println ("Case #"+(n+1)+": YES");
        System.out.println ("Case #"+(n+1)+": YES");
      }
      else
      {
        out.println ("Case #"+(n+1)+": NO");
        System.out.println ("Case #"+(n+1)+": NO");
      }
    }
    out.close();
  }
  
  
  public static String multiply(String a, String b)
  {
    if (a.equals("1"))
      return b;
    else if (b.equals("1"))
      return a;
    else if (a.equals("i")&&b.equals("i"))
      return "-1";
    else if (a.equals("i")&&b.equals("j"))
      return "k";
    else if (a.equals("i")&&b.equals("k"))
      return "-j";
    else if (a.equals("j")&&b.equals("i"))
      return "-k";
    else if (a.equals("j")&&b.equals("j"))
      return "-1";
    else if (a.equals("j")&&b.equals("k"))
      return "i";
    else if (a.equals("k")&&b.equals("i"))
      return "j";
    else if (a.equals("k")&&b.equals("j"))
      return "-i";
    else 
      return "-1";
  }
}