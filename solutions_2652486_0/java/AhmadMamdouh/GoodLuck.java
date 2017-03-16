import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.StringTokenizer;

public class GoodLuck {
	public static void main(String[] args) throws Exception {
		InputReader r = new InputReader(new FileReader("C.txt"));
		PrintWriter out = new PrintWriter(new FileWriter("C.out"));
		int T = r.nextInt();
		int test = 1;
		int R = r.nextInt();
		int N = r.nextInt();
		int M = r.nextInt();
		int K = r.nextInt();
		out.println("Case #1:");
		while (R-- > 0) {
			int[] arr = new int[K];
			for (int i = 0; i < K; i++) {
				arr[i] = r.nextInt();
			}
			int[] sol = null;
			ML: for (int a = 2; a <= M; a++) {
				for (int b = 2; b <= M; b++) {
					for (int c = 2; c <= M; c++) {
						int[] numbers = { a, b, c };
						HashSet<Integer> subsets = new HashSet<Integer>();
						for (int k = 0; k < (1 << 3); k++) {
							int product = 1;
							for (int j = 0; j < 3; j++) {
								if ((k & (1 << j)) > 0)
									product *= numbers[j];
							}
							subsets.add(product);
						}
						boolean can = true;
						for (int x : arr)
							if (!subsets.contains(x))
								can = false;
						if (can) {
							sol = numbers;
							break ML;
						}
					}
				}
			}
			String s = "";
			for (int x : sol)
				s += x;
			out.printf("%s\n", s);
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
