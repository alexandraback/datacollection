package codejam2013;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class TicTacToe {

	public static char checkDir(String[] board, int startI, int startJ,
			int stepI, int stepJ) {
		char checkedChar = 'T';
		boolean areSame = true;
		boolean hasEmpty = false;
		for (int i = startI, j = startJ; i < board.length && j < board.length; i += stepI, j += stepJ) {
			char currentChar = board[i].charAt(j);
			if (currentChar == '.') {
				hasEmpty = true;
				break;
			}

			if (currentChar == 'X' || currentChar == 'O') {
				if (checkedChar == 'T') {
					checkedChar = currentChar;
				} else if (currentChar != checkedChar) {
					areSame = false;
				}
			}
		}

		if (hasEmpty) {
			return '.';
		}
		if (areSame) {
			return checkedChar;
		}
		return 'D';
	}

	public static String getState(String[] board) {
		// check rows
		boolean hasEmpty = false;
		for (int i = 0; i < board.length; ++i) {
			char current = checkDir(board, i, 0, 0, 1);
			if (current == '.') {
				hasEmpty = true;
			} else if (current == 'O') {
				return "O won";
			} else if (current == 'X') {
				return "X won";
			}
		}

		// check columns
		for (int j = 0; j < board.length; ++j) {
			char current = checkDir(board, 0, j, 1, 0);
			if (current == '.') {
				hasEmpty = true;
			} else if (current == 'O') {
				return "O won";
			} else if (current == 'X') {
				return "X won";
			}
		}

		// check diagonals
		char current = checkDir(board, 0, 0, 1, 1);
		if (current == '.') {
			hasEmpty = true;
		} else if (current == 'O') {
			return "O won";
		} else if (current == 'X') {
			return "X won";
		}

		current = checkDir(board, board.length - 1, 0, -1, 1);
		if (current == '.') {
			hasEmpty = true;
		} else if (current == 'O') {
			return "O won";
		} else if (current == 'X') {
			return "X won";
		}

		return hasEmpty ? "Game has not completed" : "Draw";
	}

	public static void solve(String fileName, String outputFileName)
			throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(
				new FileInputStream(fileName)));
		PrintWriter writer = new PrintWriter(outputFileName);

		int size = 4;
		int testCases = Integer.parseInt(in.readLine());
		for (int t = 0; t < testCases; ++t) {
			String[] board = new String[size];
			for (int i = 0; i < size; ++i) {
				board[i] = in.readLine();
			}
			writer.format("Case #%d: %s\n", t + 1, getState(board));
			in.readLine(); // read empty line
		}
		
		writer.close();
		in.close();
	}

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		solve("A-small-attempt0.in", "out.txt");
	}

}
