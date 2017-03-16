import java.io.*;
import java.util.*;

//small passed
public class D {
	// private static final String FIN = "D-small-attempt0.in";
	// private static final String FOUT = "D-small-attempt0.out";
	private static final String FIN = "D-large.in";
	private static final String FOUT = "D-large.out";

	public static void solution(BufferedReader reader, PrintWriter out)
			throws IOException {
		In in = new In(reader);
		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			int K = in.nextInt(), C = in.nextInt(), S = in.nextInt();
			out.print("Case #" + t + ":");
			int need = Math.max(1, K - C + 1);
			if (S < need)
				out.println(" IMPOSSIBLE");
			else {
				long first = 0;
				for (int i = 1; i < Math.min(K, C); i++)
					first = first * K + i;
				for (int i = 0; i < need; i++)
					out.print(" " + (first + i));
				out.println();
			}
		}
	}

	private static void bf() {
		for (int len = 1; len <= 8; len++)
			for (int C = 1; C <= 8; C++) {
				System.out.println("===== " + len + " " + C + " =====");
				int SIZE = (int) Math.pow(len, C);
				int[] cnt = new int[SIZE];
				for (int o = 0; o < (1 << len); o++) {
					String os = Integer.toBinaryString(o);
					char[] oc = new char[len];
					Arrays.fill(oc, '0');
					for (int i = 0; i < os.length(); i++)
						oc[len - os.length() + i] = os.charAt(i);
					// System.out.print(String.valueOf(oc) + " ");

					char[] p = new char[SIZE];
					for (int i = 0; i < len; i++)
						p[i] = oc[i];
					for (int c = 1; c < C; c++) {
						int max = (int) Math.pow(len, c);
						for (int i = max - 1; i >= 0; i--)
							if (p[i] == '1')
								for (int j = 0; j < len; j++)
									p[i * len + j] = oc[j];
							else
								for (int j = 0; j < len; j++)
									p[i * len + j] = '0';
					}
					for (int i = 0; i < SIZE; i++)
						if (p[i] == '1')
							cnt[i]++;
					// System.out
					// .println(String.valueOf(p, 0, Math.min(SIZE, 256)));
				}
				int min = Integer.MAX_VALUE;
				for (int i = 0; i < SIZE; i++)
					min = Math.min(min, cnt[i]);
				// char[] cc = new char[SIZE];
				// for (int i = 0; i < SIZE; i++)
				// if (cnt[i] == min)
				// cc[i] = (char) ('0' + min);
				// else
				// cc[i] = '+';
				// for (int i = 0; i <= len; i++)
				// System.out.print(' ');
				// System.out.println(String.valueOf(cc, 0, Math.min(SIZE,
				// 256)));
				int count = 0;
				for (int i = 0; i < SIZE; i++)
					if (cnt[i] == min) {
						System.out.print(i + " ");
						count++;
						if (count >= len)
							break;
					}
				System.out.println();
			}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new FileReader(FIN));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				FOUT)));
		solution(reader, out);
		out.close();
	}

	protected static class In {
		private BufferedReader reader;
		private StringTokenizer tokenizer = new StringTokenizer("");

		public In(BufferedReader reader) {
			this.reader = reader;
		}

		public String next() throws IOException {
			while (!tokenizer.hasMoreTokens())
				tokenizer = new StringTokenizer(reader.readLine());
			return tokenizer.nextToken();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}
	}
}
