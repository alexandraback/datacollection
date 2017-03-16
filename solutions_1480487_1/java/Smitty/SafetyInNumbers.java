import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.io.*;

public final class SafetyInNumbers {

	private final static String FILE_IN = SafetyInNumbers.class.getSimpleName() + ".in";			
	private final static String FILE_OUT = SafetyInNumbers.class.getSimpleName() + ".out";			
	
	public static final void main(final String[] args) throws Exception {
		final Scanner in = new Scanner(new File(FILE_IN));
		final PrintWriter out = new PrintWriter(FILE_OUT);
		final int testCnt = in.nextInt();
		for (int caseNum = 1; caseNum <= testCnt; ++ caseNum){
			
			final int n = in.nextInt();
			final double p [] = new double [n];
			double total = 0.0;
			for (int i = 0; i < n; ++ i){
				p[i] = in.nextDouble();
				total += p[i];
			}
			
			double l = 0.0;
			double r = total + total;
			while (Math.abs(r - l) > 1e-9){
				final double c = 0.5 * (l + r);
			
				double sum = 0.0;
				for (int i = 0; i < n; ++ i){
					if (p[i] < c){
						sum += c - p[i];
					}
				}
				
				if (sum > total){
					r = c;
				}
				else {
					l = c;
				}
			}
			
			final double result = l;
			out.print(String.format("Case #%d:", caseNum));			
			for (int i = 0; i<  n; ++ i){
				final double output = (p[i] < result ? result - p[i] : 0.0) / total * 100.0;
				out.print(String.format(" %.12f", output));
			}
			out.println();
		}
		in.close();
		out.close();
	}

}
