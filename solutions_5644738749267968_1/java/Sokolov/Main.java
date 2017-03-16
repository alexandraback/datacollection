import java.io.*;
import java.util.*;
import java.math.*;


public class Main {
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	
	static void solve() throws Exception {		
		int t = nextInt();
		for (int tt = 1; tt <= t; tt++) {
			int n = nextInt();
			double[] a = new double[n];
			for (int i = 0; i < n; i++) {
				a[i] = nextDouble();
			}
			Arrays.sort(a);
			double[] b = new double[n];
			for (int i = 0; i < n; i++) {
				b[i] = nextDouble();
			}
			Arrays.sort(b);
			int cnt1 = 0;
			int l1 = 0;
			int r1 = n-1;
			int l2 = 0;
			int r2 = n-1;
			while (l1 <= r1) {
				if (a[r1] > b[r2]) {
					cnt1++;
					r1--;
				} else {
					l1++;
				}
				r2--;
			}
			int cnt2 = 0;
			int l = 0;
			int r = n-1;
			for (int i = n-1; i >= 0; i--) {
				if (a[i] > b[r]) {
					cnt2++;
					l++;
				} else {
					r--;
				}
			}
			out.println("Case #" + tt + ": " + cnt1 + " " + cnt2);
		}
	}
	
	static int sqr(int x) {
		return x*x;
	}
	
	static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static BigInteger nextBigInteger() throws IOException {
		return new BigInteger(next());
	}
	
	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}
	
	static String nextLine() throws IOException {
		tok = new StringTokenizer("");
		return in.readLine();
	}

	static boolean hasNext() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			String s = in.readLine();
			if (s == null) {
				return false;
			}
			tok = new StringTokenizer(s);
		}
		return true;
	}

	public static void main(String args[]) {
		try {
			//in = new BufferedReader(new InputStreamReader(System.in));
			//out = new PrintWriter(new OutputStreamWriter(System.out));
			in = new BufferedReader(new FileReader("1.in"));
			out = new PrintWriter(new FileWriter("1.out"));
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			java.lang.System.exit(1);
		}
	}
}