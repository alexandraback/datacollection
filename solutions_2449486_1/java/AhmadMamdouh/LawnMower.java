import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class LawnMower {
	public static void main(String[] args) throws Exception {
		InputReader r = new InputReader(new FileReader("B.in"));
		PrintWriter out = new PrintWriter(new FileWriter("B.out"));
		int T = r.nextInt();
		int test = 1;
		while (T-- > 0) {
			int n = r.nextInt();
			int m = r.nextInt();
			int[][] arr = new int[n][m];
			for (int i = 0; i < arr.length; i++) {
				for (int j = 0; j < arr[i].length; j++) {
					arr[i][j] = r.nextInt();
				}
			}
			int[] row = new int[n];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					row[i] = Math.max(row[i], arr[i][j]);
				}
			}
			int[] col = new int[m];
			for (int j = 0; j < m; j++) {
				for (int i = 0; i < n; i++) {
					col[j] = Math.max(col[j], arr[i][j]);
				}
			}
			boolean sol = true;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if(arr[i][j]==row[i]||arr[i][j]==col[j])
						continue;
					sol = false;
				}
			}
			if (sol)
				out.printf("Case #%d: YES\n", test);
			else
				out.printf("Case #%d: NO\n", test);
			test++;
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
