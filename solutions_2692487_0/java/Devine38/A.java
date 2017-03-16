import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/**
 * @author Mark Devine
 * 
 */
public class A {
	static final boolean DEBUG = false;
	static Scanner in;
	static List<PrintStream> out;

	public static void main(String[] args) throws FileNotFoundException {
		out = new ArrayList<PrintStream>();
		out.add(System.out);
		if (DEBUG) {
			in = new Scanner(new File("t"));
		} else {
			in = new Scanner(new File(A.class.getName() + ".in"));
			out.add(new PrintStream(A.class.getName() + ".out"));
		}
		int T = i();
		for (int i = 0; i < T; i++) {
			pf("Case #%d: %s\n", i + 1, solve());
		}
		d("Done");
		in.close();
		for (PrintStream ps : out) {
			ps.close();
		}
	}

	static String solve() {
		int A = i();
		int N = i();
		int[] motes = new int[N];
		int[] tries = new int[N];

		int total = 0;

		for (int i = 0; i < N; i++) {
			motes[i] = i();
		}

		if (A == 1) {
			return N + "";
		}
		Arrays.sort(motes);

		for (int i = 0; i < N; i++) {
			while (A <= motes[i]) {
				A = up(A);
				tries[i]++;
				total++;
			}
			A += motes[i];
		}
		int better = Integer.MAX_VALUE;
		int backTotal = 0;
		for (int i = 0; i < N; i++) {
			backTotal += tries[N - i - 1] - 1;
			better = Math.min(better, total - backTotal);
		}

		return Math.min(total, better) + "";
	}

	static int up(int n) {
		return n + n - 1;
	}

	static void p(String x) {
		for (PrintStream ps : out) {
			ps.print(x);
		}
	}

	static void pl(String x) {
		for (PrintStream ps : out) {
			ps.println(x);
		}
	}

	static void pf(String format, Object... args) {
		for (PrintStream ps : out) {
			ps.printf(format, args);
		}
	}

	static String f(String format, Object... args) {
		return String.format(format, args);
	}

	static void d(String x) {
		System.out.println(x);
	}

	static int i() {
		return in.nextInt();
	}

	static long l() {
		return in.nextLong();
	}

	static String s(String pattern) {
		return in.next(pattern);
	}

	static String li() {
		return in.nextLine();
	}
}