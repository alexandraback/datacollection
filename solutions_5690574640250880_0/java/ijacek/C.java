package R0;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Locale;
import java.util.Scanner;

// Minesweeper Master
public class C {

	private static Scanner sc;
	private static PrintStream out;

	static boolean poss(int R, int C, int M) {
		if ( R == 1 )
			return true;
		if ( C == 1 )
			return true;
		if ( M == 0 )
			return true;
		int d = R * C - M;
		if ( d == 1 )
			return true;
		if ( d == 2 )
			return false;
		if ( d == 3 )
			return false;
		if ( d == 4 )
			return true;
		if ( d == 5 )
			return false;
		if ( d == 7 )
			return false;

		if ( Math.min(R, C) == 2 )
			return (M & 1) == 0;

		return true;
	}

	private static void solve(int TC) {
		out.println(String.format("Case #%d:", TC));
		int R = ni();
		int C = ni();
		int M = ni();

		sol(R, C, M);
	}

	private static void sol(int R, int C, int M) {
		if ( !poss(R, C, M) ) {
			out.println("Impossible");
			return;
		}

		boolean full = (R * C - M) == 1;
		int minC = C;
		for (int i = 0; i < R; i++) {
			int remR = R - i;
			for (int j = 0; j < C; j++) {
				int remC = C - j;
				if ( remC == 1 && remR == 1 ) {
					out.print('c');
					continue;
				}
				if ( M == 0 ) {
					out.print('.');
					continue;
				}
				if ( full || C < 3 ) {
					out.print('*');
					M--;
					continue;
				}
				if ( j >= minC ) {
					out.print('.');
					continue;
				}
				if ( remR > 3 ) {
					if ( M == 1 && remC == 2 ) {
						minC = j;
						out.print('.');
						continue;
					}
				}
				if ( remR == 3 ) {
					if ( (M & 1) == 0 && remC == 3 ) {
						minC = j;
						out.print('.');
						continue;
					}
				}
				if ( remR == 2 ) {
					if ( M <= j ) {
						out.print('.');
						continue;
					}
				}
				out.print('*');
				M--;
			}
			out.println();
		}
	}

	public static void main(String[] args) throws FileNotFoundException {
		Locale.setDefault(Locale.ENGLISH);

		String file = "tst/R0/C.sm";
		sc = new Scanner(new FileInputStream(file + ".in"));
		out = new PrintStream(file + ".out");

		int TC = ni();
		for (int i = 1; i <= TC; i++)
			solve(i);
	}

	private static int ni() {
		return sc.nextInt();
	}
}
