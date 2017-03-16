package codejam.round1A;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigInteger;

public class A {

	private static BufferedReader br;

	private static long r, t;

	public static void main(final String[] args) {
		// setStreams("C:\\Users\\Yariv\\Desktop\\test");
		// setStreams("C:\\Users\\Yariv\\Desktop\\A-small-attempt0");
		setStreams("C:\\Users\\Yariv\\Desktop\\A-large");
		br = new BufferedReader(new InputStreamReader(System.in));
		final int numCases = (int) readNumber();
		handleCases(numCases);
	}

	private static void setStreams(final String baseFileName) {
		try {
			System.setIn(new FileInputStream(baseFileName + ".in"));
			System.setOut(new PrintStream(baseFileName + ".out"));
		} catch (final FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	private static void handleCases(final long numCases) {
		for (int i = 1; i <= numCases; i++) {
			handleCase(i);
		}
	}

	private static void handleCase(final int caseNumber) {
		final long[] numbers = readNumbers();
		r = numbers[0];
		t = numbers[1];

		// final long r2 = 2 * r - 1;
		// final long sqr = r2 * r2 + 8 * t;
		// final long sqrt = (long) Math.sqrt(sqr);
		// final long n = (-r2 + sqrt) / 4;

		final BigInteger r2 = new BigInteger(Long.toString(r)).multiply(
				new BigInteger("2")).subtract(new BigInteger("1"));
		final BigInteger sqr = r2.pow(2).add(
				new BigInteger("8").multiply(new BigInteger(Long.toString(t))));
		// log("sqr: " + sqr);
		final BigInteger sqrt = bigIntSqRootFloor(sqr);
		// log("sqrt: " + sqrt);
		final long sqrtL = sqrt.longValue();
		// log("sqrtL: " + sqrtL);
		final long a = (sqrt.subtract(r2)).longValue();
		// log("a: " + a);
		final long n = a / 4;
		// // final BigInteger n = (sqrt.subtract(r2)).divide(new
		// BigInteger("4"));
		// final long n = (-r2.longValue() + sqrt.longValue()) / 4;
		System.out.println("Case #" + caseNumber + ": " + n);
	}

	private static long readNumber() {
		final String line = readLine();
		final long number = Long.parseLong(line);
		return number;
	}

	private static long[] readNumbers() {
		final String line = readLine();
		final String[] numbersStr = line.split(" ");
		final long[] numbers = new long[numbersStr.length];
		for (int i = 0; i < numbersStr.length; i++) {
			numbers[i] = Long.parseLong(numbersStr[i]);
		}
		return numbers;
	}

	private static String readLine() {
		String line = null;
		try {
			line = br.readLine();
		} catch (final IOException e) {
			e.printStackTrace();
		}
		return line;
	}

	private static void log(final String message) {
		System.out.println(message);
	}

	static BigInteger sqrt(BigInteger n) {
		final Double d = Math.sqrt(n.doubleValue());
		n = BigInteger.valueOf(d.longValue());
		return n;
	}

	public static BigInteger bigIntSqRootFloor(final BigInteger x)
			throws IllegalArgumentException {
		if (x.compareTo(BigInteger.ZERO) < 0) {
			throw new IllegalArgumentException("Negative argument.");
		}
		// square roots of 0 and 1 are trivial and
		// y == 0 will cause a divide-by-zero exception
		if (x == BigInteger.ZERO || x == BigInteger.ONE) {
			return x;
		} // end if
		final BigInteger two = BigInteger.valueOf(2L);
		BigInteger y;
		// starting with y = x / 2 avoids magnitude issues with x squared
		for (y = x.divide(two); y.compareTo(x.divide(y)) > 0; y = ((x.divide(y))
				.add(y)).divide(two)) {
			;
		}
		return y;
	} // end bigIntSqRootFloor

	public static BigInteger bigIntSqRootCeil(final BigInteger x)
			throws IllegalArgumentException {
		if (x.compareTo(BigInteger.ZERO) < 0) {
			throw new IllegalArgumentException("Negative argument.");
		}
		// square roots of 0 and 1 are trivial and
		// y == 0 will cause a divide-by-zero exception
		if (x == BigInteger.ZERO || x == BigInteger.ONE) {
			return x;
		} // end if
		final BigInteger two = BigInteger.valueOf(2L);
		BigInteger y;
		// starting with y = x / 2 avoids magnitude issues with x squared
		for (y = x.divide(two); y.compareTo(x.divide(y)) > 0; y = ((x.divide(y))
				.add(y)).divide(two)) {
			;
		}
		if (x.compareTo(y.multiply(y)) == 0) {
			return y;
		} else {
			return y.add(BigInteger.ONE);
		}
	} // end bigIntSqRootCeil
} // end class bigIntSqRoot
