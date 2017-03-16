package codejam2013.qualification;

import java.io.BufferedReader;
import java.io.Closeable;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class ProblemA {

	public static void main(String[] args) {
		BufferedReader reader = null;
		PrintWriter writer = null;
		try {
			String fileName = "A-large";
			File folder = new File(new File("files", "codejam2013"), "qualification");
			File inputFile = new File(folder, fileName + ".in");
			File outputFile = new File(folder, fileName + ".out");
			reader = new BufferedReader(new FileReader(inputFile));
			writer = new PrintWriter(new FileWriter(outputFile));
			int count = Integer.parseInt(reader.readLine());
			for (int i = 0; i < count; i++) {
				char[][] grid = new char[4][4];
				for (int row = 0; row < 4; row++) {
					String line = reader.readLine();
					for (int col = 0; col < 4; col++) {
						grid[row][col] = line.charAt(col);
					}
				}
				reader.readLine();
				writer.printf("Case #%d: %s\n", i + 1, solveIt(grid));
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			close(reader);
			close(writer);
		}
		System.out.println("Done.");
	}

	private static String solveIt(char[][] grid) {
		boolean complete = checkCompleteness(grid);
		rowLoop:
		for (int i = 0; i < 4; i++) {
			char ch = grid[i][0];
			if (ch == '.') {
				continue;
			}
			for (int j = 1; j < 4; j++) {
				switch (grid[i][j]) {
				case 'X':
					switch (ch) {
					case 'T':
						ch = 'X';
						break;
					case 'X':
						break;
					case 'O':
						continue rowLoop;
					}
					break;
				case 'O':
					switch (ch) {
					case 'T':
						ch = 'O';
						break;
					case 'X':
						continue rowLoop;
					case 'O':
						break;
					}
					break;
				case 'T':
					break;
				case '.':
					continue rowLoop;
				}
			}
			return ch + " won";
		}
		columnLoop:
			for (int i = 0; i < 4; i++) {
				char ch = grid[0][i];
				if (ch == '.') {
					continue;
				}
				for (int j = 1; j < 4; j++) {
					switch (grid[j][i]) {
					case 'X':
						switch (ch) {
						case 'T':
							ch = 'X';
							break;
						case 'X':
							break;
						case 'O':
							continue columnLoop;
						}
						break;
					case 'O':
						switch (ch) {
						case 'T':
							ch = 'O';
							break;
						case 'X':
							continue columnLoop;
						case 'O':
							break;
						}
						break;
					case 'T':
						break;
					case '.':
						continue columnLoop;
					}
				}
				return ch + " won";
			}
		String result;
		result = checkDiagonal1(grid);
		if (result != null) {
			return result;
		}
		result = checkDiagonal2(grid);
		if (result != null) {
			return result;
		}
		return complete ? "Draw" : "Game has not completed";
	}

	private static String checkDiagonal1(char[][] grid) {
		char ch = grid[0][0];
		if (ch == '.') {
			return null;
		}
		for (int i = 1; i < 4; i++) {
			int j = i;
			switch (grid[i][j]) {
			case 'X':
				switch (ch) {
				case 'T':
					ch = 'X';
					break;
				case 'X':
					break;
				case 'O':
					return null;
				}
				break;
			case 'O':
				switch (ch) {
				case 'T':
					ch = 'O';
					break;
				case 'X':
					return null;
				case 'O':
					break;
				}
				break;
			case 'T':
				break;
			case '.':
				return null;
			}
		}
		return ch + " won";
	}
	
	private static String checkDiagonal2(char[][] grid) {
		char ch = grid[0][3];
		if (ch == '.') {
			return null;
		}
		for (int i = 1; i < 4; i++) {
			int j = 3 - i;
			switch (grid[i][j]) {
			case 'X':
				switch (ch) {
				case 'T':
					ch = 'X';
					break;
				case 'X':
					break;
				case 'O':
					return null;
				}
				break;
			case 'O':
				switch (ch) {
				case 'T':
					ch = 'O';
					break;
				case 'X':
					return null;
				case 'O':
					break;
				}
				break;
			case 'T':
				break;
			case '.':
				return null;
			}
		}
		return ch + " won";
	}

	private static boolean checkCompleteness(char[][] grid) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (grid[i][j] == '.') {
					return false;
				}
			}
		}
		return true;
	}

	private static void close(Closeable file) {
		if (file != null) {
			try {
				file.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}
