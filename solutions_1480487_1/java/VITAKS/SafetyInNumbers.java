import java.io.*;
import java.util.*;

public class SafetyInNumbers implements Runnable {
	public static void main(String[] args) {
		new Thread(new SafetyInNumbers()).run();
	}

	BufferedReader br;
	StringTokenizer in;
	PrintWriter out;

	public String nextToken() throws IOException {
		while (in == null || !in.hasMoreTokens())
			in = new StringTokenizer(br.readLine());
		return in.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	public long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public void solve() throws IOException {
		int n = nextInt();

		double x = 0;
		double[] s = new double[n];

		for (int i = 0; i < n; i++) {
			s[i] = nextInt();
			x += s[i];
		}

		for (int i = 0; i < n; i++) {
			double l = 0;
			double r = 1;
			for (int t = 0; t < 100; t++) {
				double m = (l + r) / 2;
				double[] M = new double[n];
				double our = s[i] + x * m;
				for (int j = 0; j < n; j++) {
					M[j] = Math.max((our - s[j]) / x, 0);
				}
				double sum = 0;
				for (int j = 0; j < n; j++)
					sum += M[j];
				if (sum > 1)
					r = m;
				else
					l = m;
			}
			out.printf(Locale.US, "%.7f ", l * 100);
		}
		
		out.println();
	}

	public void run() {
		try {
			br = new BufferedReader(new FileReader("A.in"));
			out = new PrintWriter("A.out");

			int t = nextInt();
			for (int i = 0; i < t; i++) {
				out.print("Case #" + (i + 1) + ": ");
				solve();
				System.err.println(i);
			}

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
}
