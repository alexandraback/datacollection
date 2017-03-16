import java.util.*;

public class A {
public static void main(String [] args) {
	Scanner scanner = new Scanner(System.in);
	int nCase = Integer.parseInt(scanner.nextLine());
	
	char [][] board = new char[4][];
	char T = 'T';
	for (int nc = 1; nc <= nCase; nc++) {
		for (int i = 0; i < 4; i++) {
			board[i] = scanner.nextLine().toCharArray();
		}
		
		int state = 0;
		// Check row
		for (int i = 0; i < 4 && state == 0; i++) {
			char c = 'X';
			if ((board[i][0] == c || board[i][0] == T)
				&& (board[i][1] == c || board[i][1] == T)
				&& (board[i][2] == c || board[i][2] == T)
				&& (board[i][3] == c || board[i][3] == T))
					state = 1;
			c = 'O';
			if ((board[i][0] == c || board[i][0] == T)
				&& (board[i][1] == c || board[i][1] == T)
				&& (board[i][2] == c || board[i][2] == T)
				&& (board[i][3] == c || board[i][3] == T))
					state = 2;
		}
		
		// Check col
		for (int i = 0; i < 4 && state == 0; i++) {
			char c = 'X';
			if ((board[0][i] == c || board[0][i] == T)
				&& (board[1][i] == c || board[1][i] == T)
				&& (board[2][i] == c || board[2][i] == T)
				&& (board[3][i] == c || board[3][i] == T))
					state = 1;
			c = 'O';
			if ((board[0][i] == c || board[0][i] == T)
				&& (board[1][i] == c || board[1][i] == T)
				&& (board[2][i] == c || board[2][i] == T)
				&& (board[3][i] == c || board[3][i] == T))
					state = 2;
		}
		
		// check diag
		if (state == 0) {
			char c = 'X';
			if ((board[0][0] == c || board[0][0] == T)
				&& (board[1][1] == c || board[1][1] == T)
				&& (board[2][2] == c || board[2][2] == T)
				&& (board[3][3] == c || board[3][3] == T))
					state = 1;
			if ((board[0][3] == c || board[0][3] == T)
				&& (board[1][2] == c || board[1][2] == T)
				&& (board[2][1] == c || board[2][1] == T)
				&& (board[3][0] == c || board[3][0] == T))
					state = 1;
			c = 'O';
			if ((board[0][0] == c || board[0][0] == T)
				&& (board[1][1] == c || board[1][1] == T)
				&& (board[2][2] == c || board[2][2] == T)
				&& (board[3][3] == c || board[3][3] == T))
					state = 2;
			if ((board[0][3] == c || board[0][3] == T)
				&& (board[1][2] == c || board[1][2] == T)
				&& (board[2][1] == c || board[2][1] == T)
				&& (board[3][0] == c || board[3][0] == T))
					state = 2;
		}
		if (state == 0) {
			boolean finished = true;
			for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				if (board[i][j] == '.') {
					finished = false;
					break;
				}
			}
			if (finished)
				state = 3;
		}
		
		String ans = "Game has not completed";		
		switch (state) {
			case 1:
				ans = "X won";
				break;
			case 2:
				ans = "O won";
				break;
			case 3:
				ans = "Draw";
				break;
		}
		System.out.println("Case #" + nc + ": " + ans);
		if (nc < nCase)
			scanner.nextLine();
	}
}
}