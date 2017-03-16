import static org.junit.Assert.assertEquals;

import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

import org.junit.Test;

public class Round20160B {
	static {
		Locale.setDefault(Locale.US);
	}

	@Test
	public void tests() throws Exception {
		assertEquals(1, solve("-"));
		assertEquals(1, solve("-+"));
		assertEquals(2, solve("+-"));
		assertEquals(0, solve("+++"));
		assertEquals(3, solve("--+-"));
	}

	static int solve(String testCase) {
		return new Solver(new Scanner(testCase)).solve();
	}

	static class Solver {
		private final String s;
		private final boolean[] pos;

		public Solver(Scanner scanner) {
			this.s = scanner.nextLine();
			this.pos = new boolean[s.length()];
			for (int i = 0; i < s.length(); i++)
				pos[i] = s.charAt(i) == '+';
		}

		public int solve() {
			return solve(s.length() - 1);
		}

		private int solve(int last) {
			if (last < 0)
				return 0;
			if (pos[last])
				return solve(last - 1);
			if (!pos[0]) {
				flip(last);
				int result = 1 + solve(last);
				flip(last);
				return result;
			}
			int i = 0;
			while (pos[i])
				i++;
			flip(i - 1);
			flip(last);
			int result = 2 + solve(last);
			flip(last);
			flip(i - 1);
			return result;
		}

		private void flip(int last) {
			boolean[] flipped = Arrays.copyOf(pos, last + 1);
			for (int i = 0; i <= last; i++)
				pos[i] = !flipped[last - i];
		}
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int nrOfTestCases = scanner.nextInt();
		scanner.nextLine();
		for (int caseNr = 1; caseNr <= nrOfTestCases; caseNr++) {
			Object solution = new Solver(scanner).solve();
			System.out.println("Case #" + caseNr + ": " + solution);
		}
		if (scanner.hasNext())
			System.err.println("Warning! not at end of file");
	}
}
