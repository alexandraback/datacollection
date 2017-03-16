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
public class ProblemA {

	private static Logger logger = LoggerFactory.getLogger(ProblemA.class);

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		ProblemA solver = new ProblemA();
//		solver.solve("data/BullseyeSample.txt");
		solver.solve("A-small-attempt0.in");
//		solver.solve("B-large-practice.in");
	}
	
	private int testNum;
	
	public void solve(String fileName)
	{
		try {
			Scanner fileScanner = new Scanner(new File(fileName));
			PrintStream out = new PrintStream("output.txt");
			
			// Processing input
			String line;
			line = fileScanner.nextLine();
			testNum = Integer.valueOf(line);
			
			for (int i = 0; i < testNum; i++) {
				// Get the input
				line = fileScanner.nextLine();
				Scanner lineScanner = new Scanner(line);
				long radius = lineScanner.nextLong();
				long tank = lineScanner.nextLong();
				
				// Solve the problem
				String solution = findRingNumber(radius, tank);
				
				// Print the output
				printSolution(i, solution, out);
				printSolution(i, solution, System.out);
			}
			
		} catch (FileNotFoundException e) {
			System.err.println("File(s) not found");
			e.printStackTrace();
		}
		
		
	}
	

	public String findRingNumber(long r, long t) {
//		System.out.println(r + " " + t);
		// Construct the quadratic equation a*x^2 + bx + c
		
//		long a = 2;
		long b = 2*r - 1;
//		long c = -t;
		long solution = (long)quadraticSolve(2,b,-t) ;
		
		
		return Long.toString(solution);
	}


	private double quadraticSolve(long a, long b, long c) {
		double bDouble = (double) b;
		double cDouble = (double) c;
		double delta = bDouble*bDouble - 4*a * cDouble;
		
		double x1 = (-bDouble - Math.sqrt(delta))/2/a;
		double x2 = cDouble/x1/a;
		
		return x2;
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
