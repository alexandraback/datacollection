import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class ProblemA {

	public static void main(String[] args) throws FileNotFoundException {
//		File file = new File("inputA.in");
		File file = new File("A-small-attempt1.in");
		Scanner in = new Scanner(file);
		
		int cases = in.nextInt();
		
		for (int i = 0; i < cases; i++) {
			int numberContestants = in.nextInt();
			double [] pointValues = new double[numberContestants];
			double totalPoints = 0;
			for (int j = 0; j < numberContestants; j++) {
				pointValues[j] = in.nextDouble();
				totalPoints += pointValues[j];
			}
			double [] fractions = new double[numberContestants];
			int countImpossible = 0;
			double excludedPoints = 0.0;
			for (int j = 0; j < numberContestants; j++) {
				fractions[j] = calculate(numberContestants, pointValues[j], totalPoints);
				if (fractions[j] < 0) {
					countImpossible++;
					excludedPoints+= pointValues[j];
				}
			}
			if (countImpossible > 0) {
				for (int j = 0; j < fractions.length; j++) {
					if (fractions[j] != 0) {
						fractions[j] = calculate(numberContestants-countImpossible, pointValues[j], totalPoints, excludedPoints);
					}
				}
			}
			System.out.print("Case #"+ (i+1) + ": ");
			printResults(fractions);
			System.out.println();
		} // end of for loop
	} //end of main

	private static double calculate(int numberContestants, double pointValues, double totalPoints, double excludedPoints) {
		double quota = 1/ (double) numberContestants;
		double total = quota*((2*totalPoints)-excludedPoints);
		
		return (total-pointValues)/totalPoints;
	}

	private static void printResults(double[] fractions) {
		for (int i = 0; i < fractions.length; i++) {
			double out = fractions[i]*100;
			if(out < 0){
				out = 0.0;
			}
			System.out.printf("%.6f ",out );
		}
	}

	private static double calculate(int numberContestants, double pointValues, double totalPoints) {
		double quota = 1/ (double) numberContestants;
		double total = quota*(2*totalPoints);
		return (total-pointValues)/totalPoints;
	}
	
} //end of class
