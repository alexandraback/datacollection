import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class X {
	public static void main(String[] args) throws FileNotFoundException {
		new X().run();
	}
	
	private static final String RICHARD = "RICHARD";
	private static final String GABRIEL = "GABRIEL";
	
	private static final String FILE = "../D-small-attempt0";
	
	private Scanner scanner;
	private PrintWriter out;
	
	void run() throws FileNotFoundException {
		scanner = new Scanner(new File(FILE + ".in"));
		out = new PrintWriter(new File(FILE + ".out"));
		
		int n = scanner.nextInt();
		for (int i = 1; i <= n; i++) {
			solve(i);
		}
		
		scanner.close();
		out.close();
	}
	
	void solve(int index) {
		int x = scanner.nextInt();
		int r = scanner.nextInt();
		int c = scanner.nextInt();
		
		out.println("Case #" + index + ": " + solve1(x, r, c));
	}
	
	public String solve1(int x, int r, int c) {
		if (r > c) {
			int a = c;
			c = r;
			r = a;
		}
		
		// out.println(x + " " + r + " " + c);
		
		if ((r * c) % x != 0) {
			// Richard could automatically win
			return RICHARD;
		}
		
		if (x >= c + 1) {
			// Richard could give "I" shape bar to win
			return RICHARD;
		}
		
		if (x >= 2 * r + 1) {
			// Richard could give "L" shape to win
			return RICHARD;
		}
		
		if (x >= 7) {
			// Richard could give "O" shape to win
			return RICHARD;
		}
		
		if (x == 1 || x == 2) {
			// 1x1 or 1x2 can always fill the field as long as the number of cells matches
			return GABRIEL;
		}
		
		if (x <= r + 1) {
			// The block is too small to restrict Gabriels's choice
			return GABRIEL;
		}
		
		if (r == 2) {
			if (x == 4) {
				// Rechard could give "T" shape to win
				return RICHARD;
			}
			if (x == 3) {
				return GABRIEL;
			}
		}
		
		if (r == 3) {
			if (x == 5) {
				return GABRIEL;
			}
			if (x == 6) {
				return RICHARD; // "T" shape
			}
		}
		
		if (r == 4) {
			if (x == 6) {
				return GABRIEL;
			}
		}
		
		return "?"; // TODO
	}
}

