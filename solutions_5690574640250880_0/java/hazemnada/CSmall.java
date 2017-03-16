import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class CSmall {
	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader buf = new BufferedReader(new FileReader("C-small-attempt0.in"));
		PrintWriter writer = new PrintWriter("Csmall.out");
		int tCases = Integer.parseInt(buf.readLine().trim());
		for (int t = 1; t <= tCases; t++) {
			System.out.println(t);
			StringTokenizer str = new StringTokenizer(buf.readLine().trim());
			r = Integer.parseInt(str.nextToken());
			c = Integer.parseInt(str.nextToken());
			m = Integer.parseInt(str.nextToken());
//			dp = new boolean[1 << (r * c)][r * c];
			flag = false;
			dx = new int[] { 0, -1, -1, -1, 0, 1, 1, 1 };
			dy = new int[] { -1, -1, 0, 1, 1, 1, 0, -1 };
			go(0, m, 0);
			writer.printf("Case #%d:\n", t);
			if (flag) {
				for (int i = 0; i < r; i++)
					writer.println(new String(answer[i]));
			} else {
				writer.println("Impossible");
			}
		}
		writer.close();
	}

	static int r, c, m;
//	static boolean[][] dp;
	static char[][] answer;
	static boolean flag;

	static void go(int msk, int rem, int index) {
		if (rem == 0) {
			if (check(msk)) {
				flag = true;
			}
			return;
		}
		if (index >= r * c)
			return;
		if (!flag) {
//			dp[msk][index] = true;
			go(msk, rem, index + 1);
			go(msk | (1 << index), rem - 1, index + 1);
		}
	}

	static int[] dx;
	static int[] dy;

	private static boolean check(int msk) {
		char[][] a = new char[r][c];
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++) {
				if ((msk & (1 << (i * c + j))) == 0) {
					a[i][j] = '.';
				} else
					a[i][j] = '*';
			}
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				if (a[i][j] != '*') {
					Queue<Integer> q = new LinkedList<Integer>();
					boolean[][] v = new boolean[r][c];
					q.add(i);
					q.add(j);
					int cnt = 0;
					loop: while (!q.isEmpty()) {
						int x = q.poll();
						int y = q.poll();
						if (v[x][y])
							continue;
						v[x][y] = true;
						cnt++;
						for (int k = 0; k < dx.length; k++) {
							if (x + dx[k] < r && y + dy[k] < c
									&& x + dx[k] >= 0 && y + dy[k] >= 0) {
								if (a[x + dx[k]][y + dy[k]] == '*')
									continue loop;
							}
						}
						for (int k = 0; k < dx.length; k++) {
							if (x + dx[k] < r && y + dy[k] < c
									&& x + dx[k] >= 0 && y + dy[k] >= 0) {
								q.add(x + dx[k]);
								q.add(y + dy[k]);
							}
						}

					}
					if (cnt == r * c - m) {
						a[i][j] = 'c';
						answer = a;
						return true;
					}
				}
		return false;
	}
}
