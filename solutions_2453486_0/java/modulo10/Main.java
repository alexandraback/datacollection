
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) {
		InputStream in = System.in;
		PrintStream out = System.out;
		if (args.length > 0) {
			try {
				in = new FileInputStream(args[0]);
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}
		Scanner scanner = new Scanner(in);
		int cases = scanner.nextInt();
		scanner.nextLine();
		for (int i = 1; i <= cases; ++i) {
			
			out.format("Case #%d: ",i);
			//out.println();
			
			char[][] lines = new char[4][];
			lines[0] = scanner.nextLine().toCharArray();
			lines[1] = scanner.nextLine().toCharArray();
			lines[2] = scanner.nextLine().toCharArray();
			lines[3] = scanner.nextLine().toCharArray();
			scanner.nextLine();
			
			if (check(lines, 'X')) {
				out.println("X won");
			} else if (check(lines, 'O')) {
				out.println("O won");
			} else if (checkDraw(lines)) {
				out.println("Draw");
			} else {
				out.println("Game has not completed");
			}
			
		}
	}
	
	private static boolean check(char[][] lines, char user) {
		return checkHor(lines, user) || checkVer(lines, user) || checkDia(lines, user);
	}
	
	private static boolean checkHor(char [][] lines, char val) {
		for (int i = 0; i < 4; i++) {
			boolean good = true;
			for (int j = 0; j < 4 && good; j++) {
				if (lines[i][j] != val && lines[i][j] != 'T')
					good = false;
			}
			if (good) 
				return true;
		}
		return false;
	}
	
	private static boolean checkVer(char [][] lines, char val) {
		for (int i = 0; i < 4; i++) {
			boolean good = true;
			for (int j = 0; j < 4 && good; j++) {
				if (lines[j][i] != val && lines[j][i] != 'T')
					good = false;
			}
			if (good) 
				return true;
		}
		return false;
	}
	
	private static boolean checkDia(char[][] lines, char val) {
		boolean good = true;
		for (int i = 0; i < 4; i++) {
			if (lines[i][i] != val && lines[i][i] != 'T')
				good = false;
		}
		if (good) return true;
		good = true;
		for (int i = 0; i < 4; i++) {
			if (lines[3-i][i] != val && lines[3-i][i] != 'T')
				good = false;
		}
		return good;
	}
	
	private static boolean checkDraw(char[][] lines) {
		boolean good = true;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4 && good; j++) {
				if (lines[i][j] == '.')
					good = false;
			}
		}
		return good;
	}
}
