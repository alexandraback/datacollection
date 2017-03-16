package codejam16q;

import java.io.*;
import java.util.*;

public class RevengeOfThePancakes {

	public static void main(String[] args) throws IOException {
		String problem = "revenge-of-the-pancakes";
		String example = "B-large";//example";

		File inFile = new File("data/" + problem + "/" + example + ".in");
		File outFile = new File("data/" + problem + "/" + example + ".out");

		try (Scanner in = new Scanner(inFile); PrintStream out = new PrintStream(outFile)) {
			int T = Integer.parseInt(in.nextLine());

			for (int t = 0; t < T; ++t) {
				out.println("Case #" + (t + 1) + ": " + solve(in.nextLine()));
			}
		}
	}

	private static int solve(String line) {
		boolean t = line.charAt(0) == '+';
		int c = 0;

		for (int i = 1; i < line.length(); ++i)
			if (line.charAt(i) != line.charAt(i - 1)) {
				t = !t;
				c++;
			}

		if (!t) {
			t = !t;
			c++;
		}

		return c;
	}
}
