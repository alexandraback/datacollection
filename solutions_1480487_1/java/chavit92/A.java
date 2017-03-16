import java.io.*;
import java.util.Locale;
import java.util.StringTokenizer;

public class A {
	BufferedReader in;
	StringTokenizer str;
	PrintWriter out;
	String SK;

	String next() throws IOException {
		while ((str == null) || (!str.hasMoreTokens())) {
			SK = in.readLine();
			if (SK == null)
				return null;
			str = new StringTokenizer(SK);
		}
		return str.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		int x = 0;
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
			x += a[i];
		}
		for (int i = 0; i < n; i++) {
			double l = 0;
			double r = 1;
			for (int tk = 0; tk < 200; tk++) {
				double mid = (l + r) / 2;
				// mid = 1.0/3.0;
				double has = (double) a[i] + x * mid;
				double left = 1 - mid;
				for (int j = 0; j < n; j++)
					if (i != j) {
						left -= Math.max((double) (has - (double) a[j]) / x,0);
					}
				if (left < -1e-10) {
					r = mid;
				} else {
					l = mid;
				}
			}
			out.printf(Locale.US," %.9f", r * 100);
		}
	}

	void run() throws IOException {
		in = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		int t = nextInt();
		for (int i = 0; i < t; i++) {
			out.print("Case #" + (i + 1) + ": ");
			solve();
			out.println();
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A().run();
	}

}