package qualif2013;

import java.io.*;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new FileInputStream(new File("in.txt")));
		PrintWriter out = new PrintWriter(new BufferedOutputStream(
				new FileOutputStream(new File("out.txt"))), false);
		new Solver().solve(in, out);
		out.flush();
		out.close();
	}
}

class Solver {

	protected void solve(Scanner in, PrintWriter out) throws Exception {

		int cases = in.nextInt();
		for (int k = 1; k <= cases; k++) {
			char[][] m = new char[4][4];
			for (int i = 0; i < 4; i++) {
				String line = in.next();
				for (int j = 0; j < 4; j++) {
					m[i][j] = line.charAt(j);
				}
			}

			boolean X = false;
			boolean O = false;
			boolean finish = true;

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (m[i][j] == '.')
						finish = false;
				}
			}

			int xbigdiag = 0;
			int xopdiag = 0;
			int obigdiag = 0;
			int oopdiag = 0;
			for (int i = 0; i < 4; i++) {
				if (m[i][i] == 'X') {
					xbigdiag++;
				}
				if (m[i][3 - i] == 'X') {
					xopdiag++;
				}
				if (m[i][i] == 'O') {
					obigdiag++;
				}
				if (m[i][3 - i] == 'O') {
					oopdiag++;
				}
				if (m[i][i] == 'T') {
					xbigdiag++;
					obigdiag++;
				}
				if (m[i][3 - i] == 'T') {
					xopdiag++;
					oopdiag++;
				}
				int xrow = 0;
				int orow = 0;
				int xcol = 0;
				int ocol = 0;
				for (int j = 0; j < 4; j++) {
					if (m[i][j] == 'X' || m[i][j] == 'T')
						xrow++;
					if (m[j][i] == 'X' || m[j][i] == 'T')
						xcol++;
					if (m[i][j] == 'O' || m[i][j] == 'T')
						orow++;
					if (m[j][i] == 'O' || m[j][i] == 'T')
						ocol++;
				}
				if (xrow == 4 || xcol == 4) {
					X = true;
				}
				if (orow == 4 || ocol == 4) {
					O = true;
				}
			}
			if (xbigdiag == 4 || xopdiag == 4) {
				X = true;
			}
			if (obigdiag == 4 || oopdiag == 4) {
				O = true;
			}

			if (X == true && O == false) {
				out.println(String.format("Case #%d: X won", k));
			}
			if (X == false && O == true) {
				out.println(String.format("Case #%d: O won", k));
			}
			if (X == true && O == true) {
				out.println(String.format("Case #%d: Draw", k));
			}
			if (X == false && O == false && finish == true) {
				out.println(String.format("Case #%d: Draw", k));
			}
			if (X == false && O == false && finish == false) {
				out.println(String.format("Case #%d: Game has not completed", k));
			}

		}
	}
}
