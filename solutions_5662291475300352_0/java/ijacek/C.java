package R1B;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Locale;
import java.util.Scanner;

//
public class C {

	private static Scanner sc;
	private static PrintStream out;

	static double x(int d, int m) {
		return m / 360.0 * (360 - d);
	}

	static int sol1(int d1, int m1, int d2, int m2) {
		double a1 = x(d1, m1);
		double a2 = a1 + m1;
		double b1 = x(d2, m2);
		double b2 = b1 + m2;

		if ( a1 > b1 ) {
			double z = a1;
			a1 = b1;
			b1 = z;

			z = a2;
			a2 = b2;
			b2 = z;

			int k = m1;
			m1 = m2;
			m2 = k;
		}
		if ( m1 >= m2 )
			return 0;

		if ( b1 < a2 )
			return 0;
		return 1;
	}

	static int sol() {
		int N = ni();
		int D = ni();
		int H = ni();
		int M = ni();
		if ( N == 1 ) {
			if ( H == 1 )
				return 0;
			return sol1(D, M, D, M + 1);
		}
		int D1 = ni();
		long H1 = ni();
		int M1 = ni();
		return sol1(D, M, D1, M1);
	}

	private static void solve(int TC) {
		int ret = sol();
		out.println(String.format("Case #%d: %d", TC, ret));
	}

	public static void main(String[] args) throws FileNotFoundException {
		Locale.setDefault(Locale.ROOT);

		String file = "src/R1B/C.sm";
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
