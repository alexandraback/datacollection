package y2012.round1a;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;

public class Main {
	
	static double solve(double[] prob, int length) {
		double[] correctBefore = new double[prob.length + 1];
		correctBefore[0] = 1;
		for(int i = 0; i < prob.length; i++)
			correctBefore[i+1] = correctBefore[i]*prob[i];
		double min = Double.MAX_VALUE;
		for(int i = 0; i < prob.length + 1; i++) {
			int nToComplete = 2*(prob.length - i) + length - prob.length + 1;
			double expected = correctBefore[i]*nToComplete
			                + (1 - correctBefore[i])*( nToComplete + length + 1);
			if(expected < min)
				min = expected;
		}
		return Math.min( 2 + length, min);		
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new FileReader(args[0]));
		PrintWriter writer = new PrintWriter(args[1]);
		int testCount = Integer.valueOf(reader.readLine());
		for (int i = 0; i < testCount; i++) {
			String line = reader.readLine();
			String[] fields = line.split(" ");
			int typed = Integer.valueOf(fields[0]);
			int length = Integer.valueOf(fields[1]);
			line = reader.readLine();
			fields = line.split(" ");
			double[] prob = new double[typed];
			for(int j = 0; j < typed; j++)
				prob[j] = Double.valueOf(fields[j]);
			
			String result = "Case #" + (i + 1) + ": " + solve(prob, length);
			writer.println(result);
		}
		writer.close();
	}
}
