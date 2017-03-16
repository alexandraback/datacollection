package R1A;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.math.BigDecimal;
import java.util.Locale;
import java.util.Scanner;

// Bullseye
public class A {

	private static Scanner sc;
	private static PrintStream out;

	private static void solve(int TC) {
		long r = sc.nextLong();
		long t = sc.nextLong();
		long a = 0;
		long b = t / 2;
		BigDecimal bt = BigDecimal.valueOf(t);

		while ((a + 1) < b) {
			long d = (a + b) / 2;
			BigDecimal x = BigDecimal.valueOf(r).multiply(BigDecimal.valueOf(2)).add(BigDecimal.ONE).add(BigDecimal.valueOf(d).multiply(BigDecimal.valueOf(2)));
			BigDecimal y = BigDecimal.valueOf(d).add(BigDecimal.ONE);

			BigDecimal bd = x.multiply(y);
//			long res = (2 * r + 1 + 2 * d) * (d + 1);
			if ( bd.compareTo(bt) > 0 )
				b = d;
			else
				a = d;
		}

		out.println(String.format("Case #%d: %d", TC, a + 1));
	}

	public static void main(String[] args) throws FileNotFoundException {
		Locale.setDefault(Locale.ENGLISH);

		String file = "tst/R1A/A.large";
		sc = new Scanner(new FileInputStream(file + ".in"));
		out = new PrintStream(file + ".out");

		int TC = ni();
		for (int i = 1; i <= TC; i++)
			solve(i);
	}

	private static int ni() {
		return sc.nextInt();
	}
}
