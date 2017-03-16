package com.sandris.codejam2014;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.text.NumberFormat;

public class CookieClicker {

	private static class Input {
		double price, rate, target;
	}

	private void run(File directory) throws IOException {
		File inputFile = new File(directory, "input.txt");
		File outputFile = new File(directory, "output.txt");
		BufferedReader reader = new BufferedReader(new FileReader(inputFile));
		PrintWriter writer = new PrintWriter(new FileWriter(outputFile));
		int testCaseCount = Integer.parseInt(readLine(reader));
		for (int testCaseIndex = 0; testCaseIndex < testCaseCount; testCaseIndex++) {
			printResult(testCaseIndex, new Problem(readNext(reader)).solve(2,0), writer);
		}
		writer.close();
		reader.close();
	}

	static class Problem {
		private double price;
		private double target;
		private double additionalRate;

		Problem(Input input) {
			price = input.price;
			target = input.target;
			additionalRate = input.rate;
		}
		
		private double solve(double currentRate, double timeSpent) {
			if (target < price) return target/currentRate+timeSpent;
			
			double timeWithCurrentRate = target / currentRate;
			
		    double timeToCollect = price / currentRate;
		    double potentialNewRate = currentRate + additionalRate;
		    double timeWithNewRate = target / potentialNewRate;
		    double totalTimeWithBuy = timeToCollect + timeWithNewRate;
		    
		    if (timeWithCurrentRate < totalTimeWithBuy) return timeWithCurrentRate+timeSpent;
			return solve(potentialNewRate, timeSpent+timeToCollect);
		}

		
		
	}
	
	public static void main(String[] args) throws IOException {
		new CookieClicker().run(new File(args[0]));
	}

	private String readLine(BufferedReader reader) {
		try {
			return reader.readLine();
		} catch (IOException exception) {
			throw new RuntimeException(exception);
		}
	}

	private void printResult(int testCaseIndex, double result, PrintWriter writer) {
		NumberFormat formatter = new DecimalFormat("#0.00000000");     
		int number = testCaseIndex + 1;
		String output = "Case #" + number + ": " + formatter.format(result);
		writer.println(output);
		System.out.println(output);
	}

	private Input readNext(BufferedReader reader) {
		Input input = new Input();
		String[] line = readLine(reader).split(" ");
		input.price = Double.parseDouble(line[0]);
		input.rate = Double.parseDouble(line[1]);
		input.target = Double.parseDouble(line[2]);
		return input;
	}

}


