package qualifiers;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	final static Boolean DEBUG_ENABLE = true;
	final static Boolean TIMER_ENABLE = true;

	final static String FILE_NAME = "C-large";// <<<--------

	final static String BASE = "C:/CodeJam/" + FILE_NAME;
	final static String INPUT = BASE + ".in";
	final static String OUTPUT = BASE + ".out";
	static Scanner in;
	static PrintWriter out;

	public static void main(String[] args) {
		try {
			in = new Scanner(new FileReader(INPUT));
			out = new PrintWriter(OUTPUT);

			int number_of_cases = in.nextInt();
			in.nextLine();
			for (int c = 0; c < number_of_cases; c++) {
				out.println("Case #" + (c + 1) + ": ");

				if (DEBUG_ENABLE)
					System.out.println("Solving case " + (c + 1) + "...");
				if (TIMER_ENABLE) {
					long startTime = System.currentTimeMillis();
					caseSolver();
					long endTime = System.currentTimeMillis();
					System.out.println((endTime - startTime) + " ms");
				} else
					caseSolver();

				out.println();
			}
			out.println();
			out.flush();
			out.close();
			in.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	private static void caseSolver() {
		int R = in.nextInt();
		int C = in.nextInt();
		int M = in.nextInt();
		boolean isImpossible = false;
		char[][] solution = new char[R][C];

		for (char[] row : solution)
			// all blank spots at start
			Arrays.fill(row, '.');

		if (M == 0) {// trivial solution (no mines)
			solution[0][0] = 'c';
		} else if (M == R * C - 1) {// trivial solution (only 1 free spot)
			for (char[] row : solution)
				Arrays.fill(row, '*');
			solution[0][0] = 'c';
		} else if (C == 1 || R == 1) {// row or column matrix
			solution[0][0] = 'c';
			if (C != R) {
				if (R == 1) {
					for (int i = C - M; i < C; i++) {
						solution[0][i] = '*';
					}
				} else if (C == 1) {
					for (int i = R - M; i < R; i++) {
						solution[i][0] = '*';
					}
				}
			}
		} else if (C == 2 || R == 2) {// 2 rows or 2 columns case
			if (C == R) {
				isImpossible = true;// only trivial cases for 2x2
				out.print("Impossible");
			} else {
				if (M % 2 == 1 || R * C - M == 2) {// can't have 1 square corner
													// nor only 2 spots left
					isImpossible = true;
					out.print("Impossible");
				} else {
					if (R == 2) {
						for (int i = C - M / 2; i < C; i++) {
							solution[0][i] = '*';
							solution[1][i] = '*';
						}
					} else if (C == 2) {
						for (int i = R - M / 2; i < R; i++) {
							solution[i][0] = '*';
							solution[i][1] = '*';
						}
					}
					solution[0][0] = 'c';
				}
			}
		} else {
			int v = R * C - M;
			if (v == 2 || v == 3 || v == 5 || v == 7) {
				isImpossible = true;// impossible cases for C, R > 2
				out.print("Impossible");
			} else if (true){//(R >= C) {
				int m = M;
				for (int i = 0; i < R - 3; i++) {// fill till have 3 rows
													// remaining
					for (int j = 0; j < C; j++) {
						if (m != 0) {// filling with mines top-down, left-right
							solution[i][j] = '*';
							m--;
							if (m == 0 && j == C - 2) {// if ended with 1 square
														// corner, translate to
														// next row
								solution[i][j] = '.';
								solution[i][j + 1] = '.';
								solution[++i][0] = '*';
								j = 0;
							}
						}
					}
				}

				if (m != 0) {
					for (int j = 0; j < C - 3; j++) {// fill till have 3 free
														// spots
						if (m != 0) {
							solution[R - 3][j] = '*';
							m--;
						}
					}
					if (m != 0) {
						// ******...
						// .........
						// .........
						if (m == 1) {
							// *******..
							// .........
							// .........
							solution[R - 3][C - 3] = '*';
							m = 0;
						} else if (m == 2) {
							// ******...
							// *........
							// *........
							solution[R - 2][0] = '*';
							solution[R - 1][0] = '*';
							for (int j = C - 3; j < C; j++) {
								solution[R - 3][j] = '.';
							}
							m = 0;
						} else {
							if (m % 2 == 1) {
								for (int j = C - 3; j < C; j++) {
									solution[R - 3][j] = '*';
									m--;
								}
							}
							for (int i = 0; i < m / 2; i++) {
								solution[R - 2][i] = '*';
								solution[R - 1][i] = '*';
							}
							m = 0;
						}
					}
				}
				solution[R - 1][C - 1] = 'c';
			} else if (R < C) {
				int m = M;
				for (int j = 0; j < C - 3; j++) {// fill till have 3 rows
													// remaining
					for (int i = 0; i < R; i++) {
						if (m != 0) {// filling with mines top-down, left-right
							solution[i][j] = '*';
							m--;
							if (m == 0 && i == R - 2) {// if ended with 1 square
														// corner, translate to
														// next row
								solution[i][j] = '.';
								solution[i][j + 1] = '.';
								solution[++i][0] = '*';
								j = 0;
							}
						}
					}
				}

				if (m != 0) {
					for (int j = 0; j < R - 3; j++) {// fill till have 3 free
														// spots
						if (m != 0) {
							solution[j][C - 3] = '*';
							m--;
						}
					}
					if (m != 0) {
						// ******...
						// .........
						// .........
						if (m == 1) {
							// *******..
							// .........
							// .........
							solution[R - 3][C - 3] = '*';
							m = 0;
						} else if (m == 2) {
							// ******...
							// *........
							// *........
							solution[0][C - 2] = '*';
							solution[0][C - 1] = '*';
							m = 0;
						} else {
							if (m % 2 == 1) {
								for (int j = R - 3; j < R; j++) {
									solution[j][C - 3] = '*';
									m--;
								}
							}
							for (int i = 0; i < m / 2; i++) {
								solution[i][C - 2] = '*';
								solution[i][C - 1] = '*';
							}
							m = 0;
						}
					}
				}
				solution[R - 1][C - 1] = 'c';
			}
		}

		if (!isImpossible)
			print(R, C, solution);
	}

	private static void print(int R, int C, char[][] solution) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				out.print(solution[i][j]);
			}
			out.println();
		}
	}
}
