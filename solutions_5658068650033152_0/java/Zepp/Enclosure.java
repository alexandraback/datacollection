package round1C_2014;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Enclosure {
	private static String OUTPUT_FILE = "Enclosure.out";
	private static String INPUT_SMALL = "data/C-small-attempt0.in";
	private static String INPUT_TEST = "data/TEST";

	public static void main(String[] args) throws IOException {
		File output = new File(OUTPUT_FILE);
		try (FileOutputStream fos = new FileOutputStream(output);
				PrintWriter out = new PrintWriter(fos);) {
			Scanner in = new Scanner(new File(INPUT_SMALL));
			int tests = in.nextInt();
			in.nextLine();
			for (int i = 0; i < tests; i++) {
				String ret = "Case #" + (i + 1) + ": " + solveTest(in);
				out.println(ret);
			}
		} catch (IOException e) {
			throw e;
		}
	}

	private static String solveTest(Scanner in) {
		int n = in.nextInt();
		int m = in.nextInt();
		int k = in.nextInt();

		int smaller = Math.min(n, m);
		int larger = Math.max(n, m);
		int res = n * m;
		if (k >= smaller * larger - 4) {
			res = 2 * larger + 2 * (smaller - 2) - (smaller * larger - k);
		} else {
			int perfectSquare = smaller * smaller / 2 + 1;
			if (smaller % 2 == 1 && k <= perfectSquare) {
				res = Math.min(k, smaller + smaller - 2);
			} else {
				int s = (int) Math.sqrt(k);
				int i = 0;
				int j = 0;
				for (i = s, j = s; i < smaller;) {
					i = Math.min(i++, smaller);
					j = Math.min(i++, larger);
					if (i * j >= k) {
						res = Math.min(k, i * j);
						break;
					}
				}
				int remove = (i - 2) * (j - 2);
				res = k - remove;
			}
		}
		return String.valueOf(Math.min(k, res));
	}
}