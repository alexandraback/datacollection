package codejam16r1c;

import java.io.*;
import java.util.*;

public class Slides {

	public static void main(String[] args) throws IOException {
		String problem = "slides";
		String example = "B-small-attempt0";

		File inFile = new File("data/" + problem + "/" + example + ".in");
		File outFile = new File("data/" + problem + "/" + example + ".out");

		try (Scanner in = new Scanner(inFile); PrintStream out = new PrintStream(outFile)) {
			int T = in.nextInt();

			for (int t = 0; t < T; ++t) {
				int B = in.nextInt();
				long M = in.nextLong();

				boolean[][] solution = solve(B, M);

				if (solution == null) {
					out.println("Case #" + (t + 1) + ": IMPOSSIBLE");
				} else {
					out.println("Case #" + (t + 1) + ": POSSIBLE");
					for (boolean[] row : solution) {
						for (boolean b : row)
							out.print(b ? 1 : 0);
						out.println();
					}
				}
			}
		}
		
		System.out.println("OK");
	}

	private static boolean[][] solve(int b, long m) {
		boolean[][] matrix = new boolean[b][b];

		for (int i = 1; i < b - 1; ++i)
			for (int j = 0; j < i; ++j)
				matrix[j][i] = true;

		if (b <= 20 && m == (1L << (b-2))) {
			for (int j = 0; j < b - 1; ++j)
				matrix[j][b - 1] = true;
		} else {
			boolean[] powers = new boolean[b - 2];

			long c = m;
			for (int p = 0; p < powers.length && c > 0; ++p) {
				if (c % 2 == 1)
					powers[p] = true;
				c /= 2;
			}

			if (c > 0)
				return null;

			//System.out.println(m + " " + Arrays.toString(powers));

			for (int i = 0; i < powers.length; ++i)
				matrix[i + 1][b - 1] = powers[i];
		}

		return matrix;
	}

}
