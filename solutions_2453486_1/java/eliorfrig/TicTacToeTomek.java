import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class TicTacToeTomek {
	
	private final static int lineOrColumnSize = 4;

	public static void main(String[] args) {
		long start = System.currentTimeMillis();
		String inputFilename = "A-large.in";
		StringBuilder answer = new StringBuilder();
		BufferedReader br;
		try {
			br = new BufferedReader(new FileReader(inputFilename));
			String line = br.readLine();
			int testCases = Integer.parseInt(line);
			for (int i=1; i<=testCases; i++) {
				char board[][] = new char[lineOrColumnSize][lineOrColumnSize];
				for (int j=0; j<lineOrColumnSize; j++) {
					line = br.readLine();
					for (int k=0; k<lineOrColumnSize; k++) {
						board[j][k] = line.charAt(k);
					}
				}
				String result = checkForGameResult(board);
				answer.append("Case #" + i + ": " + result + System.lineSeparator());
				line = br.readLine(); //the empty line at the end of each test case
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		writeOutput(answer.toString());
		System.out.println("in " + (System.currentTimeMillis() - start));
	}

	private static String checkForGameResult(char[][] board) {
		//check lines
		for (int line=0; line<lineOrColumnSize; line++) {
			if((board[line][0] == 'X' || board[line][0] == 'T') && (board[line][1] == 'X' || board[line][1] == 'T') && (board[line][2] == 'X' || board[line][2] == 'T') && (board[line][3] == 'X' || board[line][3] == 'T'))
				return "X won";
			else if((board[line][0] == 'O' || board[line][0] == 'T') && (board[line][1] == 'O' || board[line][1] == 'T') && (board[line][2] == 'O' || board[line][2] == 'T') && (board[line][3] == 'O' || board[line][3] == 'T'))
				return "O won";
		}
		//check columns
		for (int column=0; column<lineOrColumnSize; column++) {
			if((board[0][column] == 'X' || board[0][column] == 'T') && (board[1][column] == 'X' || board[1][column] == 'T') && (board[2][column] == 'X' || board[2][column] == 'T') && (board[3][column] == 'X' || board[3][column] == 'T'))
				return "X won";
			else if((board[0][column] == 'O' || board[0][column] == 'T') && (board[1][column] == 'O' || board[1][column] == 'T') && (board[2][column] == 'O' || board[2][column] == 'T') && (board[3][column] == 'O' || board[3][column] == 'T'))
				return "O won";
		}
		//check diagonals
		if (((board[0][0] == 'X' || board[0][0] == 'T') && (board[1][1] == 'X' || board[1][1] == 'T') && (board[2][2] == 'X' || board[2][2] == 'T') && (board[3][3] == 'X' || board[3][3] == 'T')) || 
				((board[0][3] == 'X' || board[0][3] == 'T') && (board[1][2] == 'X' || board[1][2] == 'T') && (board[2][1] == 'X' || board[2][1] == 'T') && (board[3][0] == 'X' || board[3][0] == 'T')))
			return "X won";
		else if (((board[0][0] == 'O' || board[0][0] == 'T') && (board[1][1] == 'O' || board[1][1] == 'T') && (board[2][2] == 'O' || board[2][2] == 'T') && (board[3][3] == 'O' || board[3][3] == 'T')) || 
				((board[0][3] == 'O' || board[0][3] == 'T') && (board[1][2] == 'O' || board[1][2] == 'T') && (board[2][1] == 'O' || board[2][1] == 'T') && (board[3][0] == 'O' || board[3][0] == 'T')))
			return "O won";
		//no winner, check if it's draw or game not ended
		if (isPointExist(board))
			return "Game has not completed";
		else
			return "Draw";
	}

	private static boolean isPointExist(char[][] board) {
		for (int i=0; i<lineOrColumnSize; i++) {
			for (int j=0; j<lineOrColumnSize; j++) {
				if (board[i][j] == '.')
					return true;
			}
		}
		return false;
	}

	private static void writeOutput(String string) {
		try {
			String outputFilename = "output.txt";
			BufferedWriter bw = new BufferedWriter(new FileWriter(outputFilename));
			bw.write(string);
			bw.close();
			System.out.println("success!");
		} catch (Exception e) {
			System.out.println("error!");
		}
	}
	
}
