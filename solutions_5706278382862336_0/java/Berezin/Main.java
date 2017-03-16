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
	public static int ans = 41;
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
		for (int tt = 0; tt < t; tt++) {
			out.print("Case #" + new Integer(tt + 1).toString() + ": ");
			String s = in.nextLine();
			String[] arr = s.split("/");
			int p = Integer.parseInt(arr[0]);
			int q = Integer.parseInt(arr[1]);
			boolean ok = false;
			for (int i = 0; i <= 10; i++) {
				if (d[i] == q) { ok = true; break; }
			}
			if (!ok) {
				out.println("impossible");
			} else {
				out.println(find(p, q));
			}
		}
		out.close();
	}
	private static int find(int p, int q) {
		if (p == 1 && q == 1) return 0;
		if (f[p][q] > 0) return f[p][q];
		int a3 = p;
		int a1 = q / 2;
		int a2 = (2*a3 - 2*a1);
		if (a2 >= 0) {
			f[p][q] = 1; return 1;
		} else {
			f[p][q] = 41;
			for (a1 = 0; a1 <= q / 2; a1++) {
				a2 = (2*a3 - 2*a1);
				if (a2 >= 0) {
					a2 = a2 / 2;
					f[p][q] = Math.min(f[p][q], Math.min(find(a1, q / 2), find(a2, q / 2)) + 1);
				}
			}
			return f[p][q];
		}
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