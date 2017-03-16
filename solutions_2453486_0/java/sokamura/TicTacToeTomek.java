import java.io.File;
import java.util.Scanner;


public class TicTacToeTomek {
	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new File("A-small.in"));

		int caseNum = s.nextInt();
		for (int t = 1; t <= caseNum; ++t) {
			// game board
			char[][] board = new char[4][4];

			// read test case
			for (int i = 0; i < 4; ++i) {
				board[i] = s.next().toCharArray();
			}

			// check row
			//TicTacToeTomek.printBoard(board);
			int result = TicTacToeTomek.check(board);

			// output answer
			if (result == X_WIN) {
				System.out.println("Case #" + t + ": X won");
			}
			else if(result == O_WIN) {
				System.out.println("Case #" + t + ": O won");
			}
			else if(result == NOT_OVER) {
				System.out.println("Case #" + t + ": Game has not completed");
			}
			else {
				System.out.println("Case #" + t + ": Draw");
			}
		}

		//TicTacToeTomek.test();
	}

	private static int DRAW = 0;
	private static int X_WIN = 1;
	private static int O_WIN = 2;
	private static int NOT_OVER = 3;

	public static int check(char[][] board) {
		int sumLeftDiagonal = 0;
		int sumRIghtDiagonal = 0;
		int sumBoard = 0;
		for(int i = 0; i < 4; ++i) {
			int sumRow = 0;
			int sumColumn = 0;
			for(int j = 0; j < 4; ++j) {
				sumRow += board[i][j];
				sumColumn += board[j][i];
			}
			if (checkLine(sumRow) != DRAW) {
				return checkLine(sumRow);
			}
			else if (checkLine(sumColumn) != DRAW) {
				return checkLine(sumColumn);
			}
			sumLeftDiagonal += board[i][i];
			sumRIghtDiagonal += board[i][3-i];
			sumBoard += sumRow;
		}
		if (checkLine(sumLeftDiagonal) != DRAW) {
			return checkLine(sumLeftDiagonal);
		}
		else if (checkLine(sumRIghtDiagonal) != DRAW) {
			return checkLine(sumRIghtDiagonal);
		}

		return checkBoard(sumBoard);
	}

	public static int checkLine(int n) {
		switch(n) {
		case 'X' * 4 :
		case 'X' * 3 + 'T' :
			return X_WIN;
		case 'O' * 4 :
		case 'O' * 3 + 'T' :
			return O_WIN;
		default:
			return DRAW;
		}
	}

	public static int checkBoard(int n) {
		if (n == 8 * 'X' + 8 * 'O'
				|| n == 8 * 'X' + 7 * 'O' + 'T') {
			return DRAW;
		}
		return NOT_OVER;
	}

	public static void printBoard(char[][] board) {
		for(int i=0; i<4; ++i) {
			System.out.println(board[i]);
		}
	}

	public static void test() {
		System.out.println("X = " + (int)'X' +", O = " + (int)'O' + ", . T = " + (int)'T' + ", . = " + (int)'.');
		System.out.println("4X = " + 'X' * 4);
		System.out.println("3X+T = " + ('X' * 3 + 'T'));
		System.out.println("4O = " + 'O' * 4);
		System.out.println("3O+T = " + ('O' * 3 + 'T'));
		System.out.println("4. = " + '.' * 4);
	}
}
