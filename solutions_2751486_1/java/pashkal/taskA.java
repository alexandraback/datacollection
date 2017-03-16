import java.io.*;
import java.util.*;

public class taskA {

	PrintWriter out;
	BufferedReader br;
	StringTokenizer st;

	String nextToken() throws IOException {
		while ((st == null) || (!st.hasMoreTokens()))
			st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	public void solve() throws IOException {
		String s = nextToken();
		int k = nextInt();
		int n = s.length();
		boolean[] g = new boolean[n];
		int lw = -1;
		for (int i = 0; i < n; i++) {
			if (isVowel(s.charAt(i)))
				lw = i;
			if (lw <= i - k)
				g[i] = true;
		}

		long ans = 0;
		int closest = n;
		for (int i = n - 1; i >= 0; i--) {
			if (i + k - 1 < n && g[i + k - 1])
				closest = i + k - 1;
			ans += n - closest;
		}
		out.println(ans);
	}

	private boolean isVowel(char c) {
		return c == 'a' || c == 'o' || c == 'e' || c == 'u' || c == 'i';
	}

	public void run() {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);

			br = new BufferedReader(new FileReader("taskA.in"));
			out = new PrintWriter("taskA.out");
			int n = nextInt();
			for (int i = 0; i < n; i++) {

				out.print("Case #" + (i + 1) + ": ");
				solve();
			}
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		new taskA().run();
	}
}
