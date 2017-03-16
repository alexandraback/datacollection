import java.util.*;
import java.io.*;

public class MinesweeperMaster {
	
	static final int EMPTY = 0, MINE = 1, START = 2;
	static final char[] cellChar = {'.', '*', 'c'};
	
	static final int[] dr = {-1, -1, -1, 0, 0, 1, 1, 1};
	static final int[] dc = {-1, 0, 1, -1, 1, -1, 0, 1};
	
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		
		int T = io.getInt();
		for (int test = 1; test <= T; test++) {
			int R = io.getInt(), C = io.getInt(), M = io.getInt();
			int[][] res = solve(R, C, M);
			io.println("Case #" + test + ":");
			if (res == null) {
				io.println("Impossible");
			} else {
				addClick(R, C, M, res);
				for (int i = 0; i < R; i++) {
					for (int j = 0; j < C; j++) {
						io.write(cellChar[res[i][j]]);
					}
					io.write('\n');
				}
			}
		}
		
		io.close();
	}
	
	static int[][] solve(int R, int C, int M) {
		if (R > C) {
			int[][] trans = solve(C, R, M);
			if (trans == null) return null;
			int[][] res = new int[R][C];
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					res[i][j] = trans[j][i];
				}
			}
			return res;
		}
		
		if (R == 1) {
			int[][] res = new int[R][C];
			for (int i = 0; i < M; i++) {
				res[0][i] = MINE;
			}
			return res;
		}
		
		if (M == R*C-1) {
			int[][] res = new int[R][C];
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					res[i][j] = MINE;
				}
			}
			res[R-1][C-1] = EMPTY;
			return res;
		}
		
		int[][] res = new int[R][C];
		boolean[][] vis = new boolean[R][C];
		if (!solveRec(0, 0, M, R, C, res, vis)) {
			return null;
		}
		return res;
	}
	
	static boolean solveRec(int r, int c, int m, int R, int C, int[][] res, boolean[][] vis) {
		if (m == 0) {
			return true;
		}
		if (vis[r][c]) {
			return false;
		}
		vis[r][c] = true;
		int lr = R - r, lc = C - c;
		
		// Consume a row
		if (lc <= m && lr > 2) {
			if (solveRec(r + 1, c, m - lc, R, C, res, vis)) {
				for (int i = c; i < C; i++) {
					res[r][i] = MINE;
				}
				return true;
			}
		}
		
		// Consume a column
		if (lr <= m && lc > 2) {
			if (solveRec(r, c + 1, m - lr, R, C, res, vis)) {
				for (int i = r; i < R; i++) {
					res[i][c] = MINE;
				}
				return true;
			}
		}
		
		// Add around edges
		if (lc > 2 && lr > 2) {
			if (lc - 2 + Math.max(0, lr - 3) >= m) {
				for (int i = 0; i < m; i++) {
					if (i < lc - 2) {
						res[r][c+i] = MINE;
					} else {
						res[r + i - (lc - 2) + 1][c] = MINE;
					}
				}
				return true;
			}
		}
		
		return false;
	}
	
	static void addClick(int R, int C, int M, int[][] board) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (board[i][j] == EMPTY) {
					int cnt = 0;
					for (int k = 0; k < dr.length; k++) {
						int nr = i + dr[k], nc = j + dc[k];
						if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
							if (board[nr][nc] == MINE) {
								cnt++;
							}
						}
					}
					if (cnt == 0 || M == R*C-1) {
						board[i][j] = START;
						return;
					}
				}
			}
		}
	}
	
	static class Kattio extends PrintWriter {
	    public Kattio(InputStream i) {
		super(new BufferedOutputStream(System.out));
		r = new BufferedReader(new InputStreamReader(i));
	    }
	    public Kattio(InputStream i, OutputStream o) {
		super(new BufferedOutputStream(o));
		r = new BufferedReader(new InputStreamReader(i));
	    }

	    public boolean hasMoreTokens() {
		return peekToken() != null;
	    }

	    public int getInt() {
		return Integer.parseInt(nextToken());
	    }

	    public double getDouble() { 
		return Double.parseDouble(nextToken());
	    }

	    public long getLong() {
		return Long.parseLong(nextToken());
	    }

	    public String getWord() {
		return nextToken();
	    }

	    private BufferedReader r;
	    private String line;
	    private StringTokenizer st;
	    private String token;

	    private String peekToken() {
		if (token == null) 
		    try {
			while (st == null || !st.hasMoreTokens()) {
			    line = r.readLine();
			    if (line == null) return null;
			    st = new StringTokenizer(line);
			}
			token = st.nextToken();
		    } catch (IOException e) { }
		return token;
	    }

	    private String nextToken() {
		String ans = peekToken();
		token = null;
		return ans;
	    }
	}
}
