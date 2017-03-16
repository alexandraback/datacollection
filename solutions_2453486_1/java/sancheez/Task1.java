package task1;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Task1 {

	private ArrayList<String> lines;
	private ArrayList<char[][]> borads;
	
	public Task1(ArrayList<String> lines) {
		this.lines = lines;
		this.borads = new ArrayList<char[][]>();
	}
	
	public String solveTask1() {
		this.createProcessingMap();
		return this.createResultMap();
	}
	
	protected void createProcessingMap() {	
		ArrayList<char[]> charArrays = new ArrayList<char[]>();
		boolean processedFirstLine = false;
		for (String line : this.lines) {
			if (!processedFirstLine) {
				processedFirstLine = true;
				continue;
			}
			if (line.length() < 4) {
				continue;
			}
			charArrays.add(line.toCharArray());
			if (4 == charArrays.size()) {
				char[][] board = new char[4][];
				for (int i = 0; i < board.length; ++i) {
					board[i] = charArrays.get(i);
				}
				this.borads.add(board);
				charArrays.clear();
			}
		}
	}
	
	protected String createResultMap() {
		int counter = 1;
		StringBuilder builder = new StringBuilder();
		for (char[][] board : this.borads) {
			String output;
			if (this.xWinners(board)) {
				output = "Case #" + counter + ": X won";
			}
			else if (this.oWinners(board)) {
				output = "Case #" + counter + ": O won";
			}
			else if (this.containsEmptySquares(board)) {
				output = "Case #" + counter + ": Game has not completed";
			}
			else {
				output = "Case #" + counter + ": Draw";
			}
			builder.append(output);
			builder.append(System.getProperty("line.separator"));
			counter++;
		}		
		builder.delete(builder.length() - 1, builder.length());
		return builder.toString();
	}
	
	private boolean xWinners(char[][] board) {
		return this.winnerCheck('X', board);
	}
	
	private boolean oWinners(char[][] board) {	
		return this.winnerCheck('O', board);
	}

	private boolean winnerCheck(char toCheck, char[][] board) {
		for (int i = 0; i < board.length; ++ i) {
			boolean validRow = true;			
			for (int j = 0; j < board.length; ++j) {
				if (!(toCheck == board[i][j] || 'T' == board[i][j])) {
					validRow = false;
					break;
				}
			}
			if (validRow) {
				return true;
			}
		}
		
		for (int i = 0; i < board.length; ++ i) {
			boolean validColumn = true;			
			for (int j = 0; j < board.length; ++j) {
				if (!(toCheck == board[j][i] || 'T' == board[j][i])) {
					validColumn = false;
					break;
				}
			}
			if (validColumn) {
				return true;
			}
		}	
		
		boolean checkDiagonal = true;
		for (int i = 0; i < board.length; ++i) {
			if (!(toCheck == board[i][i] || 'T' == board[i][i])) {
				checkDiagonal = false;
			}
			if (!checkDiagonal) {
				break;
			}			
		}
		if (checkDiagonal) {
			return true;
		}
		
		checkDiagonal = true;
		for (int i = 0; i < board.length; ++i) {
			if (!(toCheck == board[i][board.length - 1 - i] || 'T' == board[i][board.length - 1 - i])) {
				checkDiagonal = false;
			}
			if (!checkDiagonal) {
				break;
			}			
		}	
		if (checkDiagonal) {
			return true;
		}		
		
		return false;		
	}
	
	private boolean containsEmptySquares(char[][] board) {
		for (int i = 0; i < board.length; ++i) {
			for (int j = 0; j < board.length; ++j) {
				if ('.' == board[i][j]) {
					return true;
				}
			}		
		}
		return false;
	}
	
	public static void main(String args[]) {
		if (args.length < 2) {
			return;
		}
		write(new File(args[1]), new Task1(getLines(args[0])).solveTask1());
	}
	
	public static ArrayList<String> getLines(String fileName) {
		try {
			ArrayList<String> lines = new ArrayList<String>();
			Scanner fileReader = new Scanner(new File(fileName));
			while(fileReader.hasNext()) {
				lines.add(fileReader.nextLine());
			}
			return lines;
		}
		catch (FileNotFoundException e) {
			return null;
		}
	}
	
	public static boolean write(File file, String outputString) {
		try {
	        BufferedWriter out = new BufferedWriter(new java.io.FileWriter(file));
	        out.write(outputString);
	        out.close();
	    } 
		catch (IOException e) {
			return false;
		}
		return true;
	}		
}
