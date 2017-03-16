package qualy;

import java.util.Scanner;

public class C {
	private static boolean[][] rotate(boolean[][] vals) {
		boolean[][] ret = new boolean[vals[0].length][vals.length];
		for (int i = 0; i < vals.length; i++) {
			for (int j = 0; j < vals[i].length; j++) {
				ret[j][i] = vals[i][j];
			}
		}
		return ret;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		for (int caze = 1; caze <= cases; caze++) {
			int R = sc.nextInt();
			int C = sc.nextInt();
			int M = sc.nextInt();
			int min = Math.min(R, C);
			int free = C * R - M;
			boolean ok = true, rotated = false;
			boolean[][] ret = new boolean[R][C];
			if (free == 1 || M == 0) {
				ret[0][0] = false;
				if (M == 0) {
					for (int i = 0; i < ret.length; i++) for(int j = 0; j < ret[i].length; j++) ret[i][j] = true;
				}
			} else if (min == 1) {
				for (int i = 0; i < ret.length && free > 0; i++) {
					for (int j = 0; j < ret[i].length && free > 0; j++) {
						ret[i][j] = true;
						free--;
					}
				}
			} else if (min == 2) {
				if (free == 2 || (free % 2) == 1)
					ok = false;
				else {
					if (ret[0].length != 2) {
						rotated = true;
						ret = rotate(ret);
					}
					for (int i = 0; i < free / 2; i++) {
						ret[i][0] = ret[i][1] = true;
					}
				}
			} else {
				if (free < 4 || free == 5 || free == 7)
					ok = false;
				else {
					if (free % 2 == 0) {
						boolean passed = false;
						int i = 0, j = 0;
						free /= 2;
						while (free > 0) {
							if (j + 1 < C) {
								ret[i][j] = ret[i][j + 1] = true;
								i++;
								if (i == R) {
									i = 0;
									j += 2;
								}
								free--;
							} else {
								passed = true;
								ret[i][j] = true;
								ret[i+1][j] = true;
								i += 2;
								free--;
							}
						}
						if (!passed && i == 1) {
							ret[0][j+1] = false;
							ret[1][j] = true;
						}
					} else {
						int i,j;
						for (i = 0; i < 3; i++) for (j = 0; j < 3; j++) ret[i][j] = true;
						free -= 9;
						i = 0; j = 3;
						while (free > 0 && j < C) {
							ret[i][j] = ret[i+1][j] = true;
							j++;
							free-=2;
						}
						i = 2; j = 3;
						if (j==C) {
							i++;
							j=0;
						}
						while (free > 0) {
							ret[i][j] = true;
							j++;
							if (j==C) {
								i++;
								j=0;
							}
							free--;
						}
						if (j == 1) {
							ret[i][j] = true;
							ret[i-1][C-1] = false;
						}
					}
				}
			}

			if (rotated)
				ret = rotate(ret);
			System.out.println("Case #" + caze + ":");
			if (!ok) {
				System.out.println("Impossible");
			} else {
				System.out.print("c");
				for (int i = 0; i < R; i++) {
					for (int j = 0; j < C; j++)
						if (i != 0 || j != 0) {
							System.out.print(ret[i][j] ? "." : "*");
						}
					System.out.println();
				}
			}
		}
	}

}
