import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Lawnmower {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("input.txt"));
		int T = sc.nextInt();
		PrintWriter out = new PrintWriter(new File("output.txt"));
		for (int t = 0; t < T; t++) {
			int n = sc.nextInt();
			int m = sc.nextInt();
			int[][] a = new int[n][m];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					a[i][j] = sc.nextInt();
				}
			}
			boolean[][] ok = new boolean[n][m];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					boolean h = true;
					boolean v = true;
					for (int ni = 0; ni < n; ni++) {
						if (a[ni][j] > a[i][j]) {
							h = false;
						}
					}
					for (int nj = 0; nj < m; nj++) {
						if (a[i][nj] > a[i][j]) {
							v = false;
						}
					}
					ok[i][j] = h || v;
				}
			}
			boolean good = true;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					good &= ok[i][j];
				}
			}
			out.println("Case #" + (t + 1) + ": " + (good ? "YES" : "NO"));
		}
		out.close();
	}
	
}
