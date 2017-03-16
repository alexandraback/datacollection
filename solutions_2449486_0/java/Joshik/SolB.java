import java.util.*;
import java.io.*;

//import java.math.*;

public class SolB implements Runnable {
	public static void main(String[] args) {
		new Thread(new SolB()).start();
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

	private final String FNAME = "B-small-attempt0";

	void solve() {
		int tests = nextInt();
		all: for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			int n = nextInt();
			int m = nextInt();
			int[][] tab = new int[n][m];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					tab[i][j] = nextInt();
				}
			}
			int[] maxx = new int[n];
			int[] maxy = new int[m];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					maxx[i] = Math.max(maxx[i], tab[i][j]);
					maxy[j] = Math.max(maxy[j], tab[i][j]);
				}
			}
			boolean good = true;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (tab[i][j] != Math.min(maxx[i], maxy[j])) {
						good = false;
					}
				}
			}
			out.println(good ? "YES" : "NO");
		}
	}
}
 