import static java.lang.Math.*;
import static java.lang.System.currentTimeMillis;
import static java.lang.System.exit;
import static java.lang.System.arraycopy;
import static java.util.Arrays.sort;
import static java.util.Arrays.binarySearch;
import static java.util.Arrays.fill;

import java.util.*;
import java.io.*;

@SuppressWarnings("unused")
public class Main {
	private static final String FILENAME = "a";

	public static void main(String[] args) throws IOException {
		new Main().run();		
	}

	BufferedReader in;
	PrintWriter out;
	StringTokenizer st = new StringTokenizer("");

	private void run() throws IOException {
		in = new BufferedReader(new FileReader(FILENAME + ".in"));
		out = new PrintWriter(FILENAME + ".out");
		solve();
		in.close();
		out.close();
	}
	
	String S[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", 
			"SIX", "SEVEN", "EIGHT", "NINE"};
	int[][] b = new int[10][26];
	int[] a = new int[26];
	int[] ans = new int[10];
	
	private void solve() throws IOException {
		
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < S[i].length(); j++) {
				b[i][S[i].charAt(j) - 'A']++;
			}
		}
		
		int T = nextInt();
		for (int t = 0; t < T; t++) {
			char[] c = nextLine().toCharArray();
			for (int i = 0; i < c.length; i++)
				a[c[i] - 'A']++;
			fill(ans, 0);
			
			sub(0);
			sub(2);
			sub(6);
			sub(4);
			sub(5);			
			sub(8);
			sub(7);
			sub(1);
			sub(3);
			sub(9);
			
			out.print("Case #" + (t + 1) + ": ");
			for (int i = 0; i < 10; i++) {
//				System.err.println(a[i]);
				for (int j = 0; j < ans[i]; j++)
					out.print("" + i);
			}
			out.println();
		}
		
	}
	
	void sub(int x) {
		int m = Integer.MAX_VALUE / 2;
		for (int i = 0; i < 26; i++) {
			if (b[x][i] > 0) {
				m = min(m, a[i] / b[x][i]);
			}
		}
		for (int i = 0; i < 26; i++) {
			a[i] -= b[x][i] * m;
		}
		ans[x] = m;
	}
	
	void chk(boolean b) {
		if (b)
			return;
		System.out.println(new Error().getStackTrace()[1]);
		exit(999);
	}
	void deb(String fmt, Object... args) {
		System.out.printf(Locale.US, fmt + "%n", args);
	}
	String nextToken() throws IOException {
		while (!st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}
	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
	String nextLine() throws IOException {
		st = new StringTokenizer("");
		return in.readLine();
	}
	boolean EOF() throws IOException {
		while (!st.hasMoreTokens()) {
			String s = in.readLine();
			if (s == null)
				return true;
			st = new StringTokenizer(s);
		}
		return false;
	}
}
