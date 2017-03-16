import java.util.*;
import java.math.*;

public class A
{
	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);

		int T = scan.nextInt();
		BigInteger FIVE = new BigInteger("5");
		BigInteger TWO = new BigInteger("2");
		BigInteger ONE = new BigInteger("1");
		BigInteger FOUR = new BigInteger("4");
		BigDecimal DTWO = new BigDecimal("2");

		for(int ca=1;ca <= T;ca++)
		{
			BigInteger r = scan.nextBigInteger();
			BigDecimal t = scan.nextBigDecimal();

			BigInteger lo = ONE;
			BigInteger hi = new BigInteger("2000000000000000000");
			
			while(hi.compareTo(lo) != 0)
			{
				BigInteger mid = hi.add(lo).divide(TWO).add(ONE);

				BigInteger lo2 = r.add(ONE).multiply(TWO).subtract(ONE);
				BigInteger hi2 = lo2.add(mid.subtract(ONE).multiply(FOUR));
				BigDecimal avg = new BigDecimal(lo2.add(hi2));
				BigDecimal sum = avg.divide(DTWO).multiply(new BigDecimal(mid));

				if(sum.compareTo(t) <= 0)
					lo = mid;
				else if(sum.compareTo(t) > 0)
					hi = mid.subtract(ONE);
			}

			System.out.println("Case #" + ca + ": " + lo);
		}
	}
}