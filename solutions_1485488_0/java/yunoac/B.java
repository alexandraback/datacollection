package R1B_2012;

import java.io.*;
import java.util.*;

public class B {

	static BufferedWriter writer;

	public static void main(String[] args) throws IOException {
		writer = new BufferedWriter(new FileWriter("output.out"));
		Scanner reader = new Scanner(new FileReader("input.in"));
		int nt = reader.nextInt();
		reader.nextLine();
		for (int tc = 1; tc <= nt; tc++) {
			System.out.println(tc);
			writer.write("Case #" + tc + ": ");
			//TODO: code here
			int H = reader.nextInt();
			int N = reader.nextInt();
			int M = reader.nextInt();
			int[][] ceil = new int[N][M];
			int[][] floor = new int[N][M];
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < M; j++) {
					ceil[i][j] = reader.nextInt();
				}
			}
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < M; j++) {
					floor[i][j] = reader.nextInt();
				}
			}
			double t = solve(H, N, M, ceil, floor);
			writer.write(Double.toString(t));
			writer.newLine();
		}
		writer.close();
		System.out.println("Done.");
	}

	static final int[][] moves = new int[][] {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

	static double solve(int h, int n, int m, int[][] ceil, int[][] floor) {
		boolean[][] visited = new boolean[n][m];
		PriorityQueue<S> Q = new PriorityQueue<S>();
		Q.add(new S(0, 0, h, 0.0, false));
		visited[0][0] = true;
		while(Q.peek().i != n - 1 || Q.peek().j != m -1) {
			S cur = Q.poll();
			for(int[] move : moves) {
				int iDest = cur.i + move[0];
				int jDest = cur.j + move[1];
				if(0 <= iDest && iDest < n && 0 <= jDest && jDest < m && !visited[iDest][jDest]) {
					if(cur.h + 50 <= ceil[iDest][jDest] && floor[cur.i][cur.j] + 50 <= ceil[iDest][jDest] && floor[iDest][jDest] + 50 <= ceil[iDest][jDest] && floor[iDest][jDest] + 50 <= ceil[cur.i][cur.j]) { // Can move without waiting
						if(!cur.hasWaited) {
							visited[iDest][jDest] = true;
							Q.add(new S(iDest, jDest, cur.h, 0, false));
						} else {
							if(cur.h - floor[cur.i][cur.j] >= 20) {
								visited[iDest][jDest] = true;
								Q.add(new S(iDest, jDest, cur.h - 10, cur.t + 1, true));
							} else {
								visited[iDest][jDest] = true;
								Q.add(new S(iDest, jDest, cur.h - 100, cur.t + 10, true));
							}
						}
					} else if(floor[cur.i][cur.j] + 50 <= ceil[iDest][jDest] && floor[iDest][jDest] + 50 <= ceil[iDest][jDest] && floor[iDest][jDest] + 50 <= ceil[cur.i][cur.j]) { // Have to wait
						double dt = (50 + cur.h - ceil[iDest][jDest]) / 10.0;
						double newH = cur.h - (50 + cur.h - ceil[iDest][jDest]);
						if(newH - floor[cur.i][cur.j] >= 20) {
							visited[iDest][jDest] = true;
							Q.add(new S(iDest, jDest, newH - 10, cur.t + dt + 1, true));
						} else {
							visited[iDest][jDest] = true;
							Q.add(new S(iDest, jDest, newH - 100, cur.t + dt + 10, true));
						}
					}
				}
			}
		}
		return Q.peek().t;
	}

	static class S implements Comparable<S> {

		int i, j;
		double h, t;
		boolean hasWaited = false;

		public S(int i, int j, double h, double t, boolean hasWaited) {
			this.i = i;
			this.j = j;
			this.h = h;
			this.t = t;
			if(h < 0) {
				h = 0;
			}
			this.hasWaited = hasWaited;
		}

		public String toString() {
			return i + " " + j + " " + h + " " + t + " " + hasWaited;
		}

		@Override
		public int compareTo(S o) {
			return Double.compare(t, o.t);
		}

	}
}


