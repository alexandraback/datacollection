import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class MinesweeperMaster {
	static int r, c, m;
	static int[][] board;
	static boolean[][] visited;
	static int[] dx = new int[] { -1, -1, -1, 0, 1, 1, 1, 0 };
	static int[] dy = new int[] { -1, 0, 1, 1, 1, 0, -1, -1 };
	static boolean ok;
	static int ci, cj;
	static int[] x;

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("src/in.txt"));
		PrintWriter out = new PrintWriter("out.txt");

		int t = Integer.parseInt(in.readLine());

		for (int tc = 1; tc <= t; tc++) {
			String[] split = in.readLine().split(" ");

			r = Integer.parseInt(split[0]);
			c = Integer.parseInt(split[1]);
			m = Integer.parseInt(split[2]);

			x = new int[r * c + 1];
			board = new int[r + 1][c + 1];

			ok = false;
			generateBoard(1, m);

			out.println("Case #" + tc + ": ");
			if (ok) {
				for (int i = 1; i <= r; i++) {
					for (int j = 1; j <= c; j++) {
						if (i == ci && j == cj) {
							out.print('c');
						} else {
							if (board[i][j] >= 0) {
								out.print('.');
							} else {
								out.print('*');
							}
						}
					}

					out.println();
				}
			} else {
				out.println("Impossible");
			}
		}

		in.close();
		out.close();
	}

	private static boolean checkSol() {
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if (board[i][j] > 0 && !visited[i][j]) {
					return false;
				}
			}
		}

		return true;
	}

	private static int computeBoard() {
		int total = r * c - m;

		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if (board[i][j] == 0) {
					for (int d = 0; d < 8; d++) {
						int ni = i + dx[d];
						int nj = j + dy[d];

						if (valid(ni, nj) && board[ni][nj] == -1) {
							board[i][j]++;
						}
					}

					if (board[i][j] != 0) {
						total--;
					}
				}
			}
		}
		return total;
	}

	private static void generateBoard(int k, int m) {
		if (!ok) {
			if (k == r * c + 1) {
				if (m == 0) {
					int row = 1;
					int col = 1;

					for (int i = 1; i <= r * c; i++) {
						board[row][col] = x[i];
						col++;
						if (col > c) {
							col = 1;
							row++;
						}
					}
					int total = computeBoard();

					if (total != 0) {
						visited = new boolean[r + 1][c + 1];

						outer: for (int i = 1; i <= r; i++) {
							for (int j = 1; j <= c; j++) {
								if (board[i][j] == 0) {
									ci = i;
									cj = j;
									break outer;
								}
							}
						}

						fill(ci, cj);

						ok = checkSol();
					} else {
						int count = 0;
						
						for (int i=1;i<=r;i++) {
							for (int j=1;j<=c && count < 2;j++) {
								if (board[i][j] > 0) {
									ci = i;
									cj = j;
									count++;
								}
							}
						}
						
						if (count == 1) {
							ok = true;
						}
					}
				}
			} else {
				if (m > 0) {
					x[k] = -1;
					generateBoard(k + 1, m - 1);
				}

				x[k] = 0;
				generateBoard(k + 1, m);
			}
		}
	}

	private static boolean valid(int i, int j) {
		return (i >= 1 && i <= r && j >= 1 && j <= c);
	}

	private static void fill(int x, int y) {
		visited[x][y] = true;

		for (int d = 0; d < 8; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (valid(nx, ny)) {

				if (!visited[nx][ny]) {
					if (board[nx][ny] == 0) {
						fill(nx, ny);
					} else {
						visited[nx][ny] = true;
					}
				}
			}
		}
	}
}
