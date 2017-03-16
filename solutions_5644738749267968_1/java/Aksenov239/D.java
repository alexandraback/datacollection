import java.io.*;
import java.util.*;

public class D {
	public static void main(String[] args) {
		new D().run();
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

	public int play(double[] a, double[] b) {
		int l = a.length - 1;
		int ans = 0;
		int less = 0;
		for (int i = b.length - 1; i >= less; i--) {
			while (l >= 0 && a[l] > b[i]) {
				l--;
				less++;
			}
			if (l >= 0) {
				ans++;
				l--;
			}
		}
		return a.length - ans;
	}

	public int play2(double[] a, double[] b) {
		int l = 0;
		int ans = 0;
		for (int i = 0; i < a.length; i++)
			if (a[i] > b[l]) {
				ans++;
				l++;
			}
		return ans;
	}

	public void solve() throws IOException {
		int n = nextInt();
		double[] a = new double[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextDouble();
		}
		Arrays.sort(a);
		double[] b = new double[n];
		for (int i = 0; i < n; i++) {
			b[i] = nextDouble();
		}
		Arrays.sort(b);

		System.err.println(Arrays.toString(a));
		System.err.println(Arrays.toString(b));

		out.println(play2(a, b) + " " + play(a, b));
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
