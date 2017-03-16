import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Lawnmower {

	static boolean hasLargerInRow(int n, int m, int x, int y, int[][] height) {
		for (int i = 0; i < m; ++i) {
			if (height[x][i] > height[x][y])
				return true;
		}
		return false;
	}

	static boolean hasLargerInCol(int n, int m, int x, int y, int[][] height) {
		for (int i = 0; i < n; ++i) {
			if (height[i][y] > height[x][y])
				return true;
		}
		return false;
	}

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub

		FileWriter fw = new FileWriter("out.txt");
		Scanner scan = new Scanner(System.in);
		int testCase = scan.nextInt();
		for (int t = 1; t <= testCase; ++t) {
			int n, m;
			n = scan.nextInt();
			m = scan.nextInt();
			int[][] height = new int[n][m];
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					height[i][j] = scan.nextInt();
				}
			}
			System.out.print("Case #" + t + ": ");
			fw.write("Case #" + t + ": ");
			
			boolean ok = false;
			for (int i = 0; i < n; ++i) {
				if (ok)
					break;
				for (int j = 0; j < m; ++j) {
					if (hasLargerInCol(n, m, i, j, height)
							&& hasLargerInRow(n, m, i, j, height)) {
						System.out.println("NO");
						fw.write("NO\n");
						ok = true;
						break;
					}

				}
			}
			if (!ok) {
				System.out.println("YES");
				fw.write("YES\n");
			}

		}
		fw.flush();
		fw.close();
		
	}

}
