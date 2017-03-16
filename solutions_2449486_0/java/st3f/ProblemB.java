import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class ProblemB {
	static Scanner sc;
	static PrintStream ps;
	static int[][] a = new int[100][100];
	static boolean[][] covered = new boolean[100][100];
	static boolean result;
	
	static void nextCase() {
		int n = sc.nextInt();
		int m = sc.nextInt();
		int i, j;
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++) {
				a[i][j] = sc.nextInt();
			}
		
		for (i = 0; i < n; i++) {
			int max = a[i][0];
			for (j = 1; j < m; j++)
				max = Math.max(max, a[i][j]);
			for (j = 0; j < m; j++)
				covered[i][j] = a[i][j] == max;
		}
		
		for (j = 0; j < m; j++) {
			int max = a[0][j];
			for (i = 1; i < n; i++)
				max = Math.max(max, a[i][j]);
			for (i = 0; i < n; i++)
				if (a[i][j] == max)
					covered[i][j] = true;
		}
		
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				if (!covered[i][j]) {
					result = false;
					return;
				}
		result = true;
	}

	static void printSol() {
		ps.println(result ? "YES" : "NO");
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		sc = new Scanner(new File(args[0] + ".in"));
		ps = new PrintStream(args[0] + ".out");
		int t = sc.nextInt();
		sc.nextLine();
		
		for (int c = 1; c <= t; c++) {
			nextCase();
			ps.printf("Case #%d: ", c);
			printSol();
		}
	}
}
