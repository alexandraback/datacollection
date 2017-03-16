import java.math.*;
import java.util.*;

class ProblemC {

	private static final BigInteger MAX_TRIAL = BigInteger.valueOf(1000);

	private static BigInteger base2conv(long num, int radix) {
		if (radix == 2) {
			return BigInteger.valueOf(num);
		}
		BigInteger v = BigInteger.ONE;
		BigInteger bigRadix = BigInteger.valueOf(radix);
		BigInteger ret = BigInteger.ZERO;
		while (num != 0) {
			if ((num & 1) != 0) ret = ret.add(v);
			v = v.multiply(bigRadix);
			num >>>= 1;
		}
		return ret;
	}

	public static BigInteger extractFactor(BigInteger n) {
		BigInteger two = BigInteger.valueOf(2);

		while (n.mod(two).equals(BigInteger.ZERO)) {
			return two;
		}

		BigInteger f = BigInteger.valueOf(3);
		while (f.compareTo(MAX_TRIAL) < 0) {
			if (n.mod(f).equals(BigInteger.ZERO)) {
				return f;
			} else {
				f = f.add(two);
			}
		}

		return null;
	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();

		for (int i = 1; i <= t; i++) {
			System.out.println("Case #" + t + ":");

			int n = s.nextInt(), j = s.nextInt();
			long value = (1L << (n - 1)) | 1;

			int produced = 0;
			BigInteger converted = null;
			BigInteger[] results = new BigInteger[11];
			outer: for (; produced < j; value += 2) {
				for (int base = 2; base <= 10; base++) {
					converted = base2conv(value, base);
					results[base] = extractFactor(converted);
					if (results[base] == null) {
						continue outer;
					}
				}

				produced++;
				System.out.print(converted);

				for (int base = 2; base <= 10; base++) {
					System.out.print(" " + results[base]);
				}
				System.out.println();
			}
		}
	}

}