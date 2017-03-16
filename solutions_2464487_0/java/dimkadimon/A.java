import java.io.*;
import java.util.*;
import java.math.*;

public class A
{

	public static void main(String[] args) throws Exception
	{
    int T;	
		RandomAccessFile in = new RandomAccessFile(args[0],"r");
		T=Integer.parseInt(in.readLine());
//		System.out.println(T);
		

		for (int i=1; i<=T; i++)
		{
		  String line=in.readLine();
		  //System.out.println(line);
		  String[] temp=line.split("[ ]+");
		  long r=Long.parseLong(temp[0]);
		  long t=Long.parseLong(temp[1]);
		  
      String ans=solve(r,t);
      System.out.println("Case #"+i+": "+ans);
    }

		in.close();
	}
	

	public static String solve(long r, long t)
  {
    int num=0;
    while(true)
    {
      long units=2*r+1;
      if (units<=t)
      {
        t-=units;
        num++;
        r+=2;
      }
      else break;
    }
    return ""+num;
  }
}