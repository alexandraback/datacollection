package main;

import java.util.Scanner;

public class B {
	
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt(); in.nextLine();
		
		for (int i = 1; i <= T; i++) {

			int N = in.nextInt();
			int M = in.nextInt();
			in.nextLine();
			
			int[] maxHPerColumn = new int[M];
			int[] maxHPerRow = new int[N];
			int[][] pattern = new int[N][M];
			
			for (int n = 0; n < N; n++) {				
				for (int m = 0; m < M; m++) {
					int tmp = in.nextInt();
					pattern[n][m] = tmp;
					maxHPerColumn[m] = Math.max(maxHPerColumn[m], tmp);
					maxHPerRow[n] = Math.max(maxHPerRow[n], tmp);
				}
				if (in.hasNextLine()) in.nextLine();
			}
			
			String result = canBeCut(pattern, maxHPerColumn, maxHPerRow, N, M);
			
			System.out.format("Case #%d: %s\n", i, result);
		}
		
		in.close();
	}

	private static String canBeCut(int[][] pattern, int[] maxHPerColumn,
			int[] maxHPerRow, int N, int M) {

		for (int n = 0; n < N; n++)			
			for (int m = 0; m < M; m++)
				if (pattern[n][m] < Math.min(maxHPerRow[n], maxHPerColumn[m]))
					return "NO";
		
		return "YES";
	}
}
