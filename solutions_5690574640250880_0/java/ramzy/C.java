package codejam.qualification;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;


public class C {

	private final static boolean SMALL = true;
	
	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new FileReader("src/C-" + (SMALL ? "small" : "big") + ".in"));
		PrintWriter output = new PrintWriter("src/C-" + (SMALL ? "small" : "big") + ".out");

		String out;
		int N = input.nextInt();
		for(int i = 1; i <= N; i++) {
			int R = input.nextInt();
			int C = input.nextInt();
			int M = input.nextInt();
			out = "Case #" + i + ":\n" + solve(R, C, M);
			output.println(out);
			System.out.println(out);
		}
		input.close();
		output.close();
	}

	// R rows
	// C columns
	// M mines
	private static String solve(int R, int C, int M) {
		if (R == 1) {
			String grid = "c";
			if(C > 1) {
				for (int i = 1; i < C; i++) {
					grid += i < C-M ? "." : "*";
				}
			}
			return grid;
		}
		if (C == 1) {
			String grid = "c\n";
			if(R > 1) {
				for (int i = 1; i < R; i++) {
					grid += (i < R-M ? "." : "*") + "\n";
				}
			}
			return grid.substring(0, grid.length()-1);
		}
		if (M == 0) {
			String grid = "c";
			for (int i = 1; i < C; i++) {
				grid += ".";
			}
			grid += "\n";
			for (int i = 1; i < R; i++) {
				for (int j = 0; j < C; j++) {
					grid += ".";
				}
				grid += "\n";
			}
			return grid.substring(0, grid.length()-1);
		}

		int e = R*C - M;

		if (e == 1) {
			String grid = "";
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					if (i+j == 0) {
						grid += "c";
					} else {
						grid += "*";
					}
				}
				grid += "\n";
			}
			return grid.substring(0, grid.length()-1);
		}
		if (e == 2 || e == 3) {
			return "Impossible";
		}
		
		// l columns
		// R-k rows
		for (int l = 2; l <= C; l++) {
			for (int k = 0; k < R-1; k++) {
				if (l * (R-k) == e) {
					String grid = "";
					for (int i = 0; i < R; i++) {
						for (int j = 0; j < C; j++) {
							if (i+j == 0) {
								grid += "c";
							} else if(i < R-k && j < l) {
								grid += ".";
							} else {
								grid += "*";
							}
						}
						grid += "\n";
					}
					return grid.substring(0, grid.length()-1);
				}
			}
		}
		for (int l = 2; l <= R; l++) {
			for (int k = 0; k < C-1; k++) {
				if (l * (C-k) == e) {
					String grid = "";
					for (int i = 0; i < R; i++) {
						for (int j = 0; j < C; j++) {
							if (i+j == 0) {
								grid += "c";
							} else if(j < C-k && i < l) {
								grid += ".";
							} else {
								grid += "*";
							}
						}
						grid += "\n";
					}
					return grid.substring(0, grid.length()-1);
				}
			}
		}		

		// l columns
		// (R-k) rows
		if (C>=3 && R>=3)
		for (int l = 3; l <= C; l++) {
			for (int k = 0; k < R; k++) {
				if (l * (R-k) > e && (l-1) * (R-k) < e && l*(R-k)-e <= (l+(R-k)-1)-5) {
					int m = (l*(R-k)-e);
					String grid = "";
					for (int i = 0; i < R; i++) {
						for (int j = 0; j < C; j++) {
							if (i+j == 0) {
								grid += "c";
							} else if(i < R-k-1 && j < l-1) {
								grid += ".";
							} else if((i == R-k-1 && j == l-1) || (i == R-k-2 && j == l-1) || (i == R-k-1 && j == l-2) || (i == R-k-3 && j == l-1) || (i == R-k-1 && j == l-3)) {
								grid += ".";
							} else if(i == R-k-1 && j < l-1) {
								if (m > 0) {
									m--;
									grid += "*";
								} else {
									grid += ".";
								}
							} else if(i < R-k-1 && j == l-1) {
								if (m > 0) {
									m--;
									grid += "*";
								} else {
									grid += ".";
								}
							} else {
								grid += "*";
							}
						}
						grid += "\n";
					}
					return grid.substring(0, grid.length()-1);
				}
			}
		}
		if (C>=3 && R>=3)
		for (int l = 3; l <= R; l++) {
			for (int k = 0; k < C; k++) {
				if (l * (C-k) > e && (l-1) * (C-k) < e && l*(C-k)-e <= (l+(C-k)-1)-5) {
					int m = (l*(C-k)-e);
					String grid = "";
					for (int i = 0; i < R; i++) {
						for (int j = 0; j < C; j++) {
							if (i+j == 0) {
								grid += "c";
							} else if(j < C-k-1 && i < l-1) {
								grid += ".";
							} else if((j == C-k-1 && i == l-1) || (j == C-k-2 && i == l-1) || (j == C-k-1 && i == l-2) || (j == C-k-3 && i == l-1) || (j == C-k-1 && i == l-3)) {
								grid += ".";
							} else if(j == C-k-1 && i < l-1) {
								if (m > 0) {
									m--;
									grid += "*";
								} else {
									grid += ".";
								}
							} else if(i < C-k-1 && i == l-1) {
								if (m > 0) {
									m--;
									grid += "*";
								} else {
									grid += ".";
								}
							} else {
								grid += "*";
							}
						}
						grid += "\n";
					}
					return grid.substring(0, grid.length()-1);
				}
			}
		}
		
		
		// l columns
		// (R-k) rows
		if(true) {
			int l = 3;
			int k = 0;
			if (l * (R-k) > e && (l-1) * (R-k) < e && l*(R-k)-e <= (l+(R-k)-1)-4) {
				int m = (l*(R-k)-e);
				String grid = "";
				for (int i = 0; i < R; i++) {
					for (int j = 0; j < C; j++) {
						if (i+j == 0) {
							grid += "c";
						} else if(i < R-k-1 && j < l-1) {
							grid += ".";
						} else if((i == R-k-1 && j == l-1) || (i == R-k-2 && j == l-1) || (i == R-k-1 && j == l-2)) {
							grid += ".";
						} else if(i == R-k-1 && j < l-1) {
							grid += ".";
						} else if(i < R-k-1 && j == l-1) {
							if (m > 0) {
								m--;
								grid += "*";
							} else {
								grid += ".";
							}
						} else {
							grid += "*";
						}
					}
					grid += "\n";
				}
				return grid.substring(0, grid.length()-1);
			}
		}
		if(true) {
			int l = 3;
			int k = 0;
			if (l * (C-k) > e && (l-1) * (C-k) < e && l*(C-k)-e <= (l+(C-k)-1)-4) {
				int m = (l*(C-k)-e);
				String grid = "";
				for (int i = 0; i < R; i++) {
					for (int j = 0; j < C; j++) {
						if (i+j == 0) {
							grid += "c";
						} else if(j < C-k-1 && i < l-1) {
							grid += ".";
						} else if((j == C-k-1 && i == l-1) || (j == C-k-2 && i == l-1) || (j == C-k-1 && i == l-2)) {
							grid += ".";
						} else if(j == C-k-1 && i < l-1) {
							grid += ".";
						} else if(j < C-k-1 && i == l-1) {
							if (m > 0) {
								m--;
								grid += "*";
							} else {
								grid += ".";
							}
						} else {
							grid += "*";
						}
					}
					grid += "\n";
				}
				return grid.substring(0, grid.length()-1);
			}
		}
		
//				3<=i<=C
//				0<=k<R
//				i X (R-k) > e && (i-1) x (R-k) < e && i * (R-k) - e <= (i+(R-k)-1) - 5
//				---------
//				c...**
//				....**
//				.....*
//				*....*
//				******


		return "Impossible";

//		int empty = R*C - M;
//		if (empty < 4) {
//			return "Impossible";
//		}
//		for (int d = 1; d <= R; d++) {
//			if (empty%d == 0 && empty/d <= C) {
//				int r = d;
//				int c = empty/d;
//				
//				String grid = "";
//				for (int i = 0; i < R; i++) {
//					for (int j = 0; j < C; j++) {
//						if (i+j == 0) {
//							grid += "c";
//						} else if (i < r && j < c) {
//							grid += ".";
//						} else {
//							grid += "*";
//						}
//					}
//					grid += "\n";
//				}
//				return grid.substring(0, grid.length()-1);
//			}
//		}
		
		
		
		
		
		
//			int dots = R*C - M - 4;
//			String grid = "";
//			for (int i = 0; i < R; i++) {
//				for (int j = 0; j < C; j++) {
//					if (i+j == 0) {
//						grid += "c";
//					} else if ((i == 0 && j == 1) || (i == 1 && j == 0) || (i == 1 && j == 1)) {
//						grid += ".";
//					} else {
//						if(dots > 0) {
//							grid += ".";
//							dots--;
//						} else {
//							grid += "*";
//						}
//					}
//				}
//				grid += "\n";
//			}
//			return grid.substring(0, grid.length()-1);
	}

}
