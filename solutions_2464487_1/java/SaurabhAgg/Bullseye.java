import java.math.BigInteger;
import java.util.Scanner;


public class Bullseye
{
	private static BigInteger r;
	private static BigInteger t;
	
	private static BigInteger zero = new BigInteger("0");
	private static BigInteger one = new BigInteger("1");
	private static BigInteger two = new BigInteger("2");
	
	static BigInteger value(BigInteger k)
	{
		return two.multiply(k).multiply(k).add(k.multiply( two.multiply(r).subtract(one) ));
	}

	static BigInteger binary_search(BigInteger low, BigInteger high)
	{
		BigInteger ans = low;
		BigInteger mid = zero;
		while(low.compareTo(high) < 0)
		{
			//System.out.println("low = " + low);
			//System.out.println("high = " + high);
			mid = high.subtract(low);
			mid = mid.divide(two);
			mid = mid.add(low);
			//System.out.println("mid = " + mid);
			BigInteger val = value(mid);
			if(val.compareTo(t) <= 0)
			{
				//System.out.println("a");
				ans = mid;
				low = mid.add(one);
			}
			else
			{
				//System.out.println("b");
				high = mid;
			}
		}
		
		return ans;
	}

	public static void main(String[] args)
	{
		int cases;
		Scanner in = new Scanner(System.in);
		cases = in.nextInt();
		for(int t1 = 1; t1 <= cases; t1++)
		{
			r = new BigInteger(in.next());
			t = new BigInteger(in.next());
			
			BigInteger ans = binary_search(zero, t);
			System.out.println("Case #" + t1 + ": " + ans);
		}
	}
}
