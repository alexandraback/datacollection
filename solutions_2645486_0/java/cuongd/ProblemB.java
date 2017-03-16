/**
 * 
 */
package com.google.codejam.y2013;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * @author dongsi.tuecuong@gmail.com
 *
 */
public class ProblemB {

	private static Logger logger = LoggerFactory.getLogger(ProblemB.class);

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		ProblemB solver = new ProblemB();
//		solver.solve("data/BSample.txt");
		solver.solve("B-small-attempt1.in");
//		solver.solve("B-large-practice.in");
	}
	
	private int testNum;
	
	public void solve(String fileName)
	{
		try {
			Scanner fileScanner = new Scanner(new File(fileName));
			Scanner lineScanner;
			PrintStream out = new PrintStream("output.txt");
			
			// Processing input
			String line;
			line = fileScanner.nextLine();
			testNum = Integer.valueOf(line);
			
			for (int i = 0; i < testNum; i++) {
				// Get the input
				line = fileScanner.nextLine();
				lineScanner = new Scanner(line);
				int E = lineScanner.nextInt();
				int R = lineScanner.nextInt();
				int N = lineScanner.nextInt();
				
				line = fileScanner.nextLine();
				lineScanner = new Scanner(line);
				int[] values = new int[N];
				for (int j = 0; j < values.length; j++) {
					values[j] = lineScanner.nextInt();
				}
				
				// Solve the problem
				String solution = findMaxGain(E, R, values);
				
				// Print the output
				printSolution(i, solution, out);
				printSolution(i, solution, System.out);
			}
			
		} catch (FileNotFoundException e) {
			System.err.println("File(s) not found");
			e.printStackTrace();
		}
		
		
	}
	

	private String findMaxGain(int E, int R, int[] values) {
		
		long[][] tables = new long[2][E+1];
		int N = values.length;
		
		// fill the first row
		for (int i = 0; i < tables[0].length; i++) {
			for ( int j = R; j <= E; j++ )
			{
				tables[0][j] = j * values[N-1];
			}
		}
		
		for (int i = 1; i < N ; i++) {
			int prev = (i-1) % 2;
			int curr = i % 2;
			
			for (int j = R; j <= E; j++) {
				
				long max = -1;
				
				for (int k = 0; k <= j; k++) {
					long option;
					if ( R + j - k > E )
					{
						option = k*values[N-i-1] + tables[prev][E];
					} else
					{
						option = k*values[N-i-1] + tables[prev][R+j-k];
					}
					
					if ( max < option)
					{
						max = option;
					}
				}
				
				tables[curr][j] = max;
			}

		}
		
		return Long.toString(tables[(N-1)%2][E]);
	}


	/**
	 * Print out the solution, either to console or to a file
	 * 
	 * @param i
	 * @param solution
	 * @param outStream
	 */
	public void printSolution(int i, String solution, PrintStream outStream) {
		outStream.println("Case #" + (i+1) + ": " + solution);
	}

}
