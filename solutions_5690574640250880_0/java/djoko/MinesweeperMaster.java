import java.util.ArrayList;
import java.util.Scanner;


public class MinesweeperMaster {
	
	int board[][], r, c, total;
	
	public void solve(int r, int c, int m) {
		this.r = r;
		this.c = c;
		this.total = r * c - m;
		board = new int[r + 2][c + 2];
		
		if (total == 1) {
			printSolutionSpecialCase();
			return;
		}
		
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if (find(i, j)) {
					printSolution();
					return;
				}
			}
		}
		System.out.println("Impossible");
	}
	
	private boolean find(int row, int col) {
		board[row][col] = 1;
		
		int area = 0;
		ArrayList<Loc> candidates = new ArrayList<Loc>();
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if (board[i][j] > 0) {
					area++;
				}
				else {
					if (board[i - 1][j - 1] > 0 ||
							board[i - 1][j] > 0 ||
							board[i - 1][j + 1] > 0 ||
							board[i][j - 1] > 0 ||
							board[i][j + 1] > 0 ||
							board[i + 1][j - 1] > 0 ||
							board[i + 1][j] > 0 ||
							board[i + 1][j + 1] > 0) {
						area++;
						if (i > 0 && i <= r && j > 0 && j <= c)
							candidates.add(new Loc(i, j));
					}
				}
			}
		}
		
		if (area == total)
			return true;
		
		if (area < total) {
			for (Loc candidate : candidates) {
				if (find(candidate.row, candidate.col)) {
					return true;
				}
			}
		}

		board[row][col] = 0;
		return false;
	}
	
	private void printSolution() {
		boolean printed = false;
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if (board[i][j] > 0) {
					if (printed) {
						System.out.print('.');
					}
					else {
						System.out.print('c');
						printed = true;
					}
				}
				else {
					if (board[i - 1][j - 1] > 0 ||
							board[i - 1][j] > 0 ||
							board[i - 1][j + 1] > 0 ||
							board[i][j - 1] > 0 ||
							board[i][j + 1] > 0 ||
							board[i + 1][j - 1] > 0 ||
							board[i + 1][j] > 0 ||
							board[i + 1][j + 1] > 0) {
						System.out.print('.');
					}
					else {
						System.out.print('*');
					}
				}
			}
			System.out.println();
		}
	}
	
	private void printSolutionSpecialCase() {
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if (i == 1 && j == 1) {
					System.out.print('c');
				}
				else {
					System.out.print('*');
				}
			}
			System.out.println();
		}
	}
	
	static class Loc {
		int row, col;
		
		public Loc(int r, int c) {
			row = r; col = c;
		}
	}
	
	public void process() {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++) {
			System.out.println("Case #" + (i + 1) + ":");
			solve(sc.nextInt(), sc.nextInt(), sc.nextInt());
		}
	}
	
	public static void main(String args[]) {
		MinesweeperMaster mm = new MinesweeperMaster();
		mm.process();
	}
}
