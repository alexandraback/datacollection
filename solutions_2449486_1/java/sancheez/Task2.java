package task2;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Task2 {

	private ArrayList<String> lines;
	private ArrayList<int[][]> lawns;
	
	public Task2(ArrayList<String> lines) {
		this.lines = lines;
		this.lawns = new ArrayList<int[][]>();
	}
	
	public String solveTask1() {
		this.createProcessingMap();
		return this.createResultMap();
	}
	
	protected void createProcessingMap() {	
		
		int[][] lawn = null;
		boolean processedFirstLine = false;
		boolean readingInNewProblem = true;
		int numberOfRows = 0;
		int numberOfColumns = 0;
		int numberOfRowsProcessed = 0;
		for (String line : this.lines) {
			if (!processedFirstLine) {
				processedFirstLine = true;
				continue;
			}
			if (readingInNewProblem) {
				String[] tuple = line.split(" ");
				numberOfRows = Integer.parseInt(tuple[0]);
				numberOfColumns = Integer.parseInt(tuple[1]);
				numberOfRowsProcessed = 0;
				readingInNewProblem = false;
				lawn = new int[numberOfRows][numberOfColumns];
				continue;
			}
			else {
				String[] tuple = line.split(" ");
				int[] lineOfInts = new int[tuple.length];
				for (int i = 0; i < tuple.length; ++i) {
					lineOfInts[i] = Integer.parseInt(tuple[i]);
				}
				lawn[numberOfRowsProcessed] = lineOfInts;
				numberOfRowsProcessed++;
				if (numberOfRowsProcessed == numberOfRows) {
					readingInNewProblem = true;
					this.lawns.add(lawn);
				}
			}
		}
	}
	
	protected String createResultMap() {
		int counter = 1;
		StringBuilder builder = new StringBuilder();
		for (int[][] lawn : this.lawns) {
			if (this.trimLawn(lawn)) {
				builder.append("Case #" + counter + ": YES");
			}
			else {
				builder.append("Case #" + counter + ": NO");
			}
			builder.append(System.getProperty("line.separator"));
			counter++;			
		}
		builder.delete(builder.length() - 1, builder.length());
		return builder.toString();
	}
	
	private boolean trimLawn(int[][] lawn) {
		int[][] currentLawn = new int[lawn.length][lawn[0].length];
		for (int i = 0; i < lawn.length; ++i) {
			for (int j = 0; j < lawn[0].length; ++j) {
				currentLawn[i][j] = 100;
			}
		}
		
		// trim all rows
		for (int i = 0; i < currentLawn.length; ++i) {
			int maximumValueAllowedToCut = Integer.MIN_VALUE;
			for (int j = 0; j < currentLawn[0].length; ++j) {
				maximumValueAllowedToCut = Math.max(maximumValueAllowedToCut, lawn[i][j]);
			}
			for (int j = 0; j < currentLawn[0].length; ++j) {
				currentLawn[i][j] = maximumValueAllowedToCut;
			}			
		}
		
		// trim all columns
		for (int i = 0; i < currentLawn[0].length; ++i) {
			int maximumValueAllowedToCut = Integer.MIN_VALUE;
			for (int j = 0; j < currentLawn.length; ++j) {
				maximumValueAllowedToCut = Math.max(maximumValueAllowedToCut, lawn[j][i]);
			}
			for (int j = 0; j < currentLawn.length; ++j) {
				if (currentLawn[j][i] < maximumValueAllowedToCut) {
					continue;
				}
				currentLawn[j][i] = maximumValueAllowedToCut;
			}			
		}		
		
		return this.compareArrays(lawn, currentLawn);
	}
	
	private boolean compareArrays(int[][] requiredLawn, int[][] actualLawn) {
		for (int i = 0; i < requiredLawn.length; ++i) {
			for (int j = 0; j < requiredLawn[i].length; ++j) {
				if (requiredLawn[i][j] != actualLawn[i][j]) {
					return false;
				}
			}
		}
		return true;
	}
	
	public static void main(String args[]) {
		if (args.length < 2) {
			return;
		}
		write(new File(args[1]), new Task2(getLines(args[0])).solveTask1());
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
