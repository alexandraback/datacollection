import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Omino {

	public static void main(String[] args) throws Exception {
		Omino object = new Omino();
		String className = object.getClass().getSimpleName();

		FileReader fileReader = new FileReader(new File(className.toLowerCase() + ".in"));
		Scanner scanner = new Scanner(new BufferedReader(fileReader));

		FileWriter wr = new FileWriter(className.toLowerCase() + ".out");

		int testCases = scanner.nextInt();

		for (int tc = 1; tc <= testCases; tc++) {

			int X = scanner.nextInt();
			int R = scanner.nextInt();
			int C = scanner.nextInt();

			boolean result = object.solve(X, R, C);

			String output = (result == true) ? "GABRIEL" : "RICHARD";

			wr.write("Case #" + tc + ": " + output + "\r\n");
		}

		scanner.close();
		wr.close();
	}

	int grid[][];
	boolean solved = false;

	Set<Integer> checked;

	String[][] ominoes = new String[][] { {}, { "1" }, { "11" }, { "111", "11|01" }, { "1111", "111|001", "111|010", "11|11", "110|011" } };

	private boolean solve(int X, int R, int C) throws Exception {
		
		grid = new int[R][C];

		for (String om : ominoes[X]) {
			List<String> options = getAll(om);

			boolean canBeSolved = false;

			for (String option : options) {

				if (setAndCheck(option, X)) {
					canBeSolved = true;
					break;
				}
			}

			if (!canBeSolved)
				return false;
		}

		return true;
	}

	private List<String> getAll(String om) {

		List<String> result = new ArrayList<String>();

		for (int rotations = 0; rotations < 4; rotations++)
			for (int verticalFlips = 0; verticalFlips < 2; verticalFlips++)
				for (int horizontalFlips = 0; horizontalFlips < 2; horizontalFlips++) {

					int[][] current = fromString(om);

					for (int z = 0; z < rotations; z++)
						current = rotate(current);

					for (int z = 0; z < verticalFlips; z++)
						verticalFlip(current);

					for (int z = 0; z < horizontalFlips; z++)
						horizontalFlip(current);

					String encoded = toString(current);

					if (!result.contains(encoded))
						result.add(encoded);
				}

		return result;
	}

	private int[][] rotate(int[][] current) {

		int[][] rotated = new int[current[0].length][current.length];

		for (int i = 0; i < current.length; i++)
			for (int j = 0; j < current[0].length; j++) {
				rotated[j][current.length - i - 1] = current[i][j];
			}

		return rotated;

	}

	private void verticalFlip(int[][] current) {

		int R = current.length;

		for (int r = 0; r < R / 2; r++) {
			// we need to swap the rows

			for (int j = 0; j < current[0].length; j++) {
				int temp = current[r][j];
				current[r][j] = current[R - r - 1][j];
				current[R - r - 1][j] = temp;
			}

		}

	}

	private void horizontalFlip(int[][] current) {

		int C = current[0].length;

		for (int c = 0; c < C / 2; c++) {
			// we need to swap the rows

			for (int j = 0; j < current.length; j++) {
				int temp = current[j][c];
				current[j][c] = current[j][C - c - 1];
				current[j][C - c - 1] = temp;
			}

		}
	}

	private String toString(int[][] current) {
		String output = "";

		for (int i = 0; i < current.length; i++)
			for (int j = 0; j < current[0].length; j++) {
				if (i > 0 && j == 0)
					output += "|";

				output += current[i][j];
			}

		return output;
	}

	private int[][] fromString(String om) {
		String[] parts = om.split("[|]+");

		int[][] output = new int[parts.length][parts[0].length()];

		for (int i = 0; i < output.length; i++)
			for (int j = 0; j < output[0].length; j++)
				output[i][j] = parts[i].charAt(j) - '0';

		return output;
	}

	private boolean setAndCheck(String option, int X) throws Exception {

		String[] toSet = option.split("[|]+");

		int rowsToSet = toSet.length, colsToSet = toSet[0].length();

		int R = grid.length, C = grid[0].length;

		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				if (i + rowsToSet <= R && j + colsToSet <= C) {

					// set it up right here
					for (int mm = 0; mm < R; mm++)
						for (int nn = 0; nn < C; nn++)
							grid[mm][nn] = 0;

					for (int rr = i; rr < i + rowsToSet; rr++)
						for (int cc = j; cc < j + colsToSet; cc++)
							grid[rr][cc] = toSet[rr - i].charAt(cc - j) - '0';

					if (check(X))
						return true;
				}

		return false;
	}

	private boolean check(int X) throws Exception {
		checked = new HashSet<>();

		solved = false;
		fill(X, 2);

		return solved;
	}

	private void fill(int X, int number) {

		if (solved)
			return;
		
		int encoded = encode();

		checked.add(encoded);

		int sr = -1, sc = -1;

		// find an empty cell
		for (int r = 0; r < grid.length; r++)
			for (int c = 0; c < grid[0].length; c++) {
				if (grid[r][c] == 0) {
					sr = r;
					sc = c;
					break;
				}
			}

		if (sr == -1 && sc == -1) {
			solved = true;
			return;
		}

		dfs(sr, sc, X, number, 0);
	}

	private int encode() {
		int encoded = 0;
		for (int r = 0; r < grid.length; r++)
			for (int c = 0; c < grid[0].length; c++)
				if (grid[r][c] > 0) {
					encoded = encoded | (1 << (r * grid[0].length + c));
				}

		return encoded;
	}

	int dr[] = new int[] { -1, 1, 0, 0 };
	int dc[] = new int[] { 0, 0, -1, 1 };

	private void dfs(int sr, int sc, int x, int number, int set) {

		if (set == x) {
			// we've set everything up

			int encoded = encode();

			if (!checked.contains(encoded)) {
				fill(x, number + 1);
			}
		}

		// else, set a number
		if (grid[sr][sc] == 0) {
			// set this one
			grid[sr][sc] = number;
			dfs(sr, sc, x, number, set + 1);
			grid[sr][sc] = 0;
		} else {

			// set something around this one
			for (int rr : dr)
				for (int cc : dc) {
					int nr = sr + rr;
					int nc = sc + cc;

					if (nr < 0 || nr >= grid.length || nc < 0 || nc >= grid[0].length || grid[nr][nc] != 0)
						continue;

					grid[nr][nc] = number;
					dfs(nr, nc, x, number, set + 1);
					grid[nr][nc] = 0;
				}
		}
	}

}
