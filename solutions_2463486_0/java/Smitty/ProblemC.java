import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class ProblemC {

	public static void main(String[] args) {

		try {

			final String fileIn = ProblemC.class.getSimpleName().toLowerCase() + ".in";
			final String fileOut = ProblemC.class.getSimpleName().toLowerCase() + ".out";

			final Scanner in = new Scanner(new File(fileIn));
			final PrintWriter out = new PrintWriter(new File(fileOut));

			new ProblemC().solve(in, out);

			out.flush();
			out.close();

		} catch (Exception ex) {

			ex.printStackTrace();
		}
	}

	private final void solve(final Scanner in, final PrintWriter out) throws Exception {

		final int testCount = in.nextInt();

		for (int testCase = 1; testCase <= testCount; ++testCase) {

			int result = 0;

			final int l = in.nextInt();
			final int r = in.nextInt();

			for (int i = 1; i <= 1000; ++i) {

				if (i * i < l) {

					continue;
				}

				if (i * i > r) {

					break;
				}

				if (!isPalindrome(String.valueOf(i))) {

					continue;
				}
				if (!isPalindrome(String.valueOf(i * i))) {

					continue;
				}

				++result;
			}

			out.printf("Case #%d: %d%n", testCase, result);
		}
	}

	private final boolean isPalindrome(final String s) {

		for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {

			if (s.charAt(i) != s.charAt(j)) {

				return false;
			}
		}

		return true;
	}
}
