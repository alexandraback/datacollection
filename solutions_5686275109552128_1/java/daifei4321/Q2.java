package r0;

import java.util.Scanner;

public class Q2 {
	public static void main(String... args) {
		@SuppressWarnings("resource")
		Scanner in = new Scanner(System.in);
		int caseCount = in.nextInt();
		int[] data = new int[1001];
		int[] countsOfValue = new int[1001];
		for (int caseValue = 1; caseValue <= caseCount; caseValue++) {
			int dataCount = in.nextInt();
			for (int i = 0; i < dataCount; i++) {
				data[i] = in.nextInt();
			}
			int result;
			for (int i = 0, iMax = countsOfValue.length; i < iMax; i++) {
				countsOfValue[i] = 0;
			}
			int valueMax = 0;
			for (int i = 0; i < dataCount; i++) {
				int value = data[i];
				countsOfValue[value]++;
				if (valueMax < value) {
					valueMax = value;
				}
			}
			result = getMinStepsByEatValue(countsOfValue, valueMax);
			System.out.println("Case #" + caseValue + ": " + result);
		}
	}
	private static int getMinStepsByEatValue(int[] countsOfValue, int valueMax) {
		if (valueMax <= 3) {
			return valueMax;
		}
		int stepMinTotal = valueMax;
		for (int eatValue = 2; eatValue <= valueMax; eatValue++) {
			int stepMin = 0;
			for (int value = 1; value <= valueMax; value++) {
				stepMin += (value - 1) / eatValue * countsOfValue[value];
			}
			stepMin += eatValue;
			if (stepMinTotal > stepMin) {
				stepMinTotal = stepMin;
			}
		}
		return stepMinTotal;
	}
}
