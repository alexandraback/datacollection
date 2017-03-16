package jam1a15;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class B {
//	private static final String FILE = "B-sample";
	private static final String FILE = "B-small-attempt2";

	public static void main(String[] args) throws IOException {
		new B().start();
	}

	private void start() throws IOException {
		Scanner scanner = new Scanner(new File(FILE + ".in"));
		BufferedWriter writer = new BufferedWriter(
				new FileWriter(FILE + ".out"));
		int tests = scanner.nextInt();

		for (int i = 0; i < tests; i++) {
			String result = "Case #" + (i + 1) + ": " + runTest(scanner);
			System.out.println(result);
			writer.write(result + "\n");
		}

		writer.close();
		scanner.close();
	}

	private String runTest(Scanner scanner) {
		int k = scanner.nextInt();
		int l = scanner.nextInt();
		int s = scanner.nextInt();

		List<Character> keys = new ArrayList<>();
		String keysString = scanner.next();
		double[] letters = new double[26];
		
		for (int i = 0; i < k; i++) {
			char charAt = keysString.charAt(i);
			letters[charAt-65]++;
			keys.add(charAt);
		}
		
		String target = scanner.next();
		for (int i =0; i < l; i++) {
			char c = target.charAt(i);
			if (!keys.contains(c)) {
				//target char not on keyboard
//							return new BigDecimal(0).setScale(6, RoundingMode.HALF_EVEN).toPlainString();
				return "0.0";
			}
		}
		
		int best = bestCase(target,s);
		
		
		Double p = 1.0d;
		for (int i = 0; i < l; i++) {
			//prob literei este
			char let = target.charAt(i);
			p*=letters[let-65] / Double.valueOf(k);
		}
		p*=best;
		double rest = Double.valueOf(best) - p;
//		return new BigDecimal(rest).setScale(7, RoundingMode.HALF_EVEN).toPlainString();
		return rest + "";
	}

	private int bestCase(String target, int s) {
		int common = 0;
		for (int i = 1; i < target.length(); i++) {
			String prefix = target.substring(0, i);
			String suffix = target.substring(target.length() - i);
			if (suffix.equals(prefix)) {
				common = i;
			}
		}
		int count = 1;
		int len = target.length(); // initial
		int perTurn = target.length() - common;
		while (len + perTurn <= s) {
			len += perTurn;
			count++;
		}
		return count;
	}
}
