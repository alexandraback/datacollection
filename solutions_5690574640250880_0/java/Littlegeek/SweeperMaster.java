package codeJam2014;
import java.util.Scanner;
import java.io.*;

public class SweeperMaster {

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File(args[0]));
		FileWriter out = new FileWriter("minesout.txt");
		int T = in.nextInt();
		
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			int R = in.nextInt();
			int C = in.nextInt();
			int M = in.nextInt();
			int r = 0, c = 0; //indexes
			int m = M; //counter
			
			char field[][] = new char[R][C];
			if (R == 1 || C == 1) {
				m = 0;
				field = oneLine(R,C,M);
			}
			else if (M == R * C - 1) {
				m = 0;
				field = oneSpace(R,C);
			}
			else if ((R == 2 || C == 2) && (M % 2 == 1 || R * C - M < 4)) {
				m = -1;
				out.write("Case #" + caseNum + ":\nImpossible\n");
			}
			else if (R == 2) {
				field[0] = oneLine(1, C, M / 2)[0];
				field[1] = oneLine(1, C, M / 2)[0];
				m = 0;
			}
			else if (C == 2) {
				char line[][] = oneLine(R, 1, M / 2);
				for (;r < R; r++) {
					field[r][0] = line[r][0];
					field[r][1] = line[r][0];
				}
				m = 0;
			}
			else if (M == R * C) {
				m = -1;
				out.write("Case #" + caseNum + ":\nImpossible\n");
			}
			else {
				field = fill(R, C);
				while (R - r > 3 && m >= C) {
					for (c = 0; c < C && m > 0; c++) {
						field[r][c] = '*';
						m--;
					}
					c = 0;
					r++;
				}
				if (m < c - 1 || R - r > 3) {
					while (m > 0 && c < C - 2) { //sneak another row
						field[r][c++] = '*';
						m--;
					}
					r++;
					c = 0;
				}
				int resetR = r;
				while (m / (R-r) > 0 && C - c > 2) {
					while (r < R) {
						field[r++][c] = '*';
						m--;
					}
					c++;
					r = resetR;
				}
				
				if (m < R - r - 2) {
					for (; m > 0; m--) {
						field[r++][c] = '*';
					}
				}
				
				if (m == C - c) {
					for (int i = c; i < C; i++) {
						field[r][i] = '*';
					}
					m = 0;
				} else if (m <= C - c - 2) {
					for (int i = c; i < C && m > 0; i++) {
						field[r][i] ='*';
						m--;
					}
				} else {
					out.write("Case #" + caseNum + ":\nImpossible\n");
					System.out.println("R: " + R + "  C: " + C + "  M: " + M);
				}
			}
			
			field [R-1][C-1] = 'c';
			if (m==0) {
				out.write("Case #" + caseNum + ":\n");
				for (char[] s:field) {
					out.write(String.copyValueOf(s) + "\n");
				}
			}
		}
		in.close();
		out.close();

	}

	
	public static char[][] oneSpace(int R, int C) {
		char[][] field = new char[R][C];
		for (int r = 0; r < R; r++)
			for (int c = 0; c < C; c++)
				field[r][c] = '*';
		return field;
	}
	
	public static char[][] oneLine(int R, int C, int M) {
		char[][] field = new char[R][C];
		for (int r = 0; r < R; r++)
			for (int c = 0; c < C; c++) {
				field[r][c] = (M-- > 0) ? '*' : '.';
			}
		return field;
	}
	
	public static char[][] fill(int R, int C) {
		char[][] field = new char[R][C];
		for (int r = 0; r < R; r++)
			for (int c = 0; c < C; c++) field[r][c] = '.';
		return field;
	}
}
