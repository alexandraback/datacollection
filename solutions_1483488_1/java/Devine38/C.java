import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;

/**
 * @author Mark Devine
 * 
 */
public class C {
	static final boolean DEBUG = false;
	static Scanner in;
	static PrintStream out;

	public static void main(String[] args) throws FileNotFoundException {
		if (DEBUG) {
			in = new Scanner(new File("t"));
			out = System.out;
		} else {
			in = new Scanner(new File(C.class.getName() + ".in"));
			out = new PrintStream(C.class.getName() + ".out");
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
		HashSet<String> done = new HashSet<String>();
		int A = i();
		int B = i();

		int pairs = 0;

		for (int n = A; n < B; n++) {
			String num = Integer.toString(n);
			for (int i = 1; i < num.length(); i++) {
				num = num.substring(1, num.length()) + num.charAt(0);
				int test = Integer.parseInt(num);
				if (test >= A && test <= B && n < test) {
					String map = n + ":" + test;
					if (!done.contains(map)) {
						done.add(map);
						pairs++;
					}
				}
			}
		}

		return pairs + "";
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