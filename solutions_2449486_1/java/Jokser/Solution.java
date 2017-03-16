import java.io.*;
import java.util.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Solution implements Runnable {
	
	public void solve() throws Throwable {
		int tests = sc.nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #"+test+": ");
			int n = sc.nextInt();
			int m = sc.nextInt();
			int a [][] = new int [n][m];
			boolean canRow [] = new boolean [n];
			boolean canColumn [] = new boolean [m];
			Arrays.fill(canRow, true);
			Arrays.fill(canColumn, true);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					a[i][j] = sc.nextInt();
				}
			}
			boolean can = true;
			outer:
			for (int h = 100; h >= 1; h--) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						if (a[i][j] == h) {
							if (!canRow[i] && !canColumn[j]) {
								can = false;
								break outer;
							}
						}
					}
				}
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						if (a[i][j] == h) {
							canRow[i] = false;
							canColumn[j] = false;
						}
					}
				}
			}
			out.println(can ? "YES" : "NO");
		}
	}

	BufferedReader in;
	PrintWriter out;
	FastScanner sc;

	static Throwable uncaught;

	@Override
	public void run() {
		try {
			in = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter(new FileWriter("output.txt"));
			sc = new FastScanner(in);
			solve();
		} catch (Throwable t) {
			Solution.uncaught = t;
		} finally {
			out.close();
		}
	}

	public static void main(String[] args) throws Throwable {
		Thread t = new Thread(null, new Solution(), "", (1 << 26));
		t.start();
		t.join();
		if (uncaught != null) {
			throw uncaught;
		}
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
			strTok = new StringTokenizer(reader.readLine().trim());
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

}