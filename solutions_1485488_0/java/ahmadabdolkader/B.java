package cj2012.OneB;

import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class B {
	static final int[] dx = new int[]{0, 1, 0, -1};
	static final int[] dy = new int[]{1, 0, -1, 0};
	
	static class State implements Comparable<State> {
		int i, j, t;
		public State(int i, int j, int t) {
			this.i = i;
			this.j = j;
			this.t = t;
		}
		public boolean isValid(int N, int M) {
			if (i < 0 || i >= N) return false;
			if (j < 0 || j >= M) return false;
			return true;
		}
		public int compareTo(State s) {
			return t - s.t;
		}
	}
	
	public static int valid(int i, int j, int x, int y, int[][] c, int[][] f, int H, int t) {
		if (c[x][y] - f[x][y] < 50) return 1;
		if (c[x][y] - f[i][j] < 50) return 1;
		if (c[i][j] - f[x][y] < 50) return 1;
		if (c[x][y] - H + t < 50) return 2;
		return 0;
	}
	
	public static void main(String[] args) throws Exception {
		String fileName = "B-small-attempt0";
		Scanner scan = new Scanner(new File("in/" + fileName + ".in"));
		int T = scan.nextInt(); scan.nextLine();
		PrintWriter out = new PrintWriter(new File("out/" + fileName + ".txt"));
		for (int z = 1; z <= T; z++) {
			int H = scan.nextInt();
			int N = scan.nextInt();
			int M = scan.nextInt();
			int[][] c = new int[N][M];
			int[][] f = new int[N][M];
			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					c[i][j] = scan.nextInt();
			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					f[i][j] = scan.nextInt();
			int[][] can = new int[N][M];
			PriorityQueue<State> q = new PriorityQueue<>();
			q.add(new State(0, 0, 0));
			while (!q.isEmpty()) {
				State s = q.poll();
				can[s.i][s.j] = 1;
				for (int d = 0; d < 4; d++) {
					State s2 = new State(s.i + dx[d], s.j + dy[d], 0);
					if (!s2.isValid(N, M)) continue;
					if (valid(s.i, s.j, s2.i, s2.j, c, f, H, 0) != 0) continue;
					if (can[s2.i][s2.j] == 0)
						q.add(s2);
				}
			}
			int bestTime = Integer.MAX_VALUE;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (can[i][j] != 1) continue;
					int[][] best = new int[N][M];
					for (int[] r : best) Arrays.fill(r, Integer.MAX_VALUE);
					q.add(new State(i, j, 0));
					while (!q.isEmpty()) {
						State s = q.poll();
						if (best[s.i][s.j] <= s.t)
							continue;
						best[s.i][s.j]= s.t; 
						if (s.i == N - 1 && s.j == M - 1) {
							bestTime = Math.min(bestTime, s.t);
							continue;
						}
						for (int d = 0; d < 4; d++) {
							State s2 = new State(s.i + dx[d], s.j + dy[d], s.t);
							if (!s2.isValid(N, M)) continue;
							if (valid(s.i, s.j, s2.i, s2.j, c, f, H, s2.t) == 1) continue;
							while (valid(s.i, s.j, s2.i, s2.j, c, f, H, s2.t) == 2)
								s2.t ++;
							if (valid(s.i, s.j, s2.i, s2.j, c, f, H, s2.t) != 0) continue;
							s2.t += Double.compare(H - s2.t, f[s.i][s.j] + 20) >= 0? 10 : 100;
							q.add(s2);
						}
					}
				}
			}
			out.printf("Case #%d: %.6f\n", z, bestTime / 10.0);
		}
		out.close();
	}
}
