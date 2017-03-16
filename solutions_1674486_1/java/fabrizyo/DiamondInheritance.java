package googlejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class DiamondInheritance {

	private static boolean[][] grid;

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("inputA.txt"));
		PrintWriter pw = new PrintWriter("outputA.txt");
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			int N = sc.nextInt();

			grid = new boolean[N][N];
			for (int i = 0; i < N; i++) {
				int M = sc.nextInt();
				for (int j = 0; j < M; j++) {
					grid[i][sc.nextInt() - 1] = true;
				}
			}

			boolean[] vis = new boolean[N];
			boolean found = false;
			for (int i = 0; i < vis.length; i++) {
				if (!vis[i]) {
					boolean[] conn = new boolean[N];
					find(i, conn);

					int NV = 0;
					for (boolean b : conn) {
						if (b) {
							NV++;
						}
					}

					int NE = 0;
					for (int j = 0; j < conn.length; j++) {
						if (conn[j]) {
							for (int k = 0; k < conn.length; k++) {
								if (grid[j][k]) {
									NE++;
								}
							}
						}
					}

					found = NE + 1 != NV;
					if (found) {
						break;
					}
				}
			}

			pw.println("Case #" + t + ": " + (!found ? "No" : "Yes"));
		}
		pw.flush();
		pw.close();
	}

	private static void find(int index, boolean[] conn) {
		if (!conn[index]) {
			conn[index] = true;
			for (int i = 0; i < conn.length; i++) {
				if (!conn[i] && grid[index][i]) {
					find(i, conn);
				}
			}
		}

	}
}
