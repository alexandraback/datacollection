package com.sandris.codejam2014;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class MinesweeperMaster {

	private static class Input {
		int rows, columns, mines;
	}


	private void run(File directory) throws IOException {
		File inputFile = new File(directory, "input.txt");
		File outputFile = new File(directory, "output.txt");
		BufferedReader reader = new BufferedReader(new FileReader(inputFile));
		PrintWriter writer = new PrintWriter(new FileWriter(outputFile));
		int testCaseCount = Integer.parseInt(readLine(reader));
		for (int testCaseIndex = 0; testCaseIndex < testCaseCount; testCaseIndex++) {
			printResult(testCaseIndex, solve(readNext(reader)), writer);
		}
		writer.close();
		reader.close();

	}

	private Solution solve(Input input) {
		if (input.rows >= input.columns) return solve(input.rows, input.columns, input.mines);
		Solution transposed = solve(input.columns, input.rows, input.mines);
		transposed.transponse();
		return transposed;
	}

	private Solution solve(int rows, int cols, int mines) {
		if (mines == 0) return new Solution(rows, cols);
		if (mines == rows*cols-1) return solveAlmostFull(rows,cols);
		if (cols == 1) return solveOneColumn(rows, mines);
		if (cols == 2) return solveTwoColumns(rows, mines);
//		if (cols == 3) return solveThreeColumns(rows, mines); 
		return solveGeneral(rows, cols, mines);
	}

	private Solution solveGeneral(int rows, int columns, int mines) {
		int size = columns*rows;
		Solution solution = new Solution(rows, columns);
		solution.example[0][0] = 'c';
		int remainder = size - mines;
		if (remainder > 7) {
			if (mines <= (columns-2)*(rows - 2)) {
				int minesInColumn = rows - 2;
				for (int mineCounter = 0; mineCounter < mines; mineCounter++) {
					solution.example[rows-1-mineCounter%minesInColumn][columns-1-mineCounter/minesInColumn] = '*';
				}
				return solution;
			}
			for (int i = 2; i < rows; i++) for (int j = 2; j < columns; j++) solution.example[i][j] = '*';
			int mineCounter = mines - (rows-2)*(columns-2);
			if (remainder % 2 == 1) {
				solution.example[2][2] = '.';
				mineCounter++;
			}
			int i = rows-1;
			while (mineCounter > 0 && i > 2) {
				solution.example[i][0] = '*';
				solution.example[i][1] = '*';
				mineCounter = mineCounter - 2;
				i--;
			}
			if (mineCounter == 0) return solution;
			i = columns - 1;
			while (mineCounter > 0) {
				solution.example[0][i] = '*';
				solution.example[1][i] = '*';
				mineCounter = mineCounter - 2;
				i--;
			}
			return solution;
		}
		if (remainder == 7 || remainder == 5 || remainder == 3 || remainder == 2) return IMPOSSIBLE;

		//		remainder == 4 or 6 
		for (int i = 0; i < rows; i++) for (int j = 0; j < columns; j++) solution.example[i][j] = '*';
		solution.example[0][0] = 'c';
		solution.example[1][0] = '.'; 
		solution.example[0][1] = '.';
		solution.example[1][1] = '.';
		if (remainder == 6) {
			solution.example[0][2] = '.';
			solution.example[1][2] = '.';
		}
		return solution;
	}



	private Solution solveThreeColumns(int rows, int mines) {
		int size = 3*rows;
		Solution solution = new Solution(rows, 3);
		int remainder = size - mines;
		solution.example[0][0] = 'c';
		if (remainder > 7) {
			if (mines <= rows - 2) {
				for (int i = 0; i < mines; i++) solution.example[rows-i-1][2] = '*';
				return solution;
			}
			if (remainder % 2 == 0) {
				for (int i = 2; i < rows; i++) solution.example[i][2] = '*';
				for (int i = 0; i < (mines-(rows-2))/2; i++) {
					solution.example[rows-i-1][0] = '*';
					solution.example[rows-i-1][1] = '*';
				}
			}
			else {
				for (int i = 3; i < rows; i++) solution.example[i][2] = '*';
				for (int i = 0; i < (mines-(rows-3))/2; i++) {
					solution.example[rows-i-1][0] = '*';
					solution.example[rows-i-1][1] = '*';
				}
			}
			return solution;
		}
		if (remainder == 7 || remainder == 6 || remainder == 5 || remainder == 3 || remainder == 2) return IMPOSSIBLE;
		if (remainder == 4) {
			for (int i = 0; i < rows; i++) solution.example[i][2] = '*';
			for (int i = 2; i < rows; i++) {
				solution.example[rows-i-1][0] = '*';
				solution.example[rows-i-1][1] = '*';
			}
		}
		return solution;
	}

	private Solution solveTwoColumns(int rows, int mines) {
		if (rows == 2) return IMPOSSIBLE;
		if (mines % 2 == 0 && mines <= 2*rows-4) return createBottomMineLine(rows, 2, mines/2);  
		return IMPOSSIBLE;
	} 

	/**
	 * Fill the last rows with mines and click somewhere else
	 */
	private Solution createBottomMineLine(int rows, int columns, int filledRows) {
		Solution solution = new Solution(rows, columns);
		solution.example[0][0] = 'c';
		for (int i = 0; i < filledRows; i++) {
			for (int j = 0; j < columns; j++) solution.example[rows-i-1][j] = '*';
		}
		return solution;
	}

	private Solution solveAlmostFull(int rows, int cols) {
		Solution solution = new Solution(rows,cols);
		for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) solution.example[i][j] = '*';
		solution.example[0][0] = 'c';
		return solution;
	}

	/**
	 * using '.' to represent an empty cell, 
	 * '*' to represent a cell that contains a mine
	 * and 'c' to represent the clicked cell
	 */
	private Solution solveOneColumn(int rows, int mines) {
		if (mines == rows) return IMPOSSIBLE;
		Solution solution = new Solution(rows, 1);
		for (int i = rows - mines; i < rows; i++) solution.example[i][0] = '*';
		return solution;
	}

	public static void main(String[] args) throws IOException {
		new MinesweeperMaster().run(new File(args[0]));
	}

	private String readLine(BufferedReader reader) {
		try {
			return reader.readLine();
		} catch (IOException exception) {
			throw new RuntimeException(exception);
		}
	}

	private void printResult(int testCaseIndex, Solution result, PrintWriter writer) {
		int number = testCaseIndex + 1;
		String output = "Case #" + number + ":";
		writer.println(output);
		System.out.println(output);
		for (String line : result.output()) {
			writer.println(line);
			System.out.println(line);
		}
	}

	private Input readNext(BufferedReader reader) {
		Input input = new Input();
		String[] line = readLine(reader).split(" ");
		input.rows = Integer.parseInt(line[0]);
		input.columns = Integer.parseInt(line[1]);
		input.mines = Integer.parseInt(line[2]);
		return input;
	}


	private static final Solution IMPOSSIBLE = new Solution(1,1);
	static {
		IMPOSSIBLE.isPossible = false;
	}

	private static class Solution {
		boolean isPossible = true;
		int cols, rows;
		char[][] example;

		public Solution(int rows, int cols) {
			this.rows = rows;
			this.cols = cols;
			example = new char[rows][];
			for (int i = 0; i < rows; i++) example[i] = new char[cols];
			for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) example[i][j] = '.';
			example[0][0] = 'c';
		}

		List<String> output() {
			List<String> result = new ArrayList<String>();
			if (!isPossible) {
				result.add("Impossible");
				return result;
			}
			for (int i = 0; i < rows; i++) {
				StringBuilder builder = new StringBuilder();
				for (int j = 0; j < cols; j++) builder.append(example[i][j]);
				result.add(builder.toString());
			}
			return result;
		}

		void transponse() {
			if (!isPossible) return;
			char[][] transponse = new char[cols][];
			for (int i = 0; i < cols; i++) transponse[i] = new char[rows];
			for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) transponse[j][i] = example[i][j];
			int swap = rows;
			rows = cols;
			cols = swap;
			example = transponse;
		}


	}



}
