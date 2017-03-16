package R0;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Locale;
import java.util.Scanner;

// Cookie Clicker Alpha
public class B {

	private static Scanner sc;
	private static PrintStream out;

	static class Sol {

		final double C = sc.nextDouble();
		final double F = sc.nextDouble();
		final double X = sc.nextDouble();

		int fact;
		double time;

		double prod() {
			return 2 + F * fact;
		}

		double timeX() {
			return X / prod();
		}

		double step() {
			time += C / prod();
			fact += 1;
			return time + timeX();
		}
	}

	private static void solve(int TC) {
		Sol s = new Sol();

		double best = s.timeX();
		for (double act = s.step(); act < best; act = s.step())
			best = act;
		out.println(String.format("Case #%d: %.7f", TC, best));
	}

	public static void main(String[] args) throws FileNotFoundException {
		Locale.setDefault(Locale.ENGLISH);

		String file = "tst/R0/B.large";
		sc = new Scanner(new FileInputStream(file + ".in"));
		out = new PrintStream(file + ".out");

		int TC = ni();
		for (int i = 1; i <= TC; i++)
			solve(i);
	}

	private static int ni() {
		return sc.nextInt();
	}
}
