package contest;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.BigInteger;

public class CodeJam2013R1A
{
	public static void main(String[] args) throws Exception
	{
		// (2r+2k-1)k*pi
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		BigDecimal pi=new BigDecimal("3.141592653589793238462643383279");
		BigInteger two=new BigInteger("2");
		BigInteger one=new BigInteger("1");
		int c=0;
		while( true )
		{
			c++;
			String[] line=in.readLine().split(" ");
			BigInteger x=new BigInteger(line[0]);
			BigInteger y=new BigInteger(line[1]);
			int p,q,r;
			p=1; q=1000000000;
			while( q-p>1 )
			{
				r=(p+q)/2;
				BigInteger R=new BigInteger(""+r);
				BigInteger t=x.add(R).multiply(two).subtract(one).multiply(R);
				if( t.compareTo(y)<=0 ) p=r;
				else q=r;
			}
			System.out.printf("Case #%d: %d\n",c,p);
		}
	}
}
