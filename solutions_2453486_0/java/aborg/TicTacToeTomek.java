package googlecodejam2013.qualification.tictactoetomek;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Writer;

public class TicTacToeTomek {
	private static final String NOT_COMPLETED = "Game has not completed";
	private static final String X_WON = "X won";
	private static final String O_WON = "O won";
	private static final String DRAW = "Draw";

	public static void main(String[] args) throws IOException {
		String lineSep = System.getProperty("line.separator");
		BufferedReader br = new BufferedReader(
				args.length > 0 ? new FileReader(args[0])
						: new InputStreamReader(System.in));
		try {
			Writer out = new BufferedWriter(args.length > 1 ? new FileWriter(
					args[1]) : new OutputStreamWriter(System.out));
			try {
				int testCases = Integer.parseInt(br.readLine().trim());
				for (int i = 1; i <= testCases; ++i) {
					String[] board = new String[4];
					for (int j = 4; j-- > 0;) {
						board[j] = br.readLine();
					}
					br.readLine();
					out.write("Case #" + i + ": " + evaluate(board) + lineSep);
				}
			} finally {
				out.close();
			}
		} finally {
			br.close();
		}
	}

	private static String evaluate(String[] board) {
		if (isWon(board, 'O')) {
			return O_WON;
		}
		if (isWon(board, 'X')) {
			return X_WON;
		}
		return isCompleted(board) ? DRAW : NOT_COMPLETED;
	}

	private static boolean isWon(String[] board, char c) {
		for (int i = 4; i-- > 0;) {
			// horizontal
			boolean allOK = true;
			for (int j = 4; j-- > 0;) {
				char ch = board[i].charAt(j);
				allOK &= ch == c || ch == 'T';
			}
			if (allOK) {
				return true;
			}
			// vertical
			allOK = true;
			for (int j = 4; j-- > 0;) {
				char ch = board[j].charAt(i);
				allOK &= ch == c || ch == 'T';
			}
			if (allOK) {
				return true;
			}
		}
		boolean allOK = true;
		for (int i = 4; i-- > 0;) {
			char ch = board[i].charAt(i);
			allOK &= ch == c || ch == 'T';
		}
		if (allOK) {
			return true;
		}
		allOK = true;
		for (int i = 4; i-- > 0;) {
			char ch = board[i].charAt(3 - i);
			allOK &= ch == c || ch == 'T';
		}
		if (allOK) {
			return true;
		}
		return false;
	}

	private static boolean isCompleted(String[] board) {
		for (String line : board) {
			if (line.contains(".")) {
				return false;
			}
		}
		return true;
	}

}
