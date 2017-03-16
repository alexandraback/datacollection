import java.util.*;
import java.io.*;

public class A{
	public static boolean isFull(String[] board) {
		for(int i=0;i<board.length;i++) {
			for(int j=0;j<board[i].length();j++) {
				if(board[i].charAt(j) == '.') return false;
			}
		}
		return true;
	}
	
	public static boolean checkWin(String[] board, char player) {
		// check horizontal
		for(int i=0;i<4;i++) {
			boolean win = true;
			for(int j=0;j<4;j++) {
				if (board[i].charAt(j) != player && board[i].charAt(j) != 'T') {
					win=false;
					break;
				}
			}
			if (win) return true;
		}
		
		// check vertical
		for(int i=0;i<4;i++) {
			boolean win = true;
			for(int j=0;j<4;j++) {
				if (board[j].charAt(i) != player && board[j].charAt(i) != 'T') {
					win=false;
					break;
				}
			}
			if (win) return true;
		}
		
		// check diagonal
		boolean win = true;
		for(int i=0;i<4;i++) {
			if (board[i].charAt(i) != player && board[i].charAt(i) != 'T') {
				win=false;
				break;
			}
		}
		if (win) return true;
		win = true;
		for(int i=0;i<4;i++) {
			if (board[i].charAt(4-i-1) != player && board[i].charAt(4-i-1) != 'T') {
				win=false;
				break;
			}
		}
		if (win) return true;
		
		return false;
	}
	
	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(System.in);
		
		int T = Integer.parseInt(in.nextLine());
		
		for(int caseNo=1;caseNo<=T;caseNo++){
			String[] board = new String[4];
			for(int i=0;i<4;i++) {
				board[i] = in.nextLine();
			}
			in.nextLine();
			
					
			boolean xwin = checkWin(board, 'X');
			boolean owin = checkWin(board, 'O');
			boolean full = isFull(board);
			
			if ((xwin && owin) || (full && !xwin && !owin)) {
				System.out.printf("Case #%d: %s\n", caseNo, "Draw");
			} else if (xwin) {
				System.out.printf("Case #%d: %s\n", caseNo, "X won");
			} else if (owin) {
				System.out.printf("Case #%d: %s\n", caseNo, "O won");
			} else {
				System.out.printf("Case #%d: %s\n", caseNo, "Game has not completed");
			}
			
		}
	}
}