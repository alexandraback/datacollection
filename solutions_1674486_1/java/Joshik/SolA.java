import java.util.*;
import java.io.*;

//import java.math.*;

public class SolA implements Runnable {
	public static void main(String[] args) {
		new Thread(new SolA()).start();
	}

	@Override
	public void run() {
		try {
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	private final String FNAME = "A-large";
	
	int[][] G;
	boolean[] u;
	
	boolean dfs(int i) {
		u[i] = true;
		for (int j : G[i]) {
			if (u[j]) {
				return true;
			} else {
				if (dfs(j)) return true;
			}
		}
		return false; 
	}

	void solve() {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			System.err.println("Test: " + test);
			out.print("Case #" + (test) + ": ");
			int n = nextInt();
			G = new int[n][];
			for (int i = 0; i < n; i++) {
				int k = nextInt();
				G[i] = new int[k];
				for (int j = 0; j < k; j++) {
					G[i][j] = nextInt() - 1;
				}
			}
			boolean found = false;
			for (int i = 0; i < n; i++) {
				u = new boolean[n];
				if (dfs(i)) {
					found = true;
					break;
				}
			}
			if (found) {
				out.println("Yes");
			} else {
				out.println("No");
			}
		}
	}
}
