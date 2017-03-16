import java.util.ArrayDeque;
import java.util.Scanner;

class Point {
	public Point(int xc, int yc) {
		x = xc;
		y = yc;
	}
	public int x;
	public int y;
}

class Square {
	public boolean hasMine = false;
	public int neighbours = 0;
	public int distance = Integer.MAX_VALUE;
}

public class Program {

	private static void putMine(Square[][] board, int x, int y) {
		board[x][y].hasMine = true;
		for (int i = Math.max(0, x-1); i < Math.min(board.length, x+2); i++) {
			for (int j = Math.max(0, y-1); j < Math.min(board[0].length, y+2); j++) {
				board[i][j].neighbours++;
			}
		}
	}
	
	private static void removeMine(Square[][] board, int x, int y) {
		board[x][y].hasMine = false;
		for (int i = Math.max(0, x-1); i < Math.min(board.length, x+2); i++) {
			for (int j = Math.max(0, y-1); j < Math.min(board[0].length, y+2); j++) {
				board[i][j].neighbours--;
			}
		}
	}
	
	
	private static boolean solve(Square[][] board, int x, int y, int d, int mines, int m) {
		int r = board.length;
		int c = board[0].length;		
		
		if (mines == m) {
			if (m < (r*c)-1) {
				// check that clicking will effectively clear the grid
							
				int xc = -1, yc = -1;
				out:
				for (int i = 0; i < r; i++) {
					for (int j = 0; j < c; j++) {
						if (board[i][j].neighbours == 0) {
							xc = i;
							yc = j;
							break out;
						}
					}
				}

				
				if (xc == -1) {
					return false;
				}
				
				ArrayDeque<Point> ad = new ArrayDeque<>();				
				ad.add(new Point(xc, yc));
				
				boolean b[][] = new boolean[r][c];
				
				while (! ad.isEmpty()) {
					Point p = ad.remove();
					b[p.x][p.y] = true; 
					
					if (board[p.x][p.y].neighbours == 0) {
						for (int i = Math.max(0, p.x-1); i < Math.min(r, p.x+2); i++) {
							for (int j = Math.max(0,  p.y-1); j < Math.min(c,  p.y+2); j++) {
								if (! b[i][j]) {
									ad.add(new Point(i, j));
								}
							}
						}
					}
				}
				
				for (int i = 0; i < r; i++) {
					for (int j = 0; j < c; j++) {
						if ((! board[i][j].hasMine) && (! b[i][j])) {
							return false;
						}
					}
				}
				
			}				
			return true;
		}
		
		if (x == r) {
			x = 0;
			y++;
		}
		if (y == c) {
			return false;
		}

		if (board[x][y].distance <= d) {
			putMine(board, x, y);
			if (solve(board, x+1, y, d, mines+1, m)) {
				return true;
			}
			removeMine(board, x, y);
		}
		return solve(board, x+1, y, d, mines, m);
	}
	
	private static int nMines(boolean[][] board, int x, int y, int r, int c) {
		int n = 0;
		
		for (int i = Math.max(x-1, 0); i < Math.min(x+2, r); i++) {
			for (int j = Math.max(y-1, 0); j < Math.min(y+2, c); j++) {
				if (board[i][j]) {
					n++;
				}
			}
		}
		
		return n;
	}
	
	private static void mark(int[][] b, int r, int c, int x, int y) {
		if (b[x][y] == -1) {
			return;
		}

		boolean rec = (b[x][y] == 0);
		b[x][y] = -1;
		
		if (rec) {
			for (int i = Math.max(x-1, 0); i < Math.min(x+2, r); i++) {
				for (int j = Math.max(y-1, 0); j < Math.min(y+2, c); j++) {
					mark(b, r, c, i, j);
				}
			}
		}
	}
	
	private static boolean boardLegal(boolean[][] board, int r, int c) {
		int[][] b = new int[r][c];
		
		int xc = -1, yc = -1;
		int n = 0;	// non-mine squares
		
		// b contains
		// -1 for a mine
		// 0..8 for a square (number of mines around it)
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (board[i][j]) {
					b[i][j] = -1;					
				} else {
					n++;
					b[i][j] = nMines(board, i, j, r, c);
					if (b[i][j] == 0) {
						xc = i;
						yc = j;
					}
				}
			}
		}
		
		if (n == 1) {
			return true;
		}
		
		if (xc == -1) {
			return false;
		}
		
		mark(b, r, c, xc, yc);
		
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (b[i][j] > -1) {
					return false;
				}
			}
		}
		
		
		return true;
	}
	
	private static boolean solveBFrec(boolean[][] board, int x, int y, int r, int c, int m) {
		if (m == 0) {
			return boardLegal(board, r, c);
		} else {
			if (x == r) {
				x = 0;
				y++;
			}
			if (y == c) {
				return false;
			}
			board[x][y] = true;
			if (solveBFrec(board, x+1, y, r, c, m-1)) {
				return true;
			}
			board[x][y] = false;
			return solveBFrec(board, x+1, y, r, c, m);
		}		
	}
	
	private static boolean[][] solveBruteForce(int r, int c, int m) {
		boolean board[][] = new boolean[r][c]; // true <-> mine
		
		boolean res = solveBFrec(board, 0, 0, r, c, m);
		if (res) {
			return board;
		} else {
			return null;
		}			
	}
	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int nCases = in.nextInt();
		in.nextLine();
		for (int caseNumber = 1; caseNumber <= nCases; caseNumber++) {
			
			String[] line = in.nextLine().split(" ");
			int r = Integer.parseInt(line[0]);
			int c = Integer.parseInt(line[1]);
			int m = Integer.parseInt(line[2]);
			int n = r*c-m;

			Square[][] board = new Square[r][c];
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					board[i][j] = new Square();
				}
			}
			
			int d = 1;		// current distance
			int mines = 0;  // number of mines that have been put so far
			boolean possible = false;
			
			// the center square is at distance 0 from itself
			board[r/2][c/2].distance = 0;

			int marked = 1;	// number of squares for which a distance has been set

			while (marked < n) {
				// mark all the neighbours of squares that have distance d
				for (int i = Math.max(0, (r/2)-d); i < Math.min(r, (r/2)+d+1); i++) {
					for (int j = Math.max(0, (c/2)-d); j < Math.min(c, (c/2)+d+1); j++) {
						if (board[i][j].distance == Integer.MAX_VALUE) {					
							board[i][j].distance = d;						
							marked++;
						}
					}
				}
				d++;
			}
			// put mines on all squares at distance MAX_VALUE
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (board[i][j].distance == Integer.MAX_VALUE) {					
						putMine(board, i, j);
						mines++;
					}
				}
			}
						
			possible = solve(board, 0, 0, d-1, mines, m);

			if (! possible) {
				// if no solution is found, try again but this time, mark the top left square first
				for (int i = 0; i < r; i++) {
					for (int j = 0; j < c; j++) {
						board[i][j].distance = Integer.MAX_VALUE;
						board[i][j].hasMine = false;
						board[i][j].neighbours = 0;
					}
				}
				board[0][0].distance = 0;
				marked = 1;
				d = 1;
				mines = 0;
				while (marked < n) {
					// mark all the neighbours of squares that have distance d
					if (d < c) {
						for (int i = 0; i < Math.min(r,d+1); i++) {
							board[i][d].distance = d;
							marked++;
						}
					}
					if (d < r) {
						for (int j = 0; j < Math.min(c, d+1); j++) {
							if (board[d][j].distance == Integer.MAX_VALUE) {
								board[d][j].distance = d;
								marked++;
							}
						}
					}
					d++;						
				}

				// if the center square is marked, take its distance as the new d
				if (board[r/2][c/2].distance != Integer.MAX_VALUE) {
					d = board[r/2][c/2].distance-1;
					for (int i = 0; i < r; i++) {
						for (int j = 0; j < c; j++) {
							if ((board[i][j].distance > d) && (board[i][j].distance < Integer.MAX_VALUE)) {					
								board[i][j].distance = d;
							}
						}
					}						
					d++;
				}

				// put mines on all squares at distance MAX_VALUE
				for (int i = 0; i < r; i++) {
					for (int j = 0; j < c; j++) {
						if (board[i][j].distance == Integer.MAX_VALUE) {					
							putMine(board, i, j);
							mines++;
						}
					}
				}
			}				
			
			
			possible = solve(board, 0, 0, d-1, mines, m);
			
			if (! possible)  {
				// Apparently impossible => exhaustive search
				for (int i = 0; i < r; i++) {					
					for (int j = 0; j < c; j++) {
						board[i][j].hasMine = false;
						board[i][j].neighbours = 0;									
						board[i][j].distance = 0;
					}
				}
				d = 1;
				mines = 0;
				possible = solve(board, 0, 0, d-1, mines, m);				
			}
			 
			System.out.print("Case #");
			System.out.print(caseNumber);
			System.out.println(":");
			
			boolean[][] res = solveBruteForce(r, c, m);
			if (res == null) {
				System.out.println("Impossible");				
			} else {
				int xc = -1, yc = -1;
				for (int i = 0; i < r; i++) {
					for (int j = 0; j < c; j++) {
						if (! res[i][j])
							if ((n == 1) || (nMines(res, i, j, r, c) == 0)) {
								xc = i;
								yc = j;
							}
						}
					}

				for (int i = 0; i < r; i++) {
					for (int j = 0; j < c; j++) {
						if (res[i][j]) {
							System.out.print("*");							
						} else {
							if ((i == xc) && (j == yc)) {
								System.out.print("c");
							} else {
								System.out.print(".");
							}
						}
					}
					System.out.println();
				}
			}
			
//			if (possible) {
//				// find c = any square that has 0 neighbour (or the only square with no mine, if n == 1)
//				int xc = -1, yc = -1;
//				out:
//				for (int i = 0; i < r; i++) {
//					for (int j = 0; j < c; j++) {
//						if (board[i][j].neighbours == 0) {
//							xc = i;
//							yc = j;
//							break out;
//						} else {
//							if (n == 1) {
//								if (! board[i][j].hasMine) {
//									xc = i;
//									yc = j;
//									break out;
//								}
//							}
//						}
//					}
//				}
//				
//				if (xc == -1) {
//					System.err.print(caseNumber);
//					System.err.println(" - pas de c !!");
//				}
//
//				for (int i = 0; i < r; i++) {
//					for (int j = 0; j < c; j++) {
//						if (board[i][j].hasMine) {
//							System.out.print("*");
//						} else {
//							if ((i == xc) && (j == yc)) {
//								System.out.print("c");
//							} else {
//								System.out.print(".");
//							}
//						}
//					}
//					System.out.println();
//				}
//			} else {
//				System.out.println("Impossible");
//			}
			
			
//			System.out.print("Brute force :");
//			if (solveBruteForce(r, c, m)) {
//				System.out.println("solution trouvée");
//			} else {
//				System.out.println("impossible");
//			}
//			boolean bf = solveBruteForce(r, c, m);
//			System.err.print(caseNumber);
//			if (possible == bf) {
//				System.err.println(" OK");
//			} else {
//				System.err.println(" !! désaccord entre ancien programme et force brute");
//			}
//
		}
	}
}
