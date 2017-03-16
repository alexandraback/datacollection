package j2012r1b;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class A {
	public static String inputDirectory="src/j2012r1b/";
	public static String inputFile="A.in";
	public static String outputFile="A.out";
	public static PrintWriter output;
	public static void main(String[] args) throws FileNotFoundException{
		Scanner s=new Scanner(new File(inputDirectory + inputFile));
		output=new PrintWriter(new File(inputDirectory + outputFile));

		int cases = s.nextInt();
		s.nextLine();
		for(int Case=1;Case<=cases;Case++){
			int N = s.nextInt();
			int[] scores = new int[N];
			double[] answers = new double[N];
			int X = 0;
			for (int i=0;i<N;i++) {
				scores[i] = s.nextInt();
				X += scores[i];
			}
			s.nextLine();

			output.printf("Case #%d:", Case);
			double sum = 0;
			for (int i=0;i < N;i++) {
				double min = 0;
				double guess = .5;
				double answer = 1;
				for(int j=0;j<100;j++) {
					if (enough(guess, i, scores, X)) {
						answer=guess;
					} else {
						min = guess;
					}
					guess = (answer+min) / 2;
				}
				sum+=answer;
				output.printf(" %f", answer * 100);
			}
			//out(Case + " " + sum);
			
			output.printf("\n");
		}
		output.flush();
	}
	
	public static boolean enough(double p, int i, int[] scores, int X) {
		double myTotal = scores[i] + X*p;
		double totalPercent = p;
		for(int j = 0; j < scores.length; j++) {
			if (j==i) continue;
			double toTie = Math.max(0, (myTotal - scores[j]) / X);
			//out(i+" has " + myTotal+" from " + p +" " + j+" needs " + toTie);
			totalPercent += toTie;
			if (totalPercent >= 1) {
				return true;
			}
		}
		return false;
	}
	
	public static void out(String s){
		output.println(s);
		System.out.println(s);
	}
}
