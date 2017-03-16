package gcj2012.r1b;

import java.io.*;
import java.util.*;
import java.math.*;

import static java.lang.Math.*;
import static java.lang.Character.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import static java.math.BigInteger.*;

public class A {
	static final char PROB = A.class.getSimpleName().charAt(0);
	static final boolean PRAC = false;

	static final double EPS = 1e-12;
	static final int INF = 1 << 20;
	static final int[] di = { -1, 0, 0, 1 };
	static final int[] dj = { 0, -1, 1, 0 };
	static Scanner sc = new Scanner(System.in);

	final int N, s[];

	public A() {
		N = sc.nextInt();
		s = new int[N];
		for (int i = 0; i < N; i++)
			s[i] = sc.nextInt();
	}

	public String solve() {
		int sum = 0;
		for (int i : s)
			sum += i;

		double th = 2. * sum / N;
		while (true) {
			int ss = 0;
			int n = 0;
			for (int i = 0; i < N; i++)
				if (s[i] < th) {
					n++;
					ss += s[i];
				}
			double tt = 1. * (sum + ss) / n;
			if (tt > th - EPS)
				break;
			th = tt;
		}

		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < N; i++) {
			if (sb.length() > 0)
				sb.append(' ');

			sb.append(s[i] >= th - EPS ? 0. : 100. * (th - s[i]) / sum);
		}

		return sb.toString();
	}

	public static void main(String... args) {
		large();
		int T = Integer.parseInt(sc.nextLine());
		for (int t = 1; t <= T; t++) {
			System.err.printf("Case #%s%n", t);
			System.out.printf("Case #%s: %s%n", t, new A().solve());
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