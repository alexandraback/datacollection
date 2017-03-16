package contest;

import static java.math.BigInteger.*;

import java.io.*;
import java.lang.reflect.*;
import java.math.*;
import java.util.*;

public class A {

	public Object solve () {
		long R = sc.nextLong();
		long T = sc.nextLong();

		BigInteger p = valueOf(1), q = new BigInteger("1000000000000000000000000000000"), m;
		while (q.subtract(p).compareTo(ONE) > 0) {
			m = (p.add(q)).divide(valueOf(2));
			if (eval(R, T, m))
				p = m;
			else
				q = m;
		}
		return p;
	}

	BigInteger TWO = valueOf(2), FOUR = valueOf(4);

	boolean eval(long R, long T, BigInteger n) {
		BigInteger A = (TWO.multiply(n).multiply(valueOf(R)))
				.add((TWO.add(FOUR.multiply(n.subtract(ONE)))).multiply(n).divide(TWO));

		return A.compareTo(valueOf(T)) <= 0;
	}

	////////////////////////////////////////////////////////////////////////////////////
	private static MyScanner sc = new MyScanner();
	final MyWriter wr = new MyWriter();
	private static class MyScanner {
		int nextInt() { return sc.nextInt(); }
		long nextLong() { return sc.nextLong(); }
		private final Scanner sc;
		private MyScanner () {
			sc = new Scanner(System.in);
			sc.hasNext();
			start();
		}
	}
	private static class MyWriter extends PrintWriter {
		private final StringWriter sw;
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
			print("Case #" + n + ": " + build(new A().solve()));
		err("------------------");
		err(time());
	}
}
