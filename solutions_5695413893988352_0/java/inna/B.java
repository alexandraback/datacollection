import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

public class B {

//	final static String FILE_NAME = "B-test";
	final static String FILE_NAME = "B-small-attempt0";
//	final static String FILE_NAME = "B-large";

	private Scanner in;
	private PrintWriter out;

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new B().solveAll();
	}

	private void solveAll() throws Exception {
		in = new Scanner(new File(FILE_NAME + ".in"));
		out = new PrintWriter(new File(FILE_NAME + ".out"));
		int tcn = in.nextInt();
		for (int tc = 1; tc <= tcn; tc++) {
			solve(tc);
		}
		out.close();
	}

	private void solve(int tc) {
		String a = in.next();
		String b = in.next();
		long mind = Long.MAX_VALUE;
		long mina = Long.MAX_VALUE;
		long minb = Long.MAX_VALUE;

		long r = mr(a.length());
		for (int i = 0; i <= r; i++) {
			if (ok(i, a)) {
				for (int j = 0; j <= r; j++) {
					if (ok(j, b)) {
						long d = Math.abs(i - j);
						if ((d < mind)
								|| (d == mind && (i < mina))
								|| (d == mind && (i == mina && j < minb))) {
							mind = d;
							mina = i;
							minb = j;
						}
					}
				}
			}
		}

		String res = tos(mina, a.length()) + " " + tos(minb, a.length());

		out.format("Case #%d: %s\n", tc, res);
		System.out.format("Case #%d: %s\n", tc, res);
	}

	private boolean ok(int n, String s) {
		String ns = tos(n, s.length());
		for (int i = s.length() - 1; i >= 0; i--) {
			if (s.charAt(i) != '?') {
				if (s.charAt(i) != ns.charAt(i)) {
					return false;
				}
			}
		}
		return true;
	}

	private String tos(long n, int length) {
		String res = String.valueOf(n);
		while (res.length() < length) {
			res = "0" + res;
		}
		return res;
	}

	private long mr(int t) {
		long res = 0;
		for (int i = 0; i < t; i++) {
			res *= 10;
			res += 9;
		}
		return res;
	}
}
