package r0;

import java.util.Scanner;

public class Q1 {
	public static void main(String... args) {
		Scanner in = new Scanner(System.in);
		int caseCount = in.nextInt();
		for (int caseValue = 1; caseValue <= caseCount; caseValue++) {
			int shyValueMax = in.nextInt();
			char[] peopleCountOfShyValues = in.next().toCharArray();
			int neededTotal = 0;
			int peopleActivated = 0;
			for (int shyValue = 0; shyValue <= shyValueMax; shyValue++) {
				int peopleCountOfShyValue = peopleCountOfShyValues[shyValue] - '0';
				int neededThisTime = shyValue - peopleActivated;
				if (neededThisTime > 0) {
					neededTotal += neededThisTime;
					peopleActivated += neededThisTime;
				}
				peopleActivated += peopleCountOfShyValue;
			}
			System.out.println("Case #" + caseValue + ": " + neededTotal);
		}
	}
}
