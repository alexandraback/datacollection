import java.util.Arrays;
import java.util.Scanner;

public class CRoundB {

	public static void main(String[] args) {
		char[] arr = new char[5];
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int i = 0; i < T; i++) {
			double ans = solve(in);
			System.out.printf("Case #%d: %.8f\n", i + 1, ans);
		}

	}

	static double numWords, numBananas;
	static int K, L, S;
	static String keys, target;

	public static double solve(Scanner in) {

		numWords = 0;
		numBananas = 0;

		K = in.nextInt();
		L = in.nextInt();
		S = in.nextInt();

		keys = in.next();
		target = in.next();

		int[] count = new int[26];
		for (char c : keys.toCharArray()) {
			count[c - 'A']++;
		}

		// Check that we can actually type the word
		for (char c : target.toCharArray()) {
			if (count[c - 'A'] == 0) {
				return 0;
			}
		}

		int maxBananas = findMaxBananas(target, S);


		backtrack("");

		double ans = maxBananas;

		ans -= numBananas / numWords;

		return ans;
	}

	public static void backtrack(String cur) {
		if (cur.length() == S) {
			numWords++;
			numBananas += countInstances(target, cur.toCharArray());
			return;
		}

		for (char c : keys.toCharArray()) {
			backtrack(cur + c);
		}
	}

	// Word is the target, result is our attempt
	public static int countInstances(String word, char[] result) {
		int S = result.length;
		int ans = 0;
		for (int i = 0; i <= S - word.length(); i++) {
			for (int j = 0; j < word.length(); j++) {
				if (result[i+j] != word.charAt(j)) {
					break;
				}

				if (j == word.length() - 1) {
					ans++;
				}
			}
		}

		return ans;
	}

	public static int findMaxBananas(String word, int S) {

		char[] result = new char[S];
		Arrays.fill(result, '_');

		for (int i = 0; i < word.length(); i++) {
			result[i] = word.charAt(i);
		}

		for (int start = 1; start <= S - word.length(); start++) {
			for (int i = 0; i < word.length(); i++) {
				int curIdx = start + i;
				if (result[curIdx] == '_') {
					result[curIdx] = word.charAt(i);
				} else if (result[curIdx] != word.charAt(i)) {
					break;
				} else {
					result[curIdx] = word.charAt(i);
				}
			}
		}

		return countInstances(word, result);
	}

}
