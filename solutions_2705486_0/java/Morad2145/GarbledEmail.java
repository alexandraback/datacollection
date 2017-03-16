import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.TreeSet;

public class GarbledEmail {

	private static TreeSet<String> dict0;
	private static TreeSet<String> dict1;
	private static TreeSet<String> dict2;

	private static final int MAX_WORD_LENGTH = 10;

	private static final int MAX_COST = 100000;

	private static void readDictopnary() throws IOException {
		String filename = "garbled_email_dictionary.txt";
		BufferedReader in = new BufferedReader(new FileReader(filename));
		dict0 = new TreeSet<String>();
		dict1 = new TreeSet<String>();
		dict2 = new TreeSet<String>();

		String line;
		while ((line = in.readLine()) != null) {
			dict0.add(line);
		}

		in.close();

		for (String word : dict0) {
			for (int i = 0; i < word.length(); i++) {
				String word1 = word.substring(0, i) + "*"
						+ word.substring(i + 1);
				dict1.add(word1);
				for (int j = 0; j + 4 < i; j++) {
					String word2 = word1.substring(0, j) + "*"
							+ word1.substring(j + 1);
					dict2.add(word2);
				}
			}
		}
	}

	public static void main(String[] args) throws Exception {
		readDictopnary();
		String filename = "C-small-attempt2.in";
		BufferedReader in = new BufferedReader(new FileReader(filename));

		int T = Integer.parseInt(in.readLine());

		for (int test = 1; test <= T; test++) {
			String str = in.readLine();
			System.out.println("Case #" + test + ": " + solve(str));
		}
		in.close();
	}

	private static long solve(String str) {
		int[][] cost = new int[str.length()+1][str.length() + 1];
		for (int i = 0; i < cost.length; i++) {
			for (int j = 0; j < cost[i].length; j++) {
				cost[i][j] = -1;
			}
		}
		return findCost(str, cost, 0, str.length());
	}

	private static long findCost(String str, int[][] cost, int from, int to) {
		if (from > to) {
			throw new IllegalArgumentException();
		}
		if (cost[from][to] < 0) {
			int swCost = singleWordCost(str.substring(from, to));
			if (swCost == 0) {
				cost[from][to] = 0;
			} else {
				for (int k = from + 1; k <= to; k++) {
					int cutCost = singleWordCost(str.substring(from, k));
					cutCost += findCost(str, cost, k, to);
					swCost = Math.min(swCost, cutCost);
				}
				cost[from][to] = swCost;
			}
		}
		return cost[from][to];
	}

	private static int singleWordCost(String word) {
		if (word.length() == 0 || dict0.contains(word)) {
			return 0;
		}
		if (word.length() > MAX_WORD_LENGTH) {
			return MAX_COST;
		}

		boolean inDict2 = false;
		for (int i = 0; i < word.length(); i++) {
			String word1 = word.substring(0, i) + "*" + word.substring(i + 1);
			if (dict1.contains(word1)) {
				return 1;
			}
			for (int j = 0; (!inDict2) && j + 4 < i; j++) {
				String word2 = word1.substring(0, j) + "*"
						+ word1.substring(j + 1);
				inDict2 = inDict2 || dict2.contains(word2);
			}
		}

		return inDict2 ? 2 : MAX_COST;
	}
}