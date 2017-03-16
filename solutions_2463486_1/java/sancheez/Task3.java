package task3;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Task3 {

	private ArrayList<String> lines;
	private ArrayList<long[]> positions;
	
	public Task3(ArrayList<String> lines) {
		this.lines = lines;
		this.positions = new ArrayList<long[]>();
	}
	
	public String solveTask3() {
		this.createProcessingMap();
		return this.createResultMap();
	}
	
	protected void createProcessingMap() {	
		boolean processedFirstLine = false;
		for (String line : this.lines) {
			if (!processedFirstLine) {
				processedFirstLine = true;
				continue;
			}
			String[] tuple = line.split(" ");
			long[] intTuple = new long[2];
			intTuple[0] = (long) Math.ceil(Math.sqrt(Long.parseLong(tuple[0])));
			intTuple[1] = (long) Math.sqrt(Long.parseLong(tuple[1]));
			positions.add(intTuple);
		}
	}
	
	protected String createResultMap() {
		int counter = 1;
		StringBuilder builder = new StringBuilder();
		for (long[] range : this.positions) {
			builder.append("Case #" + counter + ": " + this.numberOfFairNumbers(range));
			builder.append(System.getProperty("line.separator"));
			counter++;		
			System.out.println(counter);
		}
		return builder.toString();
	}

	public long numberOfFairNumbers(long[] range) {	
		long numberOfFairNumbers = 0;
		for (long i = range[0]; i <= range[1]; ++i) {
			if (this.isPalindrome(i) && this.isPalindrome(i * i)) {
				numberOfFairNumbers++;
			}
		}
		return numberOfFairNumbers;
	}
	
	public boolean isPalindrome(long value) {
		if (value < 10) {
			return true;
		}
		else {
			String longAsString = Long.toString(value);
			int i = 0;
			int j = longAsString.length() - 1;
			while (i < j) {
				if (longAsString.charAt(i++) != longAsString.charAt(j--)) {
					return false;
				}
			}
			return true;
		}
	}
	
	public static void main(String args[]) {
		if (args.length < 2) {
			return;
		}
		write(new File(args[1]), new Task3(getLines(args[0])).solveTask3());
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
