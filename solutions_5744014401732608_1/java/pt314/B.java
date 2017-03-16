import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;

public class B {

	public static void main(String[] args) throws Exception {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

		int T = Integer.parseInt(in.readLine());
		for (int t = 1; t <= T; t++) {
			String[] data = in.readLine().split(" ");
			int B = Integer.parseInt(data[0]);
			long M = Long.parseLong(data[1]);
			boolean[][] slides = slides(B, M);
			out.print("Case #" + t + ": ");
			if (slides == null)
				out.println("IMPOSSIBLE");
			else {
				out.println("POSSIBLE");
				for (int i = 0; i < B; i++) {
					String row = "";
					for (int j = 0; j < B; j++) {
						row += (slides[i][j] ? "1" : "0");
					}
					out.println(row);
				}
			}
		}
		out.close();
	}
	
	private static boolean[][] slides(int B, long M) throws Exception {
		if (M > (1 << (B - 2)))
			return null;
		boolean[][] slides = new boolean[B][B];
		for (int i = 1; i < B - 1; i++) {
			for (int j = i + 1; j < B; j++) {
				slides[i][j] = true;
			}
		}
		slides[0][B - 1] = true;
		long m = M - 1;
		int i = B - 2;
		while (m > 0) {
			if (m % 2 == 1) {
				slides[0][i] = true;
			}
			m /= 2;
			i--;
		}
		return slides;
	}
}
