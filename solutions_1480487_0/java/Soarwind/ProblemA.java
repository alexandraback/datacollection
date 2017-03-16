package roundoneB;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class ProblemA {

	/**
	 * @param args
	 */
	public static String input = "A-small-attempt3.in";

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		//Scanner in = new Scanner(System.in);
		 Scanner in = new Scanner(new FileReader(input));
		//PrintWriter out = new PrintWriter(System.out);
		 PrintWriter out = new PrintWriter(new FileWriter(input + ".out"));
		int t = in.nextInt();
		for (int test = 0; test < t; test++) {
			int n = in.nextInt();
			double[] jScore = new double[n];
			double sum = 0.0;
			for (int i = 0; i < n; i++) {
				jScore[i] = in.nextDouble();
				sum+=jScore[i];
			}
			double[] f = new double[n];
			double eps = 1e-10;
			for (int i = 0; i < n; i++) {
				double high = 1.0;
				double low = 0.0;
				while (high - low > eps) {
					double fra = low + (high - low) / 2;
					double score = jScore[i] + sum * fra;
					double allNeed = 0.0;
					for (int j = 0; j < n; j++) {
						if (i == j) {
							continue;
						}
						if (jScore[j] >= score) {
							continue;
						} else {
							allNeed += (score - jScore[j]) / sum;
						}
					}
					if (allNeed + fra > 1.0) {
						high = fra;
					} else {
						low = fra;
					}
				}
				f[i] = high;
			}
			out.print("Case #" + (test + 1) + ":");
			for (int i = 0; i < n; i++) {
				out.printf(" %.6f", f[i] * 100);
			}
			out.println();
			out.flush();
		}
		out.close();
	}

}
