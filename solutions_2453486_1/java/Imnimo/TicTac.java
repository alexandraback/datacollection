import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class TicTac {
	public static void main(String[] args) {
		Scanner s;
		try {
			s = new Scanner(new File("input.txt"));
			int count = Integer.parseInt(s.nextLine());

			for (int i = 0; i < count; i++) {
				char[][] board = new char[4][4];
				for (int row = 0; row < 4; row++) {
					String nextRow = s.nextLine();
					for (int col = 0; col < 4; col++) {
						board[row][col] = nextRow.charAt(col);
					}

				}
				String result = getResult(board);
				System.out.println("Case #" + (i+1) + ": " + result);
				//printBoard(board);
				if (s.hasNextLine()) {
					s.nextLine();
				}
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

	public static String getResult(char[][] board) {
		
		char winner = 0;
		
		boolean draw = true;
		for (int row = 0; row < 4; row++) {
			for (int col = 0; col < 4; col++) {
				if (board[row][col] == '.') {
					draw = false;
				}
			}
		}
		// rows
		char matcher = ' ';
		OUTER: for (int row = 0; row < 4; row++) {
			matcher = ' ';
			for (int col = 0; col < 4; col++) {
				if (board[row][col] != '.') {
					if (board[row][col] == 'T') {
						
					} else if (matcher == ' ') {
						matcher = board[row][col];
					} else if (matcher == board[row][col]) {
						
					} else {
						continue OUTER;
					}
				} else {
					continue OUTER;
				}
			}
			//System.out.println("VICTORY ON ROW " + row);
			return matcher + " won";
		}

		// cols
		

		OUTER: for (int col = 0; col < 4; col++) {
			matcher = ' ';
			for (int row = 0; row < 4; row++) {
				if (board[row][col] != '.') {
					if (board[row][col] == 'T') {
						
					} else if (matcher == ' ') {
						matcher = board[row][col];
					} else if (matcher == board[row][col]) {
						
					} else {
						continue OUTER;
					}
				}
				else {
					continue OUTER;
				}
			}
			//System.out.println("VICTORY ON COL " + col);
			return matcher + " won";
		}
		
		matcher = ' ';
		boolean cross = true;
		OUTER: for(int x = 0;x<4;x++) {
			if (board[x][x] != '.') {
				if (board[x][x] == 'T') {
					
				} else if (matcher == ' ') {
					matcher = board[x][x];
				} else if (matcher == board[x][x]) {
					
				} else {
					cross = false;
					break OUTER;
				}
			} else {
				cross = false;
				break OUTER;
			}
	
		}
		if(cross) {
			//System.out.println("VICTORY ON POS DIAG");
			return matcher + " won";
		}
		cross = true;
		matcher = ' ';
		OUTER: for(int x = 0;x<4;x++) {
			if (board[3-x][x] != '.') {
				if (board[3-x][x] == 'T') {
					
				} else if (matcher == ' ') {
					matcher = board[3-x][x];
				} else if (matcher == board[3-x][x]) {
					
				} else {
					cross = false;
					break OUTER;
				}
			}
			else {
				cross = false;
				break OUTER;
			}
	
		}
		if(cross) {
			//System.out.println("VICTORY ON NEG DIAG");
			return matcher + " won";
		}
		if(draw) {
			return "Draw";
		} else {
			return "Game has not completed";
		}

	}

	public static void printBoard(char[][] board) {
		for (int row = 0; row < 4; row++) {
			for (int col = 0; col < 4; col++) {
				System.out.print(board[row][col] + " ");
			}
			System.out.println();
		}
	}
}
