package Slides;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Slides {
	
	public static int B, M;
	public static int[][] mat;
	public static boolean possible;

	public static void main(String[] args) throws FileNotFoundException {

		File input = new File("input.txt");
		Scanner scanner = new Scanner(input);
		
		int T = scanner.nextInt();
		for (int i = 0; i < T; i++) {
			
			B = scanner.nextInt();
			M = scanner.nextInt();
			mat = new int[B][B];
			possible = false;
			System.out.printf("Case #%d: %s\n", i + 1, calc(0, 1) ? "POSSIBLE" : "IMPOSSIBLE");
			
			if (possible)
				for (int j = 0; j < B; j++) {
					for (int k = 0; k < B; k++)
						System.out.print(mat[j][k]);
					System.out.println();
				}
		}
		
		scanner.close();
	}
	
	public static int sum;
	
	public static boolean calc(int x, int y) {
		
		if (x + 1 == B) {
			
			sum = 0;
			findsum(0);
			
			if (sum == M)
				possible = true;
			return sum == M;
		}
		else {
			
			mat[x][y] = 0;
			if (y + 1 == B) {
				if (calc(x + 1, x + 2)) return true;
			}
			else
				if (calc(x, y + 1)) return true;

			mat[x][y] = 1;
			if (y + 1 == B) {
				if (calc(x + 1, x + 2)) return true;
			}
			else
				if (calc(x, y + 1)) return true;
		}
		
		return false;
	}
	
	public static void findsum(int x) {
		
		if (x + 1 == B)
			sum++;
		else {
			
			for (int i = x + 1; i < B; i++)
				if (mat[x][i] == 1)
					findsum(i);
		}
	}
}
