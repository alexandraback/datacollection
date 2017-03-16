import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class LawnMower {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("src/input2"));
		int trials = in.nextInt();
		
		for (int trial = 1; trial <= trials; trial++) {
			int rows = in.nextInt();
			int cols = in.nextInt();
			
			int [][]lawn = new int[rows][cols];
			boolean [][]mowed = new boolean[rows][cols];
			
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					lawn[i][j] = in.nextInt();
				}
			}
			
			for (int i = 0; i < rows; i++) {
				int max = Integer.MIN_VALUE;
				for (int j = 0; j < cols; j++) {
					max = Math.max(lawn[i][j], max);
				}
				for (int j = 0; j < cols; j++) {
					if (lawn[i][j] == max) mowed[i][j] = true;
				}
			}
			
			for (int j = 0; j < cols; j++) {
				int max = Integer.MIN_VALUE;
				for (int i = 0; i < rows; i++) {
					max = Math.max(lawn[i][j], max);
				}
				for (int i = 0; i < rows; i++) {
					if (lawn[i][j] == max) mowed[i][j] = true;
				}
			}
			
			boolean doneMowing = true;
			for (int i = 0; i < rows; i++) {
				if (doneMowing == false) break;
				for (int j = 0; j < cols; j++) {
					if (!mowed[i][j]) {
						doneMowing = false;
						break;
					}
				}
			}
			
			System.out.println("Case #" + trial + ": " + (doneMowing ? "YES" : "NO"));
		}
	}
}
