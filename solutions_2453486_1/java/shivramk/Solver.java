package net.shivramk;

public class Solver {
	private char board[][] = new char[4][];
	private int curLine = 0;
	private int dotCount = 0;
	
	public Solver() {
		for (int i = 0; i < 4; ++i) {
			board[i] = new char[4];
		}
	}
	
	public void addLine(String nextLine) {
		for (int i = 0; i < 4; ++i) {
			board[curLine][i] = nextLine.charAt(i);
			if (nextLine.charAt(i) == '.') {
				dotCount++;
			}
		}
		curLine++;
	}

	public void solve() {
		for (int i = 0; i < 4; ++i) {
			if (countRow(i, 'X') == 4) {
				System.out.println("X won");
				return;
			} else if (countRow(i, 'O') == 4) {
				System.out.println("O won");
				return;
			}
		}
		for (int i = 0; i < 4; ++i) {
			if (countCol(i, 'X') == 4) {
				System.out.println("X won");
				return;
			} else if (countCol(i, 'O') == 4) {
				System.out.println("O won");
				return;
			}
		}
		if (countDiag1('X') == 4 || countDiag1('X') == 4) {
			System.out.println("X won");
		} else if (countDiag1('O') == 4 || countDiag2('O') == 4) {
			System.out.println("O won");
		} else if (dotCount == 0) {
			System.out.println("Draw");
		} else {
			System.out.println("Game has not completed");
		}
	}

	private int countDiag1(char c) {
		int count = 0;
		for (int j = 0; j < 4; ++j) {
			char ch = board[j][j];
			if (ch == c || ch == 'T') {
				count ++;
			}
		}
		return count;
	}
	
	private int countDiag2(char c) {
		int count = 0;
		for (int j = 0; j < 4; ++j) {
			char ch = board[j][3-j];
			if (ch == c || ch == 'T') {
				count ++;
			}
		}
		return count;
	}

	private int countRow(int i, char c) {
		int count = 0;
		for (int j = 0; j < 4; ++j) {
			char ch = board[i][j];
			if (ch == c || ch == 'T') {
				count ++;
			}
		}
		return count;
	}
	
	private int countCol(int j, char c) {
		int count = 0;
		for (int i = 0; i < 4; ++i) {
			char ch = board[i][j];
			if (ch == c || ch == 'T') {
				count ++;
			}
		}
		return count;
	}

}
