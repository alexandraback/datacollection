import java.io.*;
import java.util.*;

class lawnmower {
	public static void main (String [] args) throws IOException {
		long start = System.currentTimeMillis();
		BufferedReader br = new BufferedReader(new FileReader("lawnmower.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("lawnmower.out")));
		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			int[][] heights = new int[N][M];
			for (int j = 0; j < N; j++) {
				st = new StringTokenizer(br.readLine());
				for (int k = 0; k < M; k++) {
					heights[j][k] = Integer.parseInt(st.nextToken());
				}
			}
			boolean possible = true;
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < M; k++) {
					if (!checkRow(heights, j, k, N, M) && !checkCol(heights, j, k, N, M)) possible = false;
					if (!possible) break;
				}
				if (!possible) break;
			}
			String answer = possible ? "YES" : "NO";
			out.println("Case #" + (i+1) + ": " + answer);
		}
		long end = System.currentTimeMillis();
		System.out.println(end-start);
		out.close();
		System.exit(0);
	}
	public static boolean checkRow(int[][] heights, int j, int k, int N, int M) {
		for (int i = 0; i < N; i++) {
			if (heights[i][k] > heights[j][k]) return false;
		}
		return true;
	}
	public static boolean checkCol(int[][] heights, int j, int k, int N, int M) {
		for (int i = 0; i < M; i++) {
			if (heights[j][i] > heights[j][k]) return false;
		}
		return true;
	}
}

