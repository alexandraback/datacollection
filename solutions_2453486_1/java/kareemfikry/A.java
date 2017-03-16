import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {

	public static boolean X_Won(String row) {
		if (row.equals("TXXX") || row.equals("XTXX") || row.equals("XXTX")
				|| row.equals("XXXT") || row.equals("XXXX")) {
			return true;
		}
		return false;
	}

	public static boolean O_Won(String row) {
		if (row.equals("TOOO") || row.equals("OTOO") || row.equals("OOTO")
				|| row.equals("OOOT") || row.equals("OOOO")) {
			return true;
		}
		return false;
	}


	public static void main(String[] args) throws FileNotFoundException {
		
		Scanner r = new Scanner(new FileReader("A-large (2).in"));
		PrintWriter pw = new PrintWriter("A1.out");
		
		int t = r.nextInt();
		int cases = 0;
		while (t-- > 0) {
			char[][] g = new char[4][4];

			boolean dot = false;
			for (int i = 0; i < 4; i++) {
				g[i] = r.next().toCharArray();
				if (new String(g[i]).contains(".")) {
					dot = true;
				}
			}

			boolean X = false, O = false;
			for (int i = 0; i < 4; i++) {
				String row = new String(g[i]);
				if (X_Won(row)) {
					X = true;
				}
				if (O_Won(row)) {
					O = true;
				}
			}

			for (int j = 0; j < 4; j++) {
				String col = "";
				for (int i = 0; i < 4; i++) {
					col += g[i][j];
				}
				if (X_Won(col)) {
					X = true;
				}
				if (O_Won(col)) {
					O = true;
				}
			}

			String diagonal = "";
			for (int i = 0; i < 4; i++) {
				diagonal += g[i][i];
			}
			if (X_Won(diagonal)) {
				X = true;
			}
			if (O_Won(diagonal)) {
				O = true;
			}

			String right_diagonal = "";
			for (int i = 0; i < 4; i++) {
				right_diagonal += g[i][4 - (i + 1)];
			}
			if (X_Won(right_diagonal)) {
				X = true;
			}
			if (O_Won(right_diagonal)) {
				O = true;
			}

			pw.printf("Case #%d: ", ++cases);
			if (X && O) {
				pw.println("Draw");
			} else if (X) {
				pw.println("X won");
			} else if (O) {
				pw.println("O won");
			} else {
				if (!dot) {
					pw.println("Draw");
				} else {
					pw.println("Game has not completed");
				}
			}

		}
		pw.flush();
		pw.close();

	}

}