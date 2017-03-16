import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;

public class Minesweeper {

	public static void main(String[] args) throws Exception {
		Minesweeper object = new Minesweeper();
		object.work();
	}

	private void work() throws Exception {
		StreamTokenizer st = new StreamTokenizer(new BufferedReader(
				new FileReader(this.getClass().getSimpleName() + ".in")));
		PrintWriter pw = new PrintWriter(new FileWriter(this.getClass()
				.getSimpleName() + ".out"));

		st.nextToken();
		int tcases = (int) st.nval;

		for (int tc = 1; tc <= tcases; tc++) {
			st.nextToken();
			int r = (int) st.nval;

			st.nextToken();
			int c = (int) st.nval;

			st.nextToken();
			int m = (int) st.nval;

			pw.write("Case #" + tc + ":\r\n" + solve(r, c, m).trim() + "\r\n");
		}

		pw.close();
	}

	private String solve(int r, int c, int m) {
		int fields = r * c;

		int map[][] = new int[r][c];

		for (int i = 0; i < (1 << fields); i++) {

			if (Integer.bitCount(i) != m)
				continue;

			for (int row = 0; row < r; row++)
				for (int col = 0; col < c; col++) {
					int id = row * c + col;

					if (((1 << id) & i) > 0)
						map[row][col] = 1;
					else
						map[row][col] = 0;
				}

			for (int row = 0; row < r; row++)
				for (int col = 0; col < c; col++) {

					if (map[row][col] == 1)
						continue;

					map[row][col] = -1; // click

					int value = revealed(map, row, col);
					revert(map);

					if (value == fields - m)
						return encode(map);

					map[row][col] = 0;
				}

		}

		return "Impossible";
	}

	private void revert(int[][] map) {
		for (int row = 0; row < map.length; row++)
			for (int col = 0; col < map[0].length; col++)
				if (map[row][col] > 900)
					map[row][col] -= 1000;
	}

	private static int dx[] = new int[] { -1, -1, -1, 0, 1, 1, 1, 0 };
	private static int dy[] = new int[] { -1, 0, 1, 1, 1, 0, -1, -1 };

	private int revealed(int[][] map, int row, int col) {

		int old = map[row][col];
		map[row][col] = 1000 + old;

		int result = 1;

		boolean bad = false;

		for (int nx = 0; nx < dx.length; nx++) {
			int nrow = row + dx[nx], ncol = col + dy[nx];

			if (nrow >= 0 && nrow < map.length && ncol >= 0
					&& ncol < map[0].length)
				if (map[nrow][ncol] == 1)
					bad = true;
		}

		if (!bad) {

			for (int nx = 0; nx < dx.length; nx++) {
				int nrow = row + dx[nx], ncol = col + dy[nx];

				if (nrow >= 0 && nrow < map.length && ncol >= 0
						&& ncol < map[0].length)
					if (map[nrow][ncol] == 0)
						result += revealed(map, nrow, ncol);
			}

		}

		return result;
	}

	private String encode(int[][] map) {
		StringBuilder sb = new StringBuilder();

		for (int i = 0; i < map.length; i++) {

			for (int j = 0; j < map[i].length; j++) {
				char ch = 'c';

				if (map[i][j] == 1)
					ch = '*';

				if (map[i][j] == 0)
					ch = '.';

				sb.append(ch);
			}

			sb.append("\r\n");
		}

		return sb.toString();
	}

}
