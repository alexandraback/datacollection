import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class Main {
	private static char[][] board;
	private static int R, C, M;

	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("C-small-attempt3.in"));
		System.setOut(new PrintStream("C-small-attempt3.out"));
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i = 1; i <= T; i++) {
			R = sc.nextInt();
			C = sc.nextInt();
			M = sc.nextInt();
			board = new char[R][C];
			System.out.println("Case #" + i + ":");
			if (R * C == M + 1) {
				for (int j = 0; j < R; j++) {
					for (int k = 0; k < C; k++) {
						if (j == 0 && k == 0) {
							System.out.print('c');
						} else {
							System.out.print('*');
						}
					}
					System.out.println();
				}
			} else if (trySolution(0, 0)) {
				for (int j = 0; j < R; j++) {
					for (int k = 0; k < C; k++) {
						System.out.print(board[j][k]);
					}
					System.out.println();
				}
			} else {
				System.out.println("Impossible");
			}
		}
		sc.close();
	}

	private static boolean trySolution(int index, int m) {
		if (m == M) {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					if (board[i][j] != '*') {
						int count = 0;
						if (i != 0 && board[i - 1][j] == '*') {
							count++;
						}
						if (j != 0 && board[i][j - 1] == '*') {
							count++;
						}
						if (i != 0 && j != 0 && board[i - 1][j - 1] == '*') {
							count++;
						}
						if (i != 0 && j != C - 1 && board[i - 1][j + 1] == '*') {
							count++;
						}
						if (j != C - 1 && board[i][j + 1] == '*') {
							count++;
						}
						if (i != R - 1 && j != 0 && board[i + 1][j - 1] == '*') {
							count++;
						}
						if (i != R - 1 && board[i + 1][j] == '*') {
							count++;
						}
						if (i != R - 1 && j != C - 1
								&& board[i + 1][j + 1] == '*') {
							count++;
						}
						if (count == 0) {
							char[][] backup = new char[R][C];
							for (int k = 0; k < R; k++) {
								for (int l = 0; l < C; l++) {
									backup[k][l] = board[k][l];
								}
							}
							click(i, j);
							board[i][j] = 'c';
							boolean flag = true;
							for (int k = 0; k < R; k++) {
								for (int l = 0; l < C; l++) {
									if (board[k][l] == 0) {
										flag = false;
									}
								}
							}
							if (flag) {
								return true;
							} else {
								board = backup;
								return false;
							}
						}
					}
				}
			}
			return false;
		} else {
			for (int i = index; i <= R * C - M + m; i++) {
				board[i / C][i % C] = '*';
				if (trySolution(i + 1, m + 1)) {
					return true;
				}
				board[i / C][i % C] = 0;
			}
			return false;
		}
	}

	private static void click(int r, int c) {
		if (r >= 0 && r < R && c >= 0 && c < C && board[r][c] != '.') {
			board[r][c] = '.';
			if ((r == 0 || board[r - 1][c] != '*')
					&& (c == 0 || board[r][c - 1] != '*')
					&& (r == 0 || c == 0 || board[r - 1][c - 1] != '*')
					&& (r == 0 || c == C - 1 || board[r - 1][c + 1] != '*')
					&& (c == C - 1 || board[r][c + 1] != '*')
					&& (r == R - 1 || c == 0 || board[r + 1][c - 1] != '*')
					&& (r == R - 1 || board[r + 1][c] != '*')
					&& (r == R - 1 || c == C - 1 || board[r + 1][c + 1] != '*')) {
				click(r - 1, c);
				click(r, c - 1);
				click(r - 1, c - 1);
				click(r - 1, c + 1);
				click(r, c + 1);
				click(r + 1, c - 1);
				click(r + 1, c);
				click(r + 1, c + 1);
			}
		}
	}
}