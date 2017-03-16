import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;

public class Slides {

	public static void main(String[] args) throws Exception {
		Slides object = new Slides();
		String className = object.getClass().getSimpleName();

		FileReader fileReader = new FileReader(new File(className.toLowerCase() + ".in"));
		StreamTokenizer st = new StreamTokenizer(new BufferedReader(fileReader));

		FileWriter wr = new FileWriter(className.toLowerCase() + ".out");

		st.nextToken();
		int testCases = (int) st.nval;

		HashMap<String, String> solved = new HashMap<>();

		for (int tc = 1; tc <= testCases; tc++) {

			System.out.println("At test " + tc + "/" + testCases);

			st.nextToken();
			int B = (int) st.nval;

			st.nextToken();
			int M = (int) st.nval;

			String result = solved.get(B + "#" + M);
			if (result == null) {
				result = object.solve(B, M);
				solved.put(B + "#" + M, result);
			}

			wr.write("Case #" + tc + ": " + result.trim() + "\r\n");
		}

		wr.close();
	}

	int B, M;
	String result = "IMPOSSIBLE";

	int[][] mat;

	public String solve(int B, int M) {

		this.B = B;
		this.M = M;

		mat = new int[B][B];
		result = "IMPOSSIBLE";

		generate(0, 0);
		return result;
	}

	private void generate(int row, int col) {

		if (!result.equals("IMPOSSIBLE")) {
			return;
		}

		if (col == B) {
			generate(row + 1, 0);
			return;
		}

		if (row == B - 1) {
			// all zeroes
			Arrays.fill(mat[row], 0);
			generate(row + 1, 0);
			return;
		}

		if (row == B) {
			// count ways
			if (countWays() == M) {
				result = "POSSIBLE\n";

				for (int i = 0; i < B; i++) {
					for (int j = 0; j < B; j++) {
						result += mat[i][j];
					}

					result += "\n";
				}

				return;
			}

			return;
		}

		if (row == col) {
			mat[row][col] = 0;
			generate(row, col + 1);
			return;
		}

		// else, put a 0 or a 1
		if (row > col && mat[col][row] == 1) {
			mat[row][col] = 0;
			generate(row, col + 1);
			return;
		}

		mat[row][col] = 0;
		generate(row, col + 1);

		mat[row][col] = 1;
		generate(row, col + 1);
	}

	private int countWays() {

		int ways = 0;

		Queue<int[]> path = new LinkedList<>();
		path.add(new int[] { 0 });

		while (ways <= M && !path.isEmpty()) {

			int[] current = path.poll();
			int cnt = current.length;

			if (cnt > B) {
				return 1000000000;
			}

			if (current[cnt - 1] == B - 1) {
				ways++;
				continue;
			}

			// else, go from here
			for (int next = 0; next < B; next++)
				if (mat[current[cnt - 1]][next] == 1) {
					int[] nextPath = Arrays.copyOf(current, current.length + 1);
					nextPath[cnt] = next;

					path.add(nextPath);
				}

		}

		return ways;
	}
}
