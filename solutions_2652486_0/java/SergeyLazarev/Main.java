package round1A2013;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Locale;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
	
	private boolean isValid(int n) {
		while (n != 0) {
			int m = n % 10;
			if (m < 2 || m > 5) {
				return false;
			}
			n /= 10;
		}
		
		return true;
	}
	
	private int getProduct(int n, int mask) {
		int res = 1;
		while (n != 0) {
			int m = n % 10;
			if (mask % 2 == 1) {
				res *= m;
			}
			
			n /= 10;
			mask /= 2;
		}
		
		return res;
	}

	private void solve() throws IOException {
		
		Set<Integer>[] a = new Set[600];
		for (int i = 222; i <= 555; i++) {
			a[i] = new HashSet<>();
			
			if (isValid(i)) {
				for (int mask = 0; mask < 8; mask++) {
					a[i].add(getProduct(i, mask));
				}
			}
		}
		
		int tests = nextInt();
		for (int t = 1; t <= tests; t++) {
			println("Case #" + t + ":");

			int r = nextInt();
			int n = nextInt();
			int m = nextInt();
			int k = nextInt();
			
			for (int i = 0; i < r; i++) {
				int[] b = new int[k];
				for (int j = 0; j < k; j++) {
					b[j] = nextInt();
				}
				
				ArrayList<Integer> res = new ArrayList<>();
				for (int p = 222; p <= 555; p++) {
					boolean f = true;
					for (int j = 0; j < k; j++) {
						if (!a[p].contains(b[j])) {
							f = false;
							break;
						}
					}
					
					if (f) {
						res.add(p);
					}
				}
				
				Collections.shuffle(res);
				println(res.get(0));
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