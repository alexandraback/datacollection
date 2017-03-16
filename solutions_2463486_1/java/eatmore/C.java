import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.binarySearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static final long ans[];
	static {
		List<Long> ansL = new ArrayList<Long>();
		final long LIMIT = 100000000000000L;
		out: for (int nPre = 1;; nPre *= 10) {
			for (int n = nPre; n < 10 * nPre; n++) {
				long nn = (long) n * nPre + rev(n / 10, nPre);
				long nnn = nn * nn;
				if (nnn > LIMIT) {
					break out;
				} else if (isPalindrome(nnn)) {
					ansL.add(nnn);
				}
			}
			for (int n = nPre; n < 10 * nPre; n++) {
				long nn = (long) n * (nPre * 10) + rev(n, nPre * 10);
				long nnn = nn * nn;
				if (nnn > LIMIT) {
					break out;
				} else if (isPalindrome(nnn)) {
					ansL.add(nnn);
				}
			}
		}
		int n = ansL.size();
		ans = new long[n];
		for (int i = 0; i < n; i++) {
			ans[i] = ansL.get(i);
		}
	}
	
	static void solve() throws Exception {
		long a = nextLong();
		long b = nextLong();
		int l = binarySearch(ans, a);
		if (l < 0) {
			l = ~l;
		}
		int r = binarySearch(ans, b + 1);
		if (r < 0) {
			r = ~r;
		}
		printCase();
		out.println(r - l);
	}
	
	static int rev(int n, int lim) {
		int ans = 0;
		while (lim > 1) {
			ans = ans * 10 + n % 10;
			n /= 10;
			lim /= 10;
		}
		return ans;
	}
	
	static boolean isPalindrome(long n) {
		long rev = 0;
		long lim = 1;
		while (n >= lim) {
			rev = rev * 10 + n % 10;
			lim = lim * 10;
			if (lim > n) {
				break;
			}
			n /= 10;
		}
		return n == rev;
	}
	
	static void printCase() {
		out.print("Case #" + test + ": ");
	}
	
	static void printlnCase() {
		out.println("Case #" + test + ":");
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
			int tests = nextInt();
			for (test = 1; test <= tests; test++) {
				solve();
			}
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}