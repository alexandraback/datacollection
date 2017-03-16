package gcj2013.qual;

import java.io.*;
import java.util.*;
import java.util.concurrent.*;
import java.math.*;

import static java.lang.Math.*;
import static java.lang.Character.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import static java.math.BigInteger.*;

public class DSmall implements Runnable {
	private static final char PROB = DSmall.class.getSimpleName().charAt(0);
	private static final boolean isPractice = false;
	private static final Mode mode = Mode.SMALL;

	private static class Solver implements Callable<String> {
		private static final double EPS = 1e-12;
		private static final int INF = 1 << 20;
		private static final int[] di = { -1, 0, 0, 1 };
		private static final int[] dj = { 0, -1, 1, 0 };

		private final int K, N, start[], T[], chest[][];

		// parse
		public Solver(final Scanner sc) {
			K = sc.nextInt();
			N = sc.nextInt();
			start = new int[K];
			for (int i = 0; i < K; i++)
				start[i] = sc.nextInt() - 1;
			T = new int[N];
			chest = new int[N][];
			for (int i = 0; i < N; i++) {
				T[i] = sc.nextInt() - 1;
				final int k = sc.nextInt();
				chest[i] = new int[k];
				for (int j = 0; j < k; j++)
					chest[i][j] = sc.nextInt() - 1;
			}
		}

		private static final int kmax = 200;

		// solve
		@Override
		public String call() {
			final boolean[] dp = new boolean[1 << N];
			{
				final int[] keycount = new int[kmax];
				for (int j = 0; j < K; j++)
					keycount[start[j]]++;
				for (int i = 0; i < N; i++)
					dp[1 << i] = keycount[T[i]] > 0;
			}
			for (int i = 0; i < 1 << N; i++)
				if (dp[i]) {
					final int[] keycount = new int[kmax];
					for (int j = 0; j < K; j++)
						keycount[start[j]]++;
					for (int j = 0; j < N; j++)
						if ((1 << j & i) > 0) {
							keycount[T[j]]--;
							for (int k = 0; k < chest[j].length; k++)
								keycount[chest[j][k]]++;
						}
					for (int j = 0; j < N; j++)
						if ((1 << j & ~i) > 0 && keycount[T[j]] > 0)
							dp[1 << j | i] = true;
				}

			if (!dp[(1 << N) - 1])
				return "IMPOSSIBLE";

			final int[] match = new int[1 << N];
			Arrays.fill(match, N);
			match[(1 << N) - 1] = 0;
			for (int i = (1 << N) - 1; i >= 0; i--)
				if (dp[i]) {
					final int[] keycount = new int[kmax];
					for (int j = 0; j < K; j++)
						keycount[start[j]]++;
					for (int j = 0; j < N; j++)
						if ((1 << j & i) > 0) {
							keycount[T[j]]--;
							for (int k = 0; k < chest[j].length; k++)
								keycount[chest[j][k]]++;
						}
					for (int j = 0; j < N; j++)
						if ((1 << j & ~i) > 0 && keycount[T[j]] > 0 && match[1 << j | i] < N) {
							match[i] = j;
							break;
						}
				}
			for (int i = 0; i < N; i++)
				if (match[1 << i] < N) {
					match[0] = i;
					break;
				}

			final int[] to = new int[N];
			for (int i = 0, j = 0; i < N; i++, j |= 1 << match[j])
				to[i] = match[j] + 1;

			final StringBuilder sb = new StringBuilder();
			for (int i = 0; i < N; i++) {
				if (i > 0)
					sb.append(' ');
				sb.append(to[i]);
			}

			return sb.toString();
		}
	}

	// Template
	@Override
	public void run() {
		try (final Scanner sc = new Scanner(System.in)) {
			final List<Future<String>> list = new ArrayList<>();
			final int T = sc.nextInt();
			for (int i = 0; i < T; i++)
				list.add(es.submit(new Solver(sc)));
			for (int t = 1; t <= T; t++) {
				debugf("Case #%s%n", t);
				System.out.printf("Case #%s: %s%n", t, list.get(t - 1).get());
			}
			debug("done.");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static void main(String... args) {
		final DSmall t = new DSmall();
		switch (mode) {
		case SAMPLE:
			t.run();
			break;
		case SMALL: {
			String in = PROB + "-small" + (isPractice ? "-practice" : "-attempt" + 0) + ".in";
			String out = PROB + "-small.out";
			if (!isPractice)
				for (int i = 1; new File(PROB + "-small" + "-attempt" + i + ".in").exists(); i++)
					in = PROB + "-small" + "-attempt" + i + ".in";
			try {
				System.setIn(new BufferedInputStream(new FileInputStream(in)));
				System.setOut(new PrintStream(out));
				t.run();
			} catch (Exception e) {
				e.printStackTrace();
				System.exit(0);
			}
			break;
		}
		case SMALL_ALL: {
			try {
				if (!isPractice)
					for (int i = 0; new File(PROB + "-small" + "-attempt" + i + ".in").exists(); i++) {
						final String in = PROB + "-small" + "-attempt" + i + ".in";
						System.setIn(new BufferedInputStream(new FileInputStream(in)));
						t.run();
					}
				else {
					System.setIn(new BufferedInputStream(new FileInputStream(PROB + "-small-practice.in")));
					t.run();
				}
			} catch (Exception e) {
				e.printStackTrace();
				System.exit(0);
			}
			break;
		}
		case LARGE: {
			try {
				final String in = PROB + "-large" + (isPractice ? "-practice" : "") + ".in";
				final String out = PROB + "-large.out";
				System.setIn(new BufferedInputStream(new FileInputStream(in)));
				System.setOut(new PrintStream(out));
				t.run();
			} catch (Exception e) {
				e.printStackTrace();
				System.exit(0);
			}
			break;
		}
		case LARGE1: {
			try {
				final String in = PROB + "-large1" + (isPractice ? "-practice" : "") + ".in";
				final String out = PROB + "-large1.out";
				System.setIn(new BufferedInputStream(new FileInputStream(in)));
				System.setOut(new PrintStream(out));
			} catch (Exception e) {
				e.printStackTrace();
				System.exit(0);
			}
			break;
		}
		case LARGE2: {
			try {
				final String in = PROB + "-large2" + (isPractice ? "-practice" : "") + ".in";
				final String out = PROB + "-large2.out";
				System.setIn(new BufferedInputStream(new FileInputStream(in)));
				System.setOut(new PrintStream(out));
			} catch (Exception e) {
				e.printStackTrace();
				System.exit(0);
			}
			break;
		}
		default:
			throw null;
		}
		es.shutdown();
	}

	private static final int DEFAULT_PARARELL = Runtime.getRuntime().availableProcessors() + 1;
	private static final ExecutorService es = Executors.newFixedThreadPool(DEFAULT_PARARELL);

	private static enum Mode {
		SAMPLE, SMALL, SMALL_ALL, LARGE, LARGE1, LARGE2
	}

	private static void debugf(String format, Object... os) {
		System.err.printf(format, os);
	}

	private static void debug(Object... os) {
		System.err.println(deepToString(os));
	}
}
