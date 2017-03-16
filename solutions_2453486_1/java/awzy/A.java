import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
	public static void main(String[] args) throws IOException {
		String name = "A-large";
		Scanner sc = new Scanner(new File(name + ".in"));
		//Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new FileWriter(name + ".out"));
		int n = sc.nextInt();
		for (int c = 1; c <= n; c++) {
			String board = "";
			sc.nextLine();
			for (int i = 0; i < 4; i++) {
				board += sc.nextLine();
			}
			if (win(board, 'X')) {
				out.println("Case #" + c + ": " + "X won");
				//System.out.println("Case #" + c + ": " + "X won");

			} else if (win(board, 'O')) {
				out.println("Case #" + c + ": " + "O won");
				//System.out.println("Case #" + c + ": " + "O won");

			} else {
				boolean completed = true;
				for (int i = 0; i < 16; i++) {
					if (board.charAt(i) == '.') {
						out.println("Case #" + c + ": "
								+ "Game has not completed");
						//System.out.println("Case #" + c + ": "
						//		+ "Game has not completed");
						completed = false;
						break;
					}
				}
				if (completed) {
					out.println("Case #" + c + ": " + "Draw");
					//System.out.println("Case #" + c + ": " + "Draw");
				}
			}
		}
		out.close();
		sc.close();
	}

	public static boolean win(String board, char player) {
		hor: for (int i = 0; i < 16; i += 4) {
			for (int j = i; j < i + 4; j++) {
				if (board.charAt(j) != player && board.charAt(j) != 'T')
					continue hor;
			}
			return true;
		}
		vert: for (int i = 0; i < 4; i++) {
			for (int j = i; j < 16; j += 4) {
				if (board.charAt(j) != player && board.charAt(j) != 'T')
					continue vert;
			}
			return true;
		}
		boolean diag1 = true, diag2 = true;
		for (int j = 0; j < 16; j += 5) {
			if (board.charAt(j) != player && board.charAt(j) != 'T')
				diag1 = false;
		}
		for (int j = 3; j < 13; j += 3) {
			if (board.charAt(j) != player && board.charAt(j) != 'T')
				diag2 = false;
		}
		return diag1 || diag2;
	}
}
