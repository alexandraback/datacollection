import java.util.Scanner;
//1
//12 1 3

public class Second {
	static int grid[][] = new int[100][100];
	static double pr[][][] = new double[21][100][100];
	static int shiftJ = 50;

	static void go(double p, int n) {
		if (n > 20)
			return;

		int i = 0, j = shiftJ;
		if (n == 1) {
			grid[i][j] = 1;
			pr[1][i][j] = p;
			go(p, n + 1);
			return;
		}
		while (grid[i][j] != 0)
			i += 2;
		if (grid[i - 1][j - 1] == grid[i - 1][j + 1]) {
			if (grid[i - 1][j + 1] == 1) {
				grid[i][j] = 1;
				pr[n][i][j] += p;
				go(p, n + 1);
				grid[i][j] = 0;
			} else {
				int initi = i, initj = j;
				p *= .5;
				// take left
				while (i > 0 && grid[i - 1][j - 1] == 0) {
					i--;
					j--;
				}
				grid[i][j] = 1;
				pr[n][i][j] += p;
				go(p, n + 1);
				grid[i][j] = 0;

				i = initi;
				j = initj;
				int cnt = 0;
				// take right
				while (i > 0 && grid[i - 1][j + 1] == 0) {
					i--;
					j++;
					cnt++;
				}
				grid[i][j] = 1;
				pr[n][i][j] += p;
				go(p, n + 1);
				grid[i][j] = 0;
			}
		} else {
			boolean ok = false;
			// try left
			while (i > 0 && grid[i - 1][j - 1] == 0) {
				i--;
				j--;
				ok = true;
			}
			if (ok) {
				grid[i][j] = 1;
				pr[n][i][j] += p;
				go(p, n + 1);
				grid[i][j] = 0;
			} else {
				// try right
				while (i > 0 && grid[i - 1][j + 1] == 0) {
					i--;
					j++;
				}
				grid[i][j] = 1;
				pr[n][i][j] += p;
				go(p, n + 1);
				grid[i][j] = 0;
			}
		}
	}

	public static void main(String[] args) {
		go(1, 1);
		Scanner myScanner = new Scanner(System.in);
		int t = myScanner.nextInt();

		label: for (int K = 1; K <= t; K++) {
			int n = myScanner.nextInt(), jj = myScanner.nextInt(), ii = myScanner
					.nextInt();
			double res = 0;
			if (ii < 100 && jj < 50)
				for (int i = 0; i <= n; i++) {
					try {
						res += pr[i][ii][jj + 50];
					} catch (Exception e) {
						System.out.println("Case #" + K + ": " + 0);
						continue label;
					}
				}
			System.out.println("Case #" + K + ": " + res);
		}
	}
}
