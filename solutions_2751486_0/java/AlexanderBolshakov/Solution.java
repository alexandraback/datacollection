import java.util.*;
import java.io.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Solution implements Runnable {
	
	boolean isVowel(char c) {
		switch (c) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return true;
		default:
			return false;
		}
	}

	public void solve() throws Exception {
		int t = sc.nextInt();
	outer:
		for (int Case = 1; Case <= t; Case++) {
			out.print("Case #" + Case + ": ");
			String str = sc.nextToken();
			int n = sc.nextInt();
			ArrayList<Integer> starts = new ArrayList<Integer>();
			for (int l = 0; l < str.length(); ) {
				if (isVowel(str.charAt(l))) {
					l++;
					continue;
				}
				int r = l;
				while (r < str.length() && !isVowel(str.charAt(r))) {
					r++;
				}
				for (int i = l; r - i >= n; i++) {
					starts.add(i);
				}
				l = r;
			}
			long ans = 0;
			int pos = 0;
			for (int i = 0; i < str.length() && pos < starts.size(); i++) {
				while (pos < starts.size() && starts.get(pos) < i) {
					pos++;
				}
				if (pos < starts.size()) {
					ans += str.length() - (starts.get(pos) + n) + 1;
				}
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
			in = new BufferedReader(new FileReader("A-small-attempt0.in"));
			out = new PrintWriter(new FileWriter("A-small-attempt0.out"));
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