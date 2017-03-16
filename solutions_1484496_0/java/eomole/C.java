package gcj2012.r1b;

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

	final int N, S[];

	public C() {
		N = sc.nextInt();
		S = new int[N];
		for (int i = 0; i < N; i++)
			S[i] = sc.nextInt();
	}

	public String solve() {
		Set<Integer> s = new HashSet<Integer>();
		int[] sum = new int[1 << N];
		for (int i = 1; i < 1 << N; i++) {
			for (int j = 0; 1 << j <= i; j++)
				if ((i & (1 << j)) > 0)
					sum[i] += S[j];
			if (s.contains(sum[i])) {
				for (int j = 0; j < i; j++)
					if (sum[i] == sum[j]) {
						StringBuilder sbi = new StringBuilder();
						for (int ii = 0; 1 << ii <= i; ii++)
							if ((i & (1 << ii)) > 0) {
								if (sbi.length() > 0)
									sbi.append(' ');
								sbi.append(S[ii]);
							}
						StringBuilder sbj = new StringBuilder();
						for (int jj = 0; 1 << jj <= j; jj++)
							if ((j & (1 << jj)) > 0) {
								if (sbj.length() > 0)
									sbj.append(' ');
								sbj.append(S[jj]);
							}
						return sbi + "\n" + sbj;
					}
			}
			s.add(sum[i]);
		}
		return "Impossible";
	}

	public static void main(String... args) {
		 small();
		int T = Integer.parseInt(sc.nextLine());
		for (int t = 1; t <= T; t++) {
			System.err.printf("Case #%s%n", t);
			System.out.printf("Case #%s:%n%s%n", t, new C().solve());
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