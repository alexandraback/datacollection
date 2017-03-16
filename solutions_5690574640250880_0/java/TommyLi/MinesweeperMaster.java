package qualification;

import java.util.Scanner;

public class MinesweeperMaster {

	public static void main(String[] args) {
		//tool.SubmissionHelper.injectIO("C-small");
		
		final String gridMine = "*", gridEmpty = ".", gridClick = "c";
		
		Scanner scanner = new Scanner(System.in);
		
		int numberOfCases = scanner.nextInt();
		
		for (int c = 0; c < numberOfCases; c++) {
			System.out.println("Case #" + (c+1) + ": ");
			
			int R = scanner.nextInt();
			int C = scanner.nextInt();
			int M = scanner.nextInt();
		/*for (int R = 1; R <= 5; R++) {
			for (int C = 1; C <= 5; C++) {
				for (int M = 0; M < R*C; M++) {
			
			System.out.printf("R=%d, C=%d, M=%d\n", R, C, M);*/
			
			int longD = Math.max(R, C);
			int shortD = Math.min(R, C);
			
			int spaceCount = R * C - M;
			
			boolean[][] grids = null;
			
			if (shortD == 1) {
				grids = new boolean[R][C];
				
				int m = M;
				exitloop:
				for (int i = 0; i < R; i++) {
					for (int j = 0; j < C; j++) {
						if (m > 0) {
							grids[i][j] = true;
							m--;
						} else {
							break exitloop;
						}
					}
				}
			} else if (shortD == 2) {
				
				
				if (spaceCount == 1 || spaceCount != 2 && spaceCount % 2 == 0) {
					grids = new boolean[R][C];
					int m = M;
					
					if (C == shortD) {
						exitloop:
						for (int i = 0; i < R; i++) {
							for (int j = 0; j < C; j++) {
								if (m > 0) {
									grids[i][j] = true;
									m--;
								} else {
									break exitloop;
								}
							}
						}
					} else {
						exitloop:
						for (int j = 0; j < C; j++) {
							for (int i = 0; i < R; i++) {
								if (m > 0) {
									grids[i][j] = true;
									m--;
								} else {
									break exitloop;
								}
							}
						}
					}
				}
			} else if (spaceCount != 2 && spaceCount != 3 && spaceCount != 5 && spaceCount != 7) {
				
				grids = new boolean[R][C];
				int m = M;
				
				if (R >= 3 && C >= 3) {
					if (m > 0) {
						exitloop:
						for (int i = 0; i < R - 2; i++) {
							for (int j = 0; j < C - 2; j++) {
								grids[i][j] = true;
								
								m--;
								if (m <= 0) {
									break exitloop;
								}
							}
						}
					}
				}
				
				if (m > 0) {	
					boolean flag = true;
					exitloop:
					for (int j = 0; j < C - 3; j++) {
						for (int i = R - 2; i < R; i++) {
							if (flag) {
								grids[i][j] = true;
								grids[i+1][j] = true;
							}
							grids[R-3][C-3] = !flag;
							
							flag = !flag;
							
							m--;
							if (m <= 0) {
								break exitloop;
							}
						}
					}
				}
				
				
				if (m > 0) {	
					boolean flag = true;
					exitloop:
					for (int i = 0; i < R - 3; i++) {
						for (int j = C - 2; j < C; j++) {
							if (flag) {
								grids[i][j] = true;
								grids[i][j+1] = true;
							}
							grids[R-3][C-3] = !flag;
							
							flag = !flag;
							
							m--;
							if (m <= 0) {
								break exitloop;
							}
						}
					}
				}
			
				
				if (m > 0) {
					grids[R-2][C-3] = true;
					grids[R-1][C-3] = true;
					m-=2;
				}
				
				if (m > 0) {
					grids[R-3][C-2] = true;
					grids[R-3][C-1] = true;
					m-=2;
				}
				
				if (m > 0) {
					grids[R-2][C-2] = true;
					grids[R-1][C-2] = true;
					grids[R-2][C-1] = true;
					m-=3;
				}
				
				if (m > 0) {
					grids[R-1][C-1] = true;
					m--;
				}
				
				
				
			} 
			
			if (grids != null) {
				// Print result
				for (int i = 0; i < R; i++) {
					for (int j = 0; j < C; j++) {
						if (i == R - 1 && j == C - 1) {
							System.out.print(grids[i][j] ? gridMine : gridClick);
						} else {
							System.out.print(grids[i][j] ? gridMine : gridEmpty);
						}
					}
					System.out.println();
				}
			} else {
				System.out.println("Impossible");
			}
			
		}
	}
		/*}
	}*/
}
