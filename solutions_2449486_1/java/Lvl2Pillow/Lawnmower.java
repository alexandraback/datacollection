import java.io.*;

public class Lawnmower {
	public static void main (String[] args) {
		try {
			BufferedReader br = new BufferedReader(new FileReader("B-large.in"));
			// read T
			int T = Integer.parseInt(br.readLine());
			for (int i = 1; i <= T; i++) {
				// read length and width
				String temp = br.readLine();
				String[] split = temp.split("\\s+");
				int N = Integer.parseInt(split[0]);
				int M = Integer.parseInt(split[1]);
				int[][] lawn = new int[M][N];
				// create lawn in 2D array
				for (int j = 0; j < N; j++) {
					temp = br.readLine();
					split = temp.split("\\s+");
					for (int k = 0; k < M; k++) {
						lawn[k][j] = Integer.parseInt(split[k]);
					}
				}
				// test pattern
				if (testPattern(lawn))
					System.out.println("Case #" + i + ": YES");
				else
					System.out.println("Case #" + i + ": NO");
			}
			br.close();
		} catch (IOException ioe) {
			;
		}
	}
	
	public static boolean testPattern (int[][] lawn) {
		int M = lawn.length;
		int N = lawn[0].length;
		// 2 arrays to store maximum height for each row and each column
		int[] rowMax = new int[N];
		int[] colMax = new int[M];
		// initialise maximum height to 0
		for (int i = 0; i < N; i++)
			rowMax[i] = 0;
		for (int i = 0; i < M; i++)
			colMax[i] = 0;
		// find max height for each row
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (rowMax[i] < lawn[j][i])
					rowMax[i] = lawn[j][i];
		// find max height for each col
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				if (colMax[i] < lawn[i][j])
					colMax[i] = lawn[i][j];
		// attempt to recreate pattern from a new lawn (e.g. height = 100)
		int[][] newLawn = new int[M][N];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				newLawn[j][i] = Math.min(100, Math.min(rowMax[i], colMax[j]));
		// check if newLawn == lawn
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (lawn[j][i] != newLawn[j][i])
					return false;
		// else
		return true;
	}
}
