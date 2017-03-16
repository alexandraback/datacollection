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

	public static void main(String[] args) throws IOException {
		reader = new BufferedReader(new InputStreamReader(new FileInputStream(
				"B-small-attempt0.in")));
		tokenizer = null;
		writer = new PrintWriter("B-small-attempt0.out");

		int t = nextInt();
		for (int i = 1; i <= t; i++) {
			writer.print("Case #" + i + ": ");
			banana();
		}

		reader.close();
		writer.close();
	}

	private static void banana() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int[][] mas = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				mas[i][j] = nextInt();
			}
		}

		int[] mxx = new int[n];
		int[] mxy = new int[m];
		for (int i = 0; i < n; i++) {
			mxx[i] = -1;
			for (int j = 0; j < m; j++) {
				mxx[i] = Math.max(mxx[i], mas[i][j]);
			}
		}
		for (int j = 0; j < m; j++) {
			mxy[j] = -1;
			for (int i = 0; i < n; i++) {
				mxy[j] = Math.max(mxy[j], mas[i][j]);
			}
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(mas[i][j] < mxx[i] && mas[i][j] < mxy[j])
				{
					writer.println("NO");
					return;
				}
			}
		}
		writer.println("YES");
	}
}