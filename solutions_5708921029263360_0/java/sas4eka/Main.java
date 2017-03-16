import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader reader;
	static PrintWriter writer;
	static StringTokenizer tokenizer;

	static String task = "C-small";

	static String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	static int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws NumberFormatException, IOException {
		return Long.parseLong(nextToken());
	}

	public static void main(String[] args) throws IOException {
		reader = new BufferedReader(new InputStreamReader(new FileInputStream(task + ".in")));
		writer = new PrintWriter(task + ".out");
		solve();
		reader.close();
		writer.close();
	}

	static void solve() throws NumberFormatException, IOException {
		int t = nextInt();
		for (int i = 0; i < t; i++) {
			System.out.println("test " + i);
			writer.print("Case #" + (i + 1) + ": ");
			banana();
		}
	}

	static void banana() throws NumberFormatException, IOException {
		int j = nextInt();
		int p = nextInt();
		int s = nextInt();
		int k = nextInt();

		int jps = j * p * s;

		int[] A = new int[jps];
		int[] B = new int[jps];
		int[] C = new int[jps];
		int index = 0;
		for (int a = 0; a < j; a++) {
			for (int b = 0; b < p; b++) {
				for (int c = 0; c < s; c++) {
					A[index] = a;
					B[index] = b;
					C[index] = c;
					index++;
				}
			}
		}

		int vars = 1;
		for (int i = 0; i < jps; i++) {
			vars *= 2;
		}

		int ans = 0;
		int msq = 0;
		for (int msk = 0; msk < vars; msk++) {

			int cand = Integer.bitCount(msk);
			if (cand <= ans) {
				continue;
			}
			int temps[] = new int[512];
			boolean bFail = false;
			for (int i = 0; i < jps; i++) {
				if ((msk & (1 << i)) != 0) {
					int temp1 = 300 + B[i] * 10 + C[i];
					int temp2 = A[i] * 100 + 30 + C[i];
					int temp3 = A[i] * 100 + 10 * B[i] + 3;
					temps[temp1]++;
					temps[temp2]++;
					temps[temp3]++;
					if (temps[temp1] > k) {
						bFail = true;
						break;
					}
					if (temps[temp2] > k) {
						bFail = true;
						break;
					}
					if (temps[temp3] > k) {
						bFail = true;
						break;
					}
				}
			}

			if (!bFail) {
				ans = cand;
				msq = msk;
			}
		}

		writer.println(ans);
		for (int i = 0; i < jps; i++) {
			if ((msq & (1 << i)) != 0) {
				writer.println((A[i] + 1) + " " + (B[i] + 1) + " " + (C[i] + 1));
			}
		}
	}
}