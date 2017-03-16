import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class FairAndSquare {
	public static void main(String[] args) throws Exception {
		InputReader r = new InputReader(new FileReader("C.in"));
		PrintWriter out = new PrintWriter(new FileWriter("C.out"));
		int T = r.nextInt();
		int test = 1;
		TreeSet<Long> set = new TreeSet<Long>();
		long max = (long) 1e7 + 10;
		for (long x = 1; x < max; x++) {
			long square = x * x;
			if (isPalindrome("" + x) && isPalindrome("" + square))
				set.add(square);
		}
		while (T-- > 0) {
			long A = r.nextLong();
			long B = r.nextLong();
			int res = 0;
			for (long x : set)
				if (A <= x && x <= B)
					res++;
			out.printf("Case #%d: %d\n", test++, res);
		}
		out.close();
	}

	private static boolean isPalindrome(String str) {
		String rev = "";
		for (int i = str.length() - 1; i >= 0; i--)
			rev += str.charAt(i);
		return rev.equals(str);
	}

	static class InputReader {
		private BufferedReader reader;
		private StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream));
			tokenizer = null;
		}

		public InputReader(FileReader stream) {
			reader = new BufferedReader(stream);
			tokenizer = null;
		}

		public String nextLine() {
			try {
				return reader.readLine();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				return null;
			}
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}
	}
}
