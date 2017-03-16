import java.util.Scanner;

public class Mower {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int cases = reader.nextInt();
		for (int caseNum = 1; caseNum <= cases; caseNum++) {
			int row = reader.nextInt(), col = reader.nextInt();
			int[][] map = new int[row][col];
			for (int i = 0; i < row; i++)
				for (int j = 0; j < col; j++) {
					map[i][j] = reader.nextInt();
				}
			boolean result = solve(map);
			System.out.println("Case #" + caseNum + ": "
					+ (result ? "YES" : "NO"));
		}
	}

	private static boolean solve(int[][] map) {
		int r = map.length, c = map[0].length;
		boolean[][] need = new boolean[r][c];
		// horizontal
		for (int i = 0; i < r; i++) {
			int maximum = 1;
			for (int j = 0; j < c; j++) {
				if (map[i][j] >= maximum) {
					maximum = map[i][j];
				}
			}
			for (int j = 0; j < c; j++) {
				need[i][j] = map[i][j] < maximum;
			}
		}
		// vertical
		for (int i = 0; i < c; i++) {
			int maximum = 1;
			for (int j = 0; j < r; j++) {
				if (map[j][i] >= maximum) {
					maximum = map[j][i];
				}
			}
			for (int j = 0; j < r; j++) {
				if (map[j][i] < maximum && need[j][i]) {
					// System.out.println("Invalid cell at " + j + "," + i
					// + " at maximum = " + maximum);
					return false;
				}

			}
		}
		return true;
	}
}
