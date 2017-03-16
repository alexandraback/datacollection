import static java.lang.Math.*;
import static java.util.Collections.*;

import java.util.*;

public class B {

	public Object solve() {
		sc.nextInt();
		int [] P = sc.nextInts();

		int R1, R2;
		{
			PriorityQueue<Integer> Q = new PriorityQueue<>(10, reverseOrder());
			for (int p : P)
				Q.add(p);

			int T = 0; R1 = INF;
			while (!Q.isEmpty()) {
				int q = Q.poll();
				R1 = min(R1, T + q);
				if (q > 1 && q < 9) {
					Q.add(q/2);
					Q.add(q - q/2);
				}
				else if (q == 9) {
					Q.add(3);
					Q.add(6);
				}
				++T;
			}
		}

		{
			PriorityQueue<Integer> Q = new PriorityQueue<>(10, reverseOrder());
			for (int p : P)
				Q.add(p);

			int T = 0; R2 = INF;
			while (!Q.isEmpty()) {
				int q = Q.poll();
				R2 = min(R2, T + q);
				if (q > 1) {
					Q.add(q/2);
					Q.add(q - q/2);
				}
				++T;
			}
		}

		int res = min(R1, R2);
		return res;
	}

	private static final int INF = (int) 1e9;
	////////////////////////////////////////////////////////////////////////////////////
	private static IOUtils.MyScanner sc = new IOUtils.MyScanner();
	private static class IOUtils {
		public static class MyScanner {
			public int nextInt() { return sc.nextInt(); }
			public String nextLine() {
				String line = sc.nextLine().trim();
				if ("".equals(line)) // If at end of line, read next line
					line = sc.nextLine();
				return line;
			}
			public String[] nextStrings() {return nextLine().split(" "); }
			public int[] nextInts() {
				String[] L = nextStrings();
				int[] res = new int[L.length];
				for (int i = 0; i < L.length; ++i)
					res[i] = Integer.parseInt(L[i]);
				return res;
			}
			private final java.util.Scanner sc;
			private MyScanner() {
				sc = new java.util.Scanner(System.in);
				sc.hasNext();
				start();
			}
		}
		private static String build(Object o, Object... a) { return buildDelim(" ", o, a); }
		private static String buildDelim(String delim, Object o, Object... a) {
			StringBuilder b = new StringBuilder();
			append(b, o, delim);
			for (Object p : a)
				append(b, p, delim);
			return b.substring(delim.length());
		}
		//////////////////////////////////////////////////////////////////////////////////
		private static void start() { if (t == 0) t = millis(); }
		private static void append(StringBuilder b, Object o, String delim) {
			if (o.getClass().isArray()) {
				int len = java.lang.reflect.Array.getLength(o);
				for (int i = 0; i < len; ++i)
					append(b, java.lang.reflect.Array.get(o, i), delim);
			} else if (o instanceof Iterable<?>)
				for (Object p : (Iterable<?>) o)
					append(b, p, delim);
			else {
				if (o instanceof Double)
					o = new java.text.DecimalFormat("#.#########").format(o);
				b.append(delim).append(o);
			}
		}
		private static void print(Object o) {
			err(o, '(', time(), ')');
			if (PRINT)
				System.out.println(o);
		}
		private static void err(Object ...o) { System.err.println(build(o)); }
		private static long t;
		private static long millis() { return System.currentTimeMillis(); }
		private static String time() { return "Time: " + (millis() - t) / 1000.0; }
		private static final boolean PRINT = System.getProperties().containsKey("PRINT");
		private static void run(int N) {
			for (int n = 1; n <= N; ++n)
				print("Case #" + n + ": " + build(new B().solve()));
			err("------------------");
			err(time());
		}
	}
	public static void main(String[] args) {
		int N = sc.nextInt();
		IOUtils.run(N);
	}
}
