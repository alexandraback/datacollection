package com.theblind.problem;

import java.util.Scanner;

import com.theblind.utility.FileUtility;

public class PasswordProblem {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		String inputFileName = in.next();
		String inputData = FileUtility.readFromFile(inputFileName);
		
		PasswordProblem problem = new PasswordProblem();
		String content = problem.solve(inputData);
		
		FileUtility.writeToFile("output.txt", content);
	}

	private String solve(String inputData) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(inputData);
		StringBuilder sb = new StringBuilder();
		
		int testCases = in.nextInt();
		for (int i = 1; i <= testCases; ++i) {
			sb.append("Case #" + i + ": ");
			
			int alreadyTyped = in.nextInt();
			int passwordLength = in.nextInt();
			
			double[] probability = new double[alreadyTyped + 1];
			probability[0] = 1;
			for (int j = 1; j <= alreadyTyped; ++j) {
				probability[j] = in.nextDouble();
			}
			
			sb.append(calculate(alreadyTyped, passwordLength, probability));
			sb.append("\n");
		}
		return sb.toString();
	}

	private double calculate(int typed, int length, double[] probability) {
		// TODO Auto-generated method stub
		double prob = 1;
		for (double p : probability) {
			prob *= p;
		}
		double result = length + 2;
		
		for (int i = typed; i >= 0; --i) {
			double temp = (typed + length - 2 * i + 1) * prob + (typed + 2 * length - 2 * i + 2) * (1 - prob);
			prob /= probability[i];
			if (result > temp) {
				result = temp;
			}
		}
		return result;
	}

}
