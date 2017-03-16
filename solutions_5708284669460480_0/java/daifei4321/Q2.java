package r1C;

import java.util.Scanner;

public class Q2 {
	public static void main(String... args) {
		@SuppressWarnings("resource")
		Scanner in = new Scanner(System.in);
		int caseCount = in.nextInt();
		for (int caseValue = 1; caseValue <= caseCount; caseValue++) {
			int K = in.nextInt();
			int L = in.nextInt();
			int S = in.nextInt();
			String textK = in.next();
			char[] charK = textK.toCharArray();
			String textL = in.next();
			char[] charL = textL.toCharArray();
			assert(L == charL.length && K == charK.length);
			int[] appearCh = new int['Z' + 1];
			for (int i = 0; i < K; i++) {
				appearCh[charK[i]]++;
			}
			boolean hasMissing = false;
			for (int i = 0; i < L; i++) {
				if (appearCh[charL[i]] == 0) {
					hasMissing = true;
					break;
				}
			}
			double result;
			if (hasMissing) {
				result = 0;
			} else {
				int maxAppear; {
					int effectiveL = 1;
					for (;;) {
						int cmpLength = L - effectiveL;
						if (cmpLength == 0) {
							break;
						}
						if (textL.substring(0, cmpLength).equals(textL.substring(effectiveL))) {
							break;
						}
						effectiveL++;
					}
					// S >= L
					maxAppear = (S - L) / effectiveL + 1;
				}
				int[] map = new int['Z' + 1];
				int mapCount = 0; {
					for (int i = 0; i < appearCh.length; i++) {
						if (appearCh[i] > 0) {
							map[i] = mapCount++;
						}
					}
				}
				int[] appear = new int[mapCount]; {
					for (int i = 0; i < appearCh.length; i++) {
						if (appearCh[i] > 0) {
							appear[map[i]] = appearCh[i];
						}
					}
				}
				double[] appearChance = new double[appear.length]; {
					double kDouble = K;
					for (int i = 0, iMax = appearChance.length; i < iMax; i++) {
						appearChance[i] = appear[i] / kDouble;
					}
				}
				int[] Ls = new int[L];
				for (int i = 0; i < L; i++) {
					Ls[i] = map[charL[i]];
				}
				// Ls is the target string, with each character as 0 to K-1
				// appearChance[K] is the chance of every character is Ls.
				double chanceEachL = 1.0; {
					for (int i = 0; i < L; i++) {
						chanceEachL *= appearChance[Ls[i]];
					}
				}
				result = maxAppear - chanceEachL * (S - L + 1);
			}
			System.out.println("Case #" + caseValue + ": " + result);
		}
	}
}
