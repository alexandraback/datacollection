import java.util.*;
import java.io.*;

public class p4
{
  static String ans="GABRIEL";
  public static void main (String[]args)throws IOException
  {
    Scanner s=new Scanner (new File("D-small-attempt1.in"));
    PrintWriter out=new PrintWriter(new FileWriter("out.txt"));
    //Scanner s=new Scanner (System.in);
    
    int cases=s.nextInt();
    for (int n=0;n<cases;n++)
    {
      int x=s.nextInt();
      int r=s.nextInt();
      int c=s.nextInt();
      
      if (x==1)
        ans="GABRIEL";
      else if (x==2)
      {
        ans="GABRIEL";
        if (r*c%2!=0)
          ans="RICHARD";
      }
      else if (x==3)
      {
        ans="GABRIEL";
        if (r*c%3!=0)
          ans="RICHARD";
        if (r*c==3)
           ans="RICHARD";
      }
      else if (x==4)
      {
        ans="GABRIEL";
        if(r<4&&c<4)
          ans="RICHARD";
        if (r*c%4!=0)
          ans="RICHARD";
        if (r*c==8||r*c==4)
          ans="RICHARD";
      }
      else
      {
        ans="RICHARD";
      }
      
      out.println ("Case #"+(n+1)+": "+ans+" ");
      System.out.println ("Case: #"+(n+1)+": "+ans+" ");
    }
    out.close();
  }
}