package Round1A;

import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.MathContext;
import java.math.RoundingMode;
import java.util.Scanner;

public class Bullseye {
	static BigInteger one1 = new BigInteger("1");
	static BigInteger eight8 = new BigInteger("8");
	static BigInteger thirtytwo32 = new BigInteger("32");
	public static void main(String[] args) {
		Scanner input = null;
		try {	input = new Scanner(new File("bin\\Round1A\\A-large.in"));	} catch (FileNotFoundException e) {		e.printStackTrace();	}
		int T = input.nextInt();
		input.nextLine();
		long d = 4;
		for (int i = 1; i <= T; i++) {
			String[] s = input.nextLine().split(" ");
			BigInteger r = (new BigInteger(s[0])).subtract(one1);
			BigInteger t = new BigInteger(s[1]);
			System.out.print("Case #" + i + ": ");
			BigInteger a = new BigInteger("3");
			a = a.add(r).add(r); 
			a = a.add(a);
			a = (new BigInteger("4")).subtract(a);
//			System.out.print(" a=" + a + " ");
			BigInteger sqrt = bigSqrt(a.multiply(a).add(t.multiply(thirtytwo32)));
//			System.out.print(" sqrt=" + sqrt + " ");
			sqrt = sqrt.add(a);
			sqrt = sqrt.divide(eight8);
//			long n = (long)(((4 - a) + Math.sqrt((a-4)*(a-4)+32*t))/8);
//			long n = (((4 - a) + SquareRoot((a-4)*(a-4)+32*t))/8);
//			System.out.println(r + " " + t);
			System.out.println(sqrt.toString());
		}
	}
	static BigInteger bigSqrt(BigInteger x){

		String n = "";

		MathContext mc =  new MathContext(0, RoundingMode.DOWN);
		mc = MathContext.DECIMAL32;

		String mys =  x  + "";
		n = (mys) ;
		int firsttime = 0;

		BigDecimal myNumber = new BigDecimal(n);
		BigDecimal g = new BigDecimal("1");
		BigDecimal my2 = new BigDecimal("2");
		BigDecimal epsilon = new BigDecimal("0.0000000001");

		BigDecimal nByg = myNumber.divide(g, 9, BigDecimal.ROUND_FLOOR);

		BigDecimal nBygPlusg = nByg.add(g);

		BigDecimal nBygPlusgHalf =  nBygPlusg.divide(my2, 9, BigDecimal.ROUND_FLOOR);

		BigDecimal  saveg = nBygPlusgHalf;
		firsttime = 99;

		do
		{
			g = nBygPlusgHalf;
			nByg = myNumber.divide(g, 9, BigDecimal.ROUND_FLOOR);
			nBygPlusg = nByg.add(g);
			nBygPlusgHalf =  nBygPlusg.divide(my2, 9, BigDecimal.ROUND_FLOOR);
			BigDecimal  savegdiff  = saveg.subtract(nBygPlusgHalf);

			if (savegdiff.compareTo(epsilon) == -1 )
			{
				firsttime = 0;
			}
			else
			{
				saveg = nBygPlusgHalf;
			}

		} while (firsttime > 1);
		return saveg.toBigInteger();
	}
}
