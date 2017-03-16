package contest;

import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;
import java.util.Map.Entry;

public class C {

	private static final int INF = (int) 1e9;
	private static final int MOD = (int) 1e9 + 7;
	private static final double eps = 1e-9;

	public Object solve () {
		int R = sc.nextInt();
		int N = sc.nextInt();
		int M = sc.nextInt();
		int K = sc.nextInt();
		Integer [][] S = sc.nextInts(R);

		int [][] X = new int [100][];
		Set<Integer> [] Y = new Set[100]; int C = 0;

		for (int a : req(2, M))
			for (int b : req(a, M))
				for (int c : req(b, M)) {
					Set<Integer> V = new HashSet<Integer>();
					V.add(1); V.add(a); V.add(b); V.add(c);
					V.add(a*b); V.add(a*c); V.add(b*c);
					V.add(a*b*c);
					X[C] = new int [] { a, b, c };
					Y[C] = V;
					++C;
				}
		X = copyOf(X, C);
		Y = copyOf(Y, C);

		MyWriter W = new MyWriter();

		for (Integer [] s : S)
			W.lnprint(eval(s, X, Y));

		return W;
	}

	String eval(Integer [] S, int [][] X, Set<Integer>[] Y) {
		int N = X.length;
		int [] score = new int [N];
		for (int i : rep(N)) {
			for (int s : S)
				if (Y[i].contains(s))
					++score[i];
				else {
					score[i] = -INF;
					break;
				}
			int d = Y[i].size() - score[i];
			score[i] -= d;
		}
		int best = -1, max = -INF;
		for (int i : rep(N))
			if (score[i] > max) {
				max = score[i];
				best = i;
			}

		StringBuilder b = new StringBuilder();
		for (int x : X[best])
			b.append(x);
		return b.toString();
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
		for (int i = sz - 1; i >= 0; --i)
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
	private static long mod(long x, long mod) { return ((x % mod) + mod) % mod; }
	private static long modInv(long x) { return modPow(x, -1); }
	private static long modPow(long b, long e) { return valueOf(b).modPow(valueOf(e), valueOf(MOD)).longValue(); }
	private static long [] modFact(int N) {
		long [] res = new long [N]; res[0] = 1;
		for (int i = 1; i < N; ++i)
			res[i] = mod(res[i-1] * i);
		return res;
	}
	private static long [][] modBin(int N, int K) {
		long [][] res = new long [N+1][K+1];
		for (int n = 0; n <= N; ++n) {
			res[n][0] = 1;
			for (int k = 1; k <= K && k <= n; ++k)
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
		for (int i = 0; i < N; ++i)
			res[i] = S[i].toCharArray();
		return res;
	}
	private static int [][] graph (int N, Integer [][] E) { return lgraph(N, E)[0]; }
	private static int [][][] lgraph(int N, Integer [][] E) {
		int [] D = new int [N];
		for (Integer [] e : E) {
			int x = e[0] - 1, y = e[1] - 1;
			++D[x]; ++D[y];
		}
		int [][][] res = new int [2][N][];
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < N; ++j)
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
	private static class SetNode {
		private final SetNode L, R;
		private final int from, to, m;
		private final Object NO_VALUE;
		private Object X = null;
		private SetNode(int from, int to, Object NO_VALUE) {
			assert(from < to);
			this.NO_VALUE = NO_VALUE;
			this.from = from;
			this.to = to;
			m = (from + to) / 2;
			if (m > from) {
				L = new SetNode(from, m, NO_VALUE);
				R = new SetNode(m, to, NO_VALUE);
			} else
				L = R = null;
		}
		private void set(Object X, int from, int to) {
			assert(from >= this.from && to <= this.to && from < to);
			if (from == this.from && to == this.to)
				this.X = X;
			else {
				dfs(this.X, this.from, from);
				dfs(X, from, to);
				dfs(this.X, to, this.to);
				this.X = NO_VALUE;
			}
		}
		private void dfs(Object X, int from, int to) {
			if (NO_VALUE.equals(X))
				return;
			if (from == to)
				return;
			if (from < m)
				L.set(X, from, min(to, m));
			if (to > m)
				R.set(X, max(from, m), to);
		}
		private Object get(int i) {
			assert(from <= i && i < to);
			Object res = null;
			if (!NO_VALUE.equals(X))
				res = X;
			else if (i < m)
				res = L.get(i);
			else if (i >= m && m > from)
				res = R.get(i);
			else
				assert false;
			return res;
		}
	}
	private static class SumNode {
		private final SumNode L, R;
		private final int from, to, m;
		private long X = 0;
		private SumNode(int from, int to) {
			assert(from < to);
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
			assert(from >= this.from && to <= this.to && from < to);
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
			assert(from <= i && i < to);
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
		for (int v = 0; v <= W; ++v)
			res[v] = new int [C[v]];
		fill(C, 0);
		for (int [] kv : KV)
			res[kv[1]][C[kv[1]]++] = kv[0];
		return res;
	}
	private static void prefixFunction(char [] C, char [] P, int [] F, int i) {
		int j = i > 0 ? F[i-1] : 0;
		for (int k = 0; k < C.length; ++k)
			if (i+k > 0) {
				while (j > 0 && C[k] != P[j])
					j = F[j-1];
				if (C[k] == P[j])
					++j;
				F[i+k] = j;
			}
	}
	private static class Counter<T> extends TreeMap<T, Integer> {
		private static final long serialVersionUID = 1L;
		public Integer get(Object key) { return containsKey(key) ? super.get(key) : 0; }
		private void inc(T key) { super.put(key, get(key) + 1); }
		private void dec(T key) { super.put(key, get(key) - 1); }
		private Entry<T, Integer> max() {
			Entry<T, Integer> max = null;
			for (Entry<T, Integer> x : entrySet())
				if (max == null || x.getValue() > max.getValue())
					max = x;
			return max;
		}
		public Integer put(T key, Integer value) { throw new UnsupportedOperationException(); }
	}
	private static int [] singletons(int N) {
		int [] res = new int [N];
		for (int i = 0; i < N; ++i)
			res[i] = i;
		return res;
	}
	private static int dsu(int [][] E, int s, int t, int [] C) {
		int res = 0;
		for (int i = s; i < t; ++i) {
			int [] e = E[i];
			int u = root(C, e[0]), v = root(C, e[1]);
			if (u != v)
				++res;
			C[u] = C[v];
		}
		return res;
	}
	private static int root (int [] C, int s) {
		int res = s;
		while (C[res] != res)
			res = C[res];
		int v = s;
		while (v != res) {
			v = C[v];
			C[v] = res;
		}
		return C[s] = res;
	}
	private static <T> T [] permute(T [] A, Integer [] J) {
		T [] res = A.clone();
		for (int i = 0; i < J.length; ++i)
			res[i] = A[J[i]];
		return res;
	}
	private static Integer [] invert(Integer [] J) {
		int N = J.length;
		Integer [] res = new Integer [N];
		for (int i = 0; i < N; ++i)
			res[J[i]] = i;
		return res;
	}
	////////////////////////////////////////////////////////////////////////////////////
	private static MyScanner sc = new MyScanner();
	final MyWriter wr = new MyWriter();
	private static class MyScanner {
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
	private static String cbuild(Object o, Object... a) { return buildDelim("", o, a); }
	private static String buildDelim(String delim, Object o, Object... a) {
		StringBuilder b = new StringBuilder();
		append(b, o, delim);
		for (Object p : a)
			append(b, p, delim);
		return b.substring(delim.length());
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
			print("Case #" + n + ": " + build(new C().solve()));
		err("------------------");
		err(time());
	}
}
