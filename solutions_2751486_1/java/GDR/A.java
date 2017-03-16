import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {
	FastScanner in;
	PrintWriter out;

	
	
	private boolean isVowel(char c) {
		//a, e, i, o, and u
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
			return true;
		}
		return false;
	}
	
	private long sol(String s, int n) {
		long ans = 0;
		int[] a = new int[s.length()];
		int cur = 0;
		for (int i = 0; i < s.length(); i++) {
			if (!isVowel(s.charAt(i))) {
				cur++;
			} else {
				cur = 0;
			}
			a[i] = cur;
		}
		cur = 0;
		for (int i = 0; i < s.length() - n + 1; i++) {
			while (cur < s.length() && a[cur] < n || cur < i + n - 1) {
				cur++;
			}
			if (cur >= s.length()) {
				break;
			}
			ans += s.length() - cur;
		}
		return ans;
	}
	
	public void solve() throws IOException {
		int t = in.nextInt();
		for (int i = 0; i < t; i++) {
			String s = in.next();
			int n = in.nextInt();
			out.println("Case #" + (i + 1) + ": " + sol (s, n));
		}
	}

	public void run() {
		try {
			InputStream inputStream = new FileInputStream("A-large.txt.in");
			in = new FastScanner(inputStream);
			out = new PrintWriter("out.out");
			solve();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(InputStream is) {
			br = new BufferedReader(new InputStreamReader(is));
		}

		public boolean hasNext() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					String line = br.readLine();
					if (line == null) {
						return false;
					}
					st = new StringTokenizer(line);
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			if (st != null && st.hasMoreTokens()) {
				return true;
			}
			return false;
		}

		public String next() {
			if (hasNext()) {
				return st.nextToken();
			}
			return null;
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new A().run();
	}
}