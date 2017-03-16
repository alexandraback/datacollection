package r1C;

import java.util.Scanner;

public class Q3 {
	public static void main(String... args) {
		@SuppressWarnings("resource")
		Scanner in = new Scanner(System.in);
		int caseCount = in.nextInt();
		long[] preexistings = new long[101];
		for (int caseValue = 1; caseValue <= caseCount; caseValue++) {
			int C = in.nextInt();
			int D = in.nextInt();
			long V = in.nextInt();
			for (int i = 0; i < D; i++) {
				preexistings[i] = in.nextLong();
			}
			int result = 0;
			int arrived = 0;
			int nextExistToUse = 0;
			for (;;) {
//				System.out.println("ARRIVED " + arrived);
				if (arrived >= V) {
					break;
				}
				int expectToCreate = arrived + 1;
				if (nextExistToUse >= D || preexistings[nextExistToUse] > expectToCreate) {
					result++;
//					System.out.println("CREATE " + expectToCreate);
					arrived += expectToCreate * C;
				} else {
					arrived += preexistings[nextExistToUse] * C;
//					System.out.println("USED " + preexistings[nextExistToUse]);
					nextExistToUse++;
				}
			}
			System.out.println("Case #" + caseValue + ": " + result);
		}
	}
}
