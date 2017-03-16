import java.util.*;
import java.io.*;
import java.math.*;

import static java.lang.Math.*;

public class Solution implements Runnable {
	
	class Zip implements Comparable<Zip> {
		
		String zip;
		int index;
		
		public Zip(String zip, int index) {
			this.zip = zip;
			this.index = index;
		}
		
		@Override
		public int compareTo(Zip arg0) {
			return zip.compareTo(arg0.zip);
		}
		
	}
	
	int n, m;
	boolean used[];
	boolean can[][];
	int perm[];
	int map[];
	int g[][];
	
	int distance;
	int reach;
	Zip zip[];
	
	int bestResult;
	int[] bestPerm;
	
	void dfs(int v) {
		while (reach != n) {
			if (can[v][perm[reach]]) {
				distance += 2;
				reach++;
				dfs(perm[reach - 1]);
			} else {
				break;
			}
		}
	}
	
	boolean go(int k) {
		if (k == n) {
			// go
			distance = 0;
			reach = 1;
			dfs(perm[0]);
			return reach == n;
		} else {
			for (int i = 0; i < n; i++) {
				if (!used[i]) {
					used[i] = true;
					perm[k] = i;
					if (go(k + 1))
						return true;
					used[i] = false;
				}
			}
		}
		return false;
	}
	
	public void solve() throws Exception {
		int tests = sc.nextInt();
		outer:
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			n = sc.nextInt();
			m = sc.nextInt();
			zip = new Zip[n];
			for (int i = 0; i < n; i++) {
				zip[i] = new Zip(sc.nextToken(), i);
			}
			Arrays.sort(zip);
			map = new int [n];
			for (int i = 0; i < n; i++) {
				map[zip[i].index] = i;
			}
			can = new boolean [n][n];
			for (int i = 0; i < m; i++) {
				int v1 = map[sc.nextInt() - 1];
				int v2 = map[sc.nextInt() - 1];
				can[v1][v2] = true;
				can[v2][v1] = true;
			}
			perm = new int [n];
			used = new boolean [n];
			go(0);
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < n; i++) {
				sb.append(zip[perm[i]].zip);
			}
			out.println(sb.toString());
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