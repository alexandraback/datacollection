package r0;

import java.util.Scanner;

public class Q4 {
	public static void main(String... args) {
		@SuppressWarnings("resource")
		Scanner in = new Scanner(System.in);
		int caseCount = in.nextInt();
		String PEOPLE_Q = "RICHARD";
		String PEOPLE_A = "GABRIEL";
		for (int caseValue = 1; caseValue <= caseCount; caseValue++) {
			int X = in.nextInt();
			int R = in.nextInt();
			int C = in.nextInt();
			String result;
			if (X == 1) {
				// Always can.
				result = PEOPLE_A;
			} else if (X == 2) {
				// If R*C % 2 == 0, one of R,C is even, only 1 type of 2-omino, just fill it.
				result = (((R * C) % 2) == 0) ? PEOPLE_A : PEOPLE_Q;
			} else if (X == 3) {
				result = solveX3(PEOPLE_Q, PEOPLE_A, R, C);
			} else if (X == 4) {
				result = solveX4(PEOPLE_Q, PEOPLE_A, R, C);
			} else if (X == 5) {
				result = solveX5(PEOPLE_Q, PEOPLE_A, R, C);
			} else if (X == 6) {
				result = solveX6(PEOPLE_Q, PEOPLE_A, R, C);
			} else {
				// X >= 7. Choose the one with hole in center.
				result = PEOPLE_Q;
			}
			System.out.println("Case #" + caseValue + ": " + result);
		}
	}

	private static String solveX6(String PEOPLE_Q, String PEOPLE_A, int R, int C) {
		if (((R * C) % 6) != 0) {
			return PEOPLE_Q;
		}
		// One of R,C is 6N, or each is 2N,3N.
		if (R % 6 == 0) {
			return solveX6_61(PEOPLE_Q, PEOPLE_A, R, C);
		} else if (C % 6 == 0) {
			return solveX6_61(PEOPLE_Q, PEOPLE_A, C, R);
		} else if (R % 3 == 0) {
			return solveX6_32(PEOPLE_Q, PEOPLE_A, R, C);
		} else {
			return solveX6_32(PEOPLE_Q, PEOPLE_A, C, R);
		}
	}
	private static String solveX6_61(String PEOPLE_Q, String PEOPLE_A, @SuppressWarnings("unused") int A, int B) {
		if (B < 3) {
			return PEOPLE_Q; // Choose cross.
		}
		// XXXX
		//   X
		//   X  Cannot be fitted in 3xANY.
		if (B == 3) {
			return PEOPLE_Q;
		}
		// 4x6
		// By enumerate, all shapes can be inside 4x6.
		if (B == 4) {
			return PEOPLE_A;
		}
		return PEOPLE_A;
	}
	private static String solveX6_32(String PEOPLE_Q, String PEOPLE_A, int A, int B) {
		// A is 3N, B is 2N.
		if (A == 3) {
			// See solveX6_61
			return PEOPLE_Q;
		}
		// A=3(2N+1)=9,15
		if (B == 2) {
			return PEOPLE_Q;
		}
		// B=4, 8,10, 14,16, 20
		if (B % 4 == 0) {
			// k * (4x6 + 4xN), ok.
			return PEOPLE_A;
		}
		// B=10,14. Only 9x10,9x14,15x10,15x14
		// 4x6 => 4x(6+3N) => (4+2N) x (6+3N)
		// 10=4+2*3, 14=4+2*5
		// 9=6+3*1, 15=6+3*3
		return PEOPLE_A;
	}

	private static String solveX5(String PEOPLE_Q, String PEOPLE_A, int R, int C) {
		if (((R * C) % 5) != 0) {
			return PEOPLE_Q;
		}
		int A;
		int B;
		if (R % 5 == 0) {
			A = R;
			B = C;
		} else {
			A = C;
			B = R;
		}
		if (B < 3) {
			return PEOPLE_Q; // Choose cross.
		}
		// EDDCXXAABB XX
		// EEDCCXXABB  XX
		// EEDDCCXAAB   X Can only fit 3x10, not 3x5
		//
		// XXXBB
		// XAABB
		// XAAAB
		// 
		// XXXXB
		// AXBBB
		// AAAAB
		// 
		// XXXAA
		// BBXXA
		// BBBAA
		// 
		// BXXAA
		// BBXAA
		// BBXXA
		if (B == 3) {
			if (A == 5) {
				return PEOPLE_Q;
			}
			return PEOPLE_A;
		}
		// 4x5:
		// XXCCC
		// AXXCB
		// AAXCB
		// AABBB
		return PEOPLE_A;
	}

	private static String solveX4(String PEOPLE_Q, String PEOPLE_A, int R, int C) {
		if (((R * C) % 4) != 0) {
			return PEOPLE_Q;
		}
		// One of R,C is 4N, or each is 2N.
		if (R % 4 == 0) {
			return solveX4_41(PEOPLE_Q, PEOPLE_A, R, C);
		} else if (C % 4 == 0) {
			return solveX4_41(PEOPLE_Q, PEOPLE_A, C, R);
		} else {
			// R % 2 == 0 && C % 2 == 0
			return solveX4_22(PEOPLE_Q, PEOPLE_A, R, C);
		}
	}
	private static String solveX4_22(String PEOPLE_Q, String PEOPLE_A, int A, int B) {
		if (A == 2 || B == 2) {
			return PEOPLE_Q; // Choose S.
		}
		// A,B=4,6,8,10,12,14...
		// See solveX4_41, 4x3 is ok. Then 4x4 is ok. With square, all ok.
		return PEOPLE_A;
	}
	private static String solveX4_41(String PEOPLE_Q, String PEOPLE_A, @SuppressWarnings("unused") int A, int B) {
		if (B == 1) {
			return PEOPLE_Q; // Choose S.
		}
		if (B == 2) {
			return PEOPLE_Q; // Choose S.
		}
		// 4x3:
		// ABBB ABCC AACC
		// AABC ABBC AACC
		// ACCC AABC BBBB
		int remB4 = B % 4;
		if (remB4 == 1) { // B=5,9,13...
			return PEOPLE_A; // 4x(3+2)
		} else if (remB4 == 2) { // B=6,10,14...
			return PEOPLE_A; // 4x(3+3)
		} else if (remB4 == 3) { // B=3,7,11...
			return PEOPLE_A; // 4x3
		} else { // B=4,8,12...
			return PEOPLE_A; // 4x(3+1)
		}
	}

	private static String solveX3(String PEOPLE_Q, String PEOPLE_A, int R, int C) {
		// 2 types of 3-omino.
		if (((R * C) % 3) != 0) {
			return PEOPLE_Q;
		}
		// R or C is 3N. Then 1 type will surely lose. The other type:
		// Mark the 3N edge as A, the other as B.
		@SuppressWarnings("unused")
		int A;
		int B;
		if (R % 3 == 0) {
			A = R;
			B = C;
		} else {
			A = C;
			B = R;
		}
		if (B == 1) {
			return PEOPLE_Q;
		}
		int remB3 = B % 3;
		if (remB3 == 1) { // B=4,7,10...
			return PEOPLE_A; // 4x3 can be filled.
		}
		if (remB3 == 2) { // B=2,5,8...
			return PEOPLE_A; // 2x3 can be filled.
		}
		// B=3,6,9...
		return PEOPLE_A; // 3x3 can be filled.
	}
}
