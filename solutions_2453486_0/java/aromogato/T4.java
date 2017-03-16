import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class T4 {
	static final short E = 0;
	static final short X = 1;
	static final short O = 2;
	static final short T = 3;
	static int unfilled = 16;
	
	static short board[][];
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("src/input"));
		board = new short[4][4];
		
		int trials = in.nextInt();
		
		for (int i = 1; i <= trials; i++) {
			readBoard(in);
			boolean xWon = checkBoard(X);
			boolean yWon = checkBoard(O);
			
			if(xWon) {
				System.out.println("Case #" + i + ": X won");
			} else if(yWon) {
				System.out.println("Case #" + i + ": O won");
			} else if(unfilled == 16) {
				System.out.println("Case #" + i + ": Draw");
			} else {
				System.out.println("Case #" + i + ": Game has not completed");
			}
		}
	}
	
	public static boolean checkBoard(short playa) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if ((board[i][j] & playa) == 0) break;
				if (j == 3) return true;
			}
		}
		
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if ((board[j][i] & playa) == 0) break;
				if (j == 3) return true;
			}
		}
		
		for (int i = 0; i < 4; i++) {
				if ((board[i][i] & playa) == 0) break;
				if (i == 3) return true;
		}
		
		for (int i = 0; i < 4; i++) {
			if ((board[i][4-i-1] & playa) == 0) break;
			if (i == 3) return true;
		}
		
		return false;
	}
	
	public static void readBoard(Scanner in) {
		char line[];
		unfilled = 16;
		for(int i = 0; i < 4; i++) {
			line = in.next().toCharArray();
			for(int j = 0; j < 4; j++) {
				switch(line[j]) {
				case 'X':
					board[i][j] = X;
					break;
				case 'O':
					board[i][j] = O;
					break;
				case '.':
					board[i][j] = E;
					unfilled--;
					break;
				case 'T':
					board[i][j] = T;
					break;
				}
			}
		}
	}

}
