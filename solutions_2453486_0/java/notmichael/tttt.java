import java.util.*;

public class tttt {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = Integer.parseInt(in.nextLine());
		for (int i=0; i<cases; i++) {
			char[][] board = new char[4][4];
			for (int j=0; j<4; j++) {
				board[j] = in.nextLine().toCharArray();
			}
			char won = '.';
			boolean fin = false;
			for (int j=0; j<4; j++) {
				int check = 0;
				if (board[j][0]=='T') {
					check = 1;
				}
				if (same(board[j][check],board[j][0]) && same(board[j][check],board[j][1]) && same(board[j][check],board[j][2]) && same(board[j][check],board[j][3])) {
					won = board[j][check];
					fin = true;
					break;
				}
			}
			if (!fin) {
				for (int j=0; j<4; j++) {
					int check = 0;
					if (board[0][j]=='T') {
						check = 1;
					}
					if (same(board[check][j],board[0][j]) && same(board[check][j],board[1][j]) && same(board[check][j],board[2][j]) && same(board[check][j],board[3][j])) {
						won = board[check][j];
						fin = true;
						break;
					}
				}
			}
			if (!fin) {
				for (int j=0; j<2; j++) {
					if (same(board[0][3*j], board[1][1+j]) && same(board[0][3*j], board[2][2-j]) && same(board[0][3*j], board[3][3-3*j]) && same(board[2][2-j], board[3][3-3*j]) && same(board[1][1+j], board[3][3-3*j])) {
						if (board[0][3*j]!='T') {
							won = board[0][3*j];
						}
						else {
							won = board[1][1+j];
						}
						fin = true;
						break;
					}
				}
			}
			if (won == 'X') {
				System.out.println("Case #" + (i+1) + ": X won");
			}
			else if (won == 'O') {
				System.out.println("Case #" + (i+1) + ": O won");
			}
			else {
				boolean done = true;
				for (int j=0; j<4; j++) {
					for (int k=0; k<4; k++) {
						if (board[j][k]=='.') {
							done = false;
						}
					}
				}
				if (done) {
					System.out.println("Case #" + (i+1) + ": Draw");
				}
				else {
					System.out.println("Case #" + (i+1) + ": Game has not completed");
				}
			}
			if(i!=cases-1) {
				in.nextLine();
			}
		}
	}
	
	private static boolean same(char a, char b) {
		if (a==b && a!='.') {
			return true;
		}
		else if (a=='T' && b!='.') {
			return true;
		}
		else if (b=='T' && a!='.') {
			return true;
		}
		else {
			return false;
		}
	}

}
