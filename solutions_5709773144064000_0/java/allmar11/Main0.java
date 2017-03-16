/*
 * This code is meant to run under the Java Runtime Environment, version 1.7 or
 * later.
 */

package qualification.b;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Scanner;

public class Main0 {
	
	// This is used to work around the inability of Eclipse to use a file as
	// System.in when running a program.
	private static final String IN_FILE_NAME = "input.txt";
	
	private static final double INITIAL_COOKIE_RATE = 2;

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new BufferedReader(new FileReader(IN_FILE_NAME)));
		
		int numCases = in.nextInt();
		
		for (int i = 1; i <= numCases; i++) {
			double cost = in.nextDouble();
			double boost = in.nextDouble();
			double win = in.nextDouble(); 
			
			double time = solve(cost, boost, win);
			System.out.println(String.format("Case #%s: %.7f", i, time));
		}
		
		in.close();
	}
	
	private static double solve(double cost, double boost, double win) {
		// If you win before you can buy a factory, just return the time to win.
		if (win <= cost) {
			return win / INITIAL_COOKIE_RATE;
		}
		
		// Compute the cookie-producing rate at which buying more factories no
		// longer makes sense.
		double noFactoryRate = boost * (win - cost) / cost;
		
		// Determine how many factories to buy.
		long numFactories = (long) Math.max(0, Math.ceil((noFactoryRate - INITIAL_COOKIE_RATE) / boost));
		
		// Compute time to win if we buy the above-computed number of factories.
		double result = 0;
		for (int i = 0; i < numFactories; i++) {
			result += cost / (INITIAL_COOKIE_RATE + i*boost);
		}
		double finalRate = INITIAL_COOKIE_RATE + numFactories*boost;
		result += win / finalRate;
		
		return result;
	}
}
