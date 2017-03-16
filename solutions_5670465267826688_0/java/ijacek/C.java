package R0;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Locale;
import java.util.Scanner;

// Dijkstra
public class C {

	private static Scanner sc;
	private static PrintStream out;

	private static final int[] asc = new int[130];

	static {
		asc['i'] = 2;
		asc['j'] = 3;
		asc['k'] = 4;
	}

	private static final int[][] m = new int[][] {{0,}, {0, 1, 2, 3, 4,}, {0, 2, -1, 4, -3,}, {0, 3, -4, -1, 2,}, {0, 4, 3, -2, -1,},};

	static class Iter {

		final String str;
		final int res;

		int N;
		long X;

		long it;
		int pos;

		Iter() {
			N = ni();
			X = sc.nextLong();
			if ( X > 12 )
				X = 12 + X % 4;
			str = sc.next();
			int r = 1;
			for (int i = 0; i < N; i++)
				r = mul(r, next());
			res = r;
			it = 0;
		}

		int mul(int a, int b) {
			int r = m[Math.abs(a)][Math.abs(b)];
			if ( (a > 0) != (b > 0) )
				r = -r;

			return r;
		}

		boolean is() {
			return it < X && pos < N;
		}

		int next() {
			int ret = asc[str.charAt(pos++)];
			if ( pos == N ) {
				pos = 0;
				it++;
			}
			return ret;
		}

		boolean read(int a) {
			int b = 1;
			long fin = it + 5;
			while (is() && a != b && it < fin)
				b = mul(b, next());

			return a == b;
		}

		boolean end() {
			int b = 1;
			while (pos > 0)
				b = mul(b, next());

			for (long i = it; i < X; i++)
				b = mul(b, res);

			return b == 1;
		}
	}

	static boolean solve() {
		Iter it = new Iter();
		for (int i = 2; i <= 4; i++)
			if ( !it.read(i) )
				return false;

		return it.end();
	}

	public static void main(String[] args) throws FileNotFoundException {
		Locale.setDefault(Locale.ROOT);

		String file = "src/R0/C.sm";
		sc = new Scanner(new FileInputStream(file + ".in"));
		out = new PrintStream(file + ".out");

		int TC = ni();
		for (int i = 1; i <= TC; i++)
			out.println(String.format("Case #%d: %s", i, solve() ? "YES" : "NO"));
	}

	private static int ni() {
		return sc.nextInt();
	}
}
