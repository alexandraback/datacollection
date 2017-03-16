package common;

import java.io.PrintStream;
import java.util.Scanner;

public abstract class OfflineSolution extends Solution {
	
	protected int t;
	
	/**
	 * Reads input from in.
	 * @param in input Scanner
	 */
	public void readNumberCases(Scanner in) {
		t = in.nextInt();
	}
	
	public abstract void readCase(Scanner in);
	
	/**
	 * Solves one test case.
	 * @param n number of case to solve
	 */
	public abstract void solveCase();
	
	/**
	 * Prints output for one test case to out.
	 * @param n number of test case
	 * @param out print stream
	 */
	public abstract void printOutput(PrintStream out);
	
	/**
	 * Returns number of test cases to solve.
	 * @return number of test cases
	 */
	public int numberCases() {
		return t;
	}

	@Override
	public void solve(Scanner in, PrintStream out) {

		readNumberCases(in);
		for (int i = 0; i < numberCases(); i++) {
			printCaseLabel(i, out);
			readCase(in);
			solveCase();
			printOutput(out);
		}

	}

}
