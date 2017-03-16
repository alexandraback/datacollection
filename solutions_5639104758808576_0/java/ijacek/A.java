package R0;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Locale;
import java.util.Scanner;

// Standing Ovation
public class A {

	private static Scanner sc;
	private static PrintStream out;

	private static void solve(int TC) {
		int m = sc.nextInt();
		String s = sc.next();
		int cnt = 0;
		int ret = 0;
		for (int i = 0; i <= m && cnt < 9; i++) {
			int diff = Math.max(0, i - cnt);
			ret += diff;
			cnt += diff + s.charAt(i) - '0';
		}
		out.println(String.format("Case #%d: %d", TC, ret));
	}

	public static void main(String[] args) throws FileNotFoundException {
		Locale.setDefault(Locale.ROOT);

		String file = "tst/R0/A.sm";
		sc = new Scanner(new FileInputStream(file + ".in"));
		out = new PrintStream(file + ".out");

		int TC = sc.nextInt();
		for (int i = 1; i <= TC; i++)
			solve(i);
	}
}
