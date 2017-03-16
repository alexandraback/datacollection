import java.io.File;
import java.io.FileNotFoundException;
import java.util.Locale;
import java.util.Scanner;


public class ProblemA {
	
	public static void solve(Scanner sc) {
		char[][] board = new char[4][4];
		for (int i = 0; i < board.length; i++) {
			String line = sc.next();
			//for (int j = 0; j < board[i].length; j++) {
				board[i] = line.toCharArray();
			//}
		}
		for (int i = 0; i < board.length; i++) {
			if (check(board, 0, i, 1, 0)) {
				return;
			}
			if (check(board, i, 0, 0, 1)) {
				return;
			}
		} 
		
		if (check(board, 0, 0, 1, 1)) {
			return;
		}
		if (check(board, 0, 3, 1, -1)) {
			return;
		}
		
		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board.length; j++) {
				if (board[i][j] == '.') {
					System.out.println("Game has not completed");
					return;
				}
			}
		}
		System.out.println("Draw");
	}
	
	static boolean check(char[][] board, int x, int y, int dx, int dy) {
		char c = board[x][y];
		if (c == '.') {
			return false;
		}
		for (int j = 1; j < board.length; j++) {
			x += dx;
			y += dy;
			if (board[x][y] == '.') {
				return false;
			}
			if (c == 'T') {
				c = board[x][y];
			} else if (board[x][y] == 'T' || c == board[x][y]) {
				if (j == board.length - 1) {
					System.out.println(c + " won");
					return true;
				}
			} else {
				return false;
			}
		}
		return false;
	}
	
	
	
	public static void main(String[] args) throws FileNotFoundException {
//		 Scanner sc = new Scanner(new File("A-practice.in"));
//		 Scanner sc = new Scanner(new File("A-small-attempt0.in"));
		Scanner sc = new Scanner(new File("A-large.in"));
		sc.useLocale(Locale.US);
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			System.out.format(Locale.US, "Case #%d: ", i);
			solve(sc);
		}
		sc.close();
	}
}
