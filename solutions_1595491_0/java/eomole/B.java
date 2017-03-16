package gcj2012.qual;

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

	final int N, S, p, t[];

	public B() {
		N = sc.nextInt();
		S = sc.nextInt();
		p = sc.nextInt();
		t = new int[N];
		for (int i = 0; i < N; i++)
			t[i] = sc.nextInt();
	}

	public String solve() {
		int s = 0;
		int n = 0;
		for (final int tt : t)
			if (tt + 2 >= p * 3)
				n++;
			else if (tt > 0 && tt + 4 >= p * 3)
				s++;
		return "" + (n + min(s, S));
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