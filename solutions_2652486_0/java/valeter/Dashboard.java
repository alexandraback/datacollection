import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

/**
 * @author Ivan Anisimov (ivananisimov2010@gmail.com)
 * 
 */
public class Dashboard {
	public static boolean isPrime(final int n) {
		for (int i = 2; i <= Math.sqrt(n); i++) {
			if ((n % i) == 0) {
				return true;
			}
		}
		return false;
	}

	public static boolean probablyCould(final List<Integer> lst, final int k,
			final boolean[] used, final int count) {
		if (k == 1) {
			return true;
		}
		final int N = lst.size();
		if (count == N) {
			return false;
		}
		boolean result = false;
		for (int i = 0; i < N; i++) {
			if (used[i]) {
				continue;
			}
			final int cur = lst.get(i);
			if ((k % cur) == 0) {
				used[i] = true;
				result = result || probablyCould(lst, k / cur, used, count + 1);
				used[i] = false;
			}
		}
		return result;
	}

	public static boolean probablyRight(final List<Integer> lst, final int[] v) {
		final int K = v.length;
		for (int i = 0; i < K; i++) {
			final boolean[] used = new boolean[K];
			Arrays.fill(used, false);
			if (!probablyCould(lst, v[i], used, 0)) {
				return false;
			}
		}
		return true;
	}

	public static String getString(final List<Integer> lst) {
		String result = "";
		for (final Integer i : lst) {
			result += i.toString();
		}
		return result;
	}

	public static String getGuess(final int N, final int M, final int[] v) {
		final List<String> result = new ArrayList<>();

		final LinkedList<Integer> stack = new LinkedList<>();
		stack.addLast(2);
		stack.addLast(2);
		stack.addLast(1);
		outter: while (true) {
			Integer top = stack.peekLast();
			while (top == M) {
				stack.pollLast();
				if (stack.isEmpty()) {
					break outter;
				}
				top = stack.peekLast();
			}
			stack.pollLast();
			stack.addLast(top + 1);
			while (stack.size() < N) {
				stack.addLast(2);
			}
			final String curStr = getString(stack);
			if (probablyRight(stack, v)) {
				result.add(curStr);
			}
		}
		final Random r = new Random();
		return result.get(r.nextInt(result.size()));
	}

	public static void main(final String[] args) {
		final String inputFileName = "C:\\Users\\Valter\\C-small-1-attempt0.in";
		final String outputFileName = "C:\\Users\\Valter\\C-small-1-attempt0.out";

		try (final Scanner in = new Scanner(new File(inputFileName));
				final PrintWriter out = new PrintWriter(
						new File(outputFileName))) {
			final int testNum = in.nextInt();
			for (int i = 0; i < testNum; i++) {
				System.out.println("Processing test #" + (i + 1));
				final int R = in.nextInt();
				final int N = in.nextInt();
				final int M = in.nextInt();
				final int K = in.nextInt();
				out.write("Case #" + (i + 1) + ": " + '\r' + '\n');
				for (int k = 0; k < R; k++) {
					final int[] v = new int[K];
					for (int j = 0; j < K; j++) {
						v[j] = in.nextInt();
					}
					out.write(getGuess(N, M, v) + '\r' + '\n');
				}
			}
		} catch (final IOException ex) {
			System.out.println("IO error");
		}
	}
}
