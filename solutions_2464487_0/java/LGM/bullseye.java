import java.io.*;
import java.util.Formatter;
import java.util.Scanner;
import java.math.*;
/**
 * Created with IntelliJ IDEA.
 * User: LGM
 * Date: 4/27/13
 * Time: 5:48 AM
 */

public class bullseye
{
	public static void main(String... args) throws FileNotFoundException
	{
		Scanner scanner=new Scanner(new File("small.in"));
		//Scanner scanner=new Scanner(System.in);
		PrintStream stream=new PrintStream("small.out");
		int tt=scanner.nextInt();
		for (int tc=1;tc<=tt;tc++)
		{
			long r=scanner.nextLong(),t = scanner.nextLong();
			long res=0;
			long s=1,e=2000000000000000000L;
			while (s<=e)
			{
				long m=(s+e)/2;
				if (av(m,r,t))
				{
					res=m;
					s=m+1;
				}
				else
					e=m-1;
			}
			stream.println("Case #"+tc+": "+res);
		}
		stream.close();
	}

	private static boolean av(long m, long r, long t)
	{
		BigInteger integer=BigInteger.valueOf(2*r+1).multiply(BigInteger.valueOf(m));
		BigInteger temp=BigInteger.valueOf(m);
		temp=temp.multiply(temp.subtract(BigInteger.ONE));
		temp=temp.multiply(BigInteger.valueOf(2));
		integer=integer.add(temp);
	//	System.err.println(m+ " "+integer);
		return integer.compareTo(BigInteger.valueOf(t))<=0;
	}
}
