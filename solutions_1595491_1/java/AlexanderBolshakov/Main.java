import java.io.*;
import java.security.SecureRandom;
import java.util.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Main implements Runnable {
	
	static String filename = "B-large";
	
	public void solve() throws Exception {
		int t = sc.nextInt();
		for (int Case = 1; Case <= t; Case++) {
			int n = sc.nextInt(), s = sc.nextInt(), p = sc.nextInt();
			ArrayList<Integer>[] points = new ArrayList[3];
			for (int i = 0; i < 3; i++) {
				points[i] = new ArrayList<Integer>();
			}
			for (int i = 0; i < n; i++) {
				int num = sc.nextInt();
				points[num % 3].add(num);
			}
			for (int i = 0; i < 3; i++) {
				Collections.sort(points[i]);
			}
			int ans = 0;
			for (int i = points[0].size() - 1; i >= 0; i--) {
				if (points[0].get(i) / 3 >= p) {
					ans++;
					points[0].remove(i);
				}
			}
			for (int i = points[1].size() - 1; i >= 0; i--) {
				if (points[1].get(i) / 3 + 1 >= p) {
					ans++;
					points[1].remove(i);
				}
			}
			for (int i = points[2].size() - 1; i >= 0; i--) {
				if (points[2].get(i) / 3 + 1 >= p) {
					ans++;
					points[2].remove(i);
				}
			}
			for (int i = points[0].size() - 1; i >= 0 && s > 0; i--) {
				if (points[0].get(i) >= 3 && points[0].get(i) / 3 + 1 >= p) {
					ans++;
					s--;
					points[0].remove(i);
				}
			}
			for (int i = points[2].size() - 1; i >= 0 && s > 0; i--) {
				if (points[2].get(i) / 3 + 2 >= p) {
					ans++;
					s--;
					points[2].remove(i);
				}
			}
			out.printf("Case #%d: %d\n", Case, ans);
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
