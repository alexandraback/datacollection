import java.util.*;
import java.io.*;
import java.math.*;

import static java.lang.Math.*;

public class Solution implements Runnable {
	
	boolean hasMines(int R, int C, int r, int c) {
		for (int dr = -1; dr <= 1; dr++)
			for (int dc = -1; dc <= 1; dc++)
				if (r + dr >= 0 && r + dr < R && c + dc >= 0 && c + dc < C && grid[r + dr][c + dc] == '*')
					return true;
		return false;
	}
	
	char grid[][];
	boolean u[][];
	
	void dfs (int R, int C, int r, int c) {
		if (u[r][c]) return;
		u[r][c] = true;
		if (hasMines(R, C, r, c)) return;
		for (int dr = -1; dr <= 1; dr++)
			for (int dc = -1; dc <= 1; dc++)
				if (r + dr >= 0 && r + dr < R && c + dc >= 0 && c + dc < C && grid[r + dr][c + dc] == '.')
					dfs(R, C, r + dr, c + dc);
	}
	
	char[][] stupidSolve(int R, int C, int mines) {
		int total = R * C;
		grid = new char[R][C];
		u = new boolean [R][C];
		for (int mask = 0; mask < (1 << total); mask++) {
			if (Integer.bitCount(mask) != mines) continue;
			for (int i = 0; i < R; i++)
				for (int j = 0; j < C; j++) {
					grid[i][j] = '.';
					u[i][j] = false;
				}
			for (int i = 0; i < total; i++) {
				if (((1 << i) & mask) != 0) {
					grid[i / C][i % C] = '*';
				}
			}
			
			outer:
			for (int r = 0; r < R; r++)
				for (int c = 0; c < C; c++)
					if (grid[r][c] == '.' && !hasMines(R, C, r, c)) {
						dfs(R, C, r, c);
						break outer;
					}
			
			boolean good = true;
			
			outer:
			for (int r = 0; r < R; r++)
				for (int c = 0; c < C; c++)
					if (grid[r][c] == '.' && !u[r][c]) {
						good = false;
						break outer;
					}
			
			if (good)
				return grid;
		}
		return null;
	}
	
	public void solve() throws Exception {
		int tests = sc.nextInt();
		for (int test = 0; test < tests; test++) {
			out.print(String.format("Case #%d:\n", test + 1));
			int r = sc.nextInt();
			int c = sc.nextInt();
			int need = sc.nextInt();
			
			if (need == r * c - 1) {
				for (int i = 0; i < r; i++) {
					for (int j = 0; j < c; j++) {
						if (i == 0 && j == 0) {
							out.print("c");
						} else {
							out.print("*");
						}
					}
					out.println();
				}
				continue;
			}
			
			boolean dp[][][] = new boolean [c + 1][r + 1][r * c + 1];
			int pr[][][] = new int [c + 1][r + 1][r * c + 1];
			int pmines[][][] = new int [c + 1][r + 1][r * c + 1];
			
			int fillingsAdd[][][] = new int [c][r + 1][r + 1];
			for (int column = 1; column < c; column++) {
				for (int pre = 1; pre <= r; pre++) {
					for (int place = 1; place <= r; place++) {
						int totalFill = 0;
						int columnFill = place + (place != r ? 1 : 0);
						int previousFill = pre + (pre != r ? 1 : 0);
						totalFill += columnFill;
						if (column != c - 1)
							totalFill += columnFill;
						totalFill -= min(previousFill, columnFill);
						fillingsAdd[column][pre][place] = totalFill;
					}
				}
			}
			
			// initial	
			for (int mines = 1; mines <= r; mines++) {
				int columnFill = mines + (mines != r ? 1 : 0);
				int totalFill = columnFill + (c != 1 ? columnFill : 0);
				dp[1][mines][totalFill] = true;
			}
			
			int ansC = -1;
			int ansPlaced = -1;
			int ansFills = -1;
			
			outer:
			for (int column = 1; column <= c; column++) {
				for (int prev = 1; prev <= r; prev++) {
					for (int fillings = 0; fillings <= r * c; fillings++) {
						if (dp[column][prev][fillings]) {
							if (fillings == r * c - need) {
								ansC = column;
								ansPlaced = prev;
								ansFills = fillings;
								break outer;
							}
							if (column != c) {
								for (int place = prev; place >= 0; place--) {
									int nextFillings = fillings + fillingsAdd[column][prev][place];
									dp[column + 1][place][nextFillings] = true;
									pr[column + 1][place][nextFillings] = prev;
									pmines[column + 1][place][nextFillings] = fillings;
								}
							}
						}
					}
				}
			}
			
			if (ansC == -1) {
				out.println("Impossible");
			} else {
				char answer [][] = new char[r][c];
				for (int i = 0; i < r; i++)
					for (int j = 0; j < c; j++)
						answer[i][j] = '*';
				
				int column = ansC;
				int placed = ansPlaced;
				int fills = ansFills;
				
				while (column != 0) {
					int fill = placed + (placed != r ? 1 : 0);
					for (int i = 0; i < fill; i++) {
						if (column - 2 >= 0)
							answer[i][column - 2] = '.';
						answer[i][column - 1] = '.';
						if (column != c)
							answer[i][column] = '.';
					}
					int tplaced = pr[column][placed][fills];
					int tfills = pmines[column][placed][fills];
					column--;
					placed = tplaced;
					fills = tfills;
				}
				answer[0][0] = 'c';
				for (int i = 0; i < r; i++) {
					for (int j = 0; j < c; j++) {
						out.print(answer[i][j]);
					}
					out.println();
				}
			}
			
		}
	}


	static Throwable t;

	BufferedReader in;
	FastScanner sc;
	PrintWriter out;

	@Override
	public void run() {
		try {
			in = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter(new FileWriter("output.txt"));
			//in = new BufferedReader(new InputStreamReader(System.in));
			//out = new PrintWriter(System.out);
			sc = new FastScanner(in);
			solve();
		} catch (Throwable t) {
			Solution.t = t;
		} finally {
			out.close();
		}
	}

	public static void main(String[] args) throws Throwable {
		Thread thread = new Thread(null, new Solution(), "", 1 << 26);
		thread.start();
		thread.join();
		if (Solution.t != null)
			throw t;
	}

}

class FastScanner {

	BufferedReader in;
	StringTokenizer st;

	public FastScanner(BufferedReader in) {
		this.in = in;
	}

	public String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	public int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	public long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	public double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}

}