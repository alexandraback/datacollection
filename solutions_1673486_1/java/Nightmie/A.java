import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A implements Runnable {

	private void solve() throws IOException {
		int T = nextInt();
		for (int testCase = 1; testCase <= T; testCase++) {
			int A = nextInt();
			int B = nextInt();

			double[] f = new double[A + 1];

			f[A] = 1;
			for (int i = 0; i < A; i++) {
				double p = nextDouble();
				f[i] = f[A] * (1 - p);
				f[A] = f[A] * p;
			}

			for (int i = 0; i < A; i++) {
				f[i + 1] = f[i + 1] + f[i];
			}

			double MIN = B + 2;
			for (int i = 0; i < A; i++) {
				int notPassed = 2 * i + 2 * B - A + 2;
				int passed = 2 * i + B - A + 1;
				double RET = f[A - i - 1] * notPassed + (1 - f[A - i - 1])
						* passed;
				if (RET < MIN) {
					MIN = RET;
				}
			}
			writer.println(String.format("Case #%d: %.10f", testCase, MIN));
		}
	}

	public static void main(String[] args) {
		new A().run();
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	public void run() {
		try {
			reader = new BufferedReader(new InputStreamReader(
					new FileInputStream("A-large.in")));
			tokenizer = null;
			writer = new PrintWriter(new FileOutputStream("A-large.out"));
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

	String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}
}