import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class Lawnmower {
	
	static Scanner scanner;
	
	public static void main(String[] args) throws FileNotFoundException {
		scanner = new Scanner(new File("B-large.in"));
		
		int caseCount = scanner.nextInt();
		for (int caseNumber = 1; caseNumber <= caseCount; caseNumber++) {
			boolean result = solve();
			System.out.format("Case #%d: %s%n", caseNumber, result ? "YES" : "NO");
		}
	}

	static boolean solve() {
		int rowCount = scanner.nextInt();
		int columnCount = scanner.nextInt();
		
		// init
		int[][] heights = new int[rowCount][];
		boolean[][] positionIsMowable = new boolean[rowCount][]; 
		for (int y = 0; y < rowCount; y++) {
			heights[y] = new int[columnCount];
			positionIsMowable[y] = new boolean[columnCount];
			for (int x = 0; x < columnCount; x++) {
				heights[y][x] = scanner.nextInt();
			}
		}
		
		// determine mowability for each cell
		for (int y = 0; y < rowCount; y++) {
			int maxHeight = 0;
			for (int x = 0; x < columnCount; x++) {
				if (maxHeight < heights[y][x]) {
					maxHeight = heights[y][x];
				}
			}
			for (int x = 0; x < columnCount; x++) {
				if (heights[y][x] == maxHeight) {
					positionIsMowable[y][x] = true;
				}
			}
		}

		for (int x = 0; x < columnCount; x++) {
			int maxHeight = 0;
			for (int y = 0; y < rowCount; y++) {
				if (maxHeight < heights[y][x]) {
					maxHeight = heights[y][x];
				}
			}
			for (int y = 0; y < rowCount; y++) {
				if (heights[y][x] == maxHeight) {
					positionIsMowable[y][x] = true;
				}
			}
		}

		// check result
		for (int y = 0; y < rowCount; y++) {
			for (int x = 0; x < columnCount; x++) {
				if (!positionIsMowable[y][x]) {
					return false;
				}
			}
		}
		
		return true;
	}
}
