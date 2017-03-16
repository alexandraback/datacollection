
public class TicTacToeTomek {

	public String getDescription(String[] board) {
		for (int i = 0; i < board.length; i++) {
			int oCount = 0;
			int xCount = 0;
			for (int j = 0; j < board[0].length(); j++) {
				if (board[i].charAt(j) == 'O' || board[i].charAt(j) == 'T') oCount++;
				if (board[i].charAt(j) == 'X' || board[i].charAt(j) == 'T') xCount++;
			}
			if (oCount == 4) return "O won";
			if (xCount == 4) return "X won";
		}
		
		for (int i = 0; i < board[0].length(); i++) {
			int oCount = 0;
			int xCount = 0;
			for (int j = 0; j < board.length; j++) {
				if (board[j].charAt(i) == 'O' || board[j].charAt(i) == 'T') oCount++;
				if (board[j].charAt(i) == 'X' || board[j].charAt(i) == 'T') xCount++;
			}
			if (oCount == 4) return "O won";
			if (xCount == 4) return "X won";
		}
		
		int oCount = 0;
		int xCount = 0;
		for (int i = 0; i < board.length; i++) {
			if (board[i].charAt(i) == 'O' || board[i].charAt(i) == 'T') oCount++;
			if (board[i].charAt(i) == 'X' || board[i].charAt(i) == 'T') xCount++;
		
		}
		if (oCount == 4) return "O won";
		if (xCount == 4) return "X won";
		
		oCount = 0;
		xCount = 0;
		for (int i = 0; i < board.length; i++) {
			if (board[board.length - 1 - i].charAt(i) == 'O' || board[board.length - 1 - i].charAt(i) == 'T') oCount++;
			if (board[board.length - 1 - i].charAt(i) == 'X' || board[board.length - 1 - i].charAt(i) == 'T') xCount++;
		}
		if (oCount == 4) return "O won";
		if (xCount == 4) return "X won";
		
		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[0].length(); j++) {
				if (board[i].charAt(j) == '.') return "Game has not completed";
			}
		}
		return "Draw";
	}
}
