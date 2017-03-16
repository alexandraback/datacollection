package codjam2014qual;

import java.util.Scanner;

public class ProbC {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		LOOP: for (int curcase = 1; curcase <= n; curcase++) {
			int R = sc.nextInt();
			int C = sc.nextInt();
			int M = sc.nextInt();
			int m = Math.min(R, C);
			System.out.println("Case #" + curcase + ": ");
			char[][] board = new char[R][C];
			if (m == 1) {

				if (M == R * C) {
					System.out.println("Impossible");
					continue LOOP;
				}
				for (int i = 0; i < R; i++) {
					for (int j = 0; j < C; j++) {
						if (M-- > 0) {
							board[i][j] = '*';
						} else {
							board[i][j] = '.';
						}
					}
				}
				board[R - 1][C - 1] = 'c';
				for (int i = 0; i < R; i++) {
					for (int j = 0; j < C; j++) {
						System.out.print(board[i][j]);
					}
					System.out.println();
				}

			} else {
				if (m == 2) {
					if (((M % 2 != 0) || (R * C - M == 2))&&(!(R*C-M==1))) {
						System.out.println("Impossible");
						continue LOOP;
					}
					if (C == 2) {
						for (int i = 0; i < R; i++) {
							for (int j = 0; j < C; j++) {
								if (i < M / 2) {
									board[i][j] = '*';
								} else {
									board[i][j] = '.';
								}
							}
						}
					} else {
						for (int i = 0; i < R; i++) {
							for (int j = 0; j < C; j++) {
								if (j < M / 2) {
									board[i][j] = '*';
								} else {
									board[i][j] = '.';
								}
							}
						}
					}
					if(R*C-M==1)
						board[R-2][C-1] = '*';
					
					board[R - 1][C - 1] = 'c';
					for (int i = 0; i < R; i++) {
						for (int j = 0; j < C; j++) {
							System.out.print(board[i][j]);
						}
						System.out.println();
					}
				} else {
					if ((M == R * C) || (M == R * C - 2) || (M == R * C - 3)
							|| (M == R * C - 5) || (M == R * C - 7)) {
						System.out.println("Impossible");
						continue LOOP;
					}
					if (M == R * C - 1) {
						for (int i = 0; i < R; i++) {
							for (int j = 0; j < C; j++) {
								board[i][j] = '*';
							}
						}
						board[R - 1][C - 1] = 'c';
						for (int i = 0; i < R; i++) {
							for (int j = 0; j < C; j++) {
								System.out.print(board[i][j]);
							}
							System.out.println();
						}
						continue LOOP;
					}

					for (int i = 0; i < R - 3; i++) {
						boolean isbad = (C>M)&&(C-M<2);
						for (int j = 0; j < ((isbad) ? C - 2 : C); j++) {
							if (M-- > 0) {
								board[i][j] = '*';
							} else {
								board[i][j] = '.';
							}
						}
						if (isbad) {
							//board[i][C - 3] = '.';
							board[i][C - 2] = '.';
							board[i][C - 1] = '.';
						}
					}
					boolean isbad = ((M-C) % 2 != 0);
					for (int j = 0; j < ((isbad) ? C - 3 : C); j++) {
						if (M-- > 0) {
							board[R - 3][j] = '*';
						} else {
							board[R - 3][j] = '.';
						}
					}
					if (isbad) {
						board[R - 3][C - 3] = '.';
						board[R - 3][C - 2] = '.';
						board[R - 3][C - 1] = '.';
					}
					for (int i = R-2; i < R; i++) {
						for (int j = 0; j < C; j++) {
							if (j < M / 2) {
								board[i][j] = '*';
							} else {
								board[i][j] = '.';
							}
						}
					}
					board[R - 1][C - 1] = 'c';
					for (int i = 0; i < R; i++) {
						for (int j = 0; j < C; j++) {
							System.out.print(board[i][j]);
						}
						System.out.println();
					}

				}
			}

		}
	}
}
