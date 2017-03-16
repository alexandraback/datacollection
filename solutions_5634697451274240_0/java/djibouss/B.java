package gcj;

import java.io.*;
import java.util.*;

public class B {
	public static void main(String[] args) throws FileNotFoundException {
		writer = new PrintWriter("output");
		solveAllTests();
		writer.close();
	}

	private static void solveAllTests() {
		MyScanner sc = new MyScanner();
		int nbTest = sc.nextInt();
		for (int i = 1; i <= nbTest; i++) {
			String pancakes = sc.next();
			int res = solveOneTest(pancakes, 0);
			writer.println("Case #" + i + ": " + res);
		}
	}

	private static int solveOneTest(String pancakes, int time) {
		if (pancakes.length() == 0) {
			return time;
		}
		String remaining = pancakes.substring(0, pancakes.length() - 1);
		if (pancakes.charAt(pancakes.length() - 1) == '+') {
			return solveOneTest(remaining, time);
		}
		String revertRemaining = revert(remaining);
		return solveOneTest(revertRemaining, time + 1);
	}

	private static String revert(String remaining) {
		StringBuilder res = new StringBuilder();
		for (char c : remaining.toCharArray()) {
			if (c == '+') {
				res.append('-');
			} else {
				res.append('+');
			}
		}
		return res.toString();
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