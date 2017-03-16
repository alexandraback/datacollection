import java.util.*;
import java.math.BigInteger;
public class elf
{
	static Scanner scan;
	static int T;
	static long P,Q;
	static String out;
	static BigInteger pow2= new BigInteger((long)Math.pow(2,40)+"");
	
	static long gcd(long a, long b)
	{
		if(b==0)
			return a;
		return gcd(b, a%b);
	}
	static boolean isPow(long a)
	{
		for(long i=0; i<=40; i++)
		{
			if(a==1)
				return true;
			if(a%2==1)
				return false;
			a/=2;
		}
		return true;
	}
	public static void main(String[] args)
	{
		scan= new Scanner(System.in);
		T= scan.nextInt();
			
		for(int t=1; t<=T; t++)
		{	
			String s= scan.next();
			String[] s1= s.split("/");
			P= Long.parseLong(s1[0]);
			Q= Long.parseLong(s1[1]);
			out="";
			long g= gcd(P,Q);
			P= P/g;
			Q= Q/g;
			
			BigInteger p1= pow2.multiply(new BigInteger(P+""));	
			BigInteger q1= p1.mod(new BigInteger(Q+""));
			
			if(q1.equals(BigInteger.ZERO))
			{
				BigInteger p2=p1.divide(new BigInteger(Q+""));
	//				System.out.println(p1.toString());
				BigInteger[] dr = pow2.divideAndRemainder(p2);
				
				long ans = (long)(Math.log(dr[0].longValue())/Math.log(2));
				if(!dr[1].equals(BigInteger.ZERO))
					ans++;
				
	//			System.out.println(p1.toString());
				
				out= ans+"";
			}
			else
				out="impossible";
			
			int p= (int)(Math.log(Q)/Math.log(2));
	//		System.out.println(p);
			int min= Integer.MAX_VALUE;
			
		
			System.out.println("Case #"+t+": "+out);
		}
	}
}