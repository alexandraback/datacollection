import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class ProblemB {

	private static final String PROBLEM_PREFIX = "B";
	
	//private static final String PROBLEM_NAME = PROBLEM_PREFIX + "-test";

	//private static final String PROBLEM_NAME = PROBLEM_PREFIX + "-small-attempt0";
	//private static final String PROBLEM_NAME = PROBLEM_PREFIX + "-small-attempt1";
	//private static final String PROBLEM_NAME = PROBLEM_PREFIX + "-small-attempt2";
	//private static final String PROBLEM_NAME = PROBLEM_PREFIX + "-small-attempt3";
	private static final String PROBLEM_NAME = PROBLEM_PREFIX + "-large";

	public static String solve(int n, int[][] grid) {
		int maxHeight = 2500;
		int[] heights = new int[maxHeight + 1];
		for (int i = 0; i < n * 2 - 1; i++) {
			for (int j = 0; j < n; j++) {
				heights[grid[i][j]]++;
			}
		}
		int[] result = new int[n];
		int k = 0;
		for (int i = 1; i <= maxHeight; i++) {
			if (heights[i] % 2 != 0) {
				result[k++] = i;
			}
		}
		Arrays.sort(result);
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			sb.append(result[i]);
			if (i < n - 1) {
				sb.append(" ");
			}
		}
		return sb.toString();
	}

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File(PROBLEM_NAME + ".in"));
		PrintStream out = new PrintStream(new File(PROBLEM_NAME + ".out"));
		try {
			int t = in.nextInt();
			int caseNumber = 1;
			while (caseNumber <= t) {
				int n = in.nextInt();
				int[][] grid = new int[n * 2 - 1][n];
				for (int i = 0; i < n * 2 - 1; i++) {
					for (int j = 0; j < n; j++) {
						grid[i][j] = in.nextInt();
					}
				}
				out.println("Case #" + caseNumber++ + ": " + solve(n, grid));
			}
		} finally {
			in.close();
			out.close();
		}
	}

}
