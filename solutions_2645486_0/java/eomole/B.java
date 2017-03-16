package gcj2013.r1a;

import java.io.*;
import java.util.*;
import java.util.concurrent.*;
import java.math.*;

import static java.lang.Math.*;
import static java.lang.Character.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import static java.math.BigInteger.*;

public class B implements Runnable {
	private static final char PROB = B.class.getSimpleName().charAt(0);
	private static final boolean isPractice = false;
	private static final Mode mode = Mode.SMALL;

	private static class Solver implements Callable<String> {

		private final int E, R, N, v[];

		// parse
		public Solver(final Scanner sc) {
			E = sc.nextInt();
			R = sc.nextInt();
			N = sc.nextInt();
			v = new int[N];
			for (int i = 0; i < N; i++)
				v[i] = sc.nextInt();
		}

		// solve
		@Override
		public String call() {
			final long[] maxGain = new long[E + 1];
			final long[] newGain = new long[E + 1];
			for (int i = 0; i < N; i++) {
				for (int j = 0; j <= E; j++)
					newGain[j] = maxGain[j];
				for (int j = 0; j < E; j++)
					for (int k = j + 1; k <= E; k++)
						newGain[j] = max(newGain[j], maxGain[k] + 1L * (k - j) * v[i]);
				for (int j = 0; j < R; j++)
					maxGain[j] = 0;
				for (int j = 0; j <= E; j++)
					if (j + R <= E)
						maxGain[j + R] = newGain[j];
					else
						maxGain[E] = max(maxGain[E], newGain[j]);
			}
			for (int i = E; i > 0; i--)
				maxGain[i - 1] = max(maxGain[i - 1], maxGain[i]);

			return "" + maxGain[0];
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
		final B t = new B();
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
				final String in = PROB + "-large" + (isPractice ? "-practice" : "") + "-1.in";
				final String out = PROB + "-large-1.out";
				System.setIn(new BufferedInputStream(new FileInputStream(in)));
				System.setOut(new PrintStream(out));
				t.run();
			} catch (Exception e) {
				e.printStackTrace();
				System.exit(0);
			}
			break;
		}
		case LARGE2: {
			try {
				final String in = PROB + "-large" + (isPractice ? "-practice" : "") + "-2.in";
				final String out = PROB + "-large-2.out";
				System.setIn(new BufferedInputStream(new FileInputStream(in)));
				System.setOut(new PrintStream(out));
				t.run();
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
