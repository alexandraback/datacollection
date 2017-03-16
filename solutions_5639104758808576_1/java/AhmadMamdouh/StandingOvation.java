import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class StandingOvation {
	public static void main(String[] args) throws Exception {
		InputReader r = new InputReader(new FileReader("A-large.in"));
		PrintWriter out = new PrintWriter(new FileWriter("a.txt"));
		int T = r.nextInt();
		int test = 1;
		while (T-- > 0) {
			int n = r.nextInt();
			char[] arr = r.next().toCharArray();
			int currStanding = 0;
			int res = 0;
			for (int s = 0; s < arr.length; s++) {
				int numberShy = arr[s] - '0';
				if (s > currStanding) {
					int add = s - currStanding;
					res += add;
					currStanding += add;
				}
				currStanding += numberShy;
			}
			out.printf("Case #%d: %d\n", test++, res);
		}
		out.close();
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
