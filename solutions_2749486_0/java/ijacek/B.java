package R1C;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Locale;
import java.util.Scanner;

// Pogo
public class B {

	private static Scanner sc;
	private static PrintStream out;

	static void add(int n, char a, char b) {
		if ( n < 0 ) {
			char c = a;
			a = b;
			b = c;
			n = -n;
		}
		for (int i = 0; i < n; i++) {
			out.print(a);
			out.print(b);
		}
	}

	private static void solve(int TC) {
		int x = ni();
		int y = ni();
		out.print(String.format("Case #%d: ", TC));

		add(y, 'S', 'N');
		add(x, 'W', 'E');
		out.println();
	}

	public static void main(String[] args) throws FileNotFoundException {
		Locale.setDefault(Locale.ENGLISH);

		String file = "tst/R1C/B.sm";
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
