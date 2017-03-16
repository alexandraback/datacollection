import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;

public class TikTokTacTomek {
	static boolean isCompleted(char[][] map) {
		for (int row = 0; row < 4; ++row) {
			for (int col = 0; col < 4; ++ col) {
				if (map[row][col] == '.') {
					return false;
				}
			}
		}
		return true;
	}
	
	static boolean isWon(char[][] map, char player) {
		for (int row = 0; row < 4; ++row) {
			rowLoop: {
				for (int col = 0; col < 4; ++col) {
					if (map[row][col] != player && map[row][col] != 'T') {
						break rowLoop;
					}
				}
				return true;
			}
		}

		for (int col = 0; col < 4; ++col) {
			colLoop: {
				for (int row = 0; row < 4; ++row) {
					if (map[row][col] != player && map[row][col] != 'T') {
						break colLoop;
					}
				}
				return true;
			}
		}
		
		diagonal: {
			for (int i = 0; i < 4; ++i) {
				if (map[i][i] != player && map[i][i] != 'T') {
					break diagonal;
				}
			}
			return true;
		}
		
		reverseDiagonal: {
			for (int i = 0; i < 4; ++i) {
				if (map[3 - i][i] != player && map[3 - i][i] != 'T') {
					break reverseDiagonal;
				}
			}
			return true;
		}
		return false;
	}

	public static void main(String[] args) throws IOException {
		String filename = "/Users/JP90713/Downloads/A-large.in.txt";
		BufferedReader reader = new BufferedReader(new FileReader(filename));
		PrintStream stream = new PrintStream("result.txt");
		
		int stages = Integer.parseInt(reader.readLine());
		for (int stage = 1; stage <= stages; ++stage) {
			char[][] map = new char[4][4];
			for (int row = 0; row < 4; ++row) {
				for (int col = 0; col < 4; ++col) {
					map[row][col] = (char) reader.read();
				}
				reader.readLine();
			}
			reader.readLine();
			
			if (isWon(map, 'O')) {
				stream.printf("Case #%d: O won\n", stage);
			} else if (isWon(map, 'X')) {
				stream.printf("Case #%d: X won\n", stage);
			} else if (isCompleted(map)) {
				stream.printf("Case #%d: Draw\n", stage);
			} else {
				stream.printf("Case #%d: Game has not completed\n", stage);
			}		
		}
	}
}
