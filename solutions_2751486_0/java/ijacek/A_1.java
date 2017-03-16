package R1C;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Locale;
import java.util.Scanner;

// Consonants
public class A {

	private static Scanner sc;
	private static PrintStream out;
	static boolean[] w = new boolean[26];

	static boolean val(char c) {
		return w[c - 'a'];
	}

	private static void solve(int TC) {
		String s = ns();
		int N = ni();

		int b = -1;
		int n = 0;
		long ret = 0;
		for (int i = 0; i < s.length(); i++) {
			char c = s.charAt(i);
			if ( !val(c) )
				n++;
			else
				n = 0;
			if ( n >= N )
				b = i - N + 1;
			if ( b > -1 )
				ret += b + 1;
		}
		out.println(String.format("Case #%d: %d", TC, ret));
	}

	public static void main(String[] args) throws FileNotFoundException {
		Locale.setDefault(Locale.ENGLISH);

		String file = "tst/R1C/A.sm";
		sc = new Scanner(new FileInputStream(file + ".in"));
		out = new PrintStream(file + ".out");

		w[0] = w['e' - 'a'] = w['i' - 'a'] = w['o' - 'a'] = w['u' - 'a'] = true;
		int TC = ni();
		for (int i = 1; i <= TC; i++)
			solve(i);
	}

	private static int ni() {
		return sc.nextInt();
	}

	private static String ns() {
		return sc.next();
	}
}
