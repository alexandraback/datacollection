import java.io.*;
import java.util.*;
public class B
{
  public static Double time(Double rate,Double x)
  {
    return (x/rate);
  }
  public static void main(String[] arg)throws IOException
  {
    BufferedReader in=new BufferedReader(new FileReader("B-small-attempt0.in"));
    PrintWriter out=new PrintWriter(new FileWriter("B.out"));
    int num=Integer.parseInt(in.readLine());
    for(int asd=1;asd<=num;asd++)
    {
      out.print("Case #"+asd+": ");
      String[]temp=in.readLine().split(" ");
      Double c=Double.parseDouble(temp[0]);
      Double f=Double.parseDouble(temp[1]);
      Double x=Double.parseDouble(temp[2]);
      Double rate=2.0;
      Double total=0.0;
      while(time(rate+f,x)+time(rate,c)<time(rate,x))
      {
        total+=time(rate,c);
        rate+=f;
        //System.out.println("TOTAL:"+total);
      }
    out.println(total+time(rate,x));
    }
    in.close();
    out.close();
    }
}