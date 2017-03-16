import java.io.*;
import java.util.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Solution implements Runnable {
	
	int n, k;
	Boolean can [];
	int [] initialKeys, answer, need;
	int [][] inside;
	
	void put (TreeMap<Integer, Integer> map, int key, int value) {
		if (!map.containsKey(key)) {
			map.put(key, value);
		} else {
			map.put(key, map.get(key) + value);
		}
	}
	
	boolean doIt (int mask) {
		if (mask == (1 << n) - 1) return true;
		if (can[mask] != null) return can[mask];
		boolean result = false;
		TreeMap<Integer, Integer> keys = new TreeMap<>();
		for (int i = 0; i < k; i++) {
			put (keys, initialKeys[i], 1);
		}
		for (int i = 0; i < n; i++)
			if ((mask & (1 << i)) > 0) {
				put (keys, need[i], -1);
				for (int j = 0; j < inside[i].length; j++)
					put (keys, inside[i][j], 1);
			}
		for (int to = 0; to < n; to++) {
			if ((mask & (1 << to)) == 0) {
				if (keys.get(need[to]) != null && keys.get(need[to]) > 0) {
					result = result || doIt (mask | (1 << to));
				}
			}
		}
		return can[mask] = result;
	}
	
	public void solve() throws Throwable {
		int tests = sc.nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #"+test+": ");
			k = sc.nextInt();
			n = sc.nextInt();
			answer = new int [n];
			need = new int [n];
			inside = new int [n][];
			initialKeys = new int [k];
			for (int i = 0; i < k; i++) {
				initialKeys[i] = sc.nextInt() - 1;
			}
			for (int i = 0; i < n; i++) {
				need[i] = sc.nextInt() - 1;
				int count = sc.nextInt();
				inside[i] = new int [count];
				for (int j = 0; j < count; j++) {
					inside[i][j] = sc.nextInt() - 1;
				}
			}
			can = new Boolean [(1 << n)];
			if (!doIt(0)) {
				out.println("IMPOSSIBLE");
			} else {
				int mask = 0, it = 0;
				while (mask != (1 << n) - 1) {
					TreeMap<Integer, Integer> keys = new TreeMap<>();
					for (int i = 0; i < k; i++) {
						put (keys, initialKeys[i], 1);
					}
					for (int i = 0; i < n; i++)
						if ((mask & (1 << i)) > 0) {
							put (keys, need[i], -1);
							for (int j = 0; j < inside[i].length; j++)
								put (keys, inside[i][j], 1);
						}
					for (int to = 0; to < n; to++) {
						if ((mask & (1 << to)) == 0) {
							if (keys.get(need[to]) != null && keys.get(need[to]) > 0 && doIt(mask | (1 << to))) {
								answer[it++] = to + 1;
								mask |= (1 << to);
								break;
							}
						}
					}
				}
				for (int i = 0; i < n; i++) {
					out.print(answer[i]+" ");
				}
				out.println();
			}
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