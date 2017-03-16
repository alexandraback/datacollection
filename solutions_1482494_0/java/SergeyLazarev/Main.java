package round1A;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;

public class Main {
	private static final String TASKNAME = "input";

	private void solve() throws IOException {
		int tests = nextInt();
		for (int t = 1; t <= tests; t++) {
			int n = nextInt();
			int[] a = new int[n];
			int[] b = new int[n];
			
			for (int i = 0; i < n; i++) {
				a[i] = nextInt();
				b[i] = nextInt();
			}
			
			boolean[] doneA = new boolean[n];
			boolean[] doneB = new boolean[n];
			
			int res = 0;
			int s = 0;
			while (s != 2 * n) {
				boolean found = false;
				res++;
				
				for (int i = 0; i < n; i++) {
					if (!doneB[i] && b[i] <= s) {
						found = true;
						doneB[i] = true;
						if (doneA[i]) {
							s++;
						} else {
							s += 2;
							doneA[i] = true;
						}
						break;
					}
				}
				
				if (found) {
					continue;
				}
				
				int j = -1;
				for (int i = 0; i < n; i++) {
					if (!doneA[i] && a[i] <= s && (j == -1 || b[j] < b[i])) {
						j = i;
					}
				}
				
				if (j == -1) {
					break;
				}
				
				doneA[j] = true;
				s++;
			}
			
			if (s == n * 2) {
				println("Case #" + t + ": " + res);
			} else {
				println("Case #" + t + ": Too Bad");
			}
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
			reader = new BufferedReader(new InputStreamReader(System.in));
			writer = new PrintWriter(System.out);
			reader = new BufferedReader(new FileReader(TASKNAME + ".in"));
			writer = new PrintWriter(TASKNAME + ".out");
			solve();
			reader.close();
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(13);
		}
	}
}