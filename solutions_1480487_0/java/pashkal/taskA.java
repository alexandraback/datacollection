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

	boolean check(int[] a, int k, double t, double x) {
		double g = a[k] + x * t;
		double o = 1;
		for (int i = 0; i < a.length; i++) {
			o -= Math.max(0, (g - a[i]) / x);
		}
		return (o < 0);
	}

	public void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		int sum = 0;
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
			sum += a[i];
		}
		for (int i = 0; i < n; i++) {
			double l = 0;
			double r = 1;
			while (l < r - 1e-8) {
				double c = (l + r) / 2;
				if (check(a, i, c, sum)) {
					r = c;
				} else {
					l = c;
				}
			}
			out.print(l * 100);
			if (i < n - 1) {
				out.print(" ");
			} else {
				out.println();
			}
		}
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
