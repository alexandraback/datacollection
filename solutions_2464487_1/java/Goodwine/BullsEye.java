import java.math.BigInteger;
import java.util.Scanner;

public class BullsEye {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		int t;
		BigInteger ans, pastAns, midAns;
		BigInteger r;
		BigInteger p;
		Scanner sc = new Scanner(System.in);
		t = sc.nextInt();
		BigInteger two = new BigInteger("2"), bigTwo = new BigInteger("2000000000000000000000000000000000");
		BigInteger minThree = new BigInteger("-3");
		int c;
		for (int _ = 1; _ <= t; _++) {
			ans = BigInteger.ONE;
			pastAns = bigTwo;
			r = sc.nextBigInteger();
			p = sc.nextBigInteger();
			while (true) {
				midAns = ans.add(pastAns).divide(two);
				c = midAns.multiply(two.multiply(r).add(two.multiply(midAns.add(BigInteger.ONE))).add(minThree)).compareTo(p);
				if (c == 0) {
					ans = midAns;
					break;
				}
				if (c < 0) {
					if (ans.compareTo(midAns) == 0)
						break;
					ans = midAns;
				}

				if (c > 0) {
					pastAns = midAns;
				}
			}
			System.out.println("Case #" + _ + ": " + ans);
		}

	}
}
