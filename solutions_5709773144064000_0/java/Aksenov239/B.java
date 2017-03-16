import java.io.*;
import java.util.*;

public class B {
	public static void main(String[] args) {
		new B().run();
	}

	BufferedReader br;
	StringTokenizer in;
	PrintWriter out;

	public String nextToken() throws IOException {
		while (in == null || !in.hasMoreTokens()) {
			in = new StringTokenizer(br.readLine());
		}
		return in.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	public void solve() throws IOException {
		double C = nextDouble();
		double F = nextDouble();
		double X = nextDouble();

		int k = (int) Math.ceil((X * F - C * F - 2 * C) / (C * F));
		if (k < 0)
			k = 0;

		double ans = 0;
		for (int i = 0; i < k; i++) {
			ans += C / (2 + i * F);
		}

		ans += X / (2 + k * F);
		
		out.println(ans);
	}

	public void run() {
		try {
			br = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");

			int t = nextInt();
			for (int i = 0; i < t; i++) {
				out.print(String.format("Case #%d: ", i + 1));
				solve();
			}

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
