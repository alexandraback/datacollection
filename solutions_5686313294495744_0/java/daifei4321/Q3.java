package r1B;

import java.util.Scanner;

public class Q3 {
	public static void main(String... args) {
		try (Scanner in = new Scanner(System.in)) {
			int T = in.nextInt();
			for (int caseI = 0; caseI < T; caseI++) {
				int N = in.nextInt();
				String[] word1 = new String[N];
				String[] word2 = new String[N];
				for (int n = 0; n < N; n++) {
					word1[n] = in.next();
					word2[n] = in.next();
				}
				int maxFalse = 0;
				loopOverStatus:
				for (int status = 0, statusMax = (1 << N) - 1; status <= statusMax; status++) {
					boolean[] isTrue = new boolean[N];
					for (int n = 0; n < N; n++) {
						isTrue[n] = 0 != (status & (1 << n));
					}
					for (int n = 0; n < N; n++) {
						if (!isTrue[n]) {
							boolean found1 = false;
							boolean found2 = false;
							for (int nx = 0; nx < N; nx++) {
								if (nx == n || !isTrue[nx]) {
									continue;
								}
								if (word1[nx].equals(word1[n])) {
									found1 = true;
								}
								if (word2[nx].equals(word2[n])) {
									found2 = true;
								}
							}
							if (!(found1 && found2)) {
								continue loopOverStatus;
							}
						}
					}
					int countFalse = 0;
					for (int n = 0; n < N; n++) {
						if (!isTrue[n]) {
							countFalse++;
						}
					}
					if (maxFalse < countFalse) {
						maxFalse = countFalse;
					}
				}
				System.out.println("Case #" + (caseI + 1) + ": " + maxFalse);
			}
		}
	}
}
