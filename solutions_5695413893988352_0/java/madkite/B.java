package gcj2016r1b;

import java.util.*;

import com.google.*;

/**
 * @author Roman Kosenko <madkite@gmail.com>
 */
public class B extends SingleThreadSolution<Object> {
	public static void main(String[] args) throws Exception {
		solve(br -> {
			String[] s = br.readLine().split("\\s+");
			return new B(s[0], s[1]);
		}, "google/src/" + B.class.getPackage().getName() + "/" + "B-small-attempt0.in");
	}

	private final String score1, score2;
	private B(String score1, String score2) {
		this.score1 = score1;
		this.score2 = score2;
	}

	public String call() throws Exception {
		String[] solution = solveSmall(score1, score2);
		return solution[0] + ' ' + solution[1];
	}

	private static boolean check(int score, String pattern) {
		for(int i = pattern.length() - 1; i >= 0; i--) {
			int digit = score % 10;
			if(pattern.charAt(i) != '?' && pattern.charAt(i) - '0' != digit)
				return false;
			score /= 10;
		}
		return true;
	}

	private static String[] solveSmall(String score1, String score2) {
		int max = score1.length() == 3 ? 999 : score1.length() == 2 ? 99 : score1.length() == 1 ? 9 : 0;
		int[] result = null;
		for(int i = 0; i <= max; i++) {
			for(int j = 0; j <= max; j++) {
				if(check(i, score1) && check(j, score2)) {
					if(result == null)
						result = new int[]{i, j};
					else {
						int diff = Math.abs(i - j) - Math.abs(result[0] - result[1]);
						if(diff < 0) {
							result[0] = i;
							result[1] = j;
						}
						if(diff == 0) {
							if(i < result[0] || i == result[0] && j < result[1]) {
								result[0] = i;
								result[1] = j;
							}
						}
					}
				}
			}
		}
		score1 = String.format("%0" + score1.length() + "d", result[0]);
		score2 = String.format("%0" + score1.length() + "d", result[1]);
		return new String[]{score1, score2};
	}
}
