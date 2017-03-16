package Round1C;

import java.util.*;
import java.io.*;

public class Problem1 {

	public static void main(String... orange) throws Exception {
//		 String filename = "practice";
		String filename = "A-large";
		Scanner input = new Scanner(new File(filename + ".in"));
		PrintWriter writer = new PrintWriter(filename + ".out", "UTF-8");
		int T = input.nextInt();
		int N, R, C;
		for (int n = 0; n < T; n++) {
			R = input.nextInt();
			C = input.nextInt();
			N = input.nextInt();

			String out = "Case #" + (n + 1) + ": " + solve(R, C, N);
			System.out.println(out);
			writer.println(out);
		}
		writer.close();
	}

	private static int solve(int R, int C, int W) {

		if (R > 1) {
			return C / W * (R - 1) + solve(1, C, W);
		}

		if (C == W) {
			return W;
		}
		if (2 * W > C) {
			return W + 1;
		}
		int result = C / W - 1;
		int left = C - W * result;
		return result + solve(R, left, W);
	}

}
