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

public class A implements Runnable {
	private static final char PROB = A.class.getSimpleName().charAt(0);
	private static final boolean isPractice = false;
	private static final Mode mode = Mode.LARGE;

	private static class Solver implements Callable<String> {
		private static final int S = 4;
		private final char[][] map = new char[S][];

		// parse
		public Solver(final Scanner sc) {
			for (int i = 0; i < S; i++)
				map[i] = sc.next().toCharArray();
		}

		// solve
		@Override
		public String call() {
			if (win('X'))
				return "X won";
			else if (win('O'))
				return "O won";
			else if (end())
				return "Draw";
			else
				return "Game has not completed";
		}

		private boolean win(final char c) {
			loop1: for (int i = 0; i < S; i++) {
				for (int j = 0; j < S; j++)
					if (map[i][j] != 'T' && map[i][j] != c)
						continue loop1;
				return true;
			}
			loop2: for (int i = 0; i < S; i++) {
				for (int j = 0; j < S; j++)
					if (map[j][i] != 'T' && map[j][i] != c)
						continue loop2;
				return true;
			}
			label1: {
				for (int i = 0; i < S; i++)
					if (map[i][i] != 'T' && map[i][i] != c)
						break label1;
				return true;

			}
			label2: {
				for (int i = 0, j = S - 1; i < S; i++, j--)
					if (map[i][j] != 'T' && map[i][j] != c)
						break label2;
				return true;

			}
			return false;
		}

		private boolean end() {
			for (int i = 0; i < S; i++)
				for (int j = 0; j < S; j++)
					if (map[i][j] == '.')
						return false;
			return true;
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
		final A t = new A();
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
