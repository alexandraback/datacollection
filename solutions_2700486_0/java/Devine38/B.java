import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * @author Mark Devine
 * 
 */
public class B {
	static final boolean DEBUG = false;
	static Scanner in;
	static List<PrintStream> out;

	public static void main(String[] args) throws FileNotFoundException {
		out = new ArrayList<PrintStream>();
		out.add(System.out);
		if (DEBUG) {
			in = new Scanner(new File("t"));
		} else {
			in = new Scanner(new File(B.class.getName() + ".in"));
			out.add(new PrintStream(B.class.getName() + ".out"));
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
		int N = i();
		int X = i();
		int Y = i();
		double chance = 0.0;

		int rung = Math.abs(X) + Math.abs(Y);
		int height = Y;
		if (rung % 2 != 0) {
			return chance + "";
		}
		rung /= 2;
		// there is one more than this
		int rungHeight = 2 * rung;
		if (beforeRung(rung) + height + 1 > N || (height == rungHeight && N < beforeRung(rung + 1))) {
			return chance + "";
		}

		chance = getChance(N - beforeRung(rung), height, rungHeight);

		return chance + "";
	}

	static double getChance(int rungTries, int height, int rungHeight) {
		double chance = 0.0;
		if (rungTries > rungHeight + height) {
			d(rungTries + " " + height + " " + rungHeight + " " + chance);
			return 1.0;
		}
		if (height == 0) {
			for (int i = 0; i < rungTries; i++) {
				chance += Math.pow(0.5, i + 1);
			}
			d(rungTries + " " + height + " " + rungHeight + " " + chance);
			return chance;
		}
		for (int i = 0; rungTries > i; i++) {
			double extra = getChance(rungTries - i - 1, height - 1, rungHeight) / Math.pow(2, i + 1);
			chance += extra;
		}
		d(rungTries + " " + height + " " + rungHeight + " " + chance);
		return chance;
	}

	static int beforeRung(int rung) {
		if (rung == 0) {
			return 0;
		} else if (rung == 1) {
			return 1;
		} else {
			return beforeRung(rung - 1) + 4 * (rung - 1) + 1;
		}
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