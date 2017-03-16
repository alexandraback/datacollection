import static org.junit.Assert.assertEquals;

import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

import org.junit.Test;

public class Round20160C {
	static {
		Locale.setDefault(Locale.US);
	}

	@Test
	public void tests() throws Exception {
		assertOK(solve("16 50"), 16);
	}

	static void assertOK(String solution, int length) {
		Scanner scanner = new Scanner(solution);
		while (scanner.hasNext()) {
			scanner.nextLine();
			String digits = scanner.next("[01]+");
			for (int base = 2; base <= 10; base++) {
				assertEquals('1', digits.charAt(0));
				assertEquals(length, digits.length());
				assertEquals('1', digits.charAt(length - 1));
				long value = Long.valueOf(digits, base);
				final int div = scanner.nextInt();
				assertEquals(value + " (base " + base + ") is not divisible by " + div, 0, value % div);
			}
		}
		scanner.close();
	}

	static String solve(String testCase) {
		return new Solver(new Scanner(testCase)).solve();
	}

	static class Solver {
		static final int[] TEST_PRIMES = new int[] { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59,
				61, 67, 71, 73, 79, 83, 89, 97 }; // 25
		private final int[][] mods10 = new int[TEST_PRIMES.length][]; // 25 * length
		private final int[][] mods8 = new int[TEST_PRIMES.length][]; // 25 * length
		private final int[][] mods7 = new int[TEST_PRIMES.length][]; // 25 * length
		private final int[][] mods6 = new int[TEST_PRIMES.length][]; // 25 * length
		private final int[][] mods4 = new int[TEST_PRIMES.length][]; // 25 * length
		private final int[][] mods2 = new int[TEST_PRIMES.length][]; // 25 * length
		private final int length;
		private final int count;
		private final boolean[] attempt;

		public Solver(Scanner scanner) {
			this.length = scanner.nextInt();
			this.count = scanner.nextInt();
			this.attempt = new boolean[length];
			this.attempt[0] = true;
			this.attempt[length - 1] = true;
		}

		public String solve() {
			initMods(mods10, 10);
			initMods(mods8, 8);
			initMods(mods7, 7);
			initMods(mods6, 6);
			initMods(mods4, 4);
			initMods(mods2, 2);
			int solutionsFound = 0;
			StringBuilder sb = new StringBuilder();
			while (solutionsFound < count) {
				nextValue();
				if (digitSum() % 2 != 0)
					continue;
				int div2 = findDiv(mods2);
				if (div2 <= 0)
					continue;
				int div6 = findDiv(mods6);
				if (div6 <= 0)
					continue;
				int div7 = findDiv(mods7);
				if (div7 <= 0)
					continue;
				int div8 = findDiv(mods8);
				if (div8 <= 0)
					continue;
				int div10 = findDiv(mods10);
				if (div10 <= 0)
					continue;
				int div4 = findDiv(mods4);
				if (div4 <= 0)
					continue;
				solutionsFound++;
				sb.append("\n");
				appendAttempt(sb);
				sb.append(" ").append(div2).append(" ").append(2).append(" ").append(div4);
				sb.append(" ").append(2).append(" ").append(div6).append(" ").append(div7);
				sb.append(" ").append(div8).append(" ").append(2).append(" ").append(div10);
			}
			return sb.toString();
		}

		private void appendAttempt(StringBuilder sb) {
			for (int i = attempt.length - 1; i >= 0; i--)
				sb.append(attempt[i] ? '1' : '0');
		}

		private int digitSum() {
			int sum = 0;
			for (boolean element : attempt)
				if (element)
					sum++;
			return sum;
		}

		private void nextValue() {
			int i = 0;
			while (attempt[i])
				i++;
			attempt[i] = true;
			Arrays.fill(attempt, 0, i, false);
			attempt[0] = true;
		}

		private void initMods(int[][] mods, int base) {
			for (int primeIndex = 0; primeIndex < TEST_PRIMES.length; primeIndex++) {
				int prime = TEST_PRIMES[primeIndex];
				int[] primeMods = new int[length];
				primeMods[0] = 1;
				for (int i = 1; i < length; i++)
					primeMods[i] = (primeMods[i - 1] * base) % prime;
				mods[primeIndex] = primeMods;
			}
		}

		private int findDiv(int[][] mods) {
			for (int primeIndex = 0; primeIndex < TEST_PRIMES.length; primeIndex++) {
				int prime = TEST_PRIMES[primeIndex];
				int[] primeMods = mods[primeIndex];
				int mod = 0;
				for (int i = 0; i < length; i++)
					if (attempt[i])
						mod += primeMods[i];
				if (mod % prime == 0)
					return prime;
			}
			return -1;
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
