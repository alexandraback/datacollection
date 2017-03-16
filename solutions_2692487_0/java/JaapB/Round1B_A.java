import static org.junit.Assert.assertEquals;

import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

import org.junit.Test;

public class Round1B_A {
	static {
		Locale.setDefault(Locale.US);
	}

	@Test
	public void test1() throws Exception {
		assertEquals(0, solve("2 2 2 1"));
	}

	@Test
	public void test2() throws Exception {
		assertEquals(1, solve("2 4 2 1 1 6"));
	}

	@Test
	public void test3() throws Exception {
		assertEquals(2, solve("10 4 25 20 9 100"));
	}

	@Test
	public void test4() throws Exception {
		assertEquals(4, solve("1 4 1 1 1 1"));
	}

	@Test
	public void test5() throws Exception {
		assertEquals(4, solve("2 5 2 8 32 128 256"));
	}


	@Test
	public void test6() throws Exception {
		assertEquals(8, solve("2 15 256 256 256 256 256 256 256 256 256 256 256 256 256 256 256"));
	}
	static int solve(String testCase) {
		return new Solver(new Scanner(testCase)).solve();
	}

	static class Solver {
		private int size;
		private int count;
		private int[] otherSizes;

		public Solver(Scanner scanner) {
			this.size = scanner.nextInt();
			this.count = scanner.nextInt();
			this.otherSizes = new int[count];
			for (int i = 0; i < count; i++)
				this.otherSizes[i] = scanner.nextInt();
			Arrays.sort(otherSizes);
		}

		public int solve() {
			return solve(size, 0);
		}

		private int solve(int curSize, int pos) {
			if (pos >= count)
				return 0;
			int nextSize = otherSizes[pos];
			if (nextSize < curSize)
				return solve(curSize + nextSize, pos + 1);
			int whenRemoving = count - pos;
			if (curSize == 1)
				return whenRemoving;
			int whenAdding = 1 + solve(curSize * 2 - 1, pos);
			return Math.min(whenAdding, whenRemoving);
		}

	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int nrOfTestCases = scanner.nextInt();
		for (int caseNr = 1; caseNr <= nrOfTestCases; caseNr++) {
			Object solution = new Solver(scanner).solve();
			System.out.println("Case #" + caseNr + ": " + solution);
		}
	}
}
