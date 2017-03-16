import static java.lang.Integer.parseInt;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class B {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = parseInt(br.readLine());

		StringTokenizer tok;
		for (int ii = 1; ii <= T; ii++) {
			int N = Integer.parseInt(br.readLine());
			tok = new StringTokenizer(br.readLine());
			String[] train = new String[N];
			for (int i = 0; i < N; i++) {
				train[i] = tok.nextToken();
			}
			System.out.printf("Case #%d: %d\n", ii, solve(train));
		}
	}

	private static int solve(String[] train) {
		Integer[] idxs = new Integer[train.length];
		for (int i = 0; i < idxs.length; i++) {
			idxs[i] = i;
		}
		Arrays.sort(train);

		int res = 0;
		if (isValid(reorder(train, idxs))) {
			++res;
		}

		while ((idxs = nextPermutation(idxs)) != null) {
			if (isValid(reorder(train, idxs))) {
				++res;
			}
		}
		return res;
	}

	private static String[] reorder(String[] train, Integer[] idxs) {
		String[] res = new String[train.length];
		for (int i = 0; i < res.length; i++) {
			res[i] = train[idxs[i]];
		}
		return res;
	}

	private static boolean isValid(String[] train) {
		char last = train[0].charAt(0);
		StringBuilder buff = new StringBuilder(last);
		Set<Character> used = new HashSet<>();
		used.add(last);
		for (int i = 0; i < train.length; i++) {
			for (int j = 0; j < train[i].length(); j++) {
				if (i == 0 && j == 0) {
					// already processed
					continue;
				}
				char c = train[i].charAt(j);
				if (c != last) {
					if (used.contains(c))
						return false;
					used.add(c);
					buff.append(c);
					last = c;
				}
			}
		}
		return true;
	}

	// simply prints all permutation - to see how it works
	// private static void printPermutations(Comparable[] c) {
	// System.out.println(Arrays.toString(c));
	// while ((c = nextPermutation(c)) != null) {
	// System.out.println(Arrays.toString(c));
	// }
	// }

	// modifies c to next permutation or returns null if such permutation does
	// not exist
	private static Integer[] nextPermutation(final Integer[] c) {
		// 1. finds the largest k, that c[k] < c[k+1]
		int first = getFirst(c);
		if (first == -1)
			return null; // no greater permutation
		// 2. find last index toSwap, that c[k] < c[toSwap]
		int toSwap = c.length - 1;
		while (c[first].compareTo(c[toSwap]) >= 0)
			--toSwap;
		// 3. swap elements with indexes first and last
		swap(c, first++, toSwap);
		// 4. reverse sequence from k+1 to n (inclusive)
		toSwap = c.length - 1;
		while (first < toSwap)
			swap(c, first++, toSwap--);
		return c;
	}

	// finds the largest k, that c[k] < c[k+1]
	// if no such k exists (there is not greater permutation), return -1
	private static int getFirst(final Comparable[] c) {
		for (int i = c.length - 2; i >= 0; --i)
			if (c[i].compareTo(c[i + 1]) < 0)
				return i;
		return -1;
	}

	// swaps two elements (with indexes i and j) in array
	private static void swap(final Comparable[] c, final int i, final int j) {
		final Comparable tmp = c[i];
		c[i] = c[j];
		c[j] = tmp;
	}
}
