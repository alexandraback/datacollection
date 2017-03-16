import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;


public class Lawnmower {
	static boolean isHole(int[][] map, int rows, int cols, int row, int col) {
		int h = map[row][col];
		cols: {
			for (int c = 0; c < cols; ++c) {
				if (map[row][c] > h) {
					break cols;
				}
			}
			return false;
		}
		
		rows: {
			for (int r = 0; r < rows; ++r) {
				if (map[r][col] > h) {
					break rows;
				}
			}
			return false;
		}
		
		return true;
	}
	
	static boolean fun(int[][] map, int rows, int cols) {
		for (int r = 0; r < rows; ++r) {
			for (int c = 0; c < cols; ++c) {
				if (isHole(map, rows, cols, r, c)) {
					return false;
				}
			}
		}
		return true;
	}
	
	public static void main(String[] arg) throws NumberFormatException, IOException {
		String filename = "/Users/JP90713/Downloads/B-small-attempt0.in.txt";
//		String filename = "/Users/JP90713/Downloads/test";
		BufferedReader reader = new BufferedReader(new FileReader(filename));
		PrintStream stream = new PrintStream("result.txt");
		
		int stages = Integer.parseInt(reader.readLine());
		for (int stage = 1; stage <= stages; ++stage) {
			String[] rowCol = reader.readLine().split("\\s");
			int rows = Integer.parseInt(rowCol[0]);
			int cols = Integer.parseInt(rowCol[1]);
			
			int[][] map = new int[rows][cols];
			for (int i = 0; i < rows; ++i) {
				String[] tokens = reader.readLine().split("\\s+");
				for (int j = 0; j < cols; ++j) {
					map[i][j] = Integer.parseInt(tokens[j]);
				}
			}
			boolean result = fun(map, rows, cols);
			
			System.out.printf("Case #%d: %s\n", stage, result ? "YES" : "NO");
			stream.printf("Case #%d: %s\n", stage, result ? "YES" : "NO");
		}
	}
}
