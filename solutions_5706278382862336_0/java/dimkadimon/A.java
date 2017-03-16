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
		

		for (int i=1; i<=T; i++)
		{
		  String line=in.readLine();
		  String[] temp=line.split("[/]+");
		  long P=Long.parseLong(temp[0]);
		  long Q=Long.parseLong(temp[1]);      		    

      String ans=solve(P,Q);
      System.out.println("Case #"+i+": "+ans);
    }

		in.close();
	}
	
	
	public static String solve(long P, long Q)
	{
	   long gcd=GCD(P,Q);
	   P/=gcd;
	   Q/=gcd;
	   
	   //Q must be a power of 2
	   boolean ok=false;
	   for (int i=0; i<=63; i++)
	     if ((1<<i)==Q) ok=true;
	     
	   if (!ok) return "impossible";
	   
	   
	   int count=0;
	   
	   long P2=P;
	   long Q2=Q;
	   
	   while(true)
	   {
	     //System.out.println(count+" "+P2+" "+Q2);
	     count++;
	     long nextQ=Q2/2;
	     if (P2-nextQ>=0 && P2-nextQ<=nextQ) break;
	     
	     Q2=nextQ;
	     //P2--;
	   }
	   
	   return ""+count;
  }
  
  
  
	//returns the Greatest Common Divisor of two numbers		public static long GCD(long a, long b)	{		return b==0?a:GCD(b,a%b);	}  
}