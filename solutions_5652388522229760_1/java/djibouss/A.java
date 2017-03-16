package gcj;

import java.io.*;
import java.util.*;

public class A {
	public static void main(String[] args) throws FileNotFoundException {
		writer = new PrintWriter("output");
		solveAllTests();
		writer.close();
	}

	private static void solveAllTests() {
		MyScanner sc = new MyScanner();
		int nbTest = sc.nextInt();
		for (int i = 1; i <= nbTest; i++) {
			int N = sc.nextInt();
			if (N == 0) {
				writer.println("Case #" + i + ": " + "INSOMNIA");
			} else {
				int res = solveOneTest(N);
				writer.println("Case #" + i + ": " + res);
			}
		}
	}

	private static int solveOneTest(int n) {
		int cur = 0;
		boolean[] found = new boolean[10];
		while (atLeastOneNotFound(found)) {
			cur += n;
			boolean[] curFound = getCharIn(cur);
			found = merge(found, curFound);
		}
		return cur;
	}

	private static boolean[] merge(boolean[] found, boolean[] curFound) {
		boolean[] res = new boolean[10];
		for (int i = 0; i < 10; i++) {
			res[i] = found[i] || curFound[i];
		}
		return res;
	}

	private static boolean[] getCharIn(int n) {
		int cur = n;
		boolean[] res = new boolean[10];
		while (cur != 0) {
			res[cur % 10] = true;
			cur /= 10;
		}
		return res;
	}

	private static boolean atLeastOneNotFound(boolean[] found) {
		for (boolean b : found) {
			if (!b) {
				return true;
			}
		}
		return false;
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