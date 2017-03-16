import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Solution {
	Solution() throws Exception {
	}

	Object solve() throws Exception {
		int n = in.nextInt();
		int[] scores = new int[n];
		double sum = 0;
		
		for (int i = 0 ; i < n; i ++) {
			scores[i] = in.nextInt();
			sum += scores[i];
		}
		
		double[] min = new double[n];
		for (int i = 0 ; i < n; i ++) {
			double average = 2 * sum / n;
			min[i] = (average - scores[i]) / sum;
//			if (min[i] < 0)
//				min[i] = 0;
		}
		String out = "";
		for (double i : min)
			out += Math.ceil(i * 100000000) /1000000d  + " ";
		return out;
	}

	void solveAll() throws Exception {
		int cases = in.nextInt();
		in.nextLine();
		for (int i = 1; i <= cases; i++) {
			String solution = "Case #" + i + ": " + solve();
			System.out.println(solution);
			out.println(solution);
		}
		out.flush();
	}

	// -----------------------------------------------------------------------

	static Scanner in = new Scanner(System.in);
	static PrintWriter out = new PrintWriter(System.out);

	public static void main(String[] args) throws Exception {
		new Solution().solveAll();
	}
}
