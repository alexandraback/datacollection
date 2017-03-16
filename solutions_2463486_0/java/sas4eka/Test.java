import java.io.*;
import java.util.*;

public class Test {
	static BufferedReader reader;
	static StringTokenizer tokenizer;
	static PrintWriter writer;

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	static Set<Long> st;

	public static void main(String[] args) throws IOException {
		reader = new BufferedReader(new InputStreamReader(new FileInputStream(
				"C-small-attempt0.in")));
		tokenizer = null;
		writer = new PrintWriter("C-small-attempt0.out");

		st = new TreeSet<Long>();
		for (long i = 1; i < 10000000; i++) {
			if (isPalindrom(i + "")) {
				long sq = i * i;
				if (isPalindrom(sq + "")) {
					st.add(sq);
				}
			}
		}

		int t = nextInt();
		for (int i = 1; i <= t; i++) {
			writer.print("Case #" + i + ": ");
			banana();
		}

		reader.close();
		writer.close();
	}

	static boolean isPalindrom(String s) {
		for (int i = 0; i < s.length() / 2 + 1; i++) {
			if (s.charAt(i) != s.charAt(s.length() - i - 1))
				return false;
		}
		return true;
	}

	private static void banana() throws IOException {
		long a = nextInt();
		long b = nextInt();
		long res = 0;
		for (Long l : st) {
			if (l >= a && l <= b)
				res++;
		}
		writer.println(res);
	}
}