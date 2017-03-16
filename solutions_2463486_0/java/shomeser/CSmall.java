public class CSmall {
	public static final java.util.Scanner in = new java.util.Scanner(System.in);
	public static final java.io.PrintStream out = System.out;
	private static int[] squares = new int[32 * 32 + 1];

	public static void main(String[] args) {
		preCalc();

		final int n = in.nextInt();

		for (int i = 0; i < n; ++i) {
			int a = in.nextInt();
			int b = in.nextInt();

			int count = 0;

			for (int j = a; j <= b; ++j) {
				if (isSquare(j)) {
					if (isPalindrom(j) && isPalindrom(getRoot(j))) {
						count += 1;
					}
				}
			}

			out.print("Case #");
			out.print(i + 1);
			out.print(": ");
			out.println(count);
		}
	}

	private static void preCalc() {
		for (int i = 0; i < 33; ++i) {
			squares[i * i] = i;
		}
	}

	private static boolean isPalindrom(int j) {
		return isPalindrom(String.valueOf(j));
	}

	private static boolean isPalindrom(String s) {
		int length = s.length();
		int count = length / 2;
		for (int i = 0; i < count; ++i) {
			if (s.charAt(i) != s.charAt(length - i - 1)) {
				return false;
			}
		}

		return true;
	}

	private static int getRoot(int j) {
		return squares[j];
	}

	private static boolean isSquare(int j) {
		return squares[j] != 0;
	}
}
