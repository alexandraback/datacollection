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

    /*System.out.println(6000);
    for (int i=1; i<=6000; i++) System.out.println("1 2000000000000000000");
    if (1==1) return;*/
		

		for (int i=1; i<=T; i++)
		{
		  String line=in.readLine();
		  //System.out.println(line);
		  String[] temp=line.split("[ ]+");
		  long r=Long.parseLong(temp[0]);
		  long t=Long.parseLong(temp[1]);
		  
      String ans=solve2(r,t);
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
  
  public static String solve2(long r, long t)
  {
    long lo=0;
    long hi=2*999999999;
    BigInteger T=new BigInteger(""+t);
    BigInteger X=new BigInteger("2").multiply(new BigInteger(""+r)).subtract(new BigInteger("1"));
    
    for (int i=0; i<200; i++)
    {
      long m=(lo+hi) >> 1;
      /*long val=m*(2*r+2*m-1);
      if (val>t)
        hi=m;
      else
        lo=m+1;
      */
      BigInteger val=new BigInteger("2").multiply(new BigInteger(""+m)).add(X).multiply(new BigInteger(""+m));
      if (val.compareTo(T)>0)
        hi=m;
      else
        lo=m+1;      
    }
    
    return ""+(lo-1);
  }
}