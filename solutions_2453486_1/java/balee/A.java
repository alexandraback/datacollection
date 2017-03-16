import java.io.FileInputStream;
import java.util.Scanner;

// Tic-Tac-Toe-Tomek
// https://code.google.com/codejam/contest/2270488/dashboard#s=p0

public class A {

	private static String process(Scanner in) {

		String[] table = new String[4];
		String str = "";
		
		// load table
		for(int row = 0; row < 4; row++) {
			table[row] = in.next();
			str += table[row] + " ";
		}
		
		// Add cols
		for(int col = 0; col < 4; col++) { 
			for(int row = 0; row < 4; row++) 
				str += table[row].charAt(col);
			str += " ";
		}
		
		// Add diagonals
		for(int i = 0; i < 4; i++)
			str += table[i].charAt(i);
		str += " ";
		for(int i = 0; i < 4; i++)
			str += table[3-i].charAt(i);

		// Check result
		if ( str.replace("T", "X").contains("XXXX") )
			return "X won";
		if ( str.replace("T", "O").contains("OOOO") )
			return "O won";
		if ( ! str.contains(".") )
			return "Draw";
		return "Game has not completed";
		
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in.available() > 0 ? System.in : 
			new FileInputStream(Thread.currentThread().getStackTrace()[1].getClassName() + ".practice.in"));
		int T = in.nextInt();
		for(int i = 1; i <= T; i++) 
			System.out.format("Case #%d: %s\n", i, process(in));
	}
}
