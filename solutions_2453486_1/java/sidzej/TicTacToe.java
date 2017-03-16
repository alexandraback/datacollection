import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;


public class TicTacToe {

	static String filePath = "files/A-large.in";
	static char[][] board = new char[4][4];
	public static void main(String[] args) throws IOException {
		FileReader fileReader = new FileReader(filePath);
		BufferedReader bufferedReader = new BufferedReader(fileReader);

		String line;
		line = bufferedReader.readLine();
		
		int noTestCases = Integer.parseInt(line);
		for (int i = 0; i < noTestCases; i++) {
			boolean containsDot = false;
			for (int k = 0; k < 4; k++) {
				line = bufferedReader.readLine();
				for (int j = 0; j < 4; j++) {
					board[k][j] = line.charAt(j);
					if (board[k][j] == '.') {
						containsDot = true;
					}
				}
			}
			line = bufferedReader.readLine();
			//check rows
			boolean isXWin = false;
			boolean isOWin = false;
			for (int y = 0; y < 4; y++) {
				int isDotSymbol = 0;
				int isOSymbol = 0;
				int isXSymbol = 0;
				int isTSymbol = 0;
				for (int x = 0; x < 4; x++ ) {
					switch (board[y][x]) {
					case '.':
						isDotSymbol++;
						break;
					case 'O':
						isOSymbol++;
						break;
					case 'X':
						isXSymbol++;
						break;
					case 'T':
						isTSymbol++;
						break;
					}
					if (isDotSymbol > 0) {
						break;
					}
				}
				if (isDotSymbol == 0) {
					if (isOSymbol == 0 && ((isXSymbol == 3 && isTSymbol == 1) || 
							isXSymbol == 4)) {
						isXWin = true;
					}
					if (isXSymbol == 0 && ((isOSymbol == 3 && isTSymbol == 1) ||
							isOSymbol == 4)) {
						isOWin = true;
					}
				}
			}
			//check columns
			for (int x = 0; x < 4; x++) {
				int isDotSymbol = 0;
				int isOSymbol = 0;
				int isXSymbol = 0;
				int isTSymbol = 0;
				for (int y = 0; y < 4; y++ ) {
					switch (board[y][x]) {
					case '.':
						isDotSymbol++;
						break;
					case 'O':
						isOSymbol++;
						break;
					case 'X':
						isXSymbol++;
						break;
					case 'T':
						isTSymbol++;
						break;
					}
					if (isDotSymbol > 0) {
						break;
					}
				}
				if (isDotSymbol == 0) {
					if (isOSymbol == 0 && ((isXSymbol == 3 && isTSymbol == 1) || 
							isXSymbol == 4)) {
						isXWin = true;
					}
					if (isXSymbol == 0 && ((isOSymbol == 3 && isTSymbol == 1) ||
							isOSymbol == 4)) {
						isOWin = true;
					}
				}
			}
			//check diagonals;
			int isDotSymbol = 0;
			int isOSymbol = 0;
			int isXSymbol = 0;
			int isTSymbol = 0;
			for (int x = 0; x < 4; x++) {
				switch (board[x][x]) {
					case '.':
						isDotSymbol++;
						break;
					case 'O':
						isOSymbol++;
						break;
					case 'X':
						isXSymbol++;
						break;
					case 'T':
						isTSymbol++;
						break;
				}
				if (isDotSymbol > 0) {
					break;
				}
				if (isDotSymbol == 0) {
					if (isOSymbol == 0 && ((isXSymbol == 3 && isTSymbol == 1) || 
							isXSymbol == 4)) {
						isXWin = true;
					}
					if (isXSymbol == 0 && ((isOSymbol == 3 && isTSymbol == 1) ||
							isOSymbol == 4)) {
						isOWin = true;
					}
				}
			}
			isDotSymbol = 0;
			isOSymbol = 0;
			isXSymbol = 0;
			isTSymbol = 0;
			for (int x = 0; x < 4; x++) {
				switch (board[x][3 - x]) {
				case '.':
					isDotSymbol++;
					break;
				case 'O':
					isOSymbol++;
					break;
				case 'X':
					isXSymbol++;
					break;
				case 'T':
					isTSymbol++;
					break;
				}
				if (isDotSymbol > 0) {
					break;
				}
				if (isDotSymbol == 0) {
					if (isOSymbol == 0 && ((isXSymbol == 3 && isTSymbol == 1) || 
							isXSymbol == 4)) {
						isXWin = true;
					}
					if (isXSymbol == 0 && ((isOSymbol == 3 && isTSymbol == 1) ||
							isOSymbol == 4)) {
						isOWin = true;
					}
				}
			}
			if (isXWin && isOWin) {
				System.out.println("Case #" + (i+1) + ": Draw");
				continue;
			}
			if (isXWin) {
				System.out.println("Case #" + (i+1) + ": X won");
				continue;
			}
			if (isOWin) {
				System.out.println("Case #" + (i+1) + ": O won");
				continue;
			}
			if (containsDot) {
				System.out.println("Case #" + (i+1) + ": Game has not completed");
				continue;
			}
			System.out.println("Case #" + (i+1) + ": Draw");
		}
	}

}
