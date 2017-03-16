import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
	// in.next() in.nextInt() 
	// int n = in.nextInt(); for (int i = 0; i < n; i++) a[i] = in.nextInt();
	// for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) a[i][j] = in.nextInt();
	public static long mod = 1000000000 + 7;
	public static long ans = 0;
	public static void main(String[] args) throws IOException {		
		InputReader in = new InputReader(new FileInputStream("input.txt"));
		PrintWriter out = new PrintWriter(new FileOutputStream("output.txt"));
		int t = in.nextInt();
		for (int tt = 0; tt < t; tt++) {
			int n = in.nextInt(); 
			int m = in.nextInt();
			int a[][] = new int[n][m];
			int k = in.nextInt();
			ans = k;
			gen(n, m, k, a, 0, 0, 0);
			out.println("Case #" + (new Integer(tt + 1).toString()) + ": " + ans);
		}
		out.close();
	}

private static void gen(int n, int m, int k, int[][] a, int i, int j, int l) {
	if (l > Main.ans) return;
	if (j == m) {
		gen(n, m, k, a, i+1, 0, l);
		return;
	}
	if (i == n) {
		check(a, n, m, k, l);
		return;
	}
	gen(n, m, k, a, i, j + 1, l);
	a[i][j] = 1;
	gen(n, m, k, a, i, j + 1, l + 1);
	a[i][j] = 0;
}
private static void check(int[][] a, int n, int m, int k, int l) {
	int count = 0;
	boolean f[][] = new boolean[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
				tr(f, a, n, m, k, i, j);
			}
		}
	}
	for (int i = 0; i< n ; i++) {
		for (int j = 0; j < m ; j++) {
			if (!f[i][j]) {
				count++;
				if (count == k) {
					ans = Math.min(ans, l);
				}
			}
		}
	}
}
private static void tr(boolean[][] f, int[][] a, int n, int m, int k, int i,
		int j) {
	if (i < 0 || j < 0 || i >= n || j >= m) return;
	if (f[i][j]) {
		return;
	}
	if (a[i][j] == 1) return;
	f[i][j] = true;
	tr(f ,a , n, m , k, i, j + 1);
	tr(f ,a , n, m , k, i, j - 1);
	tr(f ,a , n, m , k, i - 1, j);
	tr(f ,a , n, m , k, i + 1, j);
}
}
class InputReader {
	public BufferedReader reader;
	public StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream));
		tokenizer = null;
	}
	public String nextLine() throws IOException {
		return reader.readLine();
	}
	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}
	
	public double nextDouble() {
		return Double.parseDouble(next());
	}
	
	public long nextLong() {
		return Long.parseLong(next());
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}
}