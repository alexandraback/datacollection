import java.io.*;
import java.util.*;
import java.math.*;

public class C
{
  static List<Long> goodNum=new ArrayList<Long>();
	public static void main(String[] args) throws Exception
	{
    compute();
		RandomAccessFile in = new RandomAccessFile(args[0],"r");
		int T=Integer.parseInt(in.readLine());
		

		for (int i=1; i<=T; i++)
		{
      String line=in.readLine();
      String[] temp=line.split("[ ]+");
      long A=Long.parseLong(temp[0]);
      long B=Long.parseLong(temp[1]);      
      String ans=solve(A,B);
      System.out.println("Case #"+i+": "+ans);
    }

		in.close();
	}
	

	public static String solve(long A, long B)
  {
    int count=0;
    for (int i=0; i<goodNum.size(); i++)
    {
      long num=goodNum.get(i);
      if (num>=A && num<=B) count++;
    }
    return ""+count;
  }
  
  public static void compute()
  {
    long max=10000000;
    
    for (long i=1; i<=max; i++)
    {
      if (isPal(i))
      {
        long i2=i*i;
        if (isPal(i2))
        {
          //System.out.println(i2);
          goodNum.add(i2);
        }
      }
    }
  }
  
  public static boolean isPal(long a)
  {
    String b=""+a;
    for (int i=0; i<b.length()/2; i++)
    {
      if (b.charAt(i)!=b.charAt(b.length()-1-i)) return false;
    }
    return true;
  }
}