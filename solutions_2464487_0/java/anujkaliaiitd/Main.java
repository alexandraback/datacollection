import java.util.*;
import java.math.*;
import java.io.*;

public class Main
	{
	public static void main(String args[]) throws IOException
		{
		comp(2,1,9);
		PrintWriter out=new PrintWriter(new File("output.txt"));
		BufferedReader in=new BufferedReader(new FileReader(new File("input.txt")));
		int T=Integer.parseInt(in.readLine());
		for(int i=0;i<T;i++)
			{
			String S[]=in.readLine().split(" ");
			long r=Long.parseLong(S[0]);
			long t=Long.parseLong(S[1]);
			long lo=1,hi=Long.MAX_VALUE/2;
			while(hi-lo>=10)
				{
				long mid=(hi+lo)/2;
				if(comp(mid,r,t)<=0)
					lo=mid-1;
				else
					hi=mid+1;
				}
			for(long j=hi;j>=lo;j--)
				{
				if(comp(j,r,t)<=0)
					{
					out.println("Case #"+(i+1)+": "+j);
					break;
					}
				}
			}
		out.close();
		}

	private static int comp(long n,long r,long t)
		{
		BigInteger nb=new BigInteger(Long.toString(n));
		BigInteger rb=new BigInteger(Long.toString(r));
		BigInteger tb=new BigInteger(Long.toString(t));
		BigInteger two=new BigInteger("2");
		BigInteger sum=two.multiply(nb).multiply(rb);
		sum=sum.add(two.multiply(nb).multiply(nb));
		sum=sum.subtract(nb);
		//System.out.println("sum= "+sum.toString());
		return sum.compareTo(tb);
		}
	}

//must declare new classes here