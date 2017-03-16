package codejam16q;

import java.io.*;
import java.util.*;

public class Fractiles {

	public static void main(String[] args) throws IOException {
		String problem = "fractiles";
		String example = "D-large";//example";

		File inFile = new File("data/" + problem + "/" + example + ".in");
		File outFile = new File("data/" + problem + "/" + example + ".out");

		try (Scanner in = new Scanner(inFile); PrintStream out = new PrintStream(outFile)) {
			int T = Integer.parseInt(in.nextLine());

			for (int t = 0; t < T; ++t) {
				int k = in.nextInt();
				int c = in.nextInt();
				int s = in.nextInt();

				long[] res = solve(k, c, s);

				String resStr;
				if (res == null) {
					resStr = "IMPOSSIBLE";
				} else {
					StringBuilder b = new StringBuilder();
					for (int i = 0; i < res.length; ++i) {
						if (i > 0)
							b.append(" ");
						b.append(Long.toString(res[i]));
					}
					resStr = b.toString();
				}

				out.println("Case #" + (t + 1) + ": " + resStr);

			}
		}
	}

	private static long[] solve(int k, int c, int s) {
		int n = (k + c - 1) / c;

		if (n > s)
			return null;

		int l = 0;
		long[] res = new long[n];

		for (int i = 0; i < n; ++i) {
			long p = 0;

			for (int j = 0; j < c && l < k; ++j) {
				p = p * k + l;
				l++;
			}

			res[i] = p + 1;
		}

		return res;
	}
}
