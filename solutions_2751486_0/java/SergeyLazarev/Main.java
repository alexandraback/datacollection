package round1C2013;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;

public class Main {

	private void solve() throws IOException {
		int tests = nextInt();
		for (int t = 1; t <= tests; t++) {
			print("Case #" + t + ": ");

			char[] s = nextToken().toCharArray();
			int n = nextInt();
			
			int res = 0;
			for (int i = 0; i < s.length; i++) {
				for (int j = i; j < s.length; j++) {
					int k = 0;
					int max = 0;
					for (int p = i; p <= j; p++) {
						if (s[p] != 'a' && s[p] != 'o' && s[p] != 'i' &&
								s[p] != 'e' && s[p] != 'u') {
							k++;
							max = Math.max(max, k);
						} else {
							k = 0;
						}
					}
					if (max >= n) {
//						println(i + " " + j);
						res++;
					}
				}
			}
			
			println(res);
		}
	}

	private String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	private int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(nextToken());
	}

	private double nextDouble() throws NumberFormatException, IOException {
		return Double.parseDouble(nextToken());
	}

	private long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private void print(Object o) {
		writer.print(o);
	}

	private void println(Object o) {
		writer.println(o);
	}

	private void printf(String format, Object... o) {
		writer.printf(format, o);
	}

	public static void main(String[] args) {
		long time = System.currentTimeMillis();
		Locale.setDefault(Locale.US);
		new Main().run();
		System.err.printf("%.3f\n", 1e-3 * (System.currentTimeMillis() - time));
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	private void run() {
		try {
			reader = new BufferedReader(new FileReader(new File("input.in")));
			writer = new PrintWriter(new File("output.out"));
			solve();
			reader.close();
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(13);
		}
	}
}