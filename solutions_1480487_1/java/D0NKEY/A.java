package com.googlecodejam.gcj2012.round1B;

import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class A {

//	public final static String INPUT_FILE_NAME = "test.in";
//	public final static String INPUT_FILE_NAME = "A-small-attempt3.in";
	public final static String INPUT_FILE_NAME = "A-large.in";
	
	public FileWriter outputWriter;
	public Scanner scanner;
	public String output = "";
	
	public void run() throws Exception {
		// Commons variables
		int testCaseNumber = 0;
		// Test start
		{
			int nbTests = Integer.parseInt(scanner.nextLine());
			
			for (testCaseNumber = 0; testCaseNumber < nbTests; testCaseNumber++) {
				String[] values = scanner.nextLine().split(" ");
				int nbContestants = Integer.parseInt(values[0]);
				double[] scores = new double[nbContestants];
				double sum = 0;
				for (int i = 0; i < nbContestants; i++) {
					double v = Double.parseDouble(values[i + 1]);
					scores[i] = v;
					sum += v;
				}
				
				double[][] matrix = new double[nbContestants][nbContestants];
				double[] solution = new double[nbContestants];
				for (int i = 0; i < nbContestants; i++) {
					matrix[0][i] = 1.;
					solution[0] = 1.;
				}
				for (int i = 0; i < nbContestants - 1; i++) {
					matrix[i+1][i] = sum;
					matrix[i+1][i+1] = -sum;
					solution[i+1] = (scores[i+1] - scores[i]);
				}

				for (int i = 1; i < nbContestants; i++) {
					double coeff = - matrix[i][i-1] / matrix[i-1][i-1];
					for (int j = 0; j < nbContestants; j++) {
						matrix[i][j] = matrix[i][j] + coeff * matrix[i-1][j];
					}
					solution[i] = solution[i] + solution[i-1] * coeff;
				}
				
				for (int r = nbContestants - 1; r > 1; r--) {
					for (int c = nbContestants - 1; c >= r; c--) {
						double coeff = - matrix[r-1][c] / matrix[c][c];
						matrix[r-1][c] = matrix[r-1][c] + coeff * matrix[c][c];
						solution[r-1] = solution[r-1] + solution[c] * coeff;
					}
				}

				double firstValue = 100.;
				double error = 0.;
				int nbError = 0;
				for (int i = 1; i < nbContestants; i++) {
					double val = solution[i] / matrix[i][i] * 100.;
					firstValue -= val;
					solution[i] = val;
					if (val < 0) {
						error += - val;
						nbError++;
					}
				}
				solution[0] = firstValue;
				if (firstValue < 0) {
					error += - firstValue;
					nbError++;
				}
				if (error > 0) {
					double amount = error / (double) (nbContestants - nbError);
					for (int i = 0; i < nbContestants; i++) {
						if (solution[i] < 0) {
							solution[i] = 0;
						} else {
							solution[i] -= amount;
						}
					}
				}
				
				double verif = 0;
				output += "Case #" + (testCaseNumber+1) + ":";
				for (int i = 0; i < nbContestants; i++) {
					output += " " + String.format("%.6f", solution[i]).replaceFirst(",", ".");
					verif += solution[i];
				}
				output += "\n";
//				System.out.println(verif);
			}
		}
	}
	
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	
	public void init() throws Exception {
		File temp = new File("output/");
		if (!temp.exists()) {
			temp.mkdir();
		}
		// Output file
		outputWriter = new FileWriter("output/output.txt", false);
		// Input file
		scanner = new Scanner(new File("resources/" + INPUT_FILE_NAME));
	}

	public void stop() throws Exception {
		// Closing files
		outputWriter.write(output, 0, output.length());
		scanner.close();
		outputWriter.close();
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		A instance = new A();
		long start = System.currentTimeMillis();
		
		instance.init();
		instance.run();
		instance.stop();
		
		System.out.println("Finished in " + (System.currentTimeMillis() - start) + " ms");
	}
	
}
