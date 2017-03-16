package com.greggc.codejam;

import java.io.File;
import java.util.Locale;

import com.greggc.codejam.utils.FileUtils;

public class Problem2 {
	private static final String FILE_NAME = "B-large";
	
	public void solve() {
		StringBuilder builder = new StringBuilder();
		File input = new File(FILE_NAME + ".in");
		if (input.exists()) {
			String[] strings = FileUtils.getFileAsString(input);
			int nbTestCases = Integer.parseInt(strings[0]);
			
			for (int i = 0; i < nbTestCases; i++){
				String[] values = strings[i + 1].split(" ");
				double C = Double.parseDouble(values[0]);
				double F = Double.parseDouble(values[1]);
				double X = Double.parseDouble(values[2]);
				builder.append(
						String.format(Locale.US, "Case #%1s: %2$,.7f\n",
						i + 1,
						this.calculateNbSeconds(C, F, X)));
			}
			
			FileUtils.stringToFile(builder.toString(), FILE_NAME + ".out");
		}
	}
	
	public int getMinN(double C, double F, double X) {
		int n = -1;
		
		double left;
		double right;
		
		do {
			n++;
			left = ((double) C) / (2 + (n * F)) + ((double) X / (2 + ((n + 1) * F)));
			right = ((double) X) / (2 + (n * F));
		} while (left < right);
		
		return n;
	}
	
	public double calculateNbSeconds(double C, double F, double X) {
		int N = this.getMinN(C, F, X);
		double result = 0;
		
		for (int i = 0; i < N; i++) {
			result += ((double) C) / (2 + (i * F)); 
		}
		
		result += ((double) X) / (2 + (N * F));
		
		return result;
	}
}
