package gcj2012.qual;

import java.io.*;
import java.util.*;
import java.math.*;

import static java.lang.Math.*;
import static java.lang.Character.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import static java.math.BigInteger.*;

public class C {
	static final char PROB = C.class.getSimpleName().charAt(0);
	static final boolean PRAC = false;

	static final double EPS = 1e-12;
	static final int INF = 1 << 20;
	static final int[] di = { -1, 0, 0, 1 };
	static final int[] dj = { 0, -1, 1, 0 };
	static Scanner sc = new Scanner(System.in);

	final int A, B;

	public C() {
		A = sc.nextInt();
		B = sc.nextInt();
	}

	public String solve() {
		final boolean[] f = new boolean[2000001];

		int num = 0;
		for (int i = A; i > 0; i /= 10)
			num++;

		int d = 1;
		for (int i = 1; i < num; i++)
			d *= 10;

		int ans = 0;
		for (int X = A; X <= B; X++) {
			for (int i = 0, Y = X; i < num; i++, Y = Y % 10 * d + Y / 10)
				if (A <= Y && Y < X && !f[Y]) {
					ans++;
					f[Y] = true;
				}
			for (int i = 0, Y = X; i < num; i++, Y = Y % 10 * d + Y / 10)
				if (Y < X)
					f[Y] = false;
		}
		return "" + ans;
	}

	public static void main(String... args) {
		large();
		int T = Integer.parseInt(sc.nextLine());
		for (int t = 1; t <= T; t++) {
			System.err.printf("Case #%s%n", t);
			System.out.printf("Case #%s: %s%n", t, new C().solve());
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