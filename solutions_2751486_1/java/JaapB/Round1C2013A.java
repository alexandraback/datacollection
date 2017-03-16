import static org.junit.Assert.assertEquals;

import java.util.Locale;
import java.util.Scanner;
import java.util.regex.Pattern;

import org.junit.Test;

// C:/Users/Jaap/workspace/Playground/bin
// C:/Users/Jaap/workspace/Playground/src

public class Round1C2013A {
	static {
		Locale.setDefault(Locale.US);
	}

	@Test
	public void testA() throws Exception {
		assertEquals(4, solve("quartz 3"));
	}

	@Test
	public void testB() throws Exception {
		assertEquals(11, solve("straight 3"));
	}

	@Test
	public void testC() throws Exception {
		assertEquals(3, solve("gcj 2"));
	}

	@Test
	public void testD() throws Exception {
		assertEquals(11, solve("tsetse 2"));
	}

	static int solve(String testCase) {
		return new Solver(new Scanner(testCase)).solve();
	}

	static boolean isConsonant(char ch) {
		switch (ch) {
		case 'a':
		case 'e':
		case 'i':
		case 'u':
		case 'o':
			return false;
		default:
			return true;
		}
	}

	static class Solver {
		private String s;
		private int[] ccs;
		private int[] nextMatch;
		private int n;
		private int len;

		public Solver(Scanner scanner) {
			this.s = scanner.next(Pattern.compile("\\w+"));
			this.len = s.length();
			this.ccs = new int[len + 1];
			this.nextMatch = new int[len + 1];
			this.n = scanner.nextInt();
			if (scanner.hasNextLine())
				scanner.nextLine();
		}

		public int solve() {
			int found = 0;
			ccs[len] = 0;
			int matchIndex = -1;
			for (int i = len - 1; i >= 0; i--) {
				ccs[i] = isConsonant(s.charAt(i)) ? ccs[i + 1] + 1 : 0;
				if (ccs[i] >= n)
					matchIndex = i;
				nextMatch[i] = matchIndex;
			}
			int partFound = calcPart(0);
			found += partFound;
			for (int i = 1; i < len; i++) {
				if (ccs[i - 1] >= n) {
					partFound = calcPart(i);
				}
				found += partFound;
			}
			return found;
		}

		protected int calcPart(int i) {
			int start = nextMatch[i];
			return start >= 0 ? len - n - start + 1 : 0;
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
	}
}
