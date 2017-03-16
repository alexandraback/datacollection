package R0;

import java.io.*;
import java.util.*;

public class D {

	private static class Pair {

		int x;
		int y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}

		public boolean equals(Object obj) {
			if ( !(obj instanceof Pair) )
				return false;
			Pair p = (Pair) obj;
			return x == p.x && y == p.y;
		}

		public int hashCode() {
			return 100 * x + y;
		}
	}

	private static boolean odd(int i) {
		return (i & 1) > 0;
	}

	private static int GCD(int a, int b) {
		if ( b > a ) {
			int c = a;
			a = b;
			b = c;
		}
		int c = a % b;
		if ( c == 0 )
			return b;
		return GCD(b, c);
	}

	private static int sign(int i) {
		if ( i == 0 )
			return 0;
		return i > 0 ? 1 : -1;
	}

	private static void solve(int TC) {
		int h = ni();
		int w = ni();
		int d = ni() * 2;
		int x = 0;
		int y = 0;
		for (int i = 0; i < h; i++) {
			String str = ns();
			int a = str.indexOf('X');
			if ( a > 0 ) {
				x = 2 * a - 1;
				y = 2 * i - 1;
			}
		}
		h = (h - 2) * 2;
		w = (w - 2) * 2;
		d *= d;
		int mx = d / w + 2;
		int my = d / h + 2;

		long ret = 0;
		Set<Pair> s = new HashSet<Pair>();
		for (int i = -mx; i <= +mx; i++) {
			int a = i * w + x;
			if ( odd(i) )
				a -= 2 * x - w;
			for (int j = -my; j < +my; j++) {
				if ( i == 0 && j == 0 )
					continue;
				int b = j * h + y;
				if ( odd(j) )
					b -= 2 * y - h;

				int dx = a - x;
				int dy = b - y;
				if ( dx * dx + dy * dy > d )
					continue;
				if ( dx == 0 || dy == 0 ) {
					dx = sign(dx);
					dy = sign(dy);
				} else {
					int k = GCD(Math.abs(dx), Math.abs(dy));
					dx /= k;
					dy /= k;
				}
				Pair p = new Pair(dx, dy);
				if ( !s.contains(p) ) {
					s.add(p);
					ret++;
				}
			}
		}

		out.println(String.format("Case #%d: %d", TC, ret));
	}
	private static final boolean STDIO = false;
	private static final String TASK = "D";
	private static final String ROUND = "R0";
	private static final String DATA = "sm";
	private static Scanner sc;
	private static PrintStream out;

	public static void main(String[] args) throws FileNotFoundException, IOException {
		Locale.setDefault(Locale.ENGLISH);

		String DATA_IN = String.format("tst/%s/%s.%s.in", ROUND, TASK, DATA);
		String DATA_OUT = String.format("tst/%s/%s.%s.out", ROUND, TASK, DATA);

		String str = null;
		if ( args.length > 0 )
			str = args[0];
		else if ( !STDIO )
			str = DATA_IN;
		sc = new Scanner((str != null) ? new FileInputStream(str) : System.in);

		str = null;
		if ( args.length > 1 )
			str = args[1];
		else if ( !STDIO )
			str = DATA_OUT;

		out = (str != null) ? new PrintStream(str) : System.out;

		int TC = ni();
		for (int i = 1; i <= TC; i++) {
			solve(i);
		}
	}

	private static int ni() {
		return sc.nextInt();
	}

	private static String ns() {
		return sc.next();
	}
}
