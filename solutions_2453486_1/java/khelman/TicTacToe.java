package pl.helman.codejam.tictactoe;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class TicTacToe {

	public static void main(String[] args) throws IOException {

		FileReader fr = new FileReader("d:\\cj\\tic.in");
		BufferedReader br = new BufferedReader(fr);
		String line = br.readLine();

		FileWriter fo = new FileWriter("d:\\cj\\tic.out");

		// number of cases
		int t = Integer.parseInt(line.trim());

		mainLoop: for (int i = 1; i <= t; i++) {

			char board[][] = new char[4][4];
			int dCount = 0;

			for (int y = 0; y < 4; y++) {
				line = br.readLine().trim();
				for (int x = 0; x < 4; x++) {
					board[x][y] = line.charAt(x);

					if(board[x][y] == '.') {
						dCount++;
					}
				}
			}
			
			//empty line
			br.readLine();
		
			//vertical lines
			for (int x = 0; x < 4; x++) {
				int result = checkLine(new char[]{board[x][0], board[x][1], board[x][2], board[x][3]});
				if (result != 0) {
					printResult(fo, result, i);
					continue mainLoop;
				}
			}
			
			//horizontal lines
			for (int y = 0; y < 4; y++) {
				int result = checkLine(new char[]{board[0][y], board[1][y], board[2][y], board[3][y]});
				if (result != 0) {
					printResult(fo, result, i);
					continue mainLoop;
				}
			}
			
			//diagonal1
			
			int result = checkLine(new char[]{board[0][0], board[1][1], board[2][2], board[3][3]});
			if (result != 0) {
				printResult(fo, result, i);
				continue mainLoop;
			}
			
			//diagonal1
			result = checkLine(new char[]{board[0][3], board[1][2], board[2][1], board[3][0]});
			if (result != 0) {
				printResult(fo, result, i);
				continue mainLoop;
			}
			
			//there was no winner
			if (dCount > 0) {
				fo.write("Case #" + i + ": Game has not completed\n");
			} else {
				fo.write("Case #" + i + ": Draw\n");
			}

		}

		fr.close();
		fo.close();

	}
	
	private static void printResult(FileWriter fo, int result, int t) throws IOException {
		if (result == -1) {
			fo.write("Case #" + t + ": X won\n");
		} else if (result == 1) {
			fo.write("Case #" + t + ": O won\n");
		}
	}

	private static int checkLine(char line[]) {
		
		boolean xPresent = false;
		boolean oPresent = false;
		boolean dPresent = false;
		for (int y = 0; y < 4; y++) {
			switch (line[y]) {
			case 'X':
				xPresent = true;
				break;
			case 'O':
				oPresent = true;
				break;
			case '.':
				dPresent = true;
				break;
			default:
				break;
			}
		}
		
		if(xPresent && !oPresent && !dPresent) {
			return -1;
		} else if(oPresent && !xPresent && !dPresent) {
			return 1;
		}
		
		return 0;
	}
}
