package r0;

import java.util.Scanner;

public class Q4 {
	public static void main(String... args) {
		try (Scanner in = new Scanner(System.in)) {
			int T = Integer.parseInt(in.nextLine());
			for (int caseI = 0; caseI < T; caseI++) {
				int K = in.nextInt();
				int C = in.nextInt();
				int S = in.nextInt();
				System.out.print("Case #" + (caseI + 1) + ":");
				if (S < K) {
					System.out.println(" IMPOSSIBLE");
				} else {
					for (int testSrcAt = 0; testSrcAt < K; testSrcAt++) {
						long at = testSrcAt;
						for (int loopC = 1; loopC < C; loopC++) {
							long charsBeforeAt = at;
							at = charsBeforeAt * K + testSrcAt;
						}
						System.out.print(" " + (1 + at));
					}
					System.out.println();
				}
			}
		}
	}
}
