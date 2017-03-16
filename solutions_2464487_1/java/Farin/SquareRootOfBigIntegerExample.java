import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.MathContext;
import java.math.RoundingMode;

public class SquareRootOfBigIntegerExample
{

	public BigInteger find(BigInteger my2P100000)
	{

		SquareRootOfBigIntegerExample SquareRootOfBigIntegerExample = new SquareRootOfBigIntegerExample();
		String n = "";

		MathContext mc = new MathContext(0, RoundingMode.DOWN);
		mc = MathContext.DECIMAL32;

		BigInteger two = new BigInteger("2");

		System.err.println("-----");
		System.out.println(my2P100000);
		String mys = my2P100000 + "";
		System.err.println("-----");
		n = (mys);
		int firsttime = 0;

		BigDecimal myNumber = new BigDecimal(n);
		BigDecimal g = new BigDecimal("1");
		BigDecimal my2 = new BigDecimal("2");
		BigDecimal epsilon = new BigDecimal("0.0000000001");

		BigDecimal nByg = myNumber.divide(g, 9, BigDecimal.ROUND_FLOOR);

		// Get the value of n/g
		BigDecimal nBygPlusg = nByg.add(g);

		// Get the value of "n/g + g
		BigDecimal nBygPlusgHalf = nBygPlusg.divide(my2, 9,
				BigDecimal.ROUND_FLOOR);

		// Get the value of (n/g + g)/2
		BigDecimal saveg = nBygPlusgHalf;
		firsttime = 99;

		do
		{
			g = nBygPlusgHalf;
			nByg = myNumber.divide(g, 9, BigDecimal.ROUND_FLOOR);
			nBygPlusg = nByg.add(g);
			nBygPlusgHalf = nBygPlusg.divide(my2, 9, BigDecimal.ROUND_FLOOR);
			BigDecimal savegdiff = saveg.subtract(nBygPlusgHalf);

			if (savegdiff.compareTo(epsilon) == -1)
			{
				firsttime = 0;
			}
			else
			{
				saveg = nBygPlusgHalf;
			}

		}
		while (firsttime > 1);

		BigInteger res = new BigInteger(revise(saveg + ""));
		return res;

	}

	String revise(String s)
	{
		String res = "";
		int i = 0;
		for (i = 0; i < s.length(); i++)
			if (s.charAt(i) != '.')
				res = res + s.charAt(i);
			else
				return res;

		return res;
	}
}