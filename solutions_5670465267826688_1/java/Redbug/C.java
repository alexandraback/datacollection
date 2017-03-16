import static java.lang.Math.*;

public class C {

	static int I = 2, J = 3, K = 4;

	static int [] V = V();
	static int [] V() {
		int [] res = new int [200];
		res['i'] = 2;
		res['j'] = 3;
		res['k'] = 4;
		return res;
	}
	static int [][] T = {
		{ 1, I, J, K },
		{ I, -1, K, -J },
		{ J, -K, -1, I },
		{ K, J, -I, -1 }
	};

	public Object solve() {
		int L = sc.nextInt();
		long X = sc.nextLong();
		String S = sc.next();

		String [] R = new String [5]; R[0] = "";
		for (int i : rep(4))
			R[i+1] = R[i] + S;

		char [] C = R[(int)(X%4)].toCharArray();
		int Z = 1;

		for (char c : C)
			Z = prod(Z, c);

		if (Z != -1)
			return "NO";

		C = R[(int)min(4, X)].toCharArray();
		int LI = 0; Z = 1;
		for (char c : C) {
			Z = prod(Z, c);
			++LI;
			if (Z == I)
				break;
		}
		if (Z != I)
			LI = -1;

		C = reverse(R[(int)min(4, X)]).toCharArray();
		int LK = 0; Z = 1;
		for (char c : C) {
			Z = prod2(Z, c);
			++LK;
			if (Z == K)
				break;
		}
		if (Z != K)
			LK = -1;

		if (LI > 0 && LK > 0 && LI + LK < L * X)
			return "YES";
		else
			return "NO";
	}

	int prod(int Z, char c) {
		if (Z > 0)
			return T[Z-1][V[c]-1];
		else
			return -T[-Z-1][V[c]-1];
	}

	int prod2(int Z, char c) {
		if (Z > 0)
			return T[V[c]-1][Z-1];
		else
			return -T[V[c]-1][-Z-1];
	}

	private static int [] rep(int N) { return rep(0, N); }
	private static int [] rep(int S, int T) { if (T <= S) return new int [0]; int [] res = new int [T-S]; for (int i = S; i < T; ++i) res[i-S] = i; return res; }
	private static String reverse (String S) { return new StringBuilder(S).reverse().toString(); }
	////////////////////////////////////////////////////////////////////////////////////
	private static IOUtils.MyScanner sc = new IOUtils.MyScanner();
	private static class IOUtils {
		public static class MyScanner {
			public String next() { return sc.next(); }
			public int nextInt() { return sc.nextInt(); }
			public long nextLong() { return sc.nextLong(); }
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
