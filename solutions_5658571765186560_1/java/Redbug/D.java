import static java.lang.Math.*;

public class D {

	String NO = "RICHARD", YES = "GABRIEL";

	String val(boolean res) {
		return res ? YES : NO;
	}

	public Object solve() {
		int X = sc.nextInt(), R = sc.nextInt(), C = sc.nextInt();

		int M = min(R, C);

		if (R*C % X != 0)
			return val(false);

		if (X <= 2)
			return val(true);

		if (X == 3)
			return val(M >= 2);

		if (X == 4)
			return val(M >= 3);

		if (X == 5)
			return val(M >= 4);

		if (X == 6)
			return val(M >= 4);

		else
			return val(false);
	}

	////////////////////////////////////////////////////////////////////////////////////
	private static IOUtils.MyScanner sc = new IOUtils.MyScanner();
	private static class IOUtils {
		public static class MyScanner {
			public int nextInt() { return sc.nextInt(); }
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
