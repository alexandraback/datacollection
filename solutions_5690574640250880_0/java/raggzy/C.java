package y2014.qualification;

import template.Runner;
import template.Solver;

import java.io.PrintStream;
import java.util.Scanner;

/**
 * Created by raggzy on 4/12/14.
 */
public class C extends Solver {
	public C(Scanner in, PrintStream out, int TC) {
		super(in, out, TC);
	}


	private boolean check00HasNeighborMine(char[][] field, int R, int C) {
		boolean hasMine = false;
		if (C > 1 && field[0][1] == '*') {
			hasMine = true;
		}
		if (R > 1 && field[1][0] == '*') {
			hasMine = true;
		}
		if (R > 1 && C > 1 && field[1][1] == '*') {
			hasMine = true;
		}
		return hasMine;
	}

	@Override
	public void solve() {
		int R = in.nextInt();
		int C = in.nextInt();
		int M = in.nextInt();
		char[][] field = new char[R][C];
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				field[r][c] = '.';
			}
		}
		field[0][0] = 'c';
		int xR = R - 1;
		int xC = C - 1;
		int cM = M;
		// putting mines in full row/col
		while (true) {
			int minX = Math.min(1 + xR, 1 + xC);
			if (cM < minX) {
				break;
			}
			if (minX == 1 + xR) {
				for (int r = 0; r <= xR; r++) {
					field[r][xC] = '*';
					cM--;
				}
				xC--;
			} else {
				for (int c = 0; c <= xC; c++) {
					field[xR][c] = '*';
					cM--;
				}
				xR--;
			}
		}
		// putting mines in last row/col
		for (int r = xR; r > 1; r--) {
			if (cM > 0 && xC > 1) {
				cM--;
				field[r][xC] = '*';
			}
		}
		for (int c = xC - 1; c > 1; c--) {
			if (cM > 0 && xR > 1) {
				cM--;
				field[xR][c] = '*';
			}
		}

		boolean impossible;
		if (cM > 0) {
			impossible = true;
		} else if (check00HasNeighborMine(field, R, C)) {
			boolean onlyOneCell = M == R * C - 1;
			impossible = !onlyOneCell;
		} else {
			impossible = false;
		}
		println("Case #%d:", TC);
		if (impossible) {
			println("Impossible");
		} else {
			for (int r = 0; r < R; r++) {
				for (int c = 0; c < C; c++) {
					out.print(field[r][c]);
				}
				out.println();
			}
		}
	}

	public static void main(String[] args) throws Exception {
		Runner.main(C.class);
	}
}
