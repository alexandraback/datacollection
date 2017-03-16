package codejam2013;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class LawnMower {

	public static boolean checkSquare(int[][] lawn, int i, int j) {
		boolean isFeasibleH = true;
		// check horizontally
		for (int k = 0; k < lawn[0].length; ++k) {
			if (lawn[i][k] > lawn[i][j]) {
				isFeasibleH = false;
				break;
			}
		}

		boolean isFeasibleV = true;
		// check vertically
		for (int k = 0; k < lawn.length; ++k) {
			if (lawn[k][j] > lawn[i][j]) {
				isFeasibleV = false;
				break;
			}
		}

		return isFeasibleH || isFeasibleV;
	}

	public static boolean check(int[][] lawn) {
		boolean isFeasible = true;
		outer: for (int i = 0; i < lawn.length; ++i) {
			for (int j = 0; j < lawn[0].length; ++j) {
				if (!checkSquare(lawn, i, j)) {
					isFeasible = false;
					break outer;
				}
			}
		}

		return isFeasible;
	}

	public static void solve(String fileName, String outputFileName)
			throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(
				new FileInputStream(fileName)));
		PrintWriter writer = new PrintWriter(outputFileName);

		int testCases = Integer.parseInt(reader.readLine());
		for (int t = 0; t < testCases; ++t) {
			String[] splits = reader.readLine().split(" ");
			int N = Integer.parseInt(splits[0]);
			int M = Integer.parseInt(splits[1]);
			int[][] lawn = new int[N][M];
			for (int i = 0; i < N; ++i) {
				splits = reader.readLine().split(" ");
				for (int j = 0; j < M; ++j) {
					lawn[i][j] = Integer.parseInt(splits[j]);
				}
			}
			
			String result = check(lawn) ? "YES" : "NO";
			writer.format("Case #%d: %s\n", t + 1, result);
		}

		writer.close();
		reader.close();
	}

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		solve("B-small-attempt0.in", "B.out");
	}

}
