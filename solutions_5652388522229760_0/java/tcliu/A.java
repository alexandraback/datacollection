package codejam.quali_round_2016;

import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

import codejam.util.Helper;

/**
 * Counting Sheep
 */
public class A {
	
	private static String solve(int N) {
		if (N > 0) {
			Set<Character> chars = new HashSet<>(10);
			for (int j=1; ; j++) {
				String nStr = String.valueOf(N*j);
				char[] nChars = nStr.toCharArray();
				for (int k=0; k<nChars.length; k++) {
					chars.add(nChars[k]);
				}
				if (chars.size() == 10) {
					return nStr;
				}
			}
		}
		return "INSOMNIA";
	}
	
	public static void main(String[] args) {
		Helper helper = new Helper(A.class, args);
		try (Scanner sc = helper.getScanner(); PrintStream out = helper.getPrintStream()) {
			int T = sc.nextInt();
			for (int i=0; i<T; i++) {
				int N = sc.nextInt();
				String result = solve(N);
				out.printf("Case #%d: %s%n", i+1, result);
			}
		}
	}
}
