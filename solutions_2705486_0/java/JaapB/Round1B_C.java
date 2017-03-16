import static org.junit.Assert.assertEquals;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Locale;
import java.util.Scanner;

import org.junit.Test;

public class Round1B_C {
	static {
		Locale.setDefault(Locale.US);
	}

	@Test
	public void test1() throws Exception {
		readDictionary();
		assertEquals(0, solve("codejam"));
	}

	@Test
	public void test2() throws Exception {
		readDictionary();
		assertEquals(2, solve("cxdejax"));
	}

	@Test
	public void test3() throws Exception {
		readDictionary();
		assertEquals(1, solve("cooperationaabea"));
	}

	@Test
	public void test4() throws Exception {
		readDictionary();
		assertEquals(1, solve("jobsinproduction"));
	}

	@Test
	public void test5a() throws Exception {
		DICTIONARY = new String[] { "victim", "victimless", "leos" };
		assertEquals(1, solve("vicximless"));
	}

	@Test
	public void test5b() throws Exception {
		DICTIONARY = new String[] { "victim", "victimless", "leos" };
		assertEquals(1, solve("vicximleos"));
	}

	@Test
	public void test5c() throws Exception {
		DICTIONARY = new String[] { "aaa", "ccc", "eeefffggg", "dedfffggh" };
		assertEquals(3, solve("aabcccdeefffggg"));
	}

	static int solve(String testCase) {
		return new Solver(new Scanner(testCase)).solve();
	}

	static String[] DICTIONARY;

	static class Solver {
		private String s;
		private int[][] bestSolutions;
		private int len;

		public Solver(Scanner scanner) {
			this.s = scanner.nextLine();
			this.len = s.length();
			this.bestSolutions = new int[len + 1][];
			this.bestSolutions[0] = new int[] { 0, 0, 0, 0, 0 };
			for (int i = 1; i <= len; i++)
				this.bestSolutions[i] = new int[] { Integer.MAX_VALUE, Integer.MAX_VALUE,
						Integer.MAX_VALUE, Integer.MAX_VALUE, Integer.MAX_VALUE };
		}

		public int solve() {
			for (int endPos = 1; endPos <= len; endPos++) {
				for (String word : DICTIONARY) {
					check(endPos, word);
				}
			}
			return bestSolutions[len][4];
		}

		protected void check(int endPos, String word) {
			int wordLen = word.length();
			int startPos = endPos - wordLen;
			if (startPos < 0)
				return;
			int[] bestWithoutWord = bestSolutions[startPos];
			if (bestWithoutWord[4] == Integer.MAX_VALUE)
				return;
			int startChangeCount = bestWithoutWord[4];
			int lastChange = -5;
			int newChangeCount = 0;
			for (int i = 0; i < wordLen; i++) {
				if (word.charAt(i) != s.charAt(startPos + i)) {
					if (lastChange < 0 && i < 4) {
						startChangeCount = bestWithoutWord[i];
						if (startChangeCount == Integer.MAX_VALUE)
							return;
					}
					if (i - lastChange < 5)
						return; // fail
					lastChange = i;
					newChangeCount++;
				}
			}
			if (newChangeCount == 0 && wordLen < 5) {
				for (int i = 0; i < 5; i++) {
					final int changes = bestWithoutWord[Math.min(i + wordLen, 4)];
					bestSolutions[endPos][i] = Math.min(bestSolutions[endPos][i], changes);
				}
			} else {
				int changeIndex = wordLen - lastChange;
				if (changeIndex >= 5)
					changeIndex = 5;
				final int changes = startChangeCount + newChangeCount;
				for (int i = 5 - changeIndex; i < 5; i++) {
					bestSolutions[endPos][i] = Math.min(bestSolutions[endPos][i], changes);
				}
			}
		}
	}

	public static void main(String[] args) {
		readDictionary();
		Scanner scanner = new Scanner(System.in);
		int nrOfTestCases = scanner.nextInt();
		for (int caseNr = 1; caseNr <= nrOfTestCases; caseNr++) {
			Object solution = new Solver(scanner).solve();
			System.out.println("Case #" + caseNr + ": " + solution);
		}
	}

	private static void readDictionary() {
		DICTIONARY = new String[521196];
		try {
			Scanner scanner = new Scanner(new File(
					"C:/Users/Jaap/workspace/Playground/garbled_email_dictionary.txt"));
			int i = 0;
			while (scanner.hasNextLine()) {
				String word = scanner.nextLine();
				DICTIONARY[i++] = word;
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
}
