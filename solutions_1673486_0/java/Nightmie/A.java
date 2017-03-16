import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.MathContext;
import java.util.StringTokenizer;

public class A implements Runnable {

	private void solve() throws IOException {
		int T = nextInt();
		for (int testCase = 1; testCase <= T; testCase++) {
			int A = nextInt();
			int B = nextInt();

			BigDecimal all = new BigDecimal(1);

			BigDecimal[] f = new BigDecimal[A + 1];

			f[A] = new BigDecimal(1);
			for (int i = 0; i < A; i++) {
				BigDecimal p = new BigDecimal(nextToken());
				f[i] = f[A].multiply(new BigDecimal(1).subtract(p));
				f[A] = f[A].multiply(p);
			}

			for (int i = 0; i < A; i++) {
				f[i + 1] = f[i + 1].add(f[i]);
			}
			
			BigDecimal MIN = new BigDecimal(B + 2);
			for (int i = 0; i < A; i++) {
				BigDecimal notPassed = new BigDecimal(2 * i + 2 * B - A + 2);
				BigDecimal passed = new BigDecimal(2 * i + B - A + 1);
				BigDecimal RET = f[A - i - 1].multiply(notPassed);
				RET = RET.add(new BigDecimal(1).subtract(f[A - i - 1]).multiply(passed));
				if (RET.compareTo(MIN) < 0) {
					MIN = RET;
				}
			}
			writer.println("Case #" + testCase + ": " + MIN.round(new MathContext(10)));
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
			reader = new BufferedReader(new InputStreamReader(System.in));
			tokenizer = null;
			writer = new PrintWriter(System.out);
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