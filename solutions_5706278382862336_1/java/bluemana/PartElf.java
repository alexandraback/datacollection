package gcj.y2014.round1c;

import gcj.Gcj;

import java.io.BufferedReader;
import java.math.BigInteger;

public class PartElf extends Gcj {
	
	private static class Fraction {
		
		private BigInteger numerator;
		private BigInteger denominator;
		
		public Fraction(BigInteger numerator, BigInteger denominator) {
			this.numerator = numerator;
			this.denominator = denominator;
			reduce();
		}
		
		public BigInteger getNumerator() {
			return numerator;
		}
		
		public BigInteger getDenominator() {
			return denominator;
		}
		
		private static BigInteger gcd(BigInteger n, BigInteger m) {
			while (n.compareTo(BigInteger.ZERO) != 0) {
				BigInteger r = m.mod(n);
				m = n;
				n = r;
			}
			return m;
		}
		
		private void reduce() {
			BigInteger gcd = gcd(numerator, denominator);
			while (gcd.compareTo(BigInteger.ONE) > 0) {
				numerator = numerator.divide(gcd);
				denominator = denominator.divide(gcd);
				gcd = gcd(numerator, denominator);
			}
		}
		
		public Fraction multiply(Fraction fraction) {
			return new Fraction(numerator.multiply(fraction.getNumerator()), denominator.multiply(fraction.getDenominator()));
		}
		
		public boolean greaterThanOrEqualOne() {
			return numerator.compareTo(denominator) >= 0;
		}
		
		public boolean denominatorPowerOfTwo() {
			BigInteger x = denominator;
			while ((x.mod(BigInteger.valueOf(2)).compareTo(BigInteger.ZERO) == 0) && x.compareTo(BigInteger.ONE) > 0) {
				x = x.divide(BigInteger.valueOf(2));
			}
			return x.compareTo(BigInteger.ONE) == 0;
		}
		
		@Override
		public String toString() {
			return String.format("%d/%d", numerator, denominator);
		}
	}
	
	private static final Fraction TWO = new Fraction(BigInteger.valueOf(2), BigInteger.ONE);
	
	public static void main(String[] args) throws Exception {
		new PartElf().solve();
	}

	@Override
	protected String getFileName() {
		return "A-large";
	}

	@Override
	protected String solveTestCase(int t, BufferedReader reader) throws Exception {
		Fraction fraction = parseFraction(reader);
		int minGenerations = minGenerations(fraction);
		String result = formatResult(t, minGenerations);
		return result;
	}
	
	private static Fraction parseFraction(BufferedReader reader) throws Exception {
		String[] tokens = reader.readLine().split("/");
		BigInteger numerator = BigInteger.valueOf(Long.parseLong(tokens[0]));
		BigInteger denominator = BigInteger.valueOf(Long.parseLong(tokens[1]));
		Fraction result = new Fraction(numerator, denominator);
		return result;
	}
	
	private static int minGenerations(Fraction fraction) {
		return minGenerations(fraction, 0);
	}
	
	private static int minGenerations(Fraction fraction, int generationCount) {
		int result = -1;
		if (generationCount < 40 && fraction.denominatorPowerOfTwo()) {
			Fraction f = fraction.multiply(TWO);
			if (f.greaterThanOrEqualOne()) {
				result = generationCount + 1;
			} else {
				result = minGenerations(f, generationCount + 1);
			}
		}
		return result;
	}

	private static String formatResult(int t, int minGenerations) {
		return String.format("Case #%d: %s", t + 1, minGenerations == -1 ? "impossible" : "" + minGenerations);
	}
}
