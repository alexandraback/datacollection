import java.util.Scanner;

public class Q1 {
	public static void main(String... args) {
		try (Scanner in = new Scanner(System.in)) {
			int T = in.nextInt();
			for (int i = 0; i < T; i++) {
				String result; {
					int N = in.nextInt();
					if (N == 0) {
						result = "INSOMNIA";
					} else {
						result = getAnswerForValue(N);
					}
				}
				System.out.println("Case #" + (i + 1) + ": " + result);
			}
		}
	}
	private static String getAnswerForValue(int n) {
		assert(n > 0 && n <= 1e6);
		// n <= 1e6, so at the level of 1e8, each step increases no more than 1%, and 1-100 have all digits.
		// So all answers is not bigger than 1e8, not bigger than max-int.
		boolean[] used = new boolean[10];
		int usedCount = 0;
		int kN = n;
		for (;;) {
			for (int toTest = kN;;) {
				int divide = toTest / 10;
				int remainder = toTest - divide * 10;
				toTest = divide;
				int digit = remainder;
				if (!used[digit]) {
					used[digit] = true;
					if (++usedCount == 10) {
						return Integer.toString(kN);
					}
				}
				if (toTest == 0) {
					break;
				}
			}
			kN += n;
		}
	}
}
