import java.util.*;
import java.io.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Solution implements Runnable {
	
	public void solve() throws Exception {
		int tests = sc.nextInt();
		for (int test = 1; test <= tests; test++) {
			long val = sc.nextInt();
			int n = sc.nextInt();
			int a [] = new int [n];
			for (int i = 0; i < n; i++) {
				a[i] = sc.nextInt();
			}
			Arrays.sort(a);
			int answer = Integer.MAX_VALUE;
			if (val != 1) {
				int operations = 0;
				for (int i = 0; i < n; i++) {
					answer = min (answer, operations + n - i);
					while (val <= a[i]) {
						operations++;
						val += val - 1;
					}
					val += a[i];
				}
				answer = min (answer, operations);
			} else {
				answer = n;
			}
			out.println("Case #"+test+": "+answer);
		}
	}
	
	static Throwable uncaught;
	
	BufferedReader in;
	FastScanner sc;
	PrintWriter out;
	
	@Override
	public void run() {
		try {
			in = new BufferedReader(new FileReader("input.txt"));			
			out = new PrintWriter(new FileWriter("output.txt"));
			//in = new BufferedReader(new InputStreamReader(System.in));
			//out = new PrintWriter(System.out);
			sc = new FastScanner(in);
			solve();
		} catch (Throwable uncaught) {
			Solution.uncaught = uncaught;
		} finally {
			out.close();
		}
	}
	
	public static void main(String[] args) throws Throwable {
		new Solution().run();
		if (Solution.uncaught != null) {
			throw Solution.uncaught;
		}
	}

}

class FastScanner {
	
	BufferedReader in;
	StringTokenizer st;
	
	public FastScanner(BufferedReader in) {
		this.in = in;
	}
	
	public String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		return st.nextToken();
	}
	
	public int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}
	
	public long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}
	
	public double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}
	
}