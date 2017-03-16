package codejam16q;

import java.io.*;
import java.util.*;

public class CountingSheep {

	public static void main(String[] args) throws IOException {
		String problem = "counting-sheep";
		String example = "A-large";

		File inFile = new File("data/" + problem + "/" + example + ".in");
		File outFile = new File("data/" + problem + "/" + example + ".out");

		try (Scanner in = new Scanner(inFile); PrintStream out = new PrintStream(outFile)) {
			int T = in.nextInt();

			for (int t = 0; t < T; ++t) {
				out.println("Case #" + (t + 1) + ": " + solve(in.nextInt()));
			}
		}
	}

	private static String solve(int N) {
		BitSet seen = new BitSet(10);

		if (N == 0)
			return "INSOMNIA";

		long n = N;
		see(n, seen);
		while (seen.cardinality() < 10) {
			n += N;
			see(n, seen);
		}

		return String.valueOf(n);
	}

	private static void see(long n, BitSet seen) {
		for (char c : String.valueOf(n).toCharArray())
			seen.set(c - '0');
	}
}
