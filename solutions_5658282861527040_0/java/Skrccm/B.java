import java.util.*;
import java.io.*;
public class B
{
  
  public static void main(String[]args)throws IOException
  {
    Scanner in=new Scanner(new FileReader("B-small-attempt0.in"));
    PrintWriter out=new PrintWriter(new FileWriter("B.out"));
    int n=in.nextInt();
    for(int asd=1;asd<=n;asd++)
      //for(int asd=1;asd<=1;asd++)
    {
      out.print("Case #"+asd+": ");
      int a=in.nextInt();
      int b=in.nextInt();
      int c=in.nextInt();
      int z=0;
      for(int x=0;x<a;x++)
      {
        for(int y=0;y<b;y++)
        {
          if((x&y)<c)
            z++;
        }
      }
      out.println(z);
    }
    in.close();
    out.close();
  }
}