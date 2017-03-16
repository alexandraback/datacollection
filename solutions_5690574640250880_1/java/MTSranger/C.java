import java.io.File;
import java.util.*;

public class C {

	static int[] dx = {-1, 0, 1, -1, 1, -1, 0, 1};
	static int[] dy = {-1, -1, -1, 0, 0, 1, 1, 1};
	
	public static void fillNumbers(int[][] b) {
		int r = b.length;
		int c = b[0].length;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (b[i][j] == -2) continue;
				int mines = 0;
				for (int k = 0; k < 8; k++) {
					int ii = i+dx[k];
					int jj = j+dy[k];
					if (ii >= 0 && ii < r && jj >= 0 && jj < c && b[ii][jj] == -2) {
						mines++;
					}
				}
				b[i][j] = mines;
			}
		}
	}
	
	public static int findStart(int[][] b) {
		int r = b.length;
		int c = b[0].length;
		int s = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (b[i][j] == 0) {
					return i*c+j;
				} else if (b[i][j] > 0) {
					s = i*c+j;
				}
			}
		}
		return s;
	}
	
	public static boolean isWin(int[][] b) {
		int r = b.length;
		int c = b[0].length;
		boolean[][] bb = new boolean[r][c];
		PriorityQueue<Integer> q = new PriorityQueue<Integer>();
		
		fillNumbers(b);
		
		// find a place to click
		int start = findStart(b);
		int sr = start/c;
		int sc = start%c;
		if (b[sr][sc] == 0) {
			q.add(start);
		}
		b[sr][sc] = -1;
		bb[sr][sc] = true;
		
		// flood fill
		while (!q.isEmpty()) {
			int curr = q.poll();
			int i = curr/c;
			int j = curr%c;
			for (int k = 0; k < 8; k++) {
				int ii = i+dx[k];
				int jj = j+dy[k];
				if (ii >= 0 && ii < r && jj >= 0 && jj < c && !bb[ii][jj]) {
					bb[ii][jj] = true;
					if (b[ii][jj] == 0) {
						q.add(ii*c+jj);
					}
				}
			}
		}
		
		// test if all visited
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (b[i][j] != -2 && !bb[i][j]) {
					return false;
				}
			}
		}
		return true;
	}

	public static boolean dfs(int[][] b, int r0, int c0, int s, int m) {
		int r = b.length;
		int c = b[0].length;
		int rr = r - r0;
		int cc = c - c0;
		
		if (m == 0) {
			return isWin(b);
		}
		for (int ss = s; ss <= rr*cc-m; ss++) {
			int i = ss/cc + r0;
			int j = ss%cc + c0;
			b[i][j] = -2;
			boolean res = dfs(b, r0, c0, ss+1, m-1);
			if (res) return true;
			b[i][j] = 0;
		}
		return false;
	}
	
	public static boolean solve(int[][] b, int m, boolean transpose) {
		int r = b.length;
		int c = b[0].length;
		
		if (m < r || m == r*c-1 || r <= 2 || c <= 2) {
			if ((r == 2 || c == 2) && m%2 != 0 && m != r*c-1) {
				return false;
			}
			if (r <= 2) {
				int[][] bb = new int[c][r];
				if (dfs(bb, 0, 0, 0, m)) {
					for (int i = 0; i < r; i++) {
						for (int j = 0; j < c; j++) {
							b[i][j] = bb[j][i];
						}
					}
					return true;
				}
				return false;
			}
			return dfs(b, 0, 0, 0, m);
		}
		
		for (int c0 = 0; c0 <= c-2; c0++) {
			int mleft = m - r*c0;
			int cleft = c - c0;
			if (mleft < 0) break;
			if (c0 > 0) {
				for (int i = 0; i < r; i++) {
					b[i][c0-1] = -2;
				}
			}
			if (mleft % (c - c0) <= c - c0 - 2 && (mleft/cleft < r-2 || (mleft%cleft == 0 && mleft/cleft == r-2))) {
				return dfs(b, 0, c0, 0, m - r*c0);
			}
		}
		if (!transpose) {
			int[][] bb = new int[c][r];
			if (solve(bb, m, true)) {
				for (int i = 0; i < r; i++) {
					for (int j = 0; j < c; j++) {
						b[i][j] = bb[j][i];
					}
				}
				return true;
			}
		}
		return false;
	}
	
	public static void print(int[][] b) {
		int r = b.length;
		int c = b[0].length;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				int d = b[i][j];
				if (d >= 0) {
					System.out.print('.');
				} else if (d == -1) {
					System.out.print('c');
				} else if (d == -2) {
					System.out.print('*');
				}
			}
			System.out.println();
		}
	}
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new File("C2.in"));
		int n = sc.nextInt();
		for (int csnum = 1; csnum <= n; csnum++) {
			int r = sc.nextInt();
			int c = sc.nextInt();
			int m = sc.nextInt();
			
			int[][] b = new int[r][c];
			System.out.println("Case #" + csnum + ":");
			if (solve(b, m, false)) {
				print(b);
			} else {
				System.out.println("Impossible");
			}
		}
	}
}
