package gcj2012.r1a;

import java.io.*;
import java.util.*;
import java.math.*;

import static java.lang.Math.*;
import static java.lang.Character.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import static java.math.BigInteger.*;

public class B {
	static final char PROB = B.class.getSimpleName().charAt(0);
	static final boolean PRAC = false;

	static final double EPS = 1e-12;
	static final int INF = 1 << 20;
	static final int[] di = { -1, 0, 0, 1 };
	static final int[] dj = { 0, -1, 1, 0 };
	static Scanner sc = new Scanner(System.in);

	private final int N, a[], b[];

	public B() {
		N = sc.nextInt();
		a = new int[N];
		b = new int[N];
		for (int i = 0; i < N; i++) {
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
		}
	}

	public String solve() {
		int ret = N;
		final boolean[] useda = new boolean[N];
		final boolean[] usedb = new boolean[N];
		for (int n = 0, c = 0;;) {
			boolean fail = true;
			for (int i = 0; i < N; i++)
				if (!useda[i] && b[i] <= c) {
					useda[i] = true;
					n++;
					c += usedb[i] ? 1 : 2;
					fail = false;
				}
			if (n == N)
				return "" + ret;

			if (fail) {
				int max = -1;
				for (int i = 0; i < N; i++)
					if (!usedb[i] && a[i] <= c && (max < 0 || b[i] > b[max]))
						max = i;
				if (max >= 0) {
					usedb[max] = true;
					c++;
					ret++;
				} else
					return "Too Bad";
			}
		}
	}

	public static void main(String... args) {
		 small();
		int T = Integer.parseInt(sc.nextLine());
		for (int t = 1; t <= T; t++) {
			System.err.printf("Case #%s%n", t);
			System.out.printf("Case #%s: %s%n", t, new B().solve());
		}
		System.err.println("done.");
	}

	public static void small() {
		String in = PROB + "-small" + (PRAC ? "-practice" : "-attempt" + 0) + ".in";
		String out = PROB + "-small.out";
		if (!PRAC)
			for (int i = 1; new File(PROB + "-small" + "-attempt" + i + ".in").exists(); i++)
				in = PROB + "-small" + "-attempt" + i + ".in";
		try {
			System.setIn(new BufferedInputStream(new FileInputStream(in)));
			System.setOut(new PrintStream(out));
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(0);
		}
		sc = new Scanner(System.in);
	}

	public static void large() {
		String in = PROB + "-large" + (PRAC ? "-practice" : "") + ".in";
		String out = PROB + "-large.out";
		try {
			System.setIn(new BufferedInputStream(new FileInputStream(in)));
			System.setOut(new PrintStream(out));
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(0);
		}
		sc = new Scanner(System.in);
	}

	private static void debug(Object... os) {
		System.err.println(deepToString(os));
	}
}