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
	public static void main(String[] args) throws IOException {
		new Main().run();		
	}

	BufferedReader in;
	PrintWriter out;
	StringTokenizer st = new StringTokenizer("");

	private void run() throws IOException {
//		if (new File("input.txt").exists())
//			in = new BufferedReader(new FileReader("input.txt"));
//		else
			in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
//		out = new PrintWriter("output.txt");
		solve();
		in.close();
		out.close();
	}
	

	private void solve() throws IOException {
		
		int T = nextInt();
		
		for (int t = 0; t < T; t++) {
			
			int n = nextInt();
			long m = nextLong();
			char c[] = nextToken().toCharArray();
			int a[] = new int[n];
			for (int i = 0; i < n; i++) {
				if (c[i] == 'k')
					a[i] = 6;
				if (c[i] == 'j')
					a[i] = 4;
				if (c[i] == 'i')
					a[i] = 2;
			}
			
			int p[] = new int[n];
			p[0] = a[0];
//			System.err.println(p[0]);
			for (int i = 1; i < n; i++) {
				p[i] = x[p[i - 1]][a[i]];
//				System.err.println(p[i]);
			}
			
			boolean good = true;
			
			int last = pow(p[n - 1], m);
//			System.err.println(last);
//			System.err.println();
			
			if (last != 1)
				good = false;
			
			boolean foundi = false;
			boolean foundj = false;
			
			int prev = 0;
			for (int i = 0; i < (int)min(7, m); i++) {
				
				for (int j = 0; j < n; j++) {
					int cur = x[prev][p[j]];
					
					if (cur == 2 && !foundi) {
						foundi = true;
					}
					
					if (cur == 6 && !foundj && foundi && 
							(m > 7 || !(j == n - 1 && i == m - 1))) {
						foundj = true;
					}
					
				}
				prev = x[prev][p[n - 1]];
			}
			
			if (!foundi || !foundj)
				good = false;
			
			out.println("Case #" + (t + 1) + ": " + ((good) ? "YES" : "NO"));
		}
		
		
	}
	
	int pow(int a, long b) {
		
		if (b == 0)
			return 0;
		
		int c = pow(a, b / 2);
		c = x[c][c];
		if (b % 2 != 0)
			c = x[c][a];
		
		return c;
	}
	
	int x[][] = {
			{0, 1, 2, 3, 4, 5, 6, 7},
			{1, 0, 3, 2, 5, 4, 7, 6},
			
			{2, 3, 1, 0, 6, 7, 5, 4},
			{3, 2, 0, 1, 7, 6, 4, 5},
			
			{4, 5, 7, 6, 1, 0, 2, 3},
			{5, 4, 6, 7, 0, 1, 3, 2},

			{6, 7, 4, 5, 3, 2, 1, 0},
			{7, 6, 5, 4, 2, 3, 0, 1}
	};
	
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
