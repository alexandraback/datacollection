package codejam2012;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Hashtable;
import java.util.Scanner;

public class PasswordProblem {

	public static void main(String[] args) throws Exception {

		Scanner scanner = new Scanner(new BufferedReader(new FileReader(
				"A-large-practice.in.txt")));
		Output out = new Output("A.out");

		int T = scanner.nextInt();

		for (int t = 1; t <= T; t++) {

			int A = scanner.nextInt();
			int B = scanner.nextInt();

			double[] pArr = new double[A];

			for (int i = 0; i < A; i++) {
				pArr[i] = scanner.nextDouble();
			}
			
			// 0 ... A means how many key strokes are backed up
			// A + 1 means hit enter right way
			double[] strategys = new double[A + 2];
			
			for(int i = 0; i <= A; i ++){ 
				
				double prob = getProb(pArr, i);

				for(int j = 0; j <= A; j ++){
					

					if(j < A - i){
						// didn't back space enough
						int numKeys = j + 
								B - (A - j) + 1 + 
								B + 1;
						strategys[j] += prob * numKeys;
					} else {
						// back space enough
						int numKeys = j + 
								B - (A - j) + 1;
						strategys[j] += prob * numKeys;
						
					}
				}
				
				if(i == A && A == B){
					//int numKeys = 1;
					strategys[A+1] += prob;
				} else {
					int numKeys = 1
							+ B + 1;
					strategys[A+1] += prob * numKeys;
				}
			}
			
			double min = Double.MAX_VALUE;
			for(double d : strategys){
				if(d < min){
					min = d;
				}
			}


			out.format("Case #%d: %f\n", t, min);
		}

		scanner.close();
		out.close();
	}

	private static double getProb(double[] pArr, int k) {

		double p = 1.0;
		for(int i = 0; i < k; i ++){
			p *= pArr[i];
		}
		
		if(k < pArr.length)
			p *= (1 - pArr[k]);
		
		return p;
	}

	static class Output {

		PrintWriter pw;

		public Output(String filename) throws IOException {
			pw = new PrintWriter(new BufferedWriter(new FileWriter(filename)));
		}

		public void print(String s) {
			pw.print(s);
			System.out.print(s);
		}

		public void println(String s) {
			pw.println(s);
			System.out.println(s);
		}

		public void format(String format, Object... args) {
			pw.format(format, args);
			System.out.format(format, args);
		}

		public void close() {
			pw.close();
		}
	}

}
