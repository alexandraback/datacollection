import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

public class A {

	final static String PREFIX = "C:\\codejam\\A";
	// final static String FILE_NAME = PREFIX + "-test";
//	final static String FILE_NAME = PREFIX + "-small-attempt2";
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
		int n = in.nextInt();
		int[] s = new int[n];
		int sum = 0;
		int max = 0;
		for (int i = 0; i < n; i++) {
			s[i] = in.nextInt();
			sum += s[i];
			if (s[i] > max) {
				max = s[i];
			}
		}

		String res = "";
		double p = (sum * 2.0) / n;
		int ts = 0;
		int c = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] >= p) {
				c++;
				ts += s[i];
			}
		}
		p = (sum * 2.0 - ts) / (n - c);

		for (int i = 0; i < n; i++) {
			double z = ((p - s[i]) * 100.0) / sum;
			if (z < 0.0) {
				z = 0.0;
			}
			res += " " + z;
		}
		res = res.trim();

		out.format("Case #%d: %s\n", tc, res);
		System.out.format("Case #%d: %s\n", tc, res);
	}

}
