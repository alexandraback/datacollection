import java.util.*;
public class A {
	public static void main (String [] arg) {
		Scanner sc = new Scanner(System.in);
		int T = Integer.parseInt(sc.nextLine());
		for (int ii = 1; ii<=T; ++ii) {
			char [][] board = new char [4][];
			for (int i = 0; i<4; ++i)
				board[i] = sc.next().toCharArray();
			boolean emptySpace = false;
			for (int i = 0; i<4; ++i) for (int j = 0; j<4; ++j) if (board[i][j] == '.') emptySpace = true;
			
			//Row
			char winner = (char)0;
			for (int i = 0; i<4; ++i) {
				char tmp = verdict(board[i]);
				if (tmp != 0) winner = tmp;
			}
			
			//Column
			for (int i = 0; i<4; ++i) {
				char tmp = verdict(board[0][i], board[1][i], board[2][i], board[3][i]);
				if (tmp != 0) winner = tmp;
			}
			
			//Diagonal
			char tmpD1 = verdict(board[0][0], board[1][1], board[2][2], board[3][3]);
			char tmpD2 = verdict(board[3][0], board[2][1], board[1][2], board[0][3]);
			if (tmpD1 != 0) winner = tmpD1;
			if (tmpD2 != 0) winner = tmpD2;
			
			String ans = "";
			if (winner == 'X') ans = "X won";
			if (winner == 'O') ans = "O won";
			if (winner == 0) ans = (emptySpace) ? "Game has not completed" : "Draw";
			
			//Something
			System.out.printf("Case #%d: %s\n",ii,ans);
		}
	}
	public static char verdict(char ... stuff) {
		char [] tmp = new char [256];
		for (char c : stuff) tmp[c]++;
		if (tmp['X'] == 3 && tmp['T'] == 1) return 'X';
		if (tmp['X'] == 4) return 'X';
		if (tmp['O'] == 3 && tmp['T'] == 1) return 'O';
		if (tmp['O'] == 4) return 'O';
		return (char)0;
	}
}