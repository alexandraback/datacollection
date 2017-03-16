import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {

	public static boolean cango(int[][] c, int[][] f, int i, int j, int ni,
			int nj) {
		return f[ni][nj] <= c[ni][nj] - 50 && f[i][j] <= c[ni][nj] - 50
				&& f[ni][nj] <= c[i][j] - 50 && f[i][j] <= c[i][j] - 50;
	}

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int tN = sc.nextInt();
		sc.nextLine();
		for (int tn = 0; tn < tN; tn++) {
			int h = sc.nextInt();
			int n = sc.nextInt();
			int m = sc.nextInt();
			int[][] c = new int[n][m];
			int[][] f = new int[n][m];
			for(int i = 0; i < n; i++)
				for(int j = 0; j < m; j++)
					c[i][j] = sc.nextInt();
			for(int i = 0; i < n; i++)
				for(int j = 0; j < m; j++)
					f[i][j] = sc.nextInt();
			int[][] res = new int[n][m];
			Comparator<int[]> cmp = new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					for (int i = 0; i < a.length; i++) {
						if (a[i] != b[i])
							return a[i] - b[i];
					}
					return 0;
				}
			};
			PriorityQueue<int[]> q = new PriorityQueue<int[]>(1, cmp);
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					res[i][j] = -1;
			q.offer(new int[] { 0, 0, 0 });
			while (!q.isEmpty()) {
				int[] next = q.poll();
				if (res[next[1]][next[2]] != -1)
					continue;
				int i = next[1];
				int j = next[2];
				res[i][j] = next[0];
				for (int di = -1; di <= 1; di++)
					for (int dj = -1; dj <= 1; dj++) {
						int ni = i + di;
						int nj = j + dj;
						if (Math.abs(di) + Math.abs(dj) == 1 && ni >= 0
								&& nj >= 0 && ni < n && nj < m) {
							if (cango(c, f, i, j, ni, nj)) {
								if (next[0] == 0 && h <= c[ni][nj] - 50) {
									q.offer(new int[] { 0, ni, nj });
								} else {
									int time = Math.max(next[0], h - c[ni][nj] + 50);
									int level = Math.max(0, h - time - f[i][j]);
									if (level >= 20) {
										q.offer(new int[] { time + 10, ni, nj });
									} else {
										q.offer(new int[] { time + 100, ni, nj });
									}
								}
							}
						}
					}
			}
			pw.print("Case #" + (tn + 1) + ": " + res[n - 1][m - 1] * 0.1);
			pw.println();
		}
		pw.close();
	}
}
