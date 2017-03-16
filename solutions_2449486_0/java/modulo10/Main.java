
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) {
		InputStream in = System.in;
		PrintStream out = System.out;
		if (args.length > 0) {
			try {
				in = new FileInputStream(args[0]);
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}
		Scanner scanner = new Scanner(in);
		int cases = scanner.nextInt();
		for (int c = 1; c <= cases; ++c) {
			
			out.format("Case #%d: ",c);
			int m,n;
			m = scanner.nextInt();
			n = scanner.nextInt();
			int grid[][] = new int[m][n];
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < n; ++j) {
					grid[i][j] = scanner.nextInt();
				}
			}
			
			boolean cuttable = true;
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < n; ++j) {
					if (!cuttableHor(grid, i, j) && !cuttableVer(grid, i, j))
						cuttable = false;
				}
			}
			
			if (cuttable) 
				out.println("YES");
			else
				out.println("NO");
		}
	}
	
	private static boolean cuttableHor(int grid[][], int i, int j) {
		for (int x = 0; x < grid.length; ++x) {
			if (grid[i][j] < grid[x][j])
				return false;
		}
		return true;
	}
	
	private static boolean cuttableVer(int grid[][], int i, int j) {
		for (int x = 0; x < grid[i].length; ++x) {
			if (grid[i][j] < grid[i][x])
				return false;
		}
		return true;
	}
}
