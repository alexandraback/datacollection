import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

public class A {

	final static String PREFIX = ".\\src\\A";
//	final static String FILE_NAME = PREFIX + "-test";
//	final static String FILE_NAME = PREFIX + "-small-attempt0";
	final static String FILE_NAME = PREFIX + "-large";

	private Scanner in;
	private PrintWriter out;

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new A().solveAll();
	}

	private void solveAll() throws Exception {
		in = new Scanner(new File(FILE_NAME + ".in"));
		out = new PrintWriter(new File(FILE_NAME + ".out"));
		int tcn = in.nextInt();
		for (int tc = 1; tc <= tcn; tc++) {
			solve(tc);
		}
		out.close();
	}

	String r[] = new String[4];

	private void solve(int tc) {
		for(int i = 0; i < 4; i++) {
			String x = in.next();
			r[i] = x;
		}
		String res;
		if (isWonBy('X')) {
			res = "X won";
		} else if(isWonBy('O')) {
			res = "O won";
		} else if(isFinished()) {
			res = "Draw";
		} else {
			res = "Game has not completed";
		}
		
		print("Case #%d: %s\n", tc, res);
	}
	
	private boolean isFinished() {
		for(String s : r) {
			if(s.contains(".")) return false;
		}
		return true;
	}

	private boolean isWonBy(char player) {
		//check rows & cols
		for(int i = 0; i < 4; i++) {
			boolean matchedRow = true;
			boolean matchedCol = true;
			for(int j = 0; j < 4; j++) {
				if(isNot(player, i, j)) {
					matchedRow = false;
				}
				if(isNot(player, j, i)) {
					matchedCol = false;
				}
			}
			if(matchedRow || matchedCol) return true;
		}
		//check diag
		boolean matchedDiag1 = true;			
		boolean matchedDiag2 = true;			
		for(int i = 0; i < 4; i++) {
			if(isNot(player, i, i)) {
				matchedDiag1 = false;
			}
			if(isNot(player, i, 3-i)) {
				matchedDiag2 = false;
			}
		}
		return matchedDiag1 || matchedDiag2;
	}

	private boolean isNot(char player, int i, int j) {
		char c = r[i].charAt(j);
		return c != 'T' && c != player;
	}

	private void print(String format, Object ... args) {
		out.format(format, args);
		System.out.format(format, args);
	}
}
