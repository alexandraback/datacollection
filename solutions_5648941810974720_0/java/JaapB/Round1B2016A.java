
// jaap@beetstra-it.nl

import static org.junit.Assert.assertEquals;

import java.util.Locale;
import java.util.Scanner;

import org.junit.Test;

public class Round1B2016A {
	static {
		Locale.setDefault(Locale.US);
	}

	static String[] DIGITS = new String[] { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT",
			"NINE" };

	@Test
	public void tests() throws Exception {
		assertEquals("012", solve("OZONETOWER"));
		assertEquals("2468", solve("WEIGHFOXTOURIST"));
		assertEquals("114", solve("OURNEONFOE"));
		assertEquals("3", solve("ETHER"));
		assertEquals("79", solve("SEVENNINE"));
		for (int i = 0; i < 10; i++)
			assertEquals(Integer.toString(i), solve(DIGITS[i]));
	}

	static String solve(String testCase) {
		return new Solver(new Scanner(testCase)).solve();
	}

	static class Solver {
		private final String s;

		public Solver(Scanner scanner) {
			this.s = scanner.next();
		}

		public String solve() {
			StringBuilder sb = new StringBuilder();
			append(sb, '0', count('Z'));
			append(sb, '1', count('O') - count('Z') - count('W') - count('U'));
			append(sb, '2', count('W'));
			append(sb, '3', count('H') - count('G'));
			append(sb, '4', count('U'));
			append(sb, '5', count('F') - count('U'));
			append(sb, '6', count('X'));
			append(sb, '7', count('S') - count('X'));
			append(sb, '8', count('G'));
			append(sb, '9', count('I') - (count('F') - count('U')) - count('X') - count('G'));
			return sb.toString();
		}

		static void append(StringBuilder sb, char ch, int count) {
			for (int i = 0; i < count; i++)
				sb.append(ch);
		}

		private int count(char ch) {
			int count = 0;
			for (int i = 0; i < s.length(); i++)
				if (s.charAt(i) == ch)
					count++;
			return count;
		}

	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int nrOfTestCases = scanner.nextInt();
		for (int caseNr = 1; caseNr <= nrOfTestCases; caseNr++) {
			Object solution = new Solver(scanner).solve();
			System.out.println("Case #" + caseNr + ": " + solution);
		}
		if (scanner.hasNext())
			System.err.println("Warning! not at end of file");
	}
}
