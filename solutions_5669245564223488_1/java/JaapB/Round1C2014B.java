import static org.junit.Assert.assertEquals;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;
import java.util.regex.Pattern;

import org.junit.Test;

public class Round1C2014B {
	static {
		Locale.setDefault(Locale.US);
	}

	@Test
	public void test1() throws Exception {
		assertEquals(1, solve("3\nab bbbc cd"));
	}

	@Test
	public void test2() throws Exception {
		assertEquals(4, solve("4\naa aa bc c"));
	}

	@Test
	public void test3() throws Exception {
		assertEquals(0, solve("2\nabc bcd"));
	}

	@Test
	public void test4() throws Exception {
		assertEquals(1, solve("2\nabbbbc ccccd"));
	}

	@Test
	public void test5() throws Exception {
		assertEquals(0, solve("2\nabbebbc ccccd"));
	}

	@Test
	public void test6() throws Exception {
		assertEquals((13l * 12 * 11 * 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1) % 1000000007,
				solve("13\na a a a a a a a a a a a a"));
	}

	@Test
	public void test6b() throws Exception {
		assertEquals((11 * 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1), Solver.facMod(11));
		assertEquals((13l * 12 * 11 * 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1) % 1000000007, Solver.facMod(13), 0.0001);
	}

	@Test
	public void test7() throws Exception {
		assertEquals(0, solve("2\nabba ccc"));
	}

	@Test
	public void test8() throws Exception {
		assertEquals((11 * 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1) % 1000000007, solve("12\nab a a a a a a a a a a a"));
	}

	@Test
	public void test9() throws Exception {
		assertEquals(1, solve("3\na ab b"));
		assertEquals(8, solve("4\na a b b"));
	}

	@Test
	public void test10() throws Exception {
		assertEquals(4, solve("5\na a ab b b"));
	}

	@Test
	public void test11() throws Exception {
		assertEquals(5 * 4 * 3 * 2 * 1 * 2, solve("7\na a ab c d ef gh"));
	}

	@Test
	public void test12() throws Exception {
		assertEquals(4 * 3 * 2 * 1,
				solve("5\nffvvuaaaaddbbbkzzz yynnneerrrxxxx iiiiiwqssssyy mmmmmmmmmggggggggg llltttpjjhhoo"));
	}

	@Test
	public void test13() throws Exception {
		// bb bbaauuggiiwwllxxqq qq qqoojj njjmmee ee eerrsszz zzvvcc
		// pphhkknnffttddyy
		assertEquals(2, solve("9\njjmmee eerrsszz qqoojj pphhkknnffttddyy bb ee bbaauuggiiwwllxxqq qq zzvvcc"));
	}

	@Test
	public void test14() throws Exception {
		assertEquals(0, solve("4\na ca abc a"));
	}

	static long solve(String testCase) {
		return new Solver(new Scanner(testCase)).solve();
	}

	static class Solver {
		private static final int MOD = 1000000007;
		private static final Pattern TRAIN_PATTERN = Pattern.compile("\\w+");
		private final int count;
		private final String[] trains;
		private final int[] atStartOfTrain = new int[26];
		private final int[] inMiddleOfTrain = new int[26];
		private final int[] atEndOfTrain = new int[26];
		private final int[] trainStarts;
		private final int[] trainEnds;

		public Solver(Scanner scanner) {
			this.count = scanner.nextInt();
			this.trains = new String[count];
			this.trainStarts = new int[count];
			this.trainEnds = new int[count];
			for (int i = 0; i < count; i++) {
				final String train = scanner.next(TRAIN_PATTERN);
				this.trains[i] = train;
				this.trainStarts[i] = charAtIndex(train, 0);
				this.trainEnds[i] = charAtIndex(train, train.length() - 1);
			}
			Arrays.fill(atStartOfTrain, -1);
			Arrays.fill(inMiddleOfTrain, -1);
			Arrays.fill(atEndOfTrain, -1);
		}

		static class Train {
			int chStart;
			int chEnd;
			long combinations;

			@Override
			public String toString() {
				return chStart + "[" + combinations + "]" + chEnd;
			}
		}

		public long solve() {
			if (!sanityCheck())
				return 0;
			ArrayList<Train> newTrains = new ArrayList<Train>();
			for (int ch = 0; ch < 26; ch++) {
				int trainsWithChar = 0;
				int trainEnd = -1;
				for (int t = 0; t < count; t++)
					if (trainStarts[t] == ch) {
						if (trainEnds[t] == ch)
							trainsWithChar++;
						else if (trainEnd >= 0)
							return 0;
						else
							trainEnd = trainEnds[t];
					}
				if (trainsWithChar > 0 || trainEnd >= 0) {
					Train train = new Train();
					train.chStart = ch;
					train.chEnd = trainEnd < 0 ? ch : trainEnd;
					train.combinations = facMod(trainsWithChar);
					newTrains.add(train);
				}
			}
			;
			while (true) {
				Train combineTrain1 = null;
				Train combineTrain2 = null;
				for (Train startTrain : newTrains) {
					if (startTrain.chStart != startTrain.chEnd) {
						for (Train endTrain : newTrains)
							if (startTrain.chEnd == endTrain.chStart) {
								if (endTrain.chEnd == startTrain.chStart)
									return 0;
								combineTrain1 = startTrain;
								combineTrain2 = endTrain;
								break;
							}
					}
				}
				if (combineTrain1 == null || combineTrain2 == null)
					return calc(newTrains);
				newTrains.remove(combineTrain1);
				newTrains.remove(combineTrain2);
				Train combined = new Train();
				combined.chStart = combineTrain1.chStart;
				combined.chEnd = combineTrain2.chEnd;
				combined.combinations = (combineTrain1.combinations * combineTrain2.combinations) % MOD;
				newTrains.add(combined);
			}
		}

		private long calc(ArrayList<Train> trains) {
			long result = facMod(trains.size());
			for (Train t : trains)
				result = result * t.combinations % MOD;
			return result;
		}

		public static long facMod(int n) {
			if (n <= 1)
				return 1;
			final long result = n * facMod(n - 1);
			return result % MOD;
		}

		private boolean sanityCheck() {
			for (int t = 0; t < count; t++) {
				String train = trains[t];
				final int charAtStart = charAtIndex(train, 0);
				atStartOfTrain[charAtStart] = t;
				final int charAtEnd = charAtIndex(train, train.length() - 1);
				atEndOfTrain[charAtEnd] = t;
				int middleStart = 1;
				while (middleStart < train.length() && charAtIndex(train, middleStart) == charAtStart)
					middleStart++;
				int middleEnd = train.length() - 2;
				while (middleEnd >= 0 && charAtIndex(train, middleEnd) == charAtEnd)
					middleEnd--;
				int prev = charAtStart;
				for (int p = middleStart; p <= middleEnd; p++) {
					final int ch = charAtIndex(train, p);
					if (ch != prev) {
						if (inMiddleOfTrain[ch] >= 0)
							return false;
						else if (charAtEnd == charAtStart)
							return false;
					}
					inMiddleOfTrain[ch] = t;
					prev = ch;
				}
			}
			for (int ch = 0; ch < 26; ch++) {
				if (inMiddleOfTrain[ch] >= 0 && (atStartOfTrain[ch] >= 0 || atEndOfTrain[ch] >= 0))
					return false;
				if (atStartOfTrain[ch] >= 0) {
					int trainsStartingWithButNotEndingWithChar = 0;
					for (int t = 0; t < count; t++)
						if (trainStarts[t] == ch && trainEnds[t] != ch)
							trainsStartingWithButNotEndingWithChar++;
					if (trainsStartingWithButNotEndingWithChar >= 2)
						return false;
				}
				if (atEndOfTrain[ch] >= 0) {
					int trainsEndingWithButNotStartingWithChar = 0;
					for (int t = 0; t < count; t++)
						if (trainStarts[t] != ch && trainEnds[t] == ch)
							trainsEndingWithButNotStartingWithChar++;
					if (trainsEndingWithButNotStartingWithChar >= 2)
						return false;
				}
			}
			return true;
		}

		protected int charAtIndex(String train, int charIndex) {
			return train.charAt(charIndex) - 'a';
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
