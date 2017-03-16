import java.io.*;
import java.security.SecureRandom;
import java.util.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Main implements Runnable {
	
	static String filename = "A-large";
	
	ArrayList<Integer>[] parents;
	TreeSet<Integer>[] allparents;
	
	boolean dfs(int from) {
		allparents[from] = new TreeSet<Integer>();
		for (int e : parents[from]) {
			if (allparents[e] == null) {
				if (dfs(e)) {
					return true;
				}
			}
			if (allparents[from].contains(e)) {
				return true;
			} else {
				allparents[from].add(e);
			}
			for (int p : allparents[e]) {
				if (allparents[from].contains(p)) {
					return true;
				} else {
					allparents[from].add(p);
				}
			}
		}
		return false;
	}

	public void solve() throws Exception {
		int t = sc.nextInt();
	outer:
		for (int Case = 1; Case <= t; Case++) {
			int n = sc.nextInt();
			ArrayList<Integer>[] parents = new ArrayList[n];
			for (int i = 0; i < n; i++) {
				parents[i] = new ArrayList<Integer>();
				int m = sc.nextInt();
				for (int j = 0; j < m; j++) {
					parents[i].add(sc.nextInt() - 1);
				}
			}
			this.parents = parents;
			this.allparents = new TreeSet[n];
			out.printf(Locale.US, "Case #%d: ", Case);
			for (int i = 0; i < n; i++) {
				if (allparents[i] == null && dfs(i)) {
					out.println("Yes");
					continue outer;
				}
			}
			out.println("No");
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
