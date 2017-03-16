package round1C_2014;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class PartElf {
	private static String OUTPUT_FILE = "PartElf.out";
	private static String INPUT_SMALL = "data/A-small-attempt0.in";
	private static String INPUT_TEST = "data/TEST";

	public static void main(String[] args) throws IOException {
		File output = new File(OUTPUT_FILE);
		try (FileOutputStream fos = new FileOutputStream(output);
				PrintWriter out = new PrintWriter(fos);) {
			Scanner in = new Scanner(new File(INPUT_SMALL));
			int tests = in.nextInt();
			for (int i = 0; i < tests; i++) {
				String ret = "Case #" + (i + 1) + ": " + solveTest(in);
				out.println(ret);
			}
		} catch (IOException e) {
			throw e;
		}
	}

	private static String solveTest(Scanner in) {
		String line = in.next();
		String[] tokens = line.split("/");
		int p = Integer.valueOf(tokens[0]);
		int q = Integer.valueOf(tokens[1]);
		int gcd = GCD(q, p);
		int nom = q / gcd;
		int nomPower = 0;
		for (int i = 0; i < 40; i++) {
			if (Math.pow(2, i) == nom) {
				nomPower = i;
				break;
			}
		}
		if (nomPower == 0) {
			return "impossible";
		}
		int res = 0;
		double f = ((double) p / (double) q);
		for (int j = 0; j < 40; j++) {
			if (Math.pow(0.5, j) <= f) {
				res = j;
				break;
			}
		}
		return String.valueOf(res);
	}

	// http://stackoverflow.com/questions/4009198/java-get-greatest-common-divisor
	public static int GCD(int a, int b) {
		if (b == 0)
			return a;
		return GCD(b, a % b);
	}
}