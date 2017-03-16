package gcj.y2014.round1c;

import java.io.BufferedReader;

import gcj.Gcj;

public class PartElf extends Gcj {
	
	private static class Fraction {
		
		private int numerator;
		private int denominator;
		
		public Fraction(int numerator, int denominator) {
			this.numerator = numerator;
			this.denominator = denominator;
			reduce();
		}
		
		public int getNumerator() {
			return numerator;
		}
		
		public int getDenominator() {
			return denominator;
		}
		
		private static int gcd(int n, int m) {
			while (n != 0) {
				int r = m % n;
				m = n;
				n = r;
			}
			return m;
		}
		
		private void reduce() {
			int gcd = gcd(numerator, denominator);
			while (gcd > 1) {
				numerator = numerator / gcd;
				denominator = denominator / gcd;
				gcd = gcd(numerator, denominator);
			}
		}
		
		public Fraction multiply(Fraction fraction) {
			return new Fraction(numerator * fraction.getNumerator(), denominator * fraction.getDenominator());
		}
		
		public boolean greaterThanOrEqualOne() {
			return numerator >= denominator;
		}
		
		public boolean denominatorPowerOfTwo() {
			int x = denominator;
			while ((x % 2 == 0) && x > 1) {
				x = x / 2;
			}
			return x == 1;
		}
		
		@Override
		public String toString() {
			return String.format("%d/%d", numerator, denominator);
		}
	}
	
	private static final Fraction TWO = new Fraction(2, 1);
	
	public static void main(String[] args) throws Exception {
		new PartElf().solve();
	}

	@Override
	protected String getFileName() {
		return "A-small-attempt0";
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
		int numerator = Integer.parseInt(tokens[0]);
		int denominator = Integer.parseInt(tokens[1]);
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
