package contest;

import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

@SuppressWarnings("unused")
public class A {

	private static final int INF = (int) 1e9;
	private static final int MOD = (int) 1e9 + 7;
	private static final double eps = 1e-9;

	public Object solve () {
		char [][] B = sc.nextChars(4);
		//sc.next();

		for (int i : rep(4)) {
			String res = test(B[i]);
			if (res != null)
				return res;
		}

		for (int i : rep(4)) {
			char [] C = new char [4];
			for (int j : rep(4))
				C[j] = B[j][i];
			String res = test(C);
			if (res != null)
				return res;
		}

		char [] C = new char [4], D = new char [4];
		for (int i : rep(4)) {
			C[i] = B[i][i];
			D[i] = B[i][3-i];
		}
		String res = test(C);
		if (res != null)
			return res;
		res = test(D);
		if (res != null)
			return res;

		for (int i : rep(4))
			for (int j : rep(4))
				if (B[i][j] == '.')
					return "Game has not completed";

		return "Draw";
	}

	String test(char [] L) {
		int NX = 0, NT = 0, NO = 0;
		for (char c : L)
			switch(c) {
			case 'X': ++NX; break;
			case 'T': ++NT; break;
			case 'O': ++NO; break;
			}
		if (NT + NX == 4)
			return "X won";
		else if (NT + NO == 4)
			return "O won";
		else
			return null;
	}

	////////////////////////////////////////////////////////////////////////////////////
	private static int [] rep(int N) { return rep(0, N); }
	private static int [] rep(int S, int T) { if (T <= S) return new int [0]; int [] res = new int [T-S]; for (int i = S; i < T; ++i) res[i-S] = i; return res; }
	private static int [] req(int S, int T) { return rep(S, T+1); }
	private static int [] sep(int N) { return sep(0, N); }
	private static int [] sep(int S, int T) { if (T <= S) return new int [0]; int [] res = new int [T-S]; for (int i = S; i < T; ++i) res[T-1-i] = i; return res; }
	private static int [] seq(int S, int T) { return sep(S, T+1); }
	private static int [] ccw (int [] D) { return new int [] { -D[1], D[0] }; }
	private static int [] cw (int [] D) { return new int [] { D[1], -D[0] }; }
	private static int [] digits(long N, int B, int sz) {
		int [] res = new int [sz];
		for (int i : sep(sz))
			if (N > 0) {
				res[i] = (int)(N % B);
				N /= B;
			}
		return res;
	}
	private static int digitSum(long N) {
		int res = 0;
		for (; N > 0; res += N % 10, N /= 10);
		return res;
	}
	private static <T extends Comparable<T>> T max(T x, T y) { return x.compareTo(y) > 0 ? x : y; }
	private static long mod(long x) { return mod(x, MOD); }
	private static long mod(long x, long mod) { return (x % mod + mod) % mod; }
	private static long modInv(long x) { return modPow(x, -1); }
	private static long modPow(long b, long e) { return valueOf(b).modPow(valueOf(e), valueOf(MOD)).longValue(); }
	private static long [] modFact(int N) {
		long [] res = new long [N]; res[0] = 1;
		for (int i : rep(1, N))
			res[i] = mod(res[i-1] * i);
		return res;
	}
	private static long [][] modBin(int N, int K) {
		long [][] res = new long [N+1][K+1];
		for (int n : req(0, N)) {
			res[n][0] = 1;
			for (int k : req(1, min(K, n)))
				res[n][k] = mod(res[n-1][k] + res[n-1][k-1]);
		}
		return res;
	}
	private static long pow(long b, long e) { return round(Math.pow(b, e)); }
	private static String reverse (String S) { return new StringBuilder(S).reverse().toString(); }
	@SuppressWarnings("unchecked")
	private static <T> T [] newArray(T [] A, int N) { return (T[]) java.lang.reflect.Array.newInstance(A.getClass().getComponentType(), N); }
	private static <T> T [] shift(T [] A, int k) {
		int N = A.length;
		T [] res = newArray(A, N+k);
		System.arraycopy(A, 0, res, k, N);
		return res;
	}
	private static char [][] toCharArrays(String [] S) {
		int N = S.length;
		char [][] res = new char [N][];
		for (int i : rep(N))
			res[i] = S[i].toCharArray();
		return res;
	}
	private static int [][][] lgraph(int N, Integer [][] E) {
		int [] D = new int [N];
		for (Integer [] e : E) {
			int x = e[0] - 1, y = e[1] - 1;
			++D[x]; ++D[y];
		}
		int [][][] res = new int [2][N][];
		for (int i : rep(2))
			for (int j : rep(N))
				res[i][j] = new int [D[j]];
		D = new int [N];
		for (Integer [] e : E) {
			int x = e[0] - 1, y = e[1] - 1, z = e.length > 2 ? e[2] : 1;
			res[0][x][D[x]] = y; res[0][y][D[y]] = x;
			res[1][x][D[x]] = res[1][y][D[y]] = z;
			++D[x]; ++D[y];
		}
		return res;
	}
	private static class SumNode {
		private final SumNode L, R;
		private final int from, to, m;
		private long X = 0;
		private SumNode(int from, int to) {
			assert from < to;
			this.from = from;
			this.to = to;
			m = (from + to) / 2;
			if (m > from) {
				L = new SumNode(from, m);
				R = new SumNode(m, to);
			} else
				L = R = null;
		}
		private void add(long X, int from, int to) {
			assert from >= this.from && to <= this.to && from < to;
			if (from == this.from && to == this.to)
				this.X += X;
			else {
				if (from < m)
					L.add(X, from, min(to, m));
				if (to > m)
					R.add(X, max(from, m), to);
			}
		}
		private long get(int i) {
			assert from <= i && i < to;
			long res = X;
			if (i < m)
				res += L.get(i);
			if (i >= m && m > from)
				res += R.get(i);
			return res;
		}
	}
	private static <T extends Comparable<T>> Integer [] si(final T [] X) {
		return si(X, new Comparator<T> () {
			public int compare (T x, T y) {
				return x.compareTo(y);
			}
		});
	}
	private static <T> Integer [] si(final T [] X, final Comparator<T> C) {
		int N = X.length;
		Integer [] J = new Integer [N];
		for (int i = 0; i < N; ++i)
			J[i] = i;
		sort(J, new Comparator<Integer>() {
			public int compare(Integer i, Integer j) {
				int res = C.compare(X[i], X[j]);
				return res != 0 ? res : i.compareTo(j);
			}
		});
		return J;
	}
	private static int [][] vtk(int [][] KV, int W) {
		int [] C = new int [W+1];
		for (int [] kv : KV)
			C[kv[1]]++;
		int [][] res = new int [W+1][];
		for (int v : req(0, W))
			res[v] = new int [C[v]];
		fill(C, 0);
		for (int [] kv : KV)
			res[kv[1]][C[kv[1]]++] = kv[0];
		return res;
	}
	////////////////////////////////////////////////////////////////////////////////////
	private static MyScanner sc = new MyScanner();
	final MyWriter wr = new MyWriter();
	private static class MyScanner {
		private String next() { return sc.next(); }
		private char nextChar() { return sc.next().charAt(0); }
		private int nextInt() { return sc.nextInt(); }
		private long nextLong() { return sc.nextLong(); }
		private double nextDouble() { return sc.nextDouble(); }
		private String nextLine() {
			String line = sc.nextLine().trim();
			if ("".equals(line)) // If at end of line, read next line
				line = sc.nextLine();
			return line;
		}
		private String [] next(int N) { return next(String.class, N); }
		private Integer [] nextInt(int N) { return next(Integer.class, N); }
		private Long [] nextLong(int N) { return next(Long.class, N); }
		private Double [] nextDouble(int N) { return next(Double.class, N); }
		private String [] nextLine(int N) {
			String [] a = new String[N];
			for(int i = 0; i < N; ++i)
				a[i] = nextLine();
			return a;
		}
		private String [] nextStrings() { return nextLine().split(" "); }
		private char [] nextChars() { return next().toCharArray(); }
		private Integer [] nextInts() { return next(Integer.class, nextStrings()); }
		private Long [] nextLongs() { return next(Long.class, nextStrings()); }
		private Double [] nextDoubles() { return next(Double.class, nextStrings()); }
		private String [][] nextStrings(int N) { return next(String[].class, N); }
		private char [][] nextChars(int N) { return next(char[].class, N); }
		private Integer [][] nextInts(int N) { return next(Integer[].class, N); }
		private Long [][] nextLongs(int N) { return next(Long[].class, N); }
		private Double [][] nextDoubles(int N) { return next(Double[].class, N); }
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
	private static String cbuild(Object o, Object... a) { return buildDelim("", o, a); }
	private static String buildDelim(String delim, Object o, Object... a) {
		StringBuilder b = new StringBuilder();
		append(b, o, delim);
		for (Object p : a)
			append(b, p, delim);
		return b.toString().trim();
	}
	private static Object NO() { throw new Error("NO!"); }
	////////////////////////////////////////////////////////////////////////////////////
	private static void clock() { err(time()); }
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
