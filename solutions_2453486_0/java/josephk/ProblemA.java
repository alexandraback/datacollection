import java.io.*;
import java.util.*;

public class ProblemA {

    private static final char P1 = 'X';
    private static final char P2 = 'O';
    private static final char WILD = 'T';
    private static final char DOT = '.';

    private static boolean eq(char square, char player) {
	return (square == player) || (square == WILD);
    }

    private static boolean hasWon(char[][] board, char player) {
	if (eq(board[0][0], player) && eq(board[1][1], player) &&
	    eq(board[2][2], player) && eq(board[3][3], player)) {
	    return true;
	}
	if (eq(board[0][3], player) && eq(board[1][2], player) &&
	    eq(board[2][1], player) && eq(board[3][0], player)) {
	    return true;
	}
	for (int i = 0; i < 4; i++) {
	    if (eq(board[i][0], player) && eq(board[i][1], player) &&
		eq(board[i][2], player) && eq(board[i][3], player)) {
		return true;
	    }
	    if (eq(board[0][i], player) && eq(board[1][i], player) &&
		eq(board[2][i], player) && eq(board[3][i], player)) {
		return true;
	    }
	}
	return false;
    }

    private static String getResult(char[][] board) {
	int dots = 0;
	for (int i = 0; i < board.length; i++) {
	    for (int j = 0; j < board[i].length; j++) {
		dots += board[i][j] == DOT ? 1 : 0;
	    }
	}
	if (hasWon(board, P1)) {
	    return "X won";
	} else if (hasWon(board, P2)) {
	    return "O won";
	} else if (dots == 0) {
	    return "Draw";
	} else {
	    return "Game has not completed";
	}
    }

    public static void main(String[] args) throws Exception {
	Scanner input = new Scanner(System.in);
	int games = Integer.parseInt(input.nextLine().trim());
	for (int n = 0; n < games; n++) {
	    char[][] board = new char[4][];
	    for (int i = 0; i < board.length; i++) {
		String line = input.nextLine().trim().toUpperCase();
		board[i] = line.toCharArray();
	    }
	    input.nextLine();
	    System.out.println("Case #" + (n+1) + ": " + getResult(board));
	}
    }
}