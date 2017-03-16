import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;

public class C {

	private void solve() throws IOException {
		int T = nextInt();
		while (T-- > 0) {
			int n = nextInt();
			int[] a = new int[n];
			int sum = 0;
			for (int i = 0; i < n; i++) {
				a[i] = nextInt();
				sum += a[i];
			}

			double low = 0;
			double high = 1000;
			int iter = 100;

			while (iter-- > 0) {
				double mid = low + (high - low) / 2;
				double yi = 0;
				for (int i = 0; i < a.length; i++) {
					yi += (mid - a[i]) / sum;
				}
				if (yi > 1) {
					high = mid;
				} else {
					low = mid;
				}
			}
			pf();
			for (int i = 0; i < a.length; i++) {
				double res = ((low - a[i]) / sum * 100);
				if (res + 1e-9 < 0) {
					res = 0;
					System.out.printf("%.6f", res);
				} else {
					System.out.printf("%.6f", res + 1e-9);
				}
				if (i < a.length - 1)
					System.out.print(" ");
			}
			System.out.println();
		}
	}

	public static void main(String[] args) {
		new C().run();
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	public void run() {
		try {
			reader = new BufferedReader(new FileReader("C.in"));
			// reader = new BufferedReader(new InputStreamReader(System.in));
			tokenizer = null;
			writer = new PrintWriter(System.out);
			// writer = new PrintWriter("C.out");
			solve();
			reader.close();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	BigInteger nextBigInteger() throws IOException {
		return new BigInteger(nextToken());
	}

	String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	void p(Object... objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.flush();
			writer.print(objects[i]);
			writer.flush();
		}
	}

	void pl(Object... objects) {
		p(objects);
		writer.flush();
		writer.println();
		writer.flush();
	}

	int cc;

	void pf() {
		writer.printf("Case #%d: ", ++cc);
		writer.flush();
	}

}
