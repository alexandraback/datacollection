package y2013.q;
import static java.util.Arrays.deepToString;
import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.util.Scanner;

public class A {
	Scanner sc = new Scanner(System.in);
	char [][] grid = new char[4][4];
	boolean dotFound = false;
	void read() {
		dotFound = false;
		for (int i = 0; i < grid.length; i++) {
			String line = sc.nextLine();
			for (int j = 0; j < grid.length; j++) {
				grid[i][j] = line.charAt(j);
				if(grid[i][j] == '.') dotFound = true;
			}
		}
		sc.nextLine();
	}

	void solve() {
		boolean xWon = false;
		boolean yWon = false;
		// Check lines
		for (int i = 0; i < grid.length; i++) {
			int x = 0;
			int y = 0;
			for (int j = 0; j < grid.length; j++) {
				if(grid[i][j] == 'X') x++;
				if(grid[i][j] == 'O') y++;
				if(grid[i][j] == 'T') {
					x++; y++;
				}
			}
			if(x == 4) xWon = true;
			if(y == 4) yWon = true;
		}
		// Check columns
		for (int i = 0; i < grid.length; i++) {
			int x = 0;
			int y = 0;
			for (int j = 0; j < grid.length; j++) {
				if(grid[j][i] == 'X') x++;
				if(grid[j][i] == 'O') y++;
				if(grid[j][i] == 'T') {
					x++; y++;
				}
			}
			if(x == 4) xWon = true;
			if(y == 4) yWon = true;
		}
		// Check diagonals

			int x = 0;
			int y = 0;
			for (int j = 0; j < grid.length; j++) {
				if(grid[j][j] == 'X') x++;
				if(grid[j][j] == 'O') y++;
				if(grid[j][j] == 'T') {
					x++; y++;
				}
			}
			if(x == 4) xWon = true;
			if(y == 4) yWon = true;
			
			x = 0;
			y = 0;
			int rev = 3;
			for (int j = 0; j < grid.length; j++) {
				if(grid[j][rev] == 'X') x++;
				if(grid[j][rev] == 'O') y++;
				if(grid[j][rev] == 'T') {
					x++; y++;
				}
				rev--;
			}
			if(x == 4) xWon = true;
			if(y == 4) yWon = true;
			
			if(xWon) {
				System.out.println("X won");
			} else if(yWon) {
				System.out.println("O won");
			} else if(!dotFound) {
				System.out.println("Draw");
			} else {
				System.out.println("Game has not completed");
			}
	}
	
	void display() {
		for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid.length; j++) {
				System.out.print(grid[i][j]);
			}
			System.out.println();
		}
	}

	void run() {
		int caseN = sc.nextInt();
		sc.nextLine();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			read();
			System.out.printf("Case #%d: ", caseID);
			solve();
			System.out.flush();
		}
	}

	void debug(Object... os) {
		System.err.println(deepToString(os));
	}

	public static void main(String[] args) {
		try {
			System.setIn(new BufferedInputStream(new FileInputStream(
					args.length > 0 ? args[0] : (A.class.getName() + ".in"))));
		} catch (Exception e) {
		}
		new A().run();
	}
}
