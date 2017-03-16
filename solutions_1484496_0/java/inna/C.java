import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

public class C {

	final static String PREFIX = "C:\\codejam\\C";
//	final static String FILE_NAME = PREFIX + "-test";
	 final static String FILE_NAME = PREFIX + "-small-attempt0";
	// final static String FILE_NAME = PREFIX + "-large";

	private Scanner in;
	private PrintWriter out;

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new C().solveAll();
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
		for (int i = 0; i < n; i++) {
			s[i] = in.nextInt();
		}

		String res = "Impossible";
		loop: for (int i = 1; i < (1 << n); i++) {
			int suma = sum(i, s, n);
			for (int j = 0; j < (1 << n); j++) {
				if (i != j) {
					int sumb = sum(j, s, n);
					if (suma == sumb) {
						res = print(i, s) + print(j, s);
						break loop;
					}
				}
			}
		}

		out.format("Case #%d: %s\n", tc, res);
		System.out.format("Case #%d: %s\n", tc, res);
	}

	private int sum(int z, int[] s, int n) {
		int res = 0;
		for (int i = 0; i < n; i++) {
			if ((z & 1 << i) != 0) {
				res += s[i];
			}
		}
		return res;
	}

	private String print(int z, int[] s) {
		String res = "";
		for (int i = 0; i < s.length; i++) {
			if ((z & 1 << i) != 0) {
				res += " " + s[i];
			}
		}
		return "\n" + res.trim();
	}

}
