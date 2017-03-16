package codejam.quali_round_2016;

import java.io.PrintStream;
import java.util.Scanner;

import codejam.util.Helper;

/**
 * Revenge of the Pancakes
 */
public class B {

	private static long solve(String S) {
		int count = 0;
		for (int i=S.length()-1; i>=0; i--) {
			if (!ok(S.charAt(i), count)) {
				count++;
			}
		}
		return count;
	}

	private static boolean ok(char c, int flipCount) {
		return (c == '+' && flipCount % 2 == 0) || (c == '-' && flipCount % 2 == 1);
	}
	
	public static void main(String[] args) {
		Helper helper = new Helper(B.class, args);
		try (Scanner sc = helper.getScanner(); PrintStream out = helper.getPrintStream()) {
			int T = sc.nextInt();
			for (int i=0; i<T; i++) {
				String S = sc.next();
				long result = solve(S);
				out.printf("Case #%d: %s%n", i+1, result);
			}
		}
	}
	
}
