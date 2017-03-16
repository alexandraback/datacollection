import java.util.*;
import java.io.*;
import java.math.*;

import static java.lang.Math.*;

public class Solution implements Runnable {
	
	interface WarGameSolver {
		
		int getOptimalNaomiPoints(int n, double a[], double b[]);
		
	}
	
	class DeceitfulWarGameSolver implements WarGameSolver {
		
		@Override
		public int getOptimalNaomiPoints(int n, double a[], double b[]) {
			int pointsNaomiMax = 0;
			for (int k = 0; k < n; k++) {
				int kenL = 0;
				int pointsNaomi = 0;
				for (int l = k; l < n; l++) {
					if (a[l] > b[kenL]) {
						pointsNaomi++;
						kenL++;
					}
				}
				pointsNaomiMax = max (pointsNaomiMax, pointsNaomi);
			}
			return pointsNaomiMax;
		}
		
	}
	
	class OriginalWarGameSolver implements WarGameSolver {
		
		@Override
		public int getOptimalNaomiPoints(int n, double[] a, double[] b) {
			int kenPoints = 0;
			
			boolean used[] = new boolean [n];
			
			for (int i = n - 1; i >= 0; i--) {
				int k = -1;
				for (int j = 0; j < n; j++) {
					if (!used[j] && b[j] > a[i]) {
						k = j;
						break;
					}
				}
				if (k == -1) {
					for (int j = 0; j < n; j++)
						if (!used[j]) {
							used[j] = true;
							break;
						}
				} else {
					used[k] = true;
					kenPoints++;
				}
			}
			
			return n - kenPoints;
		}
		
	}
	
	public void solve() throws Exception {
		int tests = sc.nextInt();
		for (int test = 0; test < tests; test++) {
			out.print(String.format("Case #%d: ", test + 1));
			int n = sc.nextInt();
			double a[] = new double [n];
			double b[] = new double [n];
			for (int i = 0; i < n; i++) {
				a[i] = sc.nextDouble();
			}
			for (int i = 0; i < n; i++) {
				b[i] = sc.nextDouble();
			}
			Arrays.sort(a);
			Arrays.sort(b);
			
			out.println(String.format("%d %d\n", 
					new DeceitfulWarGameSolver().getOptimalNaomiPoints(n, a, b), 
					new OriginalWarGameSolver().getOptimalNaomiPoints(n, a, b)));
		}
	}


	static Throwable t;

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
		} catch (Throwable t) {
			Solution.t = t;
		} finally {
			out.close();
		}
	}

	public static void main(String[] args) throws Throwable {
		Thread thread = new Thread(null, new Solution(), "", 1 << 26);
		thread.start();
		thread.join();
		if (Solution.t != null)
			throw t;
	}

}

class FastScanner {

	BufferedReader in;
	StringTokenizer st;

	public FastScanner(BufferedReader in) {
		this.in = in;
	}

	public String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
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