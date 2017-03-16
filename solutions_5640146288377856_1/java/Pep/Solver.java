package com.joseprio.codejam;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;

public abstract class Solver {
	private static final String STRING_SEPARATOR = " ";
	
	private PrintWriter out;
	private BufferedReader in;
	private boolean lastWriteIncludedNewLine = true;
	
	public Solver() {
		
	}
	
	public void setInput(InputStream inStream) {
		in = new BufferedReader(new InputStreamReader(inStream));
	}
	
	public void setOutput(OutputStream outStream) {
		out = new PrintWriter(outStream);
	}

	public static void main(String[] args) throws Exception {
		InputStream inStream = System.in;
		OutputStream outStream = System.out;
		
		if (args.length > 0) {
			try {
				inStream = new FileInputStream(new File(args[0]));
			} catch (IOException ioex) {
				System.err.println("Error while opening input file");
				ioex.printStackTrace();
			}
		}
		
		if (args.length > 1) {
			try {
				outStream = new FileOutputStream(new File(args[1]));
			} catch (IOException ioex) {
				System.err.println("Error while opening output file");
				ioex.printStackTrace();
			}
		}

		String mainClass = System.getProperty("sun.java.command").split(STRING_SEPARATOR)[0];
		
		// Magic access to our subclass
		Class<?> clazz = Class.forName(mainClass);
		Solver solver = (Solver)clazz.newInstance();
		
		solver.setInput(inStream);
		solver.setOutput(outStream);
		solver.runCases();
		solver.shutdown();
	}
	
	private void runCases() {
		int totalCases = readInt();
		
		for (int c=1;c<=totalCases;c++) {
			if (!lastWriteIncludedNewLine) {
				newLine();
			}
			print("Case #" + c + ": ");
			solve(c+1);
		}
	}
	
	public String readLine() {
		try {
			return in.readLine();
		} catch (IOException ioex) {
			log("Error while reading line", ioex);
		}
		
		return null;
	}
	
	public void log(String message) {
		log(message, null);
	}
	
	public void log(String message, Throwable throwable) {
		System.err.println(message);
		if (throwable != null) {
			throwable.printStackTrace();
		}
	}
	
	public int readInt() {
		return Integer.parseInt(readLine());
	}
	
	public String[] readStrings() {
		return readLine().split(STRING_SEPARATOR);
	}
	
	public int[] readInts() {
		String[] lineStrings = readStrings();
		int[] output = new int[lineStrings.length];
		
		for (int c=0;c<output.length;c++) {
			output[c] = Integer.parseInt(lineStrings[c]);
		}
		
		return output;
	}
	
	public double[] readDoubles() {
		String[] lineStrings = readStrings();
		double[] output = new double[lineStrings.length];
		
		for (int c=0;c<output.length;c++) {
			output[c] = Double.parseDouble(lineStrings[c]);
		}
		
		return output;
	}
	
	public void print(int toPrint) {
		out.print(toPrint);
		lastWriteIncludedNewLine = false;
	}
	
	public void print(double toPrint) {
		out.print(toPrint);
		lastWriteIncludedNewLine = false;
	}
	
	public void print(Object... toPrint) {
		for (int c=0;c<toPrint.length;c++) {
			Object current = toPrint[c];
			
			if (c > 0) {
				out.print(STRING_SEPARATOR);
			}
			
			if (current instanceof int[]) {
				int[] currentIntArray = (int[])current;
				
				for (int d=0;d<currentIntArray.length;d++) {
					if (d > 0) {
						out.print(STRING_SEPARATOR);
					}
					out.print(currentIntArray[d]);
				}
			} else if (current instanceof int[]) {
				double[] currentDoubleArray = (double[])current;
				
				for (int d=0;d<currentDoubleArray.length;d++) {
					if (d > 0) {
						out.print(STRING_SEPARATOR);
					}
					out.print(currentDoubleArray[d]);
				}
			} else if (current instanceof Object[]) {
				Object[] currentObjectArray = (Object[])current;
				
				for (int d=0;d<currentObjectArray.length;d++) {
					if (d > 0) {
						out.print(STRING_SEPARATOR);
					}
					out.print(currentObjectArray[d]);
					lastWriteIncludedNewLine = currentObjectArray[d].toString().endsWith(System.lineSeparator());
				}
			} else {
				out.print(current);
				lastWriteIncludedNewLine = current.toString().endsWith(System.lineSeparator());
			}
		}
	}
	
	public void printLine(Object... toPrint) {
		print(toPrint);
		newLine();
	}
	
	public void newLine() {
		lastWriteIncludedNewLine = true;
		out.println();
	}
	
	public void shutdown() {
		try {
			in.close();
		} catch (IOException ioex) {
			log("Error while closing input", ioex);
		}
		
		out.close();
	}
	
	public abstract void solve(int numCase);
}
