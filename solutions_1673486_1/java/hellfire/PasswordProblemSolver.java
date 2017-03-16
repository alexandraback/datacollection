package com.google.codejam;

import java.util.Scanner;

public class PasswordProblemSolver {

	public static double getMinExpectedKeyStrokes(int totalLength, int inputLength, double[] correctProbabilities) {
		double[] expectedValues = new double[inputLength + 2]; 

		//option 1: keep typing
		double allCorrectProbability = 1.0;
		for (double p: correctProbabilities) {
			allCorrectProbability *= p;
		}
		expectedValues[0] = (totalLength - inputLength + 1) + (1 - allCorrectProbability) * (totalLength + 1);
		
		//option 2: type backspace
		for (int i = 1; i <= inputLength; i++) {
			double cp = 1.0;
			for (int j = 0; j < inputLength - i; j++) {
				cp *= correctProbabilities[j];
			}
			
			expectedValues[i] = 2*i + totalLength - inputLength + 1 + (1 - cp) * (totalLength + 1);
		}
		
		//option 3: type enter
		expectedValues[inputLength + 1] = totalLength + 2;
		
		double min = Double.MAX_VALUE;
		for (double value : expectedValues) {
			if (value < min) {
				min = value;
			}
		}
		return min;
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		final int totalNum = Integer.parseInt(scanner.nextLine());
		
		for (int i = 0; i < totalNum; i++) {
			int inputLength = scanner.nextInt();
			int totalLength = Integer.parseInt(scanner.nextLine().trim());
			double[] correctProbabilities = new double[inputLength];
			for (int j = 0; j < inputLength; j++) {
				correctProbabilities[j] = scanner.nextDouble();
			}
			System.out.printf("Case #%d: %.6f%n", i+1, PasswordProblemSolver.getMinExpectedKeyStrokes(totalLength, inputLength, correctProbabilities));
			scanner.nextLine();
		}
	}

}
