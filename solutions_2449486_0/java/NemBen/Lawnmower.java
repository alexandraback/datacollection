import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class Lawnmower {

	public static void solve(String file) throws Exception {
		BufferedReader reader = new BufferedReader(new FileReader(new File("./"
				+ file + ".in")));
		BufferedWriter writer = new BufferedWriter(new FileWriter(new File("./"
				+ file + ".out"), false));

		try {
			int num = Integer.parseInt(reader.readLine());

			String[] cols;
			for (int n = 1; n <= num; ++n) {
				cols = reader.readLine().split("\\s");
				int rows = Integer.parseInt(cols[0]);
				int columns = Integer.parseInt(cols[1]);

				int[][] height = new int[rows][columns];
				for (int i = 0; i < rows; ++i) {
					cols = reader.readLine().split("\\s");
					for (int j = 0; j < columns; ++j) {
						height[i][j] = Integer.parseInt(cols[j]);
					}
				}

				boolean[][][] maxUntil = new boolean[rows][columns][4];
				for (int i = 0; i < rows; ++i) {
					int max;
					max = -1;
					for (int j = 0; j < columns; ++j) {
						if (height[i][j] >= max) {
							max = height[i][j];
							maxUntil[i][j][0] = true;
						}
					}

					max = -1;
					for (int j = columns - 1; j >= 0; --j) {
						if (height[i][j] >= max) {
							max = height[i][j];
							maxUntil[i][j][1] = true;
						}
					}
				}
				for (int j = 0; j < columns; ++j) {
					int max;
					max = -1;
					for (int i = 0; i < rows; ++i) {
						if (height[i][j] >= max) {
							max = height[i][j];
							maxUntil[i][j][2] = true;
						}
					}

					max = -1;
					for (int i = rows - 1; i >= 0; --i) {
						if (height[i][j] >= max) {
							max = height[i][j];
							maxUntil[i][j][3] = true;
						}
					}
				}

				boolean possible = true;
				loop: for (int i = 0; i < rows; ++i) {
					for (int j = 0; j < columns; ++j) {
						if (!(maxUntil[i][j][0] && maxUntil[i][j][1])
								&& !(maxUntil[i][j][2] && maxUntil[i][j][3])) {
							possible = false;
							break loop;
						}
					}
				}

				writer.write("Case #" + n + ": " + (possible ? "YES" : "NO"));
				writer.newLine();

			}
		} finally {
			writer.close();
			reader.close();
		}
	}

	public static void main(String[] args) throws Exception {
		solve("small2");
	}

}
