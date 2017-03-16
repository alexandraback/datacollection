import java.io.File;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Scanner;


public class Judges {
	
	public static double binarySearch(double[] scores, double total, double guess, double low, double high, int i) {
		double bar = scores[i] + total * guess;
		double x = 1 - guess;
		for (int j = 0; j < scores.length; j++) {
			if ((j != i) && (scores[j] < bar)) {
				x -= (bar - scores[j])/total;
			}
		}
		System.out.println(x);
		System.out.println(guess);
		if ((x < .0000001 && x > -.0000001)||guess==0) {
			return guess;
		} else if (x > 0) {
			return binarySearch(scores,total,(guess+high)/2,guess,high,i);
		} else {
			return binarySearch(scores,total,(guess+low)/2,low,guess,i);
		}
	}

	public static void main (String[] args) {
		String fileName;
		String line;
		fileName = "A-small-attempt1.in";
		
		Scanner fromFile = null;
		try {
			fromFile = new Scanner(new File(fileName));
		} catch (Exception e) {}
		
		int iterations = Integer.parseInt(fromFile.nextLine());
		double[][] answers = new double[iterations][];
		         
		for (int i = 0; i < iterations; i++) {
			
			line = fromFile.nextLine();
			String[] arguments = line.split(" ");
			int size = Integer.valueOf(arguments[0]);
			answers[i] = new double[size];
			double total = 0;
			double[] scores = new double[arguments.length-1];
			
			for (int j = 1; j < arguments.length; j++) {
				scores[j-1] = Double.valueOf(arguments[j]);
				total += Double.valueOf(arguments[j]);
			}
			
			for (int j = 0; j < size; j++) {
				answers[i][j] = 100 * binarySearch(scores,total,.5,0,1,j);
				System.out.println (answers[i][j]);
				if (answers[i][j] < .00001)
					answers[i][j] = 0;
			}
			
		}
		
		try {
			fromFile.close();
		} catch (Exception e){}
		
		PrintWriter toFile = null;
		try {
			File f = new File("output.txt");
			if (!f.exists())
				f.createNewFile();
			toFile = new PrintWriter(f);
		
			for (int i = 0; i < iterations; i++) {
				if (i == iterations - 1) {
					toFile.print("Case #" + (i + 1) + ": ");
					for (int j = 0; j < answers[i].length; j++) {
						toFile.print(answers[i][j] + " ");
					}
				} else {
					toFile.print("Case #" + (i + 1) + ": ");
					for (int j = 0; j< answers[i].length; j++) {
						toFile.print(answers[i][j] + " ");
					}
					toFile.println();
				}
			}
			
			toFile.close();
		
		} catch (Exception e) {}
	}
}
