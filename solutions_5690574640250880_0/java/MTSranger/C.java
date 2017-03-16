import java.io.File;
import java.util.*;

public class C {

	public static boolean dfs(int[][] b, int s, int m) {
		int r = b.length;
		int c = b[0].length;
		int[] dx = {-1, 0, 1, -1, 1, -1, 0, 1};
		int[] dy = {-1, -1, -1, 0, 0, 1, 1, 1};
		if (m == 0) {
			boolean[][] bb = new boolean[r][c];
			PriorityQueue<Integer> q = new PriorityQueue<Integer>();
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
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (b[i][j] == 0) {
						b[i][j] = -1;
						q.add(i*c+j);
						bb[i][j] = true;
						i = 1000000;
						break;
					}
				}
			}
			if (q.isEmpty()) {
				for (int i = 0; i < r; i++) {
					for (int j = 0; j < c; j++) {
						if (b[i][j] >= 0) {
							b[i][j] = -1;
							bb[i][j] = true;
							i = 1000000;
							break;
						}
					}
				}
			}
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
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (b[i][j] != -2 && !bb[i][j]) {
						return false;
					}
				}
			}
			return true;
		}
		for (int ss = s; ss <= r*c-m; ss++) {
			int i = ss/c;
			int j = ss%c;
			b[i][j] = -2;
			boolean res = dfs(b, ss+1, m-1);
			if (res) return true;
			b[i][j] = 0;
		}
		return false;
	}
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new File("C1.in"));
		int n = sc.nextInt();
		for (int csnum = 1; csnum <= n; csnum++) {
			int r = sc.nextInt();
			int c = sc.nextInt();
			int m = sc.nextInt();
			int[][] b = new int[r][c];
			System.out.println("Case #" + csnum + ":");
			if (dfs(b, 0, m)) {
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
			} else {
				System.out.println("Impossible");
			}
		}
	}
}
