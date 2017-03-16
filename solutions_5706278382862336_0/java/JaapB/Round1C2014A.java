import static org.junit.Assert.assertEquals;

import java.util.Locale;
import java.util.Scanner;

import org.junit.Test;

public class Round1C2014A {
	static {
		Locale.setDefault(Locale.US);
	}

	@Test
	public void tests() throws Exception {
		assertEquals(1, solve("1/2"));
		assertEquals(1, solve("3/4"));
	}

	@Test
	public void test2() throws Exception {
		assertEquals(2, solve("1/4"));
	}

	@Test
	public void test3() throws Exception {
		assertEquals(-1, solve("2/23"));
		assertEquals(8, solve("123/31488"));
	}

	@Test
	public void test4() throws Exception {
		assertEquals(40, solve("1/1099511627776"));
	}

	static int solve(String testCase) {
		return new Solver(new Scanner(testCase)).solve();
	}

	static class Solver {
		private final long p;
		private final long q;

		public Solver(Scanner scanner) {
			String s = scanner.next();
			int pos = s.indexOf('/');
			this.p = Long.parseLong(s.substring(0, pos));
			this.q = Long.parseLong(s.substring(pos + 1));
		}

		public int solve() {
			double target = ((double) p) / q;
			double item = 1.0 / 2;
			double current = 0;
			int result = -1;
			for (int gen = 1; gen <= 40; gen++) {
				if (target - current >= item) {
					current += item;
					if (result < 0)
						result = gen;
				}
				item = item / 2;
			}
			if (current == target)
				return result;
			return -1;
		}
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int nrOfTestCases = scanner.nextInt();
		for (int caseNr = 1; caseNr <= nrOfTestCases; caseNr++) {
			int solution = new Solver(scanner).solve();
			System.out.println("Case #" + caseNr + ": " + (solution < 0 ? "impossible" : solution));
		}
	}
}
