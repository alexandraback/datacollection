import java.io.*;
import java.util.*;


public class ProblemC {
	final static String PROBLEM_NAME = "/Users/autobee/work/gcm/problem_c";
			final static String FILE_NAME_IN =  "C-large.in";
			final static String FILE_NAME_OUT =  "C-large.out";
//	final static String FILE_NAME_IN =  "C-small-attempt-in.txt";
//	final static String FILE_NAME_OUT =  "C-small-attempt-out.txt";
	//	final static String FILE_NAME_IN =  "input.txt";
	//	final static String FILE_NAME_OUT =  "output.txt";

	/**
	 * @param args
	 */

	int R, C, M, rM;
	int[][] matrix;

	boolean addMine(int i, int j) {
		if (matrix[i][j] == 0 && rM > 0) {
			//			if (i == 0 && R > 1 && matrix[i+1][])
			rM--;
			matrix[i][j] = -1;
			return true;
		}

		return false;
	}

	void removeMine(int i, int j) {
		matrix[i][j] = 0;
		rM++;
	}

	boolean test(int  cr, int cc) {
		boolean left = true;// 왼쪽으로 먼저 진행. false 면 위로 먼저 진행
		if (C > R) left = false;
		
		// 클릭시 숫자인 경우. 한칸만 열어도된다!
		if (R * C == M + 1) {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					matrix[i][j] = -1;
				}
			}
			matrix[cr][cc] = 1;
			return true;
		}

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				matrix[i][j] = 0;
			}
		}
		rM = M;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				int r = cr - 1 + i;
				int c = cc - 1 + j;
				if (r >= 0 && r < R && c >= 0 && c < C) {
					matrix[r][c] = 2;
				}
			}
		}
		matrix[cr][cc] = 1;

		if (left) {
			for (int i = R - 1; i >= 0; i--) {
				for (int j = C - 1; j >= 0; j--) {
					// 지뢰 매설
					if ((R > 1 && i == 0) || (C > 1 && j == 0)) continue;
					if (addMine(i, j)) {
						if (i == 1) {
							if (addMine(0, j) == false) removeMine(i, j);
						}
						if (j == 1) {
							if (addMine(i, 0) == false) removeMine(i, j);
						}
					}
				}
			}
		} else {
			for (int j = C - 1; j >= 0; j--) {
				for (int i = R - 1; i >= 0; i--) {
					// 지뢰 매설
					if ((R > 1 && i == 0) || (C > 1 && j == 0)) continue;
					if (addMine(i, j)) {
						if (i == 1) {
							if (addMine(0, j) == false) removeMine(i, j);
						}
						if (j == 1) {
							if (addMine(i, 0) == false) removeMine(i, j);
						}
					}
				}
			}
		}

		if (rM == 0) return true;

		return false;
	}

	// 0 빈곳, 1 클릭, 2 주위. -1 지뢰.
	void solve(Scanner sc, PrintWriter pw) {
		R = sc.nextInt();
		C = sc.nextInt();
		M = sc.nextInt();

		matrix = new int[R][C];

		boolean canClick = false;
		for (int i = 0; i < Math.min(2, R); i++) {
			for (int j = 0; j < Math.min(2, C); j++) {
				//		for (int i = 0; i < R/2; i++) {
				//			for (int j = 0; j < C/2; j++) {
				if (canClick == false && test(i, j)) {
					canClick = true;
				}
			}
		}

		StringBuilder sb = new StringBuilder();
		if (canClick) {
			// success
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					if (matrix[i][j] == 1) {
						sb.append('c');
					} else if (matrix[i][j] == -1){
						sb.append('*');
					} else {
						sb.append('.');
					}
				}
				if (i != R-1) sb.append('\n');
			}
			pw.println(sb);
		} else {
			pw.println("Impossible");
		}
	}


	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileReader(PROBLEM_NAME + "/" + FILE_NAME_IN));
		PrintWriter pw = new PrintWriter(new FileWriter(PROBLEM_NAME + "/" + FILE_NAME_OUT));
		int caseCnt = sc.nextInt();
		for (int caseNum=0; caseNum<caseCnt; caseNum++) {
			System.out.println("Processing test case " + (caseNum + 1));
			pw.print("Case #" + (caseNum+1) + ":\n");
			new ProblemC().solve(sc, pw);
		}
		pw.flush();
		pw.close();
		sc.close();

	}

}
