import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;

public class A implements Runnable {

	private void solve() throws IOException {
		int t = nextInt();
		while (t-- > 0) {
			int A = nextInt();
			int B = nextInt();
			int K = nextInt();
			int ans = 0;
			for (int i = 0; i < A; i++) {
				for (int j = 0; j < B; j++) {
					if ((i & j) < K) {
						++ans;
					}
				}
			}
			pf();
			pl(ans);
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
//			reader = new BufferedReader(new BufferedReader(new InputStreamReader(System.in)));
//			writer = new PrintWriter(System.out);
			reader = new BufferedReader(new BufferedReader(new FileReader("B-small-attempt0.in")));
			writer = new PrintWriter("B.out");
			tokenizer = null;
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
			writer.print(objects[i]);
		}
	}

	void pl(Object... objects) {
		p(objects);
		writer.println();
	}

	int cc;

	void pf() {
		writer.printf("Case #%d: ", ++cc);
	}

}