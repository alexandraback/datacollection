import java.io.*;
import java.util.*;

public class taskA {

	PrintWriter out;
	BufferedReader br;
	StringTokenizer st;

	String nextToken() throws IOException {
		while ((st == null) || (!st.hasMoreTokens()))
			st = new StringTokenizer(br.readLine(), " \n\t\\/");
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
		long p = nextLong();
		long q = nextLong();
		long g = gcd(p, q);
		p /= g;
		q /= g;
		if ((q & (q - 1)) != 0) {
			out.println("impossible");
			return;
		}
		int ans = 1;
		while (p < q / 2) {
			q /= 2;
			ans++;
		}
		out.println(ans);
	}

	private long gcd(long p, long q) {
		while (p * q != 0) {
			if (p > q)
				p %= q;
			else
				q %= p;
		}
		return p + q;
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
