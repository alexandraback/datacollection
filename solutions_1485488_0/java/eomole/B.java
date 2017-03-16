package gcj2012.r1b;

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

	final int H, N, M, C[][], F[][];

	public B() {
		H = sc.nextInt();
		N = sc.nextInt();
		M = sc.nextInt();
		C = new int[N][M];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				C[i][j] = sc.nextInt();
		F = new int[N][M];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				F[i][j] = sc.nextInt();
	}

	public String solve() {
		double[][] wait = new double[N][M];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				wait[i][j] = C[i][j] - F[i][j] >= 50 ? C[i][j] - H >= 50 ? Double.NEGATIVE_INFINITY
						: .1 * (H - C[i][j] + 50.) : Double.POSITIVE_INFINITY;
		double[][] drag = new double[N][M];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				drag[i][j] = .1 * (H - F[i][j] - 20.);

		double[][] min = new double[N][M];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				min[i][j] = Double.POSITIVE_INFINITY;
		min[0][0] = Double.NEGATIVE_INFINITY;

		Queue<P> que = new PriorityQueue<P>();
		que.offer(new P(0, 0, min[0][0]));
		while (!que.isEmpty()) {
			P p = que.poll();
			if (p.time > min[p.i][p.j])
				continue;
			for (int d = 0; d < 4; d++) {
				int ni = p.i + di[d];
				int nj = p.j + dj[d];
				if (0 <= ni && ni < N && 0 <= nj && nj < M)
					if (C[p.i][p.j] - F[ni][nj] >= 50 && C[ni][nj] - F[p.i][p.j] >= 50) {
						double t = time(drag[p.i][p.j], max(wait[ni][nj], min[p.i][p.j]));
						if (t < min[ni][nj]) {
							min[ni][nj] = t;
							que.offer(new P(ni, nj, t));
						}
					}
			}
		}

		if (Double.isInfinite(min[N - 1][M - 1]))
			return "0.0";

		return "" + min[N - 1][M - 1];
	}

	static double time(double drag, double min) {
		return min + (drag + EPS > min ? 1. : 10.);
	}

	static class P implements Comparable<P> {

		final int i, j;
		final double time;

		public P(int i, int j, double time) {
			this.i = i;
			this.j = j;
			this.time = time;
		}

		@Override
		public int compareTo(P o) {
			return Double.compare(time, o.time);
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