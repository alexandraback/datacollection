/* Filename: GCJ2016QB.java
 * Author: Mushiyo
 */

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class GCJ2016QB {

	public static void main(String[] args) throws FileNotFoundException {
		// Scanner input = new Scanner(System.in);
		// PrintWriter out = new PrintWriter(System.out);
		Scanner input = new Scanner(new File("B-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new File("pB.out"));

		while (input.hasNext()) {
			int T = input.nextInt();

			for (int t = 1; t <= T; ++t) {
				String S = input.next();

				out.printf("Case #%d: %d\n", t, countFlip(S));
			}
		}

		out.close();
		input.close();
	}

	static int countFlip(String S) {
		int count = S.endsWith("-") ? 1 : 0;

		for (int i = 1; i < S.length(); ++i) {
			if (S.charAt(i) != S.charAt(i - 1)) {
				++count;
			}
		}

		return count;
	}

}
