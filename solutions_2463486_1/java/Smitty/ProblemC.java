import java.io.File;
import java.io.PrintWriter;
import java.util.NavigableSet;
import java.util.Scanner;
import java.util.TreeSet;

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

		final NavigableSet<Long> goodNumbers = new TreeSet<Long>();

		for (int i = 1; i <= (int) (1e7 + 1); ++i) {

			final long l = i;

			if (!isPalindrome(String.valueOf(l))) {

				continue;
			}

			if (!isPalindrome(String.valueOf(l * l))) {

				continue;
			}

			goodNumbers.add(l * l);
		}

		final int testCount = in.nextInt();

		for (int testCase = 1; testCase <= testCount; ++testCase) {

			final long l = in.nextLong();
			final long r = in.nextLong();

			final int result = goodNumbers.subSet(l, true, r, true).size();

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
