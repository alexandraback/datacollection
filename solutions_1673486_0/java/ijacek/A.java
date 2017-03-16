package R1A;

import java.io.*;
import java.util.*;

public class A {

	private static void solve(int TC) {
		int A = ni();
		int B = ni();
		int BA = B - A + 1;
		double p[] = new double[A];
		for (int i = 0; i < p.length; i++)
			p[i] = sc.nextDouble();
		double acc[] = new double[A + 1];
		acc[0] = 1;
		for (int i = 1; i < acc.length; i++)
			acc[i] = acc[i - 1] * p[i - 1];

		double min = B + 2;
		for (int i = 0; i <= A; i++) {
			double d = acc[i];
			double r = 2 * (A - i) + BA + (1 - d) * (B + 1);
			if ( r < min )
				min = r;
		}

		out.println(String.format("Case #%d: %.6f", TC, min));
	}
	private static Scanner sc;
	private static PrintStream out;

	public static void main(String[] args) throws FileNotFoundException, IOException {
		Locale.setDefault(Locale.ENGLISH);

		String file = "tst/R1A/A.sm";
		sc = new Scanner(new FileInputStream(file + ".in"));
		out = new PrintStream(file + ".out");

		int TC = ni();
		for (int i = 1; i <= TC; i++) {
			solve(i);
		}
	}

	private static int ni() {
		return sc.nextInt();
	}
}
