import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
	public static class Scanner
	{
		BufferedReader reader;
		StringTokenizer token;
		Scanner(Reader reader)
		{
			this.reader=new BufferedReader(reader);
			this.token=new StringTokenizer("");
		}
		boolean hasNext() throws IOException
		{
			while(!token.hasMoreTokens())
			{
				String str=reader.readLine();
				if(str=="") return false;
				token=new StringTokenizer(str);
			}
			return true;
		}
		String next() throws IOException
		{
			hasNext();
			return token.nextToken();
		}
		int nextInt() throws IOException
		{
			return Integer.parseInt(next());
		}
	}
	static boolean is_even=false;
//	static BigInteger f(BigInteger v)
//	{
//		if(v.compareTo(BigInteger.ZERO)<0) return BigInteger.ZERO;
//		if(!is_even)
//			return v.multiply(BigInteger.valueOf(2).multiply(v).add(BigInteger.ONE));
//		else
//			return v.multiply(v.multiply(BigInteger.valueOf(4)));
//			
//	}
	static BigInteger f(BigInteger r0, BigInteger n)
	{
		return (BigInteger.valueOf(2).multiply(r0).add(BigInteger.ONE)).multiply(n).add(BigInteger.valueOf(2).multiply(n).multiply(n.subtract(BigInteger.ONE)));
	}
	public static void main(String args[]) throws IOException
	{
		Scanner in = new Scanner(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		int TEST=in.nextInt();
		for(int test=1;test<=TEST;test++)
		{
			BigInteger r,t;
			r=new BigInteger(in.next());
			t=new BigInteger(in.next());
			is_even=!r.testBit(0);
			long lb,rb;
			lb=0;
			rb=t.longValue();
			while(lb<rb)
			{
				BigInteger c=BigInteger.valueOf((lb+rb+1)/2);
				BigInteger v=f(r,c);
				if(v.compareTo(t)<=0)
					lb=c.longValue();
				else
					rb=c.longValue()-1;
			}
			out.println("Case #"+test+": "+lb);
			out.flush();
		}
	}

}
