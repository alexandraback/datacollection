package gcj;

import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class C {
	static int[] firstPrimes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 51 };
	static int N = 32;
	static int J = 500;
	static int found = 0;
	static long cur = 0L;

	public static void main(String[] args) throws FileNotFoundException {
		writer = new PrintWriter("output");
		writer.println("Case #" + 1 + ": ");

		while (found < J) {
			String tmp = Long.toBinaryString(cur);
			tmp = appendLeadingZeros(tmp);
			String curString = "1" + tmp + "1";
			int[] res = decomp(curString);
			if (res != null) {
				found++;
				for (int i : res) {
					curString += " " + i;
				}
				writer.println(curString);
			}
			cur++;
		}

		writer.close();
	}

	private static int[] decomp(String curString) {
		int[] res = new int[9];
		for (int b = 2; b <= 10; b++) {
			BigInteger attempt = new BigInteger(curString, b);
			Integer tmp = findTrivialDiv(attempt);
			if (tmp == null) {
				return null;
			}
			res[b - 2] = tmp;
		}
		return res;
	}

	private static Integer findTrivialDiv(BigInteger attempt) {
		for (int p : firstPrimes) {
			BigInteger div = new BigInteger(p + "");
			BigInteger mod = attempt.remainder(div);
			if (BigInteger.ZERO.equals(mod)) {
				return p;
			}
		}

		return null;
	}

	private static String appendLeadingZeros(String tmp) {
		int leadingStringLength = N - 2 - tmp.length();
		if (leadingStringLength < 0) {
			throw new IllegalArgumentException("already too long");
		}
		String toBeAppended = "";
		for (int i = 0; i < leadingStringLength; i++) {
			toBeAppended += "0";
		}
		return toBeAppended + tmp;
	}

	private static void solveAllTests() {
		MyScanner sc = new MyScanner();
		int nbTest = sc.nextInt();
		for (int i = 1; i <= nbTest; i++) {
			// int res = solveOneTest();
			// writer.println("Case #" + i + ": " + res);
		}
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