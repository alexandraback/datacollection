package googlecodejam;

import java.math.BigInteger;
import java.util.Scanner;

public class A {

	private static long powers[] = new long[61];

	private static class Fraction {
		public long nominator;
		public long denominator;

		private Fraction(long nominator, long denominator) {
			this.nominator = nominator;
			this.denominator = denominator;
		}

		public void simplify() {
			long divider = BigInteger.valueOf(nominator).gcd(BigInteger.valueOf(denominator)).longValue();
			nominator /= divider;
			denominator /= divider;
		}

		public boolean isValid() {
			return (nominator < denominator)
					&& (denominator % 2 == 0)
					&& ((nominator * denominator) % 2 == 0);
		}

		public long getSolution() {
			while (nominator != 1) {
				if (nominator % 2 != 0) {
					nominator -= 1;
				}
				this.simplify();
				if (denominator % 2 != 0) {
					return -1;
				}
			}
			if (nominator == 1) {
				int result = 0;
				while (denominator != 1) {
					denominator = denominator >> 1;
					result++;
				}
				return result;
			}
			return 0;
		}
	}

	public static void main(String[] args) {
		initialise();
		Scanner scanner = new Scanner(System.in);
		int totalTests = scanner.nextInt();
		for (int currentTest = 1; currentTest <= totalTests; currentTest++) {
			String fractionString = scanner.next("[0-9]+/[0-9]+");
			String[] parts = fractionString.split("/");
			Fraction fraction = new Fraction(Long.parseLong(parts[0]), Long.parseLong(parts[1]));
			fraction.simplify();
			long solution;
			if (fraction.isValid() && (solution = fraction.getSolution()) != -1) {
				System.out.println("Case #" + currentTest + ": " + solution);
			} else {
				System.out.println("Case #" + currentTest + ": impossible");
			}
		}
	}

	private static void initialise() {
		powers[0] = 1;
		for (int i = 1; i < powers.length; i++) {
			powers[i] = powers[i - 1] * 2;
		}
	}
}
