package codejam.quali_round_2016;

import java.io.PrintStream;
import java.util.Scanner;

import codejam.util.Helper;

/**
 * Fractiles
 */
public class D {

	private static String solveSmall(int K, int C, int S) {
		if (S == 1 && S < K) {
			return "IMPOSSIBLE";
		} else {
			StringBuilder sb = new StringBuilder();
			for (int i=0; i<K; i++) {
				if (i > 0)
					sb.append(" ");
				sb.append(i+1);
			}
			return sb.toString();
		}
	}
	
	public static void main(String[] args) {
		Helper helper = new Helper(D.class, args);
		try (Scanner sc = helper.getScanner(); PrintStream out = helper.getPrintStream()) {
			int T = sc.nextInt();
			for (int i=0; i<T; i++) {
				int K = sc.nextInt(), C = sc.nextInt(), S = sc.nextInt();
				String result = solveSmall(K, C, S);
				out.printf("Case #%d: %s%n", i+1, result);
			}
		}
	}
}
