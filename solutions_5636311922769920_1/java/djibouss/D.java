package gcj;

import java.io.*;
import java.util.*;

public class D {
	public static void main(String[] args) throws FileNotFoundException {
		writer = new PrintWriter("output");
		solveAllTests();
		writer.close();
	}

	private static void solveAllTests() {
		MyScanner sc = new MyScanner();
		int nbTest = sc.nextInt();
		for (int i = 1; i <= nbTest; i++) {
			int k = sc.nextInt();
			int c = sc.nextInt();
			int s = sc.nextInt();
			if (k == 1) {
				writer.println("Case #" + i + ": " + 1);
				continue;
			}
			if (c == 1 && s < k) {
				writer.println("Case #" + i + ": " + "IMPOSSIBLE");
				continue;
			}
			if (s < k - 1) {
				writer.println("Case #" + i + ": " + "IMPOSSIBLE");
				continue;
			}

			int[] res = solveOneTest(k, c, s);
			String resAsString = "";
			for (int r : res) {
				resAsString += r + " ";
			}
			writer.println("Case #" + i + ": " + resAsString);
		}
	}

	private static int[] solveOneTest(int k, int c, int s) {
		int[] res = new int[s];
		int next = 2;
		for (int i = 0; i < s; i++) {
			res[i] = next;
			next++;
		}
		return res;

	}

	static PrintWriter writer;

	// -----------MyScanner class for faster input thx Flatfoot----------
	public static class MyScanner {
		BufferedReader br;
		StringTokenizer st;

		public MyScanner() {
			try {
				this.br = new BufferedReader(new FileReader(new File("input")));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String next() {
			while (this.st == null || !this.st.hasMoreElements()) {
				try {
					this.st = new StringTokenizer(this.br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return this.st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine() {
			String str = "";
			try {
				str = this.br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}

	}
	// --------------------------------------------------------
}