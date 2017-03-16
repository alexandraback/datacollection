import java.io.FileInputStream;
import java.util.Scanner;

// Lawnmower
// https://code.google.com/codejam/contest/2270488/dashboard#s=p1

public class B {

	/*
	private static void dump(int N, int M, int[][] table)  {
		for(int row = 0; row < N; row++) {
			for(int col = 0; col < M; col++) {
				System.out.print(table[row][col] + " ");
			}
			System.out.println("");
		}
	}
	*/

	private static boolean checkRow(int colCount, int row, int[][] table, int height) {
		for(int i = 0; i < colCount; i++)
			if ( table[row][i] > height )
				return false;
		return true;
	}

	private static void setRowOk(int colCount, int row, int[][] table) {
		for(int i = 0; i < colCount; i++)
			table[row][i] = 0;
	}

	private static boolean checkCol(int rowCount, int col, int[][] table, int height) {
		for(int i = 0; i < rowCount; i++)
			if ( table[i][col] > height )
				return false;
		return true;
	}

	private static void setColOk(int rowCount, int col, int[][] table) {
		for(int i = 0; i < rowCount; i++)
			table[i][col] = 0;
	}

	private static boolean check(int N, int M, int[][] table, int height)  {

		for(int row = 0; row < N; row++) {
			for(int col = 0; col < M; col++) {
				if ( table[row][col] == height ) {
					if ( checkRow(M, row, table, height) ) 
						setRowOk(M, row, table);
					else if ( checkCol(N, col, table, height) )
						setColOk(N, col, table);
					else {
						//dump(N, M, table);
						return false;
					}
				}
			}
		}

		//dump(N, M, table);

		return true;
	}

	private static String process(Scanner in) {

		int N = in.nextInt();
		int M = in.nextInt();
		int[][] table = new int[N][M];
		int[] heightCounts = new int[101];

		// Read input
		for(int row = 0; row < N; row++) {
			for(int col = 0; col < M; col++) {
				table[row][col] = in.nextInt();
				heightCounts[table[row][col]]++;
			}
		}

		// Process
		for(int height = 1; height < 101; height++) {
			if ( heightCounts[height] > 0 ) 
				if ( ! check(N, M, table, height) )
					return "NO";
		}

		return "YES";
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in.available() > 0 ? System.in : 
			new FileInputStream(Thread.currentThread().getStackTrace()[1].getClassName() + ".practice.in"));
		int T = in.nextInt();
		for(int i = 1; i <= T; i++) 
			System.out.format("Case #%d: %s\n", i, process(in));
	}
}
