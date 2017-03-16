import java.io.BufferedReader;
import java.io.FileReader;
import java.io.BufferedWriter;
import java.io.FileWriter;

import java.util.*;

class Minesweeper {
	private static final String PROB_NAME = "minesweeper";

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(PROB_NAME + ".in"));
		BufferedWriter out = new BufferedWriter(new FileWriter(PROB_NAME + ".out"));

		int numTestCases = Integer.parseInt(in.readLine());
		for (int caseNumber = 1; caseNumber <= numTestCases; caseNumber++) {
			out.write("Case #" + caseNumber + ":\n");

			// SOLUTION HERE
			String[] line = in.readLine().split(" ");
			int rows = Integer.parseInt(line[0]);
			int cols = Integer.parseInt(line[1]);
			int mines = Integer.parseInt(line[2]);


			if (mines == rows * cols - 1) {
				for (int r = 0; r < rows - 1; r++) {
					for (int c = 0; c < cols; c++) {
						out.write('*');
					}
					out.write('\n');
				}
				for (int c = 0; c < cols - 1; c++) {
					out.write('*');
				}
				out.write("c\n");
				continue;
			}

			if (mines == 0) {
				for (int r = 0; r < rows; r++) {
					for (int c = 0; c < cols; c++) {
						if (r == rows - 1 && c == cols - 1) {
							out.write('c');
						} else
							out.write('.');
					}
					out.write('\n');
				}
				continue;
			}

			if (rows == 1) {
				for (int i = 0; i < mines; i++) {
					out.write('*');
				}
				for (int i = mines; i < cols - 1; i++) {
					out.write('.');
				}
				out.write("c\n");
				continue;
			}
			if (cols == 1) {
				for (int i = 0; i < mines; i++) {
					out.write("*\n");
				}
				for (int i = mines; i < rows - 1; i++) {
					out.write(".\n");
				}
				out.write("c\n");
				continue;
			}

			if (rows != 1 && cols != 1 && mines > rows * cols - 4) {
				out.write("Impossible\n");
				continue;
			}
			if (rows == 2 || cols == 2) {
				{
					if (mines % 2 == 1) {
						out.write("Impossible\n");
						continue;
					}
					if (rows == 2) {
						for (int i = 0; i < (int) (mines / 2.0 + 0.5); i++) {
							out.write('*');
						}
						for (int i = (int) (mines / 2.0 + 0.5); i < cols; i++) {
							out.write('.');
						}
						out.write('\n');
						for (int i = 0; i < mines / 2; i++) {
							out.write('*');
						}
						for (int i = mines / 2; i < cols - 1; i++) {
							out.write('.');
						}
						out.write("c\n");
					} else {
						for (int i = 0; i < (int) (mines / 2.0 + 0.5); i++) {
							out.write("**\n");
						}
						for (int i = (int) (mines / 2.0 + 0.5); i < rows - 1; i++) {
							out.write("..\n");
						}
						out.write(".c\n");
					}
				}
				continue;
			}

			if (mines == rows * cols - 4) {
				for (int r = 0; r < rows - 2; r++) {
					for (int c = 0; c < cols; c++) {
						out.write('*');
					}
					out.write('\n');
				}
				for (int c = 0; c < cols - 2; c++) {
					out.write('*');
				}
				out.write(cols > 1 ? "..\n" : ".\n");
				for (int c = 0; c < cols - 2; c++) {
					out.write('*');
				}
				out.write(cols > 1 ? ".c\n" : "c\n");
				continue;
			}
			char[][] board = new char[rows][cols];
			int numMinesPlaced = 0;
			outer:
			for (int r = 0; r < rows - 1; r++) {
				for (int c = 0; c < cols; c++) {
					if (numMinesPlaced == mines) break outer;
					if (c == cols - 2) {
						if (mines - numMinesPlaced == 1) continue outer;
					}
					if (r == rows - 3) {
						if (c >= cols - 3) {
							if ((mines - numMinesPlaced - cols + c) % 2 != 0) {
								continue outer;
							}
						}
					}
					board[r][c] = '*';
					numMinesPlaced++;
					if (numMinesPlaced == mines) {
						break outer;
					}
					if (r == rows - 2) { // second to last row need matching mines in last row
						board[r + 1][c] = '*';
						numMinesPlaced++;
						if (numMinesPlaced == mines) {
							break outer;
						}
					}
				}
			}
			flood(board, rows - 1, cols - 1, rows, cols, false);

			boolean solved = true;
			for (int r = 0; r < rows; r++) {
				for (int c = 0; c < cols; c++) {
					if (board[r][c] == 0) {
						solved = false;
						break;
					}
				}
			}
			if (solved) {
				// output board
				for (int r = 0; r < rows; r++) {
					for (int c = 0; c < cols; c++) {
						if (r == rows - 1 && c == cols - 1) {
							out.write('c');
						} else {
							out.write(board[r][c] == '*' ? '*' : '.');
						}
					}
					out.write('\n');
				}
			} else {
				out.write("Impossible\n");
			}
		}

		out.close();
	}

	private static void flood(char[][] board, int r, int c, int rows, int cols, boolean continueForward) {
		if (!inBoard(r, c, rows, cols)) {
			return;
		}
		if (board[r][c] == '*' || board[r][c] == 'c') {
			return;
		}
		if (getOrEmpty(board, r - 1, c - 1, rows, cols) != '*' &&
			getOrEmpty(board, r - 1, c, rows, cols) != '*' &&
			getOrEmpty(board, r - 1, c + 1, rows, cols) != '*' &&
			getOrEmpty(board, r, c - 1, rows, cols) != '*' &&
			getOrEmpty(board, r, c + 1, rows, cols) != '*' &&
			getOrEmpty(board, r + 1, c - 1, rows, cols) != '*' &&
			getOrEmpty(board, r + 1, c, rows, cols) != '*' &&
			getOrEmpty(board, r + 1, c + 1, rows, cols) != '*') {
			setOrDoNothing(board, r, c, 'c');
			flood(board, r - 1, c - 1, rows, cols, true);
			flood(board, r - 1, c, rows, cols, true);
			flood(board, r - 1, c + 1, rows, cols, true);
			flood(board, r, c - 1, rows, cols, true);
			flood(board, r, c + 1, rows, cols, true);
			flood(board, r + 1, c - 1, rows, cols, true);
			flood(board, r + 1, c, rows, cols, true);
			flood(board, r + 1, c + 1, rows, cols, true);
		} else {
			setOrDoNothing(board, r, c, 'r');/*
			if (continueForward) {
				if (inBoard(r - 1, c - 1, rows, cols)) {
					board[r - 1][c - 1] = board[r - 1][c - 1] == 0 ? 'r' : board[r - 1][c - 1];
				}
				if (inBoard(r - 1, c, rows, cols)) {
					board[r - 1][c] = board[r - 1][c] == 0 ? 'r' : board[r - 1][c];
				}
				if (inBoard(r - 1, c + 1, rows, cols)) {
					board[r - 1][c + 1] = board[r - 1][c + 1] == 0 ? 'r' : board[r - 1][c + 1];
				}
				if (inBoard(r, c - 1, rows, cols)) {
					board[r][c - 1] = board[r][c - 1] == 0 ? 'r' : board[r][c - 1];
				}
				if (inBoard(r, c + 1, rows, cols)) {
					board[r][c + 1] = board[r][c + 1] == 0? 'r' : board[r][c + 1];
				}
				if (inBoard(r + 1, c - 1, rows, cols)) {
					board[r + 1][c - 1] = board[r + 1][c - 1] == 0 ? 'r' : board[r + 1][c - 1];
				}
				if (inBoard(r + 1, c, rows, cols)) {
					board[r + 1][c] = board[r + 1][c] == 0 ? 'r' : board[r + 1][c];
				}
				if (inBoard(r + 1, c + 1, rows, cols)) {
					board[r + 1][c + 1] = board[r + 1][c + 1] == 0 ? 'r' : board[r + 1][c + 1];
				}
			}*/
		}
	}
	private static boolean inBoard(int r, int c, int rows, int cols) {
		return r > -1 && r < rows && c > -1 && c < cols;
	}
	private static char getOrEmpty(char[][] board, int r, int c, int rows, int cols) {
		if (r > -1 && r < rows && c > -1 && c < cols) {
			return board[r][c];
		}
		return (char) 0;
	}

	private static boolean setOrDoNothing(char[][] array, int r, int c, char val) {
		if (r > -1 && r < array.length && c > -1 && c < array[0].length) {
			array[r][c] = val;
			return true;
		}
		return false;
	}
}