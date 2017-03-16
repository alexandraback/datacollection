package contest;

import static java.util.Arrays.*;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

public class C {

	public Object solve () {
		R = sc.nextInt();
		N = sc.nextInt();
		M = sc.nextInt();
		K = sc.nextInt();
		Long [][] S = sc.nextLongs(R);
		MyWriter W = new MyWriter();

		for (Long [] s : S)
			W.lnprint(eval(s));

		return W;
	}

	int R, N, M, K;
	Random r = new Random();

	String eval(Long [] S) {
		for (;;) {
			StringBuilder b = new StringBuilder(); int f = 0;
			for (f = 0; f < 1000; ) {
				int x = 2 + r.nextInt(M-1);
				boolean ok = false;
				for (int i = 0; i < K; ++i)
					if (S[i] % x == 0) {
						ok = true;
						S[i] /= x;
					}
				if (ok)
					b.append(x);
				else
					++f;
			}
			if (b.length() > N)
				continue;

			while(b.length() < N)
				b.append(2 + r.nextInt(M-1));

			return b.toString();
		}
	}

	////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////
	private static MyScanner sc = new MyScanner();
	final MyWriter wr = new MyWriter();
	static class MyScanner {
		String next() { return sc.next(); }
		char nextChar() { return sc.next().charAt(0); }
		int nextInt() { return sc.nextInt(); }
		long nextLong() { return sc.nextLong(); }
		double nextDouble() { return sc.nextDouble(); }
		String nextLine() {
			String line = sc.nextLine().trim();
			if ("".equals(line)) // If at end of line, read next line
				line = sc.nextLine();
			return line;
		}
		String [] next(int N) { return next(String.class, N); }
		Integer [] nextInt(int N) { return next(Integer.class, N); }
		Long [] nextLong(int N) { return next(Long.class, N); }
		Double [] nextDouble(int N) { return next(Double.class, N); }
		String [] nextLine(int N) {
			String [] a = new String[N];
			for(int i = 0; i < N; ++i)
				a[i] = nextLine();
			return a;
		}
		String [] nextStrings() { return nextLine().split(" "); }
		char [] nextChars() { return next().toCharArray(); }
		Integer [] nextInts() { return next(Integer.class, nextStrings()); }
		Long [] nextLongs() { return next(Long.class, nextStrings()); }
		Double [] nextDoubles() { return next(Double.class, nextStrings()); }
		String [][] nextStrings(int N) { return next(String[].class, N); }
		char [][] nextChars(int N) { return next(char[].class, N); }
		Integer [][] nextInts(int N) { return next(Integer[].class, N); }
		Long [][] nextLongs(int N) { return next(Long[].class, N); }
		Double [][] nextDoubles(int N) { return next(Double[].class, N); }
		@SuppressWarnings("unchecked")
		private <T> T[] next(Class<T> c, String [] s) {
			try {
				T[] a = (T[])Array.newInstance(c, s.length);
				Method m = c.getMethod("parse" + type(c), String.class);
				for (int i = 0; i < s.length; ++i)
					Array.set(a, i, m.invoke(null, s[i]));
				return a;
			} catch (Exception e) {
				throw new Error(e);
			}
		}
		@SuppressWarnings("unchecked")
		private <T> T[] next(Class<T> c, int N) {
			try {
				T[] a = (T[])Array.newInstance(c, N);
				String s = c.isArray() ? type(c.getComponentType()) + 's' : type(c);
				Method m = MyScanner.class.getDeclaredMethod("next" + s);
				for (int i = 0; i < N; ++i)
					a[i] = (T)m.invoke(this);
				return a;
			} catch (Exception e) {
				throw new Error(e);
			}
		}
		private <T> String type(Class<T> c) {
			try {
				Class<?> t = c;
				try {
					t = (Class<?>)t.getField("TYPE").get(null);
				} catch (NoSuchFieldException e) {} // String? char?
				String s = t.getSimpleName();
				return Character.toUpperCase(s.charAt(0)) + s.substring(1);  // Capitalize first character of type; e.g., int --> Int
			} catch(Exception e) {
				throw new Error(e);
			}
		}
		private final Scanner sc;
		private MyScanner () {
			sc = new Scanner(System.in);
			sc.hasNext();
			start();
		}
	}
	private static class MyWriter extends PrintWriter {
		private final StringWriter sw;
		private void lnprint(Object o) { println(); print(o); }
		public String toString() { return sw.toString(); }
		private MyWriter() { this(new StringWriter()); }
		private MyWriter(StringWriter sw) { super(sw); this.sw = sw; }
	}
	private static String build(Object o, Object... a) { return buildDelim(" ", o, a); }
	private static String buildDelim(String delim, Object o, Object... a) {
		StringBuilder b = new StringBuilder();
		append(b, o, delim);
		for (Object p : a)
			append(b, p, delim);
		return b.substring(delim.length());
	}
	////////////////////////////////////////////////////////////////////////////////////
	private static void start() { if (t == 0) t = millis(); }
	private static void append(StringBuilder b, Object o, String delim) {
		if (o.getClass().isArray()) {
			int len = Array.getLength(o);
			for (int i = 0; i < len; ++i)
				append(b, Array.get(o, i), delim);
		} else if (o instanceof Iterable<?>)
			for (Object p : (Iterable<?>)o)
				append(b, p, delim);
		else
			b.append(delim).append(o);
	}
	private static void print (Object o) {
		System.err.println(build(o, '(', time(), ')'));
		if (PRINT)
			System.out.println(o);
	}
	private static void err (Object o) { System.err.println(o); }
	private static long t;
	private static long millis() { return System.currentTimeMillis(); }
	private static String time() { return "Time: " + (millis() - t) / 1000.0; }
	private static final boolean PRINT = System.getProperties().containsKey("PRINT");
	////////////////////////////////////////////////////////////////////////////////////
	public static void main(String[] args) {
		int N = sc.nextInt();
		for (int n = 1; n <= N; ++n)
			print("Case #" + n + ": " + build(new C().solve()));
		err("------------------");
		err(time());
	}
}
