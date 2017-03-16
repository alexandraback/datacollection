import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

/**
 * @author Mark Devine
 * 
 */
public class B {
	static final boolean DEBUG = false;
	static Scanner in;
	static PrintStream out;

	public static void main(String[] args) throws FileNotFoundException {
		if (DEBUG) {
			in = new Scanner(new File("t"));
			out = System.out;
		} else {
			in = new Scanner(new File(B.class.getName() + ".in"));
			out = new PrintStream(B.class.getName() + ".out");
		}
		int T = i();
		for (int i = 0; i < T; i++) {
			pl(f("Case #%d: %s", i + 1, solve()));
		}
		out.close();
		in.close();
		System.out.println("Done");
	}

	static String solve() {
		int Number = i();
		int Surprising = i();
		int minResult = i();
		
		int supMin = 3 * minResult - 4;
		int regMin = 3 * minResult - 2;
		
		if (supMin == -1) {
			supMin = 1;
		}
		if (supMin <= 0) {
			supMin = 0;
		}
		if (regMin < 0) {
			regMin = 0;
		}
		
		Integer[] results = new Integer[Number];
		for (int i = 0; i < Number; i++) {
			results[i] = i();
		}
		Arrays.sort(results, Collections.reverseOrder());
		
//		pl(f("Suprising min: %d, %d", minResult, supMin));
//		pl(Arrays.toString(results));
		for (int i = 0; i < Number; i++) {
			if (results[i] >= regMin) {
				continue;
			} else if (results[i] >= supMin && Surprising > 0) {
				Surprising--;
				continue;
			} else {
				return i + "";
			}
		}
		
		return Number + "";
	}

	static void p(String x) {
		out.print(x);
	}

	static void pl(String x) {
		out.println(x);
	}

	static String f(String format, Object... args) {
		return String.format(format, args);
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