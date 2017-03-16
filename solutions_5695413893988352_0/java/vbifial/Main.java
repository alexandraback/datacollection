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
	private static final String FILENAME = "b";

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
	
	long alc = 20000;
	long arc = 10000;
	int len = 0;
	
	private void solve() throws IOException {
		
		int T = nextInt();
		for (int t = 0; t < T; t++) {
			
			int alc = 1000000;
			int arc = 10000;
			
			char[] s = nextToken().toCharArray();
			char[] g = nextToken().toCharArray();
			len = s.length;
			
			for (int i = 0; i < 1000; i++) {
				char[] x = String.format("%0" + len + "d", i).toCharArray();
//				System.err.println(x);
				if (x.length > len)
					break;
				boolean o = true;
				for (int k = 0; k < len; k++) {
					if (s[k] != '?' && s[k] != x[k])
						o = false;
				}
				if (!o)
					continue;
				for (int j = 0; j < 1000; j++) {
					char[] y = String.format("%0" + len + "d", j).toCharArray();
					if (y.length > len)
						break;
					o = true;
					for (int k = 0; k < len; k++) {
						if (g[k] != '?' && g[k] != y[k])
							o = false;
					}
					if (!o)
						continue;
//					System.err.println(x);
//					System.err.println(s);
//					System.err.println(y);
//					System.err.println(g);
					if (abs(i - j) < abs(alc - arc) ||
							(abs(i - j) == abs(alc - arc) && 
							(i < alc || (i == alc && j < arc)))) {
						alc = i;
						arc = j;
					}
				}
			}
			
			
			out.print("Case #" + (t + 1) + ": " + 
					String.format("%0" + len + "d %0" + len + "d", alc, arc));
			
			out.println();
		}
		
	}
	
	void rec(char[] l, char[] r) {
		
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
