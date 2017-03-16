import java.math.*;
import java.util.*;

public class C
{
	public static boolean check(long x)
	{
		String val=Long.toString(x, 2);
		String output=val;

		for(int b=2; b<=10; b++)
		{
			BigInteger num=new BigInteger(val, b);
			boolean found=false;

			for(BigInteger div=new BigInteger("2"); div.compareTo(BigInteger.valueOf(10))<=0; div=div.add(BigInteger.ONE))
			{
				if( num.remainder(div).compareTo(BigInteger.ZERO)==0 )
				{
					output+=" "+div;
					found=true;
					break;
				}
			}

			if( !found )
				return false;
		}

		System.out.println(output);
		return true;
	}

    public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();

		for(int cases=1; cases<=N; cases++)
		{
			System.out.format("Case #%d:%n", cases);
			int n=sc.nextInt();
			int m=sc.nextInt();
			int c=0;

			for(long i=(1L<<(n-1))|1; c<m && i<1L<<n; i+=2)
				if( check(i) )
					c++;
		}
	}
}
