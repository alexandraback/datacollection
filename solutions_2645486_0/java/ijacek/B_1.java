package R1A;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Locale;
import java.util.Scanner;

// Manage your Energy
public class B {

	private static Scanner sc;
	private static PrintStream out;

	private static void solve(int TC) {
		long E = ni();
		long R = ni();
		if ( R > E )
			R = E;
		int N = ni();
		long[] v = new long[N];

		long max = 0;
		for (int i = 0; i < v.length; i++) {
			v[i] = ni();
			if ( v[i] > max )
				max = v[i];
		}

		long g = 0;
		for (int i = 0; i < v.length; i++) {
			long a = v[i];
			if ( a == max ) {
				g += E * a;
				E = R;
				max = -1;
			}
			else {
				g += R * a;
			}
		}

		out.println(String.format("Case #%d: %d", TC, g));
	}

	public static void main(String[] args) throws FileNotFoundException {
		Locale.setDefault(Locale.ENGLISH);

		String file = "tst/R1A/B.sm";
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
