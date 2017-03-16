import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author wannabe
 */
public class Main {

	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("slides.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("slides.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Slides solver = new Slides();
		solver.solve(1, in, out);
		out.close();
	}

	static class Slides {

		public void solve(int testNumber, Scanner in, PrintWriter out) {
			int n = in.nextInt();
			for (int i = 1; i <= n; i++) {
				out.println("Case #" + i + ": " + solve(in.nextInt(), in.nextLong()));
			}
		}

		private String solve(int B, long M) {
			int[][] res = new int[B][B];
			res[0][B - 1] = 1;
			M--;
			if (M > 0) {
				for (int j = B - 2; j >= 0; j--) {
					if (M <= 0) {
						break;
					}
					res[0][j] = 1;
					res[j][B - 1] = 1;
					M--;
					if (M <= 0) {
						break;
					}
					int cnt = j;
					while (cnt < B - 2) {
						res[cnt][++cnt] = 1;
						M -= B - 1 - cnt;
						if (M <= 0) {
							break;
						}
					}
				}
			}

			if (M != 0) {
				return "IMPOSSIBLE";
			}
			StringBuilder sb = new StringBuilder();
			sb.append("POSSIBLE").append("\n");
			for (int i = 0; i < res.length; i++) {
				for (int j = 0; j < res.length; j++) {
					sb.append(res[i][j]);
				}
				sb.append("\n");
			}
			return sb.toString();
		}

	}
}

