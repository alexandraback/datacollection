import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Path implements Runnable {
	int[] a = new int[20];

	private void solve() throws IOException {
		int test = nextInt();
		for (int t = 1; t <= test; t++) {
			int n = nextInt();
			int[][] d = new int[n + 1][n + 1];
			for (int j = 1; j <= n; j++) {
				int num = nextInt();
				for (int k = 0; k < num; k++)
					d[j][nextInt()] = 1;
			}
			boolean ok = false;
			for (int k = 1; k <= n; k++) {
				if (ok)
					break;
				for (int i = 1; i <= n; i++) {
					if (ok)
						break;
					for (int j = 1; j <= n; j++) {
						if (ok)
							break;
						d[i][j] += d[i][k] * d[k][j];
						if (d[i][j] >= 2) {
							ok = true;
							break;
						}
					}
				}
			}
			if (ok)
				writer.write("Case #" + t + ": Yes\n");
			else
				writer.write("Case #" + t + ": No\n");
		}

	}

	public static void main(String[] args) {
		new Path().run();
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;
	String fileName = "Path";

	public void run() {
		try {
			reader = new BufferedReader(new FileReader(fileName + ".in"));
			tokenizer = null;
			writer = new PrintWriter(new FileWriter(fileName + ".out"));
			solve();
			reader.close();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}
}