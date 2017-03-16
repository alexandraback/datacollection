import java.io.*;

public class TicTacToe {

	public static String getLine(BufferedReader buf) {
		String ret = null;
		try {
			ret = buf.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return ret;
	}

	public static void main(String[] args) {
		BufferedReader buf = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(getLine(buf));
		for (int i = 0; i < T; i++) {
			char[][] board = new char[4][];
			for (int j = 0; j < 4; j++) {
				String line = getLine(buf);
				board[j] = line.toCharArray();
			}
			System.out.println("Case #" + (i+1) + ": " + state(board));
			getLine(buf);
		}
	}

	public static String state(char[][] board) {
		boolean xWins = false;
		boolean oWins = false;
		for (int i = 0; i < board.length; i++) {
			boolean allX = true;
			boolean allO = true;
			for (int j = 0; j < board[0].length; j++) {
				if (board[i][j] != 'X' && board[i][j] != 'T') allX = false;
				if (board[i][j] != 'O' && board[i][j] != 'T') allO = false;
			}
			xWins |= allX; oWins |= allO;
			allX = true; allO = true;
			for (int j = 0; j < board[0].length; j++) {
				if (board[j][i] != 'X' && board[j][i] != 'T') allX = false;
				if (board[j][i] != 'O' && board[j][i] != 'T') allO = false;
			}
			xWins |= allX; oWins |= allO;
		}
		boolean allX = true;
		boolean allO = true;
		for (int i = 0; i < board.length; i++) {
			if (board[i][i] != 'X' && board[i][i] != 'T') allX = false;
			if (board[i][i] != 'O' && board[i][i] != 'T') allO = false;
		}
		xWins |= allX; oWins |= allO;

		allX = true;
		allO = true;
		for (int i = 0; i < board.length; i++) {
			if (board[board.length-1-i][i] != 'X' && board[board.length-1-i][i] != 'T') allX = false;
			if (board[board.length-1-i][i] != 'O' && board[board.length-1-i][i] != 'T') allO = false;
		}
		xWins |= allX; oWins |= allO;

		if (xWins) return "X won";
		if (oWins) return "O won";
		boolean allFilled = true;
		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board.length; j++) {
				if (board[i][j] == '.') allFilled = false;
			}
		}
		if (allFilled) return "Draw";
		return "Game has not completed";
	}

}
