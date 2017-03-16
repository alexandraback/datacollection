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
	public static int ans = 0;
	public static long d[] = new long[40];
	public static int f[][] = new int[1005][1005];
	public static void main(String[] args) throws IOException {		
		InputReader in = new InputReader(new FileInputStream("input.txt"));
		PrintWriter out = new PrintWriter(new FileOutputStream("output.txt"));
		int t = in.nextInt();
	    d[0] = 1;
	    for (int i = 1;  i <= 10; i++) {
	    	d[i] = d[i-1] * 2;
	    }
	    StringBuilder s[] = new StringBuilder[10];
		for (int tt = 0; tt < t; tt++) {
			out.print("Case #" + new Integer(tt + 1).toString() + ": ");
			int n = in.nextInt();
			for (int i = 0 ;i < n ; i++) {
				s[i] = new StringBuilder(in.next());
			}
			boolean f[] = new boolean[n];
			int a[] = new int[n];
			gen(0, f, a, s);
			out.println(ans);
			System.out.println(ans);
			ans = 0;
		}
		out.close();
	}
	private static void gen(int i, boolean[] f, int a[], StringBuilder[] s) {
		if (i == f.length) {
			check(a, s);
		}
		for (int ii = 0; ii < f.length; ii++) {
			if (!f[ii]) {
				f[ii] = true;
				a[i] = ii;
				gen(i+1, f, a, s);
				f[ii] = false;
			}
		}
	}
	private static void check(int[] a, StringBuilder[] s) {
		StringBuilder ss = new StringBuilder("");
		for (int i = 0; i < a.length; i++) {
			ss.append(s[a[i]]);
		}
		boolean ch[] = new boolean[500]; int x = 0;
		String sss = ss.toString();
		for (char c : sss.toCharArray()) {
			if (x > 0 && ch[(int)c] && sss.charAt(x) != sss.charAt(x - 1)) {
				return;
			}
			ch[(int)c] = true;
			x++;
		}
		ans++;
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