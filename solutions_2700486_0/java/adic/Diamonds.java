import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class Diamonds {
	
	public static final void main(String[] params) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("Diamonds.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("Diamonds.out"));
		int count = Integer.parseInt(br.readLine().trim());
		for (int test = 0; test < count; test++) {
			String[] parts = br.readLine().split(" ");
			int n = Integer.parseInt(parts[0]);
			int x = Integer.parseInt(parts[1]);
			int y = Integer.parseInt(parts[2]);
			bw.write("Case #" + (test+1) + ": " + new Diamonds().solve(n, x, y));
			bw.newLine();
		}
		bw.close();
		br.close();
	}
	
	private int[][] a;
	private int[][] f;
	private int m, total;
	
	private double solve(int n, double x, double y) {
		m = n + 1 + n % 2;
		a = new int[m][m];
		f = new int[m][m];
		total = 0;
		rec(n, 0, 0);
		int i = m/2, j = m/2;
		i  = (int) Math.round(i - y/2 - x/2);
		j = (int) Math.round(j - y/2 + x/2);
		if (i < 0 || j < 0) return 0;
		return ((double) f[i][j]) / total;
	}
	
	private void rec(int n, int i, int j) {
		if (n == 0) {
			copy(); total++;
		} else {
			if (i + j == m - 1) {
				a[i][j] = 1;
				rec(n - 1, 0, 0);
				a[i][j] = 0;
				return;
			}
			while (a[i+1][j+1] == 0 && a[i+1][j] == 0 && a[i][j+1] == 0) {
				i++; j++;
				if (i + j == m - 1) {
					a[i][j] = 1;
					rec(n - 1, 0, 0);
					a[i][j] = 0;
					return;
				}
			}
			if (a[i][j+1] == 1 && a[i+1][j] == 1) {
				a[i][j] = 1;
				rec(n-1, 0, 0);
				a[i][j] = 0;
				return;
			}
			if (a[i][j+1] == 0) {
				rec(n, i, j+1);
			}
			if (a[i+1][j] == 0) {
				rec(n, i+1, j);
			}
		}
	}
	
	private void copy() {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				f[i][j] += a[i][j];
			}
		}
	}

}
