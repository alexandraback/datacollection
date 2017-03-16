import java.math.BigInteger;
import java.util.Scanner;

public class ABullseye {
	
	static BigInteger two = new BigInteger("2");
	
	static BigInteger calc(BigInteger d, BigInteger r)
	{
		return d.multiply(r).multiply(two).add(two.multiply(d).multiply(d)).subtract(d);
	}

	public static void main(String[] args) {
		int T;
		Scanner in = new Scanner(System.in);
		T = in.nextInt();
		for (int caseNum = 1; caseNum <= T; ++caseNum)
		{
			BigInteger r, t;
			r = in.nextBigInteger();
			t = in.nextBigInteger();
			BigInteger lower = new BigInteger("0"), upper = new BigInteger("1000000000");
			BigInteger d;
			while (true)
			{
				d = (upper.subtract(lower).divide(two).add(lower));
				BigInteger result = calc(d, r);
				if (result.compareTo(t) == 0)
				{
					break;
				}
				else if (result.compareTo(t) > 0)
				{
					upper = d;
				}
				else if (result.compareTo(t) < 0)
				{
					if (calc(d.add(new BigInteger("1")), r).compareTo(t) > 0)
					{
						break;
					}
					lower = d;
				}
			}
			System.out.println("Case #" + caseNum + ": " + d);
		}
	}
}
