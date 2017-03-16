import java.math.*;
import java.util.*;

public class Bullseye {

	public static final BigInteger TWO = new BigInteger("2");
	public static final BigInteger FOUR = new BigInteger("4");

	public static BigInteger square(BigInteger x) {
		return x.multiply(x);
	}

	public static BigInteger sqrt(BigInteger x) {
		if (x.equals(BigInteger.ZERO))
			return BigInteger.ZERO;

		BigInteger left = new BigInteger("1");
		BigInteger right = x.add(BigInteger.ZERO);
		while (left.add(BigInteger.ONE).compareTo(right) < 0) {
			BigInteger mid = left.add(right.subtract(left).divide(TWO));
			BigInteger msq = mid.multiply(mid);
			int res = msq.compareTo(x);
			if (res <= 0) {
				left = mid;
			} else {
				right = mid.subtract(BigInteger.ONE);
			}
		}
		if (square(right).compareTo(x) <= 0)
			return right;
		else
			return left;
	}

	public static void solveProblem(int caseNumber, Scanner in) {
		long r = in.nextLong();
		long t = in.nextLong();
		BigInteger bt = new BigInteger(new Long(t).toString());
		bt = bt.add(bt);
		BigInteger br = new BigInteger(new Long(r).toString()).multiply(TWO).subtract(BigInteger.ONE);
		BigInteger delta = square(br);
		delta = delta.add(bt.multiply(FOUR));
		BigInteger result = br.negate().add(sqrt(delta)).divide(FOUR);
		System.out.println("Case #" + caseNumber + ": " + result);
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int numTests = in.nextInt();
		for (int i = 0; i < numTests; i++)
			solveProblem(i + 1, in);
	}

}
