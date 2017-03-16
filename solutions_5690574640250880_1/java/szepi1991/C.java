import java.io.BufferedInputStream;
import java.util.Scanner;


public class C {

	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));

		int T =	sc.nextInt();
		for (int t = 1; t <= T; ++t) {
			System.out.println("Case #" + t + ":");
			System.out.println(solve(sc.nextInt(), sc.nextInt(),sc.nextInt()));
		}

	}

	private static String solve(int R, int C, int M) {
		boolean [][] mines = new boolean [R][C];
		if (M + 1 == R*C) {
			fill(mines, M);
		} else {
			if (R == 1 || C == 1) fill(mines, M);
			else {
				// there at least a 2x2 corner on the field
				// we need it not to be filled
				if (M + 4 > R*C) return "Impossible";                  // TODO this should be strict!!!
				// we also need that there's not exactly 5, or 7 mines missing
				if (M + 5 == R*C || M + 7 == R*C) return "Impossible";
				// now assume there's mines everywhere -- except the 2x2 section
				fill(mines, R*C);
				mines[R-2][C-2] = false;
				mines[R-2][C-1] = false;
				mines[R-1][C-2] = false;
				mines[R-1][C-1] = false;
				// now we keep freeing 2x1 sections above our 2x2 thing
				int overMines = R*C - 4 - M; // this is how many we want to get rid of
				Point [] lastTwo = new Point[2];
				for (int r = R-3; r >= 0; --r) { // could do this with just one calculation ... oh well
					if (overMines >= 2) {
						// remove mines in this row
						mines[r][C-2] = false;
						mines[r][C-1] = false;
						overMines -= 2;
						lastTwo[0] = new Point(r, C-2);
						lastTwo[1] = new Point(r, C-1);
					}
				}
				// either there's 0 or 1 mine left now,
				// or we filled in the first 2 columns
				if (overMines == 1) {
					// check if there something to move to the side
					// and check if there's space on the side
					if (C-3 < 0) return "Impossible";
					if (lastTwo[0] == null) return "Impossible";
					// otherwise move last + 1 remainder to the side
					// -- assuming there's 3 spots!
					if (R < 3) return "Impossible";
					mines[lastTwo[0].r][lastTwo[0].c] = true;
					mines[lastTwo[1].r][lastTwo[1].c] = true;
					for (int i = 0; i < 3; ++i) {
						mines[R-i-1][C-3] = false;
					}
					overMines -= 1; // add two, subtract 3
					// and we are good
				} else if (overMines >= 2) {
					// now we free up the bottom 2 rows
					int freeUp = Math.min(overMines / 2, C-2);
					for (int i = 0; i < freeUp; ++i) {
						mines[R-1][C-3-i] = false;
						mines[R-2][C-3-i] = false;
					}
					overMines -= 2*freeUp;
					// it's possible that we have 1 leftover, but no
					// higher row to place it into!!
					if (overMines == 1 && R == 2) return "Impossible"; 
					
					// at this point go and free up as many as needed
					// going from (R-3, C-3) column-wise
					OUTERLOOP:
					for (int cc = C-3; cc >= 0; --cc) {
						for (int rr = R-3; rr >= 0; --rr) {
							if (overMines == 0) break OUTERLOOP;
							mines[rr][cc] = false;
							overMines--;
						}
					}
				}
				// now we have 0 mines left to erase
				if (overMines != 0) return "BUG!";
			}
		}
		// now the boolean array just needs to be translated into a string
		StringBuilder ret = new StringBuilder();
		for (int r = 0; r < R; ++r) {
			for (int c = 0; c < C; ++c) {
				if (r == R-1 && c == C-1) ret.append('c');
				else ret.append( mines[r][c] ? '*' : '.' );
			}
			if (r != R - 1) ret.append('\n');
		}
		
		return ret.toString();
	}

	private static void fill(boolean [][] field, int M) {
		int m = 0;
		for (int r = 0; m < M; ++r) {
			for (int c = 0; c < field[r].length && m < M; ++c) {
				field[r][c] = true;
				m++;
			}
		}
	}
	
	static class Point {
		int c;
		int r;
		
		public Point(int r, int c) {
			this.c = c;
			this.r = r;
		}
	}

}
