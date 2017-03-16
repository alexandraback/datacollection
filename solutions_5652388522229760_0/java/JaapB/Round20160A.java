import static org.junit.Assert.assertEquals;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Locale;
import java.util.Scanner;

import org.junit.Test;

public class Round20160A {
	static {
		Locale.setDefault(Locale.US);
	}

	@Test
	public void tests() throws Exception {
		assertEquals("INSOMNIA", solve("0"));
		assertEquals("10", solve("1"));
		assertEquals("90", solve("2"));
		assertEquals("110", solve("11"));
		assertEquals("5076", solve("1692"));
	}

	static String solve(String testCase) {
		return new Solver(new Scanner(testCase)).solve();
	}

	static class Solver {
		private final long n;
		private final HashSet<Integer> target;

		public Solver(Scanner scanner) {
			this.n = scanner.nextInt();
			this.target = new HashSet<Integer>(Arrays.asList(0, 1, 2, 3, 4, 5, 6, 7, 8, 9));
		}

		public String solve() {
			for (long i = 1; i < 200; i++) {
				long total = i * n;
				long exp = 1;
				while (total >= exp) {
					int digit = (int) ((total / exp) % 10);
					target.remove(digit);
					exp *= 10;
				}
				if (target.isEmpty())
					return Long.toString(total);
			}
			return "INSOMNIA";
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
