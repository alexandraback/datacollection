import java.io.*;

public class ProblemA {

    static final int SIZE_BOARD = 4;

    public static String checkBoard(char[][] board)
    {
	int ndot = 0;
	// Check columns
	for (int i = 0; i < SIZE_BOARD; ++i) {
	    int no = 0;
	    int nx = 0;
	    for (int j = 0; j < SIZE_BOARD; ++j) {
		if (board[i][j] == 'O') no++;
		if (board[i][j] == 'X') nx++;
		if (board[i][j] == 'T') {
		    no++;
		    nx++;
		}
		if (board[i][j] == '.') ndot++;
	    }
	    if (no == SIZE_BOARD) return "O won";
	    if (nx == SIZE_BOARD) return "X won";
	}
	// Check lines
	for (int i = 0; i < SIZE_BOARD; ++i) {
	    int no = 0;
	    int nx = 0;
	    for (int j = 0; j < SIZE_BOARD; ++j) {
		if (board[j][i] == 'O') no++;
		if (board[j][i] == 'X') nx++;
		if (board[j][i] == 'T') {
		    no++;
		    nx++;
		}
	    }
	    if (no == SIZE_BOARD) return "O won";
	    if (nx == SIZE_BOARD) return "X won";
	}
	// Check diagonals
	int no = 0;
	int nx = 0;
	for (int i = 0; i < SIZE_BOARD; ++i) {
	    if (board[i][i] == 'O') no++;
	    if (board[i][i] == 'X') nx++;
	    if (board[i][i] == 'T') {
		no++;
		nx++;
	    }	    
	}
	if (no == SIZE_BOARD) return "O won";
	if (nx == SIZE_BOARD) return "X won";
	no = 0;
	nx = 0;
	for (int i = 0; i < SIZE_BOARD; ++i) {
	    if (board[i][SIZE_BOARD-1-i] == 'O') no++;
	    if (board[i][SIZE_BOARD-1-i] == 'X') nx++;
	    if (board[i][SIZE_BOARD-1-i] == 'T') {
		no++;
		nx++;
	    }	    
	}
	if (no == SIZE_BOARD) return "O won";
	if (nx == SIZE_BOARD) return "X won";

	if (ndot > 0) return "Game has not completed";
	else return "Draw";
    }

    public static void main(String[] args)
	throws IOException
    {
	BufferedReader fin = new BufferedReader(new FileReader(args[0]));
	int T = Integer.parseInt(fin.readLine());
	for (int t = 1; t <= T; ++t) {
	    char[][] board = new char[SIZE_BOARD][];
	    for (int i = 0; i < SIZE_BOARD; ++i) {
		board[i] = fin.readLine().toCharArray();
	    }
	    System.out.println("Case #" + t + ": " + checkBoard(board));
	    fin.readLine();
	}
	System.out.println();
    }

}