package r0;

import java.util.Arrays;
import java.util.Scanner;

public class Q4B {
	/**
	 * This helper helped visualize the result:
	 * 3 columns(K=3), expand 1(C=1), got 3 Xs, each is: 0 1 2
	 * 3 columns, expand 2, got 9 Xs, each is: 00 01 02 10 11 12 20 21 22
	 * In example, 2 and 6 works, because X2 is 01 and X6 is 12, and they carry all 012.
	 * Solution: find S Xs, with their values to cover all. If cannot, then impossible; otherwise, output their loc.
	 */
	public static void mainHelper(String... args) {
		int K = Integer.parseInt(args[0]), C = Integer.parseInt(args[1]);
		int[] masks = new int[K];
		for (int i = 0; i < K; i++) {
			masks[i] = 1 << (K - 1 - i);
		}
		for (int v = (1 << K) - 1; v >= 0; v--) {
			boolean[] bits = new boolean[K];
			for (int i = 0; i < K; i++) {
				bits[i] = 0 != (v & masks[i]);
			}
			for (int i = 0; i < K; i++) {
				System.out.print(bits[i] ? '1' : '0');
			}
			System.out.print(' ');
			boolean[] result = bits;
			for (int exp = 1; exp < C; exp++) {
				boolean[] expanded = new boolean[result.length * K];
				for (int at = 0; at < result.length; at++) {
					if (result[at]) {
						Arrays.fill(expanded, at * K, at * K + K, true);
					} else {
						System.arraycopy(bits, 0, expanded, at * K, K);
					}
				}
				result = expanded;
			}
			for (int i = 0; i < result.length; i++) {
				System.out.print(result[i] ? '1' : '0');
			}
			System.out.println();
		}
	}
	public static void main(String... args) {
		try (Scanner in = new Scanner(System.in)) {
			int T = Integer.parseInt(in.nextLine());
			for (int caseI = 0; caseI < T; caseI++) {
				int K = in.nextInt();
				int C = in.nextInt();
				int S = in.nextInt();
				System.out.print("Case #" + (caseI + 1) + ":");
				// Each X covers at most C columns.
				if (C * S < K) {
					System.out.println(" IMPOSSIBLE");
				} else {
					int coverFrom = 0;
					for (;;) {
						int[] coverValues = new int[C];
						for (int at = 0; at < C; at++) {
							coverValues[at] = Math.min(coverFrom + at, K - 1);
						}
						// Convert from coverValues to xIndex:
						long xIndex = 0;
						for (int at = 0; at < C; at++) {
							xIndex *= K;
							xIndex += coverValues[at];
						}
						System.out.print(" " + (1 + xIndex));
						coverFrom += C;
						if (coverFrom >= K) {
							// Enough already.
							break;
						}
					}
					System.out.println();
				}
			}
		}
	}
}
