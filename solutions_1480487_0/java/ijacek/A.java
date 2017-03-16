package R1B;

import java.io.*;
import java.util.*;

public class A {

	private static class C {

		int s;
		double d;

		public C(int s) {
			this.s = s;
		}
	}

	private static void solve(int TC) {
		int N = ni();
		int sum = 0;
		C[] c = new C[N + 1];
		C[] b = new C[N + 1];
		for (int i = 0; i < N; i++) {
			b[i] = c[i] = new C(ni());
			sum += c[i].s;
		}
		b[N] = c[N] = new C(1000000);
		Arrays.sort(b, new Comparator<C>() {

			public int compare(C o1, C o2) {
				if ( o1.s < o2.s )
					return -1;
				if ( o1.s > o2.s )
					return 1;
				return 0;
			}
		});

		double d = 0;
		boolean br = false;
		for (int i = 1; i < N + 1 && !br; i++) {
			int diff = b[i].s - b[i - 1].s;
			double ad = diff / (double) sum;
			double all = ad * i;
			double res = 1.0 - d;

			if ( res < all ) {
				all = res;
				ad = res / i;
				br = true;
			}
			d += all;
			for (int j = 0; j < i; j++)
				b[j].d += ad;
		}
		out.print(String.format("Case #%d:", TC));
		for (int i = 0; i < N; i++)
			out.print(String.format(" %.6f", c[i].d * 100));
		out.println();
	}
	private static Scanner sc;
	private static PrintStream out;

	public static void main(String[] args) throws FileNotFoundException, IOException {
		Locale.setDefault(Locale.ENGLISH);

		String file = "tst/R1B/A.sm";
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
