import java.util.*;
import java.io.*;
import java.math.BigInteger;
public class bulls
{
	static BigInteger t,r0;
	static BigInteger two= new BigInteger(2+"");
	static long upper, lower;
	static int T;
	static BigInteger area(long n)
	{
		BigInteger t1= new BigInteger(n+"");
		BigInteger temp= new BigInteger(n+"");
		BigInteger t2= temp.subtract(BigInteger.ONE);
		temp= (r0.multiply(temp)).add(temp.multiply(t2));
		
		temp= two.multiply( temp).add(t1);
		return temp;
	}
	public static void main(String[] args)throws IOException
	{
		Scanner scan= new Scanner(System.in);
		
		T= Integer.parseInt(scan.next());
		for(int x=1; x<=T; x++)
		{
			r0= new BigInteger(scan.next());
			t= new BigInteger(scan.next());
			upper= (long)Math.pow(10,18);
			lower= 0;
			long mid= (upper+lower)/2;
			BigInteger a= BigInteger.ZERO;
		//	System.out.println(t.toString()+" "+r0.toString());
			for(int i=0; i<1000; i++)
			{
				a=area(mid);
				if(x==1)
	//			System.out.println(a.toString()+" "+t+"    "+mid+" "+upper+" "+lower);
				if(lower==upper-1)
				{
					if(area(upper).compareTo(t)>0)
					{
						mid=lower;
						break;
					}
					mid=upper;
					break;
				}
				if(a.compareTo(t)>0)
					upper=mid;
				if(a.compareTo(t)==0)
					break;
				if(a.compareTo(t)<0)
					lower=mid;
				mid=lower+(upper-lower)/2;
			}
			System.out.println("Case #"+x+": "+mid);
		}
	}
}