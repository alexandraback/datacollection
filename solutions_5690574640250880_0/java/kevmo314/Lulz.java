import java.util.*;
import java.text.*;

public class Lulz {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		testCase:
		for(int t = 1; t <= T; t++) {
			int R = in.nextInt();
			int C = in.nextInt();
			int M = in.nextInt();
			
			System.out.println("Case #" + t + ":");
			if(R > 1 && C > 1) {
				if(M == R * C - 1) {
					for(int i = 0; i < R; i++) {
						for(int j = 0; j < C; j++) {
							System.out.print(i + j == 0 ? "c" : "*");
						}
						System.out.println();
					}
				} else {
					for(int c = 2; c <= C; c++) {
						for(int r = 2; r <= R; r++) {
							int maxMines = R * C - (r * 2 + c * 2 - 4);
							int minMines = R * C - (r * c);
							if(minMines <= M && M <= maxMines) {
								// a solution :O
								boolean[][] map = new boolean[R][C];
								for(int i = 0; i < r; i++) {
									map[i][0] = true;
									map[i][1] = true;
								}
								for(int i = 0; i < c; i++) {
									map[0][i] = true;
									map[1][i] = true;
								}
								int mineCount = maxMines;
								if(mineCount == M) {
									for(int a = 0; a < R; a++) {
										for(int b = 0; b < C; b++) {
											System.out.print(a + b == 0 ? "c" : (map[a][b] ? "." : "*"));
										}
										System.out.println();
									}
									continue testCase;											
								}
								for(int i = 2; i < r; i++) {
									for(int j = 2; j < c; j++) {
										map[i][j] = true;
										if(--mineCount == M) {
											for(int a = 0; a < R; a++) {
												for(int b = 0; b < C; b++) {
													System.out.print(a + b == 0 ? "c" : (map[a][b] ? "." : "*"));
												}
												System.out.println();
											}
											continue testCase;											
										}
									}
								}
							}
						}
					}
					System.out.println("Impossible");
				}
			} else {
				int freeCount = 0;
				for(int i = 0; i < R; i++) {
					for(int j = 0; j < C; j++) {
						System.out.print(i + j == 0 ? "c" : (++freeCount < R * C - M ? "." : "*"));
					}
					System.out.println();
				}
			}
		}
	}
}