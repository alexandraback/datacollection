import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class RevengeOfThePancakes {
	static class P {
		String s;
		int cost;

		public P(String ss, int c) {
			s = ss;
			cost = c;
		}
	}

	public static void main(String[] args) {
		InputReader r = new InputReader(System.in);
		int T = r.nextInt();
		int test = 1;
		while (test <= T) {
			char[] s = r.next().toCharArray();
			int res = s[0] == '+' ? 0 : -1;
			for (int i = 0; i < s.length; i++) {
				if (s[i] == '+')
					continue;
				res += 2;
				while (i < s.length && s[i] == '-')
					i++;
				i--;
			}
			System.out.printf("Case #%d: %s\n", test, res);
			test++;
		}
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

		public double nextDouble() {
			return Double.parseDouble(next());
		}
	}
}
