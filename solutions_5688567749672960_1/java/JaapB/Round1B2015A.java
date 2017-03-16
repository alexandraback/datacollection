import static org.junit.Assert.assertEquals;

import java.util.Locale;
import java.util.Scanner;

import org.junit.Test;

//jaap@beetstra-it.nl
public class Round1B2015A {
	static {
		Locale.setDefault(Locale.US);
	}

	@Test
	public void tests() throws Exception {
		assertEquals(1, solve("1"));
		assertEquals(19, solve("19"));
		assertEquals(15, solve("23"));
	}

	@Test
	public void test2() throws Exception {
		assertEquals(14, solve("31"));
	}

	@Test
	public void test3() throws Exception {
		assertEquals(22214, solve("31234567"));
	}

	@Test
	public void test4() throws Exception {
		assertEquals(29, solve("100"));
	}

	@Test
	public void test5() throws Exception {
		assertEquals(28, solve("99"));
	}

	@Test
	public void test6() throws Exception {
		assertEquals(137, solve("999"));
	}

	static long solve(String testCase) {
		return new Solver(new Scanner(testCase)).solve();
	}

	static class Solver {
		private final long n;

		public Solver(Scanner scanner) {
			this.n = scanner.nextLong();
		}

		public long solve() {
			long target = n;
			long count = 0;
			while (target >= 1) {
				count++;
				if (shouldReverse(target)) {
					final long reverse = reverse(target);
					if (reverse < target)
						target = reverse;
					else
						target--;
				} else
					target--;
			}
			return count;
		}

		boolean shouldReverse(long nr) {
			if (nr <= 10)
				return false;
			if (nr % 10 != 1)
				return false;
			long digit = 10;
			while (nr >= digit * digit) {
				if ((nr / digit) % 10 != 0)
					return false;
				digit *= 10;
			}
			return true;
		}

		static long reverse(long nr) {
			long result = 0;
			long digit = 1;
			while (nr >= digit) {
				result = result * 10 + (nr / digit) % 10;
				digit *= 10;
			}
			return result;
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
