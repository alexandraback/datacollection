import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Locale;
import java.util.StringTokenizer;

public class C {
	
	HashSet<BigInteger> pals[] = new HashSet[101];
	ArrayList<BigInteger> all;

	boolean isPal(BigInteger x) {
		BigInteger now = x, ans = val(0);
		while (now.compareTo(val(0)) > 0) {
			ans = ans.multiply(val(10)).add(now.mod(val(10)));
			now = now.divide(val(10));
		}
		return x.compareTo(ans) == 0;
	}
	
	boolean isGood(BigInteger x) {
		return isPal(x) && isPal(x.multiply(x));
	}
	void gen(int len) {
		if (len > 50) return;
		pals[len] = new HashSet<>();
		if (len == 1) {
			pals[len].add(val(1));
			pals[len].add(val(2));
			pals[len].add(val(3));
		} else {
			for(BigInteger p : pals[len - 1]) {
				BigInteger newp = val(0);
				for(int i = 0; i <= 2; i++) {
					newp = p.mod(BigInteger.TEN.pow(len / 2));
					newp = newp.add(p.divide(BigInteger.TEN.pow(len / 2)).multiply(BigInteger.TEN.pow(len  / 2 + 1)));
					newp = newp.add(val(i).multiply(BigInteger.TEN.pow(len / 2)));

					if (isGood(newp) && newp.compareTo(val(10).pow(len - 1)) >= 0) {
						pals[len].add(newp);
					}
				}
			}
		}
		gen(len + 1);
	}
	
	int solve(BigInteger x) {
		int ans = Collections.binarySearch(all, x); 
		return ans < 0 ? (- ans - 1) : ans;
	}
	void do_solve() {
		BigInteger a = new BigInteger(nextToken());
		BigInteger b = new BigInteger(nextToken()).add(val(1));
		out.println(solve(b) - solve(a));
	}

	void mainProgram() {
		init("C");
	
		gen(1);
		all = new ArrayList<>(0);
		for(int len = 1; len <= 50; len++) {
			for(BigInteger x : pals[len]) {
				all.add(x.multiply(x));
			}
		}
		Collections.sort(all);
		int tests = nextInt();
		for(int test = 1; test <= tests; test++) {
			long T = System.currentTimeMillis();
			out.print("Case #" + test + ": ");
			do_solve();
			System.err.println("Time on test " + test + ": "
					+ (System.currentTimeMillis() - T) + " ms");
		}
		out.close();
	}

	static void debug(Object... o) {
		System.err.println(Arrays.deepToString(o));
	}

	void init(String filename) {
		Locale.setDefault(Locale.US);
		if (filename != null)
			try {
				in = new BufferedReader(new FileReader(filename + ".in"));
				out = new PrintWriter(filename + ".out");
			} catch (Exception e) {
				e.printStackTrace();
				filename = null;
			}
		if (filename == null) {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
		}
		st = new StringTokenizer("");
	}

	static BufferedReader in;
	static StringTokenizer st = new StringTokenizer("");
	static PrintWriter out;
	static long systemTime;

	public static void main(String[] args) {
		try {
			setTime();
			new C().mainProgram();
			printTime();
			printMemory();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	static void setTime() {
		systemTime = System.currentTimeMillis();
	}

	static void printTime() {
		System.err.println("Time consumed: "
				+ (System.currentTimeMillis() - systemTime));
	}

	static void printMemory() {
		System.err.println("Memory consumed: "
				+ (Runtime.getRuntime().totalMemory() - Runtime.getRuntime()
						.freeMemory()) / 1000 + "kb");
	}

	boolean hasMoreTokens() {
		try {
			while (!st.hasMoreTokens()) {
				st = new StringTokenizer(in.readLine());
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		return st.hasMoreTokens();
	}

	String nextToken() {
		return hasMoreTokens() ? st.nextToken() : null;
	}

	Integer nextInt() {
		return Integer.parseInt(nextToken());
	}

	Double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	Long nextLong() {
		return Long.parseLong(nextToken());
	}

	BigInteger add(BigInteger A, BigInteger B) {
		return A.add(B);
	}

	BigInteger mult(BigInteger A, BigInteger B) {
		return A.multiply(B);
	}

	BigInteger sub(BigInteger A, BigInteger B) {
		return A.subtract(B);
	}

	BigInteger div(BigInteger A, BigInteger B) {
		return A.divide(B);
	}

	BigInteger mi(BigInteger A) {
		return (BigInteger.ZERO).subtract(A);
	}

	BigInteger sq(BigInteger A) {
		return A.multiply(A);
	}

	BigInteger val(long a) {
		return BigInteger.valueOf(a);
	}

	int cmp(BigInteger a, BigInteger b) {
		return a.compareTo(b);
	}

	BigInteger gcd(BigInteger a, BigInteger b) {
		if (cmp(a, val(0)) < 0)
			a = mi(a);
		if (cmp(b, val(0)) < 0)
			b = mi(b);
		return a.gcd(b);
	}
}
