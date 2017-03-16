import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;


public class Lawnmower {

	static String filePath = "files/B-large.in";
	static int[][] board;
	public static void main(String[] args) throws IOException {
		FileReader fileReader = new FileReader(filePath);
		BufferedReader bufferedReader = new BufferedReader(fileReader);

		String line;
		line = bufferedReader.readLine();
		
		int noTestCases = Integer.parseInt(line);
		for (int i = 0; i < noTestCases; i++) {
			int maxX;
			int maxY;
			line = bufferedReader.readLine();
			String[] temp = line.split(" ");
			maxY = Integer.parseInt(temp[0]);
			maxX = Integer.parseInt(temp[1]);
			board = new int[maxY][maxX];
			for (int l = 0; l < maxY; l++) {
				line = bufferedReader.readLine();
				temp = line.split(" ");
				for (int l2 = 0; l2 < maxX; l2++) {
					board[l][l2] = Integer.parseInt(temp[l2]);
				}
			}
			boolean allOk = true;
			for (int y = 0; y < maxY; y++) {
				for (int x = 0; x < maxX; x++) {
					int value = board[y][x];
					//check row
					boolean rowCheck = true;
					for (int column = 0; column < maxX; column++) {
						if (board[y][column] > value) {
							rowCheck = false;
							break;
						}
					}
					//check column
					boolean columnCheck = true; 
					for (int row = 0; row < maxY; row++) {
						if (board[row][x] > value) {
							columnCheck = false;
							break;
						}
					}
					if (!rowCheck && !columnCheck) {
						allOk = false;
						break;
					}
				}
				if (!allOk) {
					break;
				}
			}
			if (allOk) {
				System.out.println("Case #" + (i + 1) + ": " + "YES");
			} else {
				System.out.println("Case #" + (i + 1) + ": " + "NO");
			}
		}
	}

}
