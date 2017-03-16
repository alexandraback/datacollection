import java.io.*;
import java.security.SecureRandom;
import java.util.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Main implements Runnable {
	
	static String filename = "C-small-attempt0";
	
	boolean hasBit(int n, int pos) {
		return (n & (1 << pos)) != 0;
	}

	public void solve() throws Exception {
		int t = sc.nextInt();
		for (int Case = 1; Case <= t; Case++) {
			int n = sc.nextInt();
			int[] nums = new int[n];
			for (int i = 0; i < n; i++) {
				nums[i] = sc.nextInt();
			}
			int ones = (1 << n) - 1;
			int ans1 = 0, ans2 = 0;
			int[] sum = new int[(1 << n)];
			int[] next = new int[(1 << n)];
			Arrays.fill(sum, -1);
			Arrays.fill(next, -1);
			HashMap<Integer, Integer> first = new HashMap<Integer, Integer>();
			HashMap<Integer, Integer> pos = new HashMap<Integer, Integer>();
			for (int i = 1; i < (1 << n); i++) {
				int s = 0;
				for (int j = 0; j < n; j++) {
					if (hasBit(i, j)) {
						s += nums[j];
					}
				}
				sum[i] = s;
				if (!pos.containsKey(s)) {
					pos.put(s, i);
					first.put(s, i);
				} else {
					next[pos.get(s)] = i;
					pos.put(s, i);
				}
			}
		outer:
			for (int i = 1; i < (1 << n); i++) {
				if (i % 10000 == 0) {
					//System.out.println(i);
				}
				if (Integer.bitCount(i) > n / 2) {
					continue;
				} else {
					int curpos = first.get(sum[i]);
					while (curpos != -1) {
						if ((i & curpos) == 0) {
							ans1 = i;
							ans2 = curpos;
							break outer;
						}
						curpos = next[curpos];
					}
				}
			}
			out.printf(Locale.US, "Case #%d:\n", Case);
			if (ans1 == 0 && ans2 == 0) {
				out.println("Impossible");
			} else {
				for (int i = 0; i < n; i++) {
					if (hasBit(ans1, i)) {
						out.print(nums[i] + " ");
					}
				}
				out.println();
				for (int i = 0; i < n; i++) {
					if (hasBit(ans2, i)) {
						out.print(nums[i] + " ");
					}
				}
				out.println();
			}
			//out.println(ans1 + " " + ans2);
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
