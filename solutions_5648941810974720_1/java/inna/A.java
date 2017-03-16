import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

public class A {

//	final static String FILE_NAME = "A-test";
//	final static String FILE_NAME = "A-small-attempt0";
	final static String FILE_NAME = "A-large";

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
		String[] ts = {"ZERO", "TWO", "SIX", "EIGHT", "THREE", "SEVEN", "FOUR", "FIVE", "ONE", "NINE"};
		int[] ti = {0, 2, 6, 8, 3, 7, 4, 5, 1, 9};
		char[] tch = {'Z', 'W', 'X', 'G', 'H', 'S', 'U', 'V', 'O', 'I'};
		int[] cc = new int[10];
		int[] ll = new int[26];
		String x = in.next();
		for (int i = 0; i < x.length(); i++) {
			ll[x.charAt(i) - 'A']++;
		}

		for (int i = 0; i < 10; i++) {
			char c = tch[i];
			int a = ll[c - 'A'];
			if (a >= 0) {
				cc[ti[i]] = a;
				String s = ts[i];
				for (int k = 0; k < s.length(); k++) {
					ll[s.charAt(k) - 'A'] -= a;
				}
			}
		}

		String res = "";
		for (int i = 0; i < cc.length; i++) {
			while (cc[i] > 0) {
				res += i;
				cc[i]--;
			}
		}
		out.format("Case #%d: %s\n", tc, res);
		System.out.format("Case #%d: %s\n", tc, res);
	}
}
