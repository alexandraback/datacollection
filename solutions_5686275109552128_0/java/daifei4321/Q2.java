package r0;

import java.util.Scanner;

public class Q2 {
	public static void main(String... args) {
		@SuppressWarnings("resource")
		Scanner in = new Scanner(System.in);
		int caseCount = in.nextInt();
		int[] data = new int[7];
		int[] countsOfValue = new int[10];
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
			result = getMinStepsRec(countsOfValue, valueMax);
			System.out.println("Case #" + caseValue + ": " + result);
		}
	}
	private static final int[][][][][][][] mems = new int[6+1][7+1][7+1][9+1][10+1][13+1][18+1];
	private static int getMinStepsRec(int[] countsOfValue, int valueMax) {
		if (valueMax <= 3) {
			return valueMax;
		}
		int mem = mems[countsOfValue[9]][countsOfValue[8]][countsOfValue[7]][countsOfValue[6]]
				[countsOfValue[5]][countsOfValue[4]][countsOfValue[3]];
		if (0 != mem) {
			return mem;
		}
		int stepMin = valueMax;
		for (int valueToMove = 1, valueToMoveMax = (valueMax + 1) / 2; valueToMove <= valueToMoveMax; valueToMove++) {
			int valueToRemain = valueMax - valueToMove;
			assert(valueToRemain >= valueToMove);
			countsOfValue[valueToMove]++;
			countsOfValue[valueToRemain]++;
			int valueMaxSub;
			if (0 != --countsOfValue[valueMax]) {
				valueMaxSub = valueMax;
			} else {
				valueMaxSub = valueMax - 1;
				while (countsOfValue[valueMaxSub] == 0) {
					valueMaxSub--;
				}
			}
			int stepMove = 1 + getMinStepsRec(countsOfValue, valueMaxSub);
			countsOfValue[valueMax]++;
			countsOfValue[valueToMove]--;
			countsOfValue[valueToRemain]--;
			if (stepMin > stepMove) {
				stepMin = stepMove;
			}
		}
		mems[countsOfValue[9]][countsOfValue[8]][countsOfValue[7]][countsOfValue[6]]
				[countsOfValue[5]][countsOfValue[4]][countsOfValue[3]] = stepMin;
		return stepMin;
	}
}
