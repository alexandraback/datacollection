package codejam2013.qualification;

import java.io.BufferedReader;
import java.io.Closeable;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class ProblemB {

	public static void main(String[] args) {
		BufferedReader reader = null;
		PrintWriter writer = null;
		try {
			String fileName = "B-large";
			File folder = new File(new File("files", "codejam2013"), "qualification");
			File inputFile = new File(folder, fileName + ".in");
			File outputFile = new File(folder, fileName + ".out");
			reader = new BufferedReader(new FileReader(inputFile));
			writer = new PrintWriter(new FileWriter(outputFile));
			int count = Integer.parseInt(reader.readLine());
			for (int i = 0; i < count; i++) {
				String[] parameters = reader.readLine().split("\\s");
				int n = Integer.parseInt(parameters[0]);
				int m = Integer.parseInt(parameters[1]);
				int[][] lawn = new int[n][m];
				for (int j = 0; j < n; j++) {
					int k = 0;
					for (int h : parseIntegers(reader.readLine())) {
						lawn[j][k++] = h;
					}
				}
				writer.printf("Case #%d: %s\n", i + 1, solveIt(lawn, n, m));
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			close(reader);
			close(writer);
		}
		System.out.println("Done.");
	}

	private static final int MAX_HEIGHT = 100;

	private static String solveIt(int[][] lawn, int n, int m) {
		boolean[][] possible = resetPossibilities(lawn, n, m);
		sweepLines(lawn, possible, n, m);
		sweepColumns(lawn, possible, n, m);
		return checkPossibility(possible, n, m) ? "YES" : "NO";
	}

	private static boolean[][] resetPossibilities(int[][] lawn, int n, int m) {
		boolean[][] possible = new boolean[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				possible[i][j] = (lawn[i][j] == MAX_HEIGHT);
			}
		}
		return possible;
	}

	private static boolean checkPossibility(boolean[][] possible, int n, int m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!possible[i][j]) {
					return false;
				}
			}
		}
		return true;
	}

	private static void sweepLines(int[][] lawn, boolean[][] possible, int n, int m) {
		for (int i = 0; i < n; i++) {
			int max = lawn[i][0];
			for (int j = 1; j < m; j++) {
				if (lawn[i][j] > max) {
					max = lawn[i][j];
				}
			}
			for (int j = 0; j < m; j++) {
				if (lawn[i][j] == max) {
					possible[i][j] = true;
				}
			}
		}
	}

	private static void sweepColumns(int[][] lawn, boolean[][] possible, int n, int m) {
		for (int j = 0; j < m; j++) {
			int max = lawn[0][j];
			for (int i = 1; i < n; i++) {
				if (lawn[i][j] > max) {
					max = lawn[i][j];
				}
			}
			for (int i = 0; i < n; i++) {
				if (lawn[i][j] == max) {
					possible[i][j] = true;
				}
			}
		}
	}

	public static int[] parseIntegers(String line) {
		String[] strings = line.split("\\s");
		int[] numbers = new int[strings.length];
		for (int i = 0; i < strings.length; i++) {
			numbers[i] = Integer.parseInt(strings[i]);
		}
		return numbers;
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
