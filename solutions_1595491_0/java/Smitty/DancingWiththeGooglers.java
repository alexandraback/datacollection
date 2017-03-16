import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.io.*;

public class DancingWiththeGooglers {

	private final static String FILE_IN = DancingWiththeGooglers.class
			.getSimpleName() + ".in";
	private final static String FILE_OUT = DancingWiththeGooglers.class
			.getSimpleName() + ".out";

	public static void main(String[] args) throws Exception {
		final Scanner in = new Scanner(new File(FILE_IN));
		final PrintWriter out = new PrintWriter(FILE_OUT);

		final Map<Integer, Set<Integer>> ok = new HashMap<Integer, Set<Integer>>();
		for (int i = 0; i <= 10; ++i) {
			add(ok, i, i, i);
			if (i < 10) {
				add(ok, i, i, i + 1);
				add(ok, i, i + 1, i + 1);
			}
		}
		final Map<Integer, Set<Integer>> totalOk = new HashMap<Integer, Set<Integer>>();
		for (int i = 0; i <= 10; ++i) {
			for (int j = i; j <= Math.min(10, i + 2); ++j) {
				for (int k = j; k <= Math.min(10, i + 2); ++k) {
					add(totalOk, i, j, k);
				}
			}
		}

		for (int i = 9; i >= 0; --i) {
			ok.get(i).addAll(ok.get(i + 1));
			totalOk.get(i).addAll(totalOk.get(i + 1));
		}

		final int testCnt = in.nextInt();
		for (int caseNum = 1; caseNum <= testCnt; ++caseNum) {
			final int n = in.nextInt();
			final int s = in.nextInt();
			final int p = in.nextInt();
			final int[] a = new int[n];
			for (int i = 0; i < n; ++i) {
				a[i] = in.nextInt();
			}
			Arrays.sort(a);
			int result = 0;
			int left = s;
			for (int score : a) {
				if (ok.get(p).contains(score)) {
					++result;
				} else if (left > 0 && totalOk.get(p).contains(score)) {
					--left;
					++result;
				}
			}
			out.println(String.format("Case #%d: %d", caseNum, result));
		}
		in.close();
		out.close();
	}

	private final static void add(final Map<Integer, Set<Integer>> col,
			final int a, final int b, final int c) {
		final int s = a + b + c;
		final int max = Math.max(a, Math.max(b, c));
		if (!col.containsKey(max)) {
			col.put(max, new HashSet<Integer>());
		}
		col.get(max).add(s);
	}
}
