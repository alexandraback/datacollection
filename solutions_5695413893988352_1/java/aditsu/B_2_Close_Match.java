import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B_2_Close_Match {
	
	private String repl(final String a, final char x) {
		final char[] c = a.toCharArray();
		for (int i = 0; i < c.length; ++i) {
			if (c[i] == '?') {
				c[i] = x;
			}
		}
		return new String(c);
	}
	
	private boolean less(final Comparable[] a, final Comparable[] b) {
		for (int i = 0; i < 3; ++i) {
			final int x = a[i].compareTo(b[i]);
			if (x < 0) {
				return true;
			}
			if (x > 0) {
				return false;
			}
		}
		return false;
	}
	
	private Comparable[] make(final String a, final String b) {
		return new Comparable[] {Math.abs(Long.parseLong(a) - Long.parseLong(b)), a, b};
	}
	
	private String[] solve(final String a, final String b) {
		if (a.isEmpty()) {
			return new String[]{a, b};
		}
		final char ca = a.charAt(0);
		final char cb = b.charAt(0);
		final char a1 = ca == '?' ? cb == '?' ? '0' : (char) Math.max(cb - 1, '0') : ca;
		final char a2 = ca == '?' ? cb == '?' ? '1' : (char) Math.min(cb + 1, '9') : ca;
		final char b1 = cb == '?' ? ca == '?' ? '0' : (char) Math.max(ca - 1, '0') : cb;
		final char b2 = cb == '?' ? ca == '?' ? '1' : (char) Math.min(ca + 1, '9') : cb;
		Comparable[] best = {Long.MAX_VALUE, "", ""};
		for (char ai = a1; ai <= a2; ++ai) {
			for (char bi = b1; bi <= b2; ++bi) {
				if (ca == '?' && cb == '?' && ai == '1' && bi == '1') {
					continue;
				}
				if (ai == bi) {
					final String[] r = solve(a.substring(1), b.substring(1));
					final Comparable[] t = make(ai + r[0], bi + r[1]);
					if (less(t, best)) {
						best = t;
					}
				}
				else if (ai < bi) {
					final Comparable[] t = make(repl(ai + a.substring(1), '9'), repl(bi + b.substring(1), '0'));
					if (less(t, best)) {
						best = t;
					}
				}
				else {
					final Comparable[] t = make(repl(ai + a.substring(1), '0'), repl(bi + b.substring(1), '9'));
					if (less(t, best)) {
						best = t;
					}
				}
			}
		}
		return new String[]{(String) best[1], (String) best[2]};
	}
	
	public void solve(final Scanner sc, final PrintWriter pw) {
		final String[] a = sc.nextLine().split(" ");
		final String[] r = solve(a[0], a[1]);
		pw.println(r[0] + " " + r[1]);
	}
	
	public static void main(final String... args) throws IOException {
		final String fname = "B-large";
		final Scanner sc = new Scanner(new File(fname + ".in"));
		final PrintWriter pw = new PrintWriter(fname + ".out");
		final int t = sc.nextInt();
		sc.nextLine();
		
		for (int i = 1; i <= t; ++i) {
			System.out.println(i);
			pw.print("Case #" + i + ": ");
			new B_2_Close_Match().solve(sc, pw);
		}
		pw.close();
	}
}
