import java.io.*;
import java.util.*;
import java.util.concurrent.*;
import java.math.*;

import static java.lang.Math.*;
import static java.lang.Character.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import static java.math.BigInteger.*;

public class C implements Runnable {
	private static final char PROB = C.class.getSimpleName().charAt(0);
	private static int DEFAULT_PARARELL = Runtime.getRuntime().availableProcessors() + 1;
	private static File DIR = new File(".");
	private static boolean TEST_ALL = false;

	public static class Solver implements Callable<String> {
		private final int N, d[], n[], w[], e[], s[], delta_d[], delta_p[], delta_s[];

		private static class Event implements Comparable<Event> {
			final int d, w, e, s;

			private Event(int d, int w, int e, int s) {
				this.d = d;
				this.w = w;
				this.e = e;
				this.s = s;
			}

			@Override
			public int compareTo(Event o) {
				return d - o.d;
			}
		}

		// parse
		public Solver(final Scanner sc) {
			N = sc.nextInt();
			d = new int[N];
			n = new int[N];
			w = new int[N];
			e = new int[N];
			s = new int[N];
			delta_d = new int[N];
			delta_p = new int[N];
			delta_s = new int[N];
			for (int i = 0; i < N; i++) {
				d[i] = sc.nextInt();
				n[i] = sc.nextInt();
				w[i] = sc.nextInt();
				e[i] = sc.nextInt();
				s[i] = sc.nextInt();
				delta_d[i] = sc.nextInt();
				delta_p[i] = sc.nextInt();
				delta_s[i] = sc.nextInt();
			}
		}

		// solve
		@Override
		public String call() {
			Queue<Event> que = new PriorityQueue<>();
			for (int i = 0; i < N; i++)
				for (int j = 0; j < n[i]; j++)
					que.offer(new Event(d[i] + j * delta_d[i], w[i] + j * delta_p[i], e[i] + j * delta_p[i], s[i] + j
							* delta_s[i]));
			int[] height = new int[1001];
			int[] new_height = new int[1001];
			int ans = 0;
			for (int d = 0; !que.isEmpty();) {
				final Event attack = que.poll();
				if (d < attack.d) {
					d = attack.d;
					System.arraycopy(new_height, 0, height, 0, 1001);
				}
				boolean suc = false;
				for (int i = attack.w; i < attack.e; i++)
					if (height[i + 500] < attack.s) {
						suc = true;
						new_height[i + 500] = max(new_height[i + 500], attack.s);
					}
				if(suc)
					ans++;
			}
			return "" + ans;
		}
	}

	// Template
	@Override
	public void run() {
		final ExecutorService es = Executors.newFixedThreadPool(DEFAULT_PARARELL);
		try (final Scanner sc = new Scanner(System.in)) {
			final List<Future<String>> list = new ArrayList<>();
			final int T = sc.nextInt();
			for (int i = 0; i < T; i++)
				list.add(es.submit(new Solver(sc)));
			for (int t = 1; t <= T; t++) {
				debugf("Case #%s%n", t);
				System.out.printf("Case #%s: %s%n", t, list.get(t - 1).get());
				System.gc();
			}
			debug("done.");
		} catch (Exception e) {
			e.printStackTrace();
		}
		es.shutdown();
	}

	public static void main(String... args) throws IOException {
		if (TEST_ALL) {
			for (final String input : seekInputFiles()) {
				debug("INPUT", input);
				System.setIn(new BufferedInputStream(new FileInputStream(new File(DIR, input))));
				System.setOut(new PrintStream(input + ".out"));
				new C().run();
			}
		} else {
			final String input = seekInputFile();
			debug("INPUT", input);
			if (input != null) {
				System.setIn(new BufferedInputStream(new FileInputStream(new File(DIR, input))));
				System.setOut(new PrintStream(input + ".out"));
			} else
				DEFAULT_PARARELL = 1;
			new C().run();
		}
	}

	private static String seekInputFile() {
		final String[] names = new String[] { PROB + "-large-practice-2.in", PROB + "-large-practice-1.in",
				PROB + "-large-practice.in", PROB + "-large-2.in", PROB + "-large-1.in", PROB + "-large.in",
				PROB + "-small-practice-2.in", PROB + "-small-practice-1.in", PROB + "-small-practice.in" };
		for (final String s : names)
			if (new File(DIR, s).exists())
				return s;
		for (int k = 2; k >= 0; k--) {
			int max = -1;
			for (int i = 0; new File(DIR, PROB + "-small" + (k > 0 ? "-" + k : "") + "-attempt" + i + ".in").exists(); i++)
				max = i;
			if (max >= 0)
				return PROB + "-small" + (k > 0 ? "-" + k : "") + "-attempt" + max + ".in";
		}
		return null;
	}

	private static List<String> seekInputFiles() {
		final List<String> ret = new ArrayList<>();
		final String[] names = new String[] { PROB + "-large-practice-2.in", PROB + "-large-practice-1.in",
				PROB + "-large-practice.in", PROB + "-large-2.in", PROB + "-large-1.in", PROB + "-large.in",
				PROB + "-small-practice-2.in", PROB + "-small-practice-1.in", PROB + "-small-practice.in" };
		for (final String s : names)
			if (new File(DIR, s).exists())
				ret.add(s);
		for (int k = 2; k >= 0; k--) {
			int max = -1;
			for (int i = 0; new File(DIR, PROB + "-small" + (k > 0 ? "-" + k : "") + "-attempt" + i + ".in").exists(); i++)
				max = i;
			if (max >= 0)
				ret.add(PROB + "-small" + (k > 0 ? "-" + k : "") + "-attempt" + max + ".in");
		}
		return ret;
	}

	private static void debugf(String format, Object... os) {
		System.err.printf(format, os);
	}

	private static void debug(Object... os) {
		System.err.println(deepToString(os));
	}
}
