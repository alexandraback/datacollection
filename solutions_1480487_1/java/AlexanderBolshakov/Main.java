import java.io.*;
import java.security.SecureRandom;
import java.util.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Main implements Runnable {
	
	static String filename = "A-large";

	public void solve() throws Exception {
		int t = sc.nextInt();
		for (int Case = 1; Case <= t; Case++) {
			int n = sc.nextInt();
			int[] s = new int[n];
			int x = 0;
			for (int i = 0; i < n; i++) {
				s[i] = sc.nextInt();
				x += s[i];
			}
			out.printf(Locale.US, "Case #%d: ", Case);
			double l = 0, r = 3 * x;
		tsearch:
			for (int it = 0; it < 100; it++) {
				double m = (l + r) / 2;
				//out.println(m);
				double left = x;
				for (int i = 0; i < n; i++) {
					if (s[i] >= m) {
						continue;
					} else if (m - s[i] > left) {
						r = m;
						continue tsearch;
					} else {
						left -= m - s[i];
					}
				}
				l = m;
			}
			//out.println(x + " " + l);
			for (int i = 0; i < n; i++) {
				out.printf(Locale.US, "%.10f ", s[i] >= l ? 0 : (l - s[i]) / x * 100);
			}
			out.println();
		}
	}
	
	BufferedReader in;
	PrintWriter out;
	FastScanner sc;
	
	
	public static void main(String[] args) {
		new Thread(null, new Main(), "", 1 << 25).start();
	}
	
	@Override
	public void run() {
		try {
			init();
			solve();
		} catch (Exception e) {
			throw new RuntimeException(e);
		} finally {
			out.close();
		}
	}
	
	void init() throws Exception {
		in = new BufferedReader(new FileReader(filename + ".in"));
		out = new PrintWriter(new FileWriter(filename + ".out"));
		sc = new FastScanner(in);
	}
}

class FastScanner {
	
	BufferedReader reader;
	StringTokenizer strTok;
	
	public FastScanner(BufferedReader reader) {
		this.reader = reader;
	}
	
	public String nextToken() throws IOException {
		while (strTok == null || !strTok.hasMoreTokens()) {
			strTok = new StringTokenizer(reader.readLine());
		}
		
		return strTok.nextToken();
	}
	
	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	public long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	
	public double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
	
	public BigInteger nextBigInteger() throws IOException {
		return new BigInteger(nextToken());
	}
	
}
