package codejam16r1c;

import java.io.*;
import java.util.*;

public class FashionPolice {

	public static void main(String[] args) throws IOException {
		String problem = "fashion-police";
		String example = "C-small-attempt1";

		File inFile = new File("data/" + problem + "/" + example + ".in");
		File outFile = new File("data/" + problem + "/" + example + ".out");

		try (Scanner in = new Scanner(inFile); PrintStream out = new PrintStream(outFile)) {
			int T = in.nextInt();

			for (int t = 0; t < T; ++t) {
				int J = in.nextInt();
				int P = in.nextInt();
				int S = in.nextInt();
				int K = in.nextInt();

				int[][] solution = solve(J, P, S, K);

				out.println("Case #" + (t + 1) + ": " + solution.length);
				for (int[] row : solution)
					out.println((row[0] + 1) + " " + (row[1] + 1) + " " + (row[2] + 1));

			}
		}

		System.out.println("OK");
	}

	private static int[][] solve(int J, int P, int S, int K) {
		boolean[][][] used = new boolean[J][P][S];

		int[][] jp = new int[J][P];
		int[][] js = new int[J][S];
		int[][] ps = new int[P][S];

		int[][] sol = new int[J * P * S][3];
		int solC = 0;

		while (true) {
			int[] row = find(J, P, S, K, jp, js, ps, used);

			if (row == null)
				break;

			sol[solC++] = row;
			used[row[0]][row[1]][row[2]] = true;
			jp[row[0]][row[1]]++;
			js[row[0]][row[2]]++;
			ps[row[1]][row[2]]++;
		}

		return Arrays.copyOf(sol, solC);
	}

	private static int[][] solveSlow(int J, int P, int S, int K) {
		boolean[][][] used = new boolean[J][P][S];

		int[][] jp = new int[J][P];
		int[][] js = new int[J][S];
		int[][] ps = new int[P][S];

		int[][] sol = new int[J * P * S][3];
		return solveRec(J, P, S, K, used, jp, js, ps, sol, 0);
	}

	private static int[][] solveRec(int J, int P, int S, int K, boolean[][][] used, int[][] jp, int[][] js, int[][] ps, int[][] sol, int i) {
		int[][] best = Arrays.copyOf(sol, i);

		for (int j = 0; j < J; ++j)
			for (int p = 0; p < P; ++p)
				if (jp[j][p] < K)
					for (int s = 0; s < S; ++s)
						if (js[j][s] < K && ps[p][s] < K && !used[j][p][s]) {
							used[j][p][s] = true;
							jp[j][p]++;
							js[j][s]++;
							ps[p][s]++;

							sol[i] = new int[] { j, p, s };

							int[][] res = solveRec(J, P, S, K, used, jp, js, ps, sol, i + 1);

							if (res.length > best.length)
								best = res;

							used[j][p][s] = false;
							jp[j][p]--;
							js[j][s]--;
							ps[p][s]--;
						}

		return best;
	}

	private static int[] find(int J, int P, int S, int K, int[][] jp, int[][] js, int[][] ps, boolean[][][] used) {
		int bs = Integer.MAX_VALUE;
		int[] best = null;

		for (int j = 0; j < J; ++j)
			for (int p = 0; p < P; ++p)
				if (jp[j][p] < K)
					for (int s = 0; s < S; ++s)
						if (js[j][s] < K && ps[p][s] < K && !used[j][p][s])
							if (bs > jp[j][p] + js[j][s] + ps[p][s]) {
								best = new int[] { j, p, s };
								bs = jp[j][p] + js[j][s] + ps[p][s];
							}

		return best;
	}

	private static boolean check(int j, int p, int s, int k, int[][] solution) {
		int[][] jp = new int[j][p];
		int[][] js = new int[j][s];
		int[][] ps = new int[p][s];

		for (int[] row : solution) {
			jp[row[0]][row[1]]++;
			js[row[0]][row[2]]++;
			ps[row[1]][row[2]]++;

			if (jp[row[0]][row[1]] > k || js[row[0]][row[2]] > k || ps[row[1]][row[2]] > k)
				return false;
		}

		return true;
	}

}
