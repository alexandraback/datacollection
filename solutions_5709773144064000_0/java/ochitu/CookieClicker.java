package shb.test.codejam.k14;

import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;

import shb.test.codejam.JamInputReader;

public class CookieClicker {
	private JamInputReader jam;
	private StringBuffer out;
	public CookieClicker(String string) throws FileNotFoundException {
		jam = new JamInputReader(string);
		out= new StringBuffer();
	}
	public static void main(String[] args) throws IOException {
//		CookieClicker problem = new CookieClicker("cookie-sample.in");
		CookieClicker problem = new CookieClicker("B-small-attempt0.in");

		int tests =  problem.jam.readInt();
		for (int t=1; t<=tests; t++) {
			problem.solve(t);
		}
		
		problem.printResults("cookie-clicker.out");
	}
	private void solve(int t) {
		double [] input = jam.readDoubleArray(3);
		double c = input[0];
		double f = input[1];
		double x = input[2];
		
		double cps = 2d;
		double timeSpent = 0d;
		
		while (true) {
			//how much time is needed for goal X at current rate?
			double current = x/cps + timeSpent; 
			
			//how much time is needed for next factory?
			double timeToNextFactory = c / cps;
			double timeWithNextFactory = x/(cps+f) + timeToNextFactory + timeSpent; 
			
			if (timeWithNextFactory < current) {
				timeSpent += timeToNextFactory;
				cps+=f;
			} else {
				break;
			}
		}
		if (t>1) {
			out.append("\n");
		}
		out.append("Case #" + t + ": ");
		
		DecimalFormat df = new DecimalFormat("#.0000000");
		out.append(df.format( x/cps + timeSpent));
		
	}
	private void printResults(String filename) throws IOException {
		BufferedWriter writer = new BufferedWriter(new FileWriter(filename));
		writer.append(out.toString());
		writer.close();
	}
}
