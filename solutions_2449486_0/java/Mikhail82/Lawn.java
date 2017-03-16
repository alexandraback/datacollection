import java.io.*;
import java.util.*;

public class Lawn {

	public static String getLine(BufferedReader buf) {
		String ret = null;
		try {
			ret = buf.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return ret;
	}

	public static void main(String[] args) {
		BufferedReader buf = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(getLine(buf));
		for (int i = 0; i < T; i++) {
			String[] tok = getLine(buf).split(" ");
			int N = Integer.parseInt(tok[0]);
			int M = Integer.parseInt(tok[1]);
			int[][] grid = new int[N][M];
			for (int j = 0; j < N; j++) {
				String[] line = getLine(buf).split(" ");
				int[] r = new int[M];
				for (int k = 0; k < M; k++) r[k] = Integer.parseInt(line[k]);
				grid[j] = r;
			}
			int[] rowCuts = new int[N];
			for (int j = 0; j < grid.length; j++) {
				int maxHeight = -100;
				for (int k = 0; k < grid[0].length; k++) {
					if (grid[j][k] > maxHeight) {
						maxHeight = grid[j][k];
					}
				}
				rowCuts[j] = maxHeight;
			}
			int[] colCuts = new int[M];
			for (int j = 0; j < grid[0].length; j++) {
				int maxHeight = -100;
				for (int k = 0; k < grid.length; k++) {
					if (grid[k][j] > maxHeight) {
						maxHeight = grid[k][j];
					}
				}
				colCuts[j] = maxHeight;
			}
			boolean pass = true;
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < M; k++) {
					if (grid[j][k] != (rowCuts[j]<colCuts[k]?rowCuts[j]:colCuts[k])) {
						pass = false;
						break;
					}
				}
			}
			if (pass) System.out.println("Case #" + (i+1) + ": YES");
			else System.out.println("Case #" + (i+1) + ": NO");
		}
	}

}
