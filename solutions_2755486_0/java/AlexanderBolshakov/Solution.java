import java.util.*;
import java.io.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Solution implements Runnable {
	
	class Attack implements Comparable<Attack> {
		
		int d, w, e, s;
		
		public Attack(int d, int w, int e, int s) {
			this.d = d;
			this.w = w;
			this.e = e;
			this.s = s;
		}
		
		@Override
		public int compareTo(Attack o) {
			return this.d - o.d;
		}
		
	}

	public void solve() throws Exception {
		int t = sc.nextInt();
	outer:
		for (int Case = 1; Case <= t; Case++) {
			out.print("Case #" + Case + ": ");
			int N = sc.nextInt();
			ArrayList<Attack> attacks = new ArrayList<Attack>();
			for (int i = 0; i < N; i++) {
				int d = sc.nextInt();
				int n = sc.nextInt();
				int w = sc.nextInt(), e = sc.nextInt();
				int s = sc.nextInt();
				int delta_d = sc.nextInt();
				int delta_p = sc.nextInt();
				int delta_s = sc.nextInt();
				for (int a = 0; a < n; a++) {
					attacks.add(new Attack(d + delta_d * a, w + delta_p * a, e + delta_p * a, s + delta_s * a));
				}
			}
			Collections.sort(attacks);
			int[] wall = new int[20001];
			int zero = 10000;
			int ans = 0;
			for (int i = 0; i < attacks.size(); ) {
				int j = i;
				while (j < attacks.size() && attacks.get(j).d == attacks.get(i).d) {
					j++;
				}
				for (int ii = i; ii < j; ii++) {
					Attack a = attacks.get(ii);
					boolean success = false;
					for (int pos = a.w; pos < a.e; pos++) {
						if (wall[zero + pos] < a.s) {
							success = true;
							break;
						}
					}
					if (success) {
						ans++;
					}
				}
				for (int ii = i; ii < j; ii++) {
					Attack a = attacks.get(ii);
					for (int pos = a.w; pos < a.e; pos++) {
						wall[zero + pos] = max(wall[zero + pos], a.s);
					}
				}
				i = j;
			}
			out.println(ans);
		}
	}

	static Throwable uncaught;

	BufferedReader in;
	FastScanner sc;
	PrintWriter out;

	@Override
	public void run() {
		try {
			in = new BufferedReader(new FileReader("C-small-attempt0.in"));
			out = new PrintWriter(new FileWriter("C-small-attempt0.out"));
			sc = new FastScanner(in);
			solve();
		} catch (Throwable uncaught) {
			Solution.uncaught = uncaught;
		} finally {
			out.close();
		}
	}

	public static void main(String[] args) throws Throwable {
		Thread thread = new Thread(null, new Solution(), "", (1 << 26));
		thread.start();
		thread.join();
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