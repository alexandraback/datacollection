package contest;

import static java.util.Arrays.*;

import java.text.*;
import java.util.*;

public class D {

	public Object solve() {
		sc.nextInt();
		Double [] N = toObject(sc.nextDoubles());
		Double [] K = toObject(sc.nextDoubles());

		int [] res = new int [2];
		sort(N); TreeSet<Double> S;

		S = new TreeSet<>(); for (double k : K) S.add(k);
		for (double n : N)
			if (n > S.first()) {
				S.pollFirst();
				++res[0];
			} else
				S.pollLast();

		S = new TreeSet<>(); for (double k : K) S.add(k);
		for (double n : N) {
			Double k = S.ceiling(n);
			if (k != null)
				S.remove(k);
			else {
				S.pollFirst();
				++res[1];
			}
		}

		return res;
	}

	private static Double [] toObject(double ... A) { Double [] res = new Double [A.length]; for (int i = 0; i < A.length; ++i) res[i] = A[i]; return res; }
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
			public double[] nextDoubles() {
				String[] L = nextStrings();
				double[] res = new double[L.length];
				for (int i = 0; i < L.length; ++i)
					res[i] = Double.parseDouble(L[i]);
				return res;
			}
			private final Scanner sc;
			private MyScanner() {
				sc = new Scanner(System.in);
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
					o = new DecimalFormat("#.#########").format(o);
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
				print("Case #" + n + ": " + build(new D().solve()));
			err("------------------");
			err(time());
		}
	}
	public static void main(String[] args) {
		int N = sc.nextInt();
		IOUtils.run(N);
	}
}
