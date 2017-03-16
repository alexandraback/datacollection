import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

/**
 * 
 * @author anurag
 *
 */
public class TicTacToeTomek {

	public static void main(String[] args) throws IOException {
		File inputFile = new File("E:\\Code-Jam\\TicTacToeTomek\\A-small-attempt0.in");
		File outputFile = new File("E:\\Code-Jam\\TicTacToeTomek\\A-small-attempt0.out");
		BufferedReader reader = new BufferedReader(new FileReader(inputFile));
		BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile));
		int noOfTestCases = Integer.parseInt(reader.readLine());
		char[][] board = new char[4][4];
		for (int i = 1; i <= noOfTestCases; i++) {
			boolean incomplete = false;
			for (int j = 0; j < 4; j++) {
				String input = reader.readLine();
				if (input.contains(".")) {
					incomplete = true;
				}
				for (int k = 0; k < 4; k++) {
					board[j][k] = input.charAt(k);
				}
			}
			String result = getBoardStatus(board);
			if (result.equals("Draw") && incomplete) {
				result = "Game has not completed";
			}
			String line = "Case #" + i + ": " + result + "\n";
			reader.readLine();
			writer.write(line);
		}
		reader.close();
		writer.close();
	}

	private static String getBoardStatus(char[][] board) {
		char startChar = '.';
		int k = 0;
		// Horizontal check
		for (int i = 0; i < 4; i++) {
			startChar = board[i][0];
			k = 1;
			if (startChar == 'T') {
				startChar = board[i][1];
				k = 2;
			}
			if (startChar != '.') {
				for (int j = k; j < 4; j++) {
					if (board[i][j] != 'T' && startChar != board[i][j]) {
						break;
					}
					if (j == 3) {
						return (startChar == 'X') ? "X won" : "O won";
					}
				}
			}
		}
		// Vertical check
		for (int i = 0; i < 4; i++) {
			startChar = board[0][i];
			k = 1;
			if (startChar == 'T') {
				startChar = board[1][i];
				k = 2;
			}
			if (startChar != '.') {
				for (int j = k; j < 4; j++) {
					if (board[j][i] != 'T' && startChar != board[j][i]) {
						break;
					}
					if (j == 3) {
						return (startChar == 'X') ? "X won" : "O won";
					}
				}
			}
		}
		// Diagonal check
		startChar = board[0][0];
		k = 1;
		if (startChar == 'T') {
			startChar = board[1][1];
			k = 2;
		}
		if (startChar != '.') {
			for (int j = k; j < 4; j++) {
				if (board[j][j] != 'T' && startChar != board[j][j]) {
					break;
				}
				if (j == 3) {
					return (startChar == 'X') ? "X won" : "O won";
				}
			}
		}
		startChar = board[0][3];
		k = 1;
		if (startChar == 'T') {
			startChar = board[1][2];
			k = 2;
		}
		if(startChar!='.') {
			for (int j = k; j < 4; j++) {
				if (board[j][3 - j] != 'T' && startChar != board[j][3 - j]) {
					break;
				}
				if (j == 3) {
					return (startChar == 'X') ? "X won" : "O won";
				}
			}
		}
		return "Draw";
	}
}
