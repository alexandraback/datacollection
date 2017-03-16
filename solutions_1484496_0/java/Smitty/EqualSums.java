import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.io.*;

public final class EqualSums {

	private final static String FILE_IN = EqualSums.class.getSimpleName()
			+ ".in";
	private final static String FILE_OUT = EqualSums.class.getSimpleName()
			+ ".out";

	public static final void main(final String[] args) throws Exception {
		final Scanner in = new Scanner(new File(FILE_IN));
		final PrintWriter out = new PrintWriter(FILE_OUT);
		final int testCnt = in.nextInt();

		int last[] = new int[100000 * 20];
		int prev[] = new int[100000 * 20];
		int lastIndex = 1;

		for (int caseNum = 1; caseNum <= testCnt; ++caseNum) {

			final int n = in.nextInt();
			final int a[] = new int[n];
			for (int i = 0; i < n; ++i) {
				a[i] = in.nextInt();
			}

			int result = Integer.MAX_VALUE;
			int m0 = -1;
			int m1 = -1;

			++lastIndex;
			for (int m = 1; m < (1 << n); ++m) {
				int sum = 0;
				for (int i = 0; i < n; ++i) {
					if ((m & (1 << i)) != 0) {
						sum += a[i];
					}
				}
				if (last[sum] != lastIndex) {
					last[sum] = lastIndex;
					prev[sum] = m;
				} else if (sum < result) {
					m0 = prev[sum];
					m1 = m;
					result = sum;
				}
			}

			out.println(String.format("Case #%d:", caseNum));
			if (result == Integer.MAX_VALUE) {
				out.println("Impossible");
			} else {
				boolean first;
				first = true;
				for (int i = 0; i < n; ++i) {
					if ((m0 & (1 << i)) != 0) {
						if (!first) {
							out.print(" ");
						}
						first = false;
						out.print(a[i]);
					}
				}
				out.println();
				first = true;
				for (int i = 0; i < n; ++i) {
					if ((m1 & (1 << i)) != 0) {
						if (!first) {
							out.print(" ");
						}
						first = false;
						out.print(a[i]);
					}
				}
				out.println();
			}

		}
		in.close();
		out.close();
	}

}
