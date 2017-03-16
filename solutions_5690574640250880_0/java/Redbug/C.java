package contest;

import static java.util.Arrays.*;

import java.io.*;
import java.text.*;
import java.util.*;

public class C {

	public Object solve() {
		int R = sc.nextInt(), C = sc.nextInt(), M = sc.nextInt();
		int D = R*C - M;

		MyWriter W = new MyWriter();
		//W.lnprint("-->", R, C, M, D);

		char s = '.';
		int X = C, q = D / X;
		while (R > 1 && X > 1 && (q < 2 || D % X == 1))
			if (q > 2 && X > 2) {
				s = '*'; ++D;
			} else
				q = D/(--X);

		if ((X == 1 || q + Integer.signum(D % X) > R) && minimum(R, C, D) > 1)
			return W.lnprint("Impossible");

		char [][] res = new char [R][C];
		for (char [] r : res) fill(r, '*');
		for (int r : rep(q))
			for (int c : rep(X))
				res[r][c] = '.';
		if (q > 0)
			res[q-1][X-1] = s;

		for (int c : rep(D % X))
			res[q][c] = '.';
		res[0][0] = 'c';

		for (int i : rep(R))
			W.lnprint(new String(res[i]));
		return W;
	}

	private static <T extends Comparable<T>> int fmin(T [] A) { return fmin(A, 0, A.length); }
	private static <T extends Comparable<T>> int fmin(T [] A, int s, int t) {
		int res = s;
		for (int i = s; i < t; ++i)
			if (A[i].compareTo(A[res]) < 0)
				res = i;
		return res;
	}
	private static <T extends Comparable<T>> T minimum(@SuppressWarnings("unchecked") T ... A) { return A[fmin(A)]; }
	private static int [] rep(int N) { return rep(0, N); }
	private static int [] rep(int S, int T) { if (T <= S) return new int [0]; int [] res = new int [T-S]; for (int i = S; i < T; ++i) res[i-S] = i; return res; }
	////////////////////////////////////////////////////////////////////////////////////
	private static IOUtils.MyScanner sc = new IOUtils.MyScanner();
	private static class MyWriter extends PrintWriter {
		public MyWriter lnprint(Object o, Object ...a) { println(); print(IOUtils.build(o, a)); return this; }
		public String toString() { return out.toString(); }
		public MyWriter() { super(new StringWriter()); }
	}
	private static class IOUtils {
		public static class MyScanner {
			public int nextInt() { return sc.nextInt(); }
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
				print("Case #" + n + ": " + build(new C().solve()));
			err("------------------");
			err(time());
		}
	}
	public static void main(String[] args) {
		int N = sc.nextInt();
		IOUtils.run(N);
	}
}
