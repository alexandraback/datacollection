package round1B;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {

	/* TODO */
	String solve(Scanner in) throws IOException {
		int n = in.nextInt();
		int[] scores = new int[n];
		for(int i = 0; i < n; i++)
			scores[i] = in.nextInt();
		
		int sum = 0;
		for(int s : scores)
			sum += s;
		
		double[] ans = new double[n];
		for(int i = 0; i < n; i++) {
			double lo = 0, hi = 1;
			for(int t = 0; t < 50; t++) {
				double mid = (lo+hi)/2;
				if(caneliminate(i, scores, sum, mid))
					lo = mid;
				else
					hi = mid;
			}
			ans[i] = hi;
		}
		
		String s = "";
		for(double d : ans)
			s += " " + d*100;
		
		return s;
	}
	
	boolean caneliminate(int index, int[] scores, double sum, double p) {
		double score = scores[index] + sum*p, rem = 1-p;
		for(int i = 0; i < scores.length; i++)
			if(i != index) {
				if(scores[i] < score)
					rem -= (score - scores[i]) / sum;
			}
		return rem >= 0;
	}
	
/*************************************************************************************************/
	
	public static void main(String[] args) throws IOException {
		for(File f : new File(".").listFiles())
			if(f.isFile() && f.getName().startsWith(A.class.getSimpleName() + "-")
					      && f.getName().endsWith(".in")) {
				
				Scanner in = new Scanner(new FileReader(f));
				PrintWriter out = new PrintWriter(new FileWriter(f.getName() + ".out"));
				
				int cases = in.nextInt(); in.nextLine();
				for(int caseno = 1; caseno <= cases; caseno++)
					out.printf("Case #%d:%s%n", caseno, new A().solve(in));
				
				out.close();
			}
	}
}
