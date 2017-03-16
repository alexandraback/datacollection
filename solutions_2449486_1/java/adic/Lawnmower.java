import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class Lawnmower {
	
	public static final void main(String[] params) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("Lawnmower.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("Lawnmower.out"));
		int count = Integer.parseInt(br.readLine().trim());
		for (int test = 0; test < count; test++) {
			String[] parts = br.readLine().split(" +");
			int n = Integer.parseInt(parts[0]);
			int m = Integer.parseInt(parts[1]);
			int[][] x = new int[n][m];
			for (int i = 0; i < n; i++) {
				parts = br.readLine().split(" +");
				for (int j = 0; j < m; j++) {
					x[i][j] = Integer.parseInt(parts[j]);
				}
			}
			bw.write("Case #" + (test+1) + ": " + (new Lawnmower().solve(x, n, m) ? "YES" : "NO"));
			bw.newLine();
		}
		bw.close();
		br.close();
	}
	
	private boolean solve(int[][] x, int n, int m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				boolean isTop = true;
				for (int k = 0; k < m; k++) {
					if (x[i][k] > x[i][j]) {
						isTop = false;
						break;
					}
				}
				if (!isTop) {
					isTop = true;
					for (int k = 0; k < n; k++) {
						if (x[k][j] > x[i][j]) {
							isTop = false;
							break;
						}
					}
					if (!isTop) {
						return false;
					}
				}
			}
		}
		return true;
	}
	
}
