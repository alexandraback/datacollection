package gcj2013;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class TicTacToeTomek {
	static String PATH = "/home/caq/Desktop/gcj2013/qual/", PROBLEM = "A",
			SIZE = "large", ATTEMPT = "0";

	public static void main(String[] args) throws IOException {

		String filename = PATH + PROBLEM + "-" + SIZE;
		if (!SIZE.equals("large"))
			filename += "-attempt" + ATTEMPT;
		BufferedReader br = new BufferedReader(new FileReader(filename + ".in"));
		BufferedWriter bw = new BufferedWriter(
				new FileWriter(filename + ".out"));
		int n = new Integer(br.readLine());
		for (int i = 0; i < n; i++) {
			// each case
			int[][] map = new int[4][];
			boolean hasdot = false;
			for (int j = 0; j < 4; j++) {
				map[j] = new int[4];
				String line = br.readLine();
				for (int k = 0; k < 4; k++) {
					switch (line.charAt(k)) {
					case 'X':
						map[j][k] = 1;
						break;
					case 'O':
						map[j][k] = 2;
						break;
					case 'T':
						map[j][k] = 3;
						break;
					default: // '.'
						hasdot = true;
						map[j][k] = 0;
					}
				}
			}
			if (i < n - 1)
				br.readLine(); // blank line

			boolean finished = false;
			// check rows
			for (int j = 0; j < 4; j++) {
				int number = map[j][0];
				if (number == 3)
					number = map[j][1]; // 'T'
				if (number == 0)
					continue; // not finished this line
				boolean notwon = false;
				for (int k = 1; k < 4; k++) {
					if (map[j][k] != number && map[j][k] != 3) {
						notwon = true;
						break;
					}
				}
				if (notwon)
					continue;
				// someone won
				bw.write("Case #" + (i + 1) + ": " + (number == 1 ? "X" : "O")
						+ " won");
				bw.newLine();
				finished = true;
				break;
			}
			if (finished)
				continue;

			// check columns
			for (int k = 0; k < 4; k++) {
				int number = map[0][k];
				if (number == 3)
					number = map[1][k]; // 'T'
				if (number == 0)
					continue; // not finished this line
				boolean notwon = false;
				for (int j = 1; j < 4; j++) {
					if (map[j][k] != number && map[j][k] != 3) {
						notwon = true;
						break;
					}
				}
				if (notwon)
					continue;
				// someone won
				bw.write("Case #" + (i + 1) + ": " + (number == 1 ? "X" : "O")
						+ " won");
				bw.newLine();
				finished = true;
				break;
			}
			if (finished)
				continue;

			// check diagonals
			int number = map[0][0];
			if (number == 3)
				number = map[1][1];
			if (number != 0) {
				if ((map[1][1] == 3 || map[1][1] == number)
						&& (map[2][2] == 3 || map[2][2] == number)
						&& (map[3][3] == 3 || map[3][3] == number)) {
					// someone won
					bw.write("Case #" + (i + 1) + ": "
							+ (number == 1 ? "X" : "O") + " won");
					bw.newLine();
					finished = true;
				}
			}
			if (finished)
				continue;

			number = map[0][3];
			if (number == 3)
				number = map[1][2];
			if (number != 0) {
				if ((map[1][2] == 3 || map[1][2] == number)
						&& (map[2][1] == 3 || map[2][1] == number)
						&& (map[3][0] == 3 || map[3][0] == number)) {
					// someone won
					bw.write("Case #" + (i + 1) + ": "
							+ (number == 1 ? "X" : "O") + " won");
					bw.newLine();
					finished = true;
				}
			}
			if (finished)
				continue;

			// no one has won
			if (hasdot) {
				// not finished
				bw.write("Case #" + (i + 1) + ": Game has not completed");
				bw.newLine();
			} else {
				// draw
				bw.write("Case #" + (i + 1) + ": Draw");
				bw.newLine();
			}
		}

		bw.close();
		br.close();
		System.out.println("Finished.");
	}

}
