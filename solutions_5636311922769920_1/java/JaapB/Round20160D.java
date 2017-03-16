import static org.junit.Assert.assertEquals;

import java.math.BigInteger;
import java.util.Locale;
import java.util.Scanner;

import org.junit.Test;

public class Round20160D {
	static {
		Locale.setDefault(Locale.US);
	}

	@Test
	public void tests() throws Exception {
		assertEquals("2", solve("2 3 2"));
		assertEquals("2", solve("2 3 1"));
		assertEquals("1", solve("1 1 1"));
		assertEquals("IMPOSSIBLE", solve("2 1 1"));
		assertEquals("1 2", solve("2 1 2"));
		assertEquals("2 3", solve("3 2 3"));
		assertEquals("2 3", solve("3 2 2"));
		assertEquals("6", solve("3 3 1"));
	}

	@Test
	public void testDiff() throws Exception {
		assertEquals("2 12", solve("4 2 2"));
	}

	static String solve(String testCase) {
		return new Solver(new Scanner(testCase)).solve();
	}

	static class Solver {
		private final int orgLen;
		private final int complexity;
		private final int cleaned;

		public Solver(Scanner scanner) {
			this.orgLen = scanner.nextInt();
			this.complexity = scanner.nextInt();
			this.cleaned = scanner.nextInt();
		}

		public String solve() {
			StringBuilder sb = new StringBuilder();
			if (cleaned * complexity < orgLen)
				return "IMPOSSIBLE";
			int end = complexity;
			sb.append(solPart(0, end).add(BigInteger.ONE));
			while (end < orgLen) {
				int start = end;
				end = start + complexity;
				sb.append(" ").append(solPart(start, end).add(BigInteger.ONE));
			}
			return sb.toString();
		}

		private BigInteger solPart(int start, int end) {
			if (end > orgLen)
				end = orgLen;
			BigInteger total = BigInteger.valueOf(start);
			for (int i = start + 1; i < end; i++)
				total = total.multiply(BigInteger.valueOf(orgLen)).add(BigInteger.valueOf(i));
			return total;
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
