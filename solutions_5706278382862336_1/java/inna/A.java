import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

public class A {

	final static String PREFIX = "C:\\codejam\\A";
//	final static String FILE_NAME = PREFIX + "-test";
//	    final static String FILE_NAME = PREFIX + "-small-attempt0";
	    final static String FILE_NAME = PREFIX + "-large";

	private Scanner in;
	private PrintWriter out;

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new A().solveAll();
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
		String x = in.next();
		String[] split = x.split("/");
		long p = Long.parseLong(split[0]);
		long q = Long.parseLong(split[1]);

		long c = calc(p, q);
		String res = c > 0 ? "" + c : "impossible";

		out.format("Case #%d: %s\n", tc, res);
		System.out.format("Case #%d: %s\n", tc, res);
	}

	private long calc(long p, long q) {
		long res = 0;
		boolean ok = false;
		for (int i = 1; i < 41; i++) {
			long pow = (long) Math.pow(2, i);
			if (p * pow >= q) {
				if (res == 0) {
					res = i;
				}
				long r = q % pow;
				long d = q / pow;
				if (r == 0 && p == d) {
					ok = true;
				} else {
					p -= d;
				}
				if (p < 0 || q < 0) {
					break;
				}
				if (ok) {
					break;
				}
			}
		}
		if (!ok) {
			return 0;
		}
		return res;
	}

}
