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
	public static long ans = 1;
	public static long block = 0;
	public static long d[] = new long[40];
	public static long ff[][] = new long[500][500];
	public static long fac[] = new long[105];
	public static void main(String[] args) throws IOException {		
		InputReader in = new InputReader(new FileInputStream("input.txt"));
		PrintWriter out = new PrintWriter(new FileOutputStream("output.txt"));
		int t = in.nextInt();
	    StringBuilder s[] = new StringBuilder[100];
	    fac[1] = 1; fac[0] = 1;
	    for (int i = 2; i <= 100; i++) {
	    	fac[i] = (fac[i - 1] * (long)i) % mod;
	    }
		for (int tt = 0; tt < t; tt++) {
			for (int i = (int)'a'; i <= (int)'z'; i++) {
				for (int j = (int)'a'; j <= (int)'z'; j++) {
					ff[i][j] = 0;
				}
			}
			out.print("Case #" + new Integer(tt + 1).toString() + ": ");
			int n = in.nextInt();
			for (int i = 0 ;i < n ; i++) {
				s[i] = new StringBuilder(in.next());
			}
			ans = 1; block = 0;
			if (precheck(n, s)) {
				doo(n, s);
			}
			out.println(ans);
		}
		out.close();
	}
	private static boolean precheck(int n, StringBuilder[] s) {
		boolean dd[][] = new boolean[100][500];
		for (int i = 0 ; i< n; i++) {
			for (char c : s[i].toString().toCharArray()) {
				dd[i][(int)c] = true;
			}
		}
		int vs[] = new int[500];
		for (int i = (int)'a'; i <= (int)'z'; i++) {
			for (int q = 0; q < s.length; q++) {
				if (dd[q][i]) {
					vs[i]++;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (char c : s[i].toString().toCharArray()) {
				if (c != s[i].charAt(0) && c != s[i].charAt(s[i].length() - 1)) {
					if (vs[c] > 1) {
						ans = 0; return false;
					}
				}
			}
		}
		return true;
	}
	private static void doo(int n, StringBuilder[] s) {
		for (int i = 0; i < n; i++) {
			s[i] = check(s[i].toString());
			if (s[i].toString().equals("-")) {
				ans = 0; return;
			}
		}
		for (int i = (int)('a'); i <= (int)('z'); i++) {
			for (int j = (int)('a'); j <= (int)('z'); j++) {
				if (i != j && ff[i][j] > 1) {
					ans = 0; return;
				}
				if (i != j && ff[i][j] * ff[j][i] > 0)  {
					ans = 0 ;return;
				}
			}
		}
		for (int i = (int)('a'); i <= (int)('z'); i++) {
			int x = 0;
			for (int j = (int)('a'); j <= (int)('z'); j++) {
				if (j != i && ff[i][j] > 0) x++;
			}
			if (x > 1) {
				ans = 0 ;return;
			}
		}
		for (int i = 0; i < n; i++) {
			int a = (int)s[i].charAt(0);
			int b = (int)s[i].charAt(1);
			if (ff[a][b] > 0) {
				block++;
				if (a == b) {
					ans = (ans * fac[(int) ff[a][a]]) % mod;					
				}
				ff[a][b] = 0;
				sendBoth(a, b);
			}
		}
		ans = (ans * fac[(int) block]) % mod;
	}
	private static void sendBoth(int a, int b) {
		sendRight(b);
		sendLeft(a);
	}
	private static void sendRight(int b) {
		ans = (ans * fac[(int) ff[b][b]]) % mod; ff[b][b] = 0;
		for (int j = (int)('a'); j <= (int)('z'); j++) { 
			if (ff[b][j] > 0) {
				ff[b][j] = 0;
				sendRight(j);
			}
		}
	}
	private static void sendLeft(int a) {
		ans = (ans * fac[(int) ff[a][a]]) % mod; ff[a][a] = 0;
		for (int j = (int)('a'); j <= (int)('z'); j++) {
			if (ff[j][a] > 0) {
				ff[j][a] = 0;
				sendLeft(j);
			}
		}
	}
	private static StringBuilder check(String s) {
		StringBuilder c = new StringBuilder(""); 
		c.append(s.charAt(0));
		c.append(s.charAt(s.length() - 1));
		
		boolean fg[] = new boolean[500];
		fg[s.charAt(0)] = true;
		for (int i = 1; i < s.length(); i++) {
			if (fg[s.charAt(i)] && s.charAt(i) != s.charAt(i - 1)) {
				ans = 0; return new StringBuilder("-");
			}
		}
		ff[(int)c.charAt(0)][(int)c.charAt(1)]++;
		return c;
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