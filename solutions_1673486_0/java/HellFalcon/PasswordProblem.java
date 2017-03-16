package google.codejam2012.round1;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Locale;
import java.util.StringTokenizer;

public class PasswordProblem {
	
	static public strictfp double getMinExpectedNumOfStrokes(int n, int m, double[] probabilities) {
		double min = m + 2;
		double p = 1.0;
		for (int i = 1; i <= n; i++) {
			p *= probabilities[i-1];
			double expected = p * (1 + n - i + m - i) + (1.0 - p) * (1 + n - i + m - i + 1 + m);
			min = min > expected ? expected : min;
		}
		return min;
	}
	
	static public void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in), 64 << 10);
			int testsNumber = Integer.parseInt(br.readLine().trim());
			for (int test = 1; test <= testsNumber; test++) {
				StringTokenizer tokenizer = new StringTokenizer(br.readLine());
				int n = Integer.parseInt(tokenizer.nextToken());
				int m = Integer.parseInt(tokenizer.nextToken());
				double[] p = new double[n];
				tokenizer = new StringTokenizer(br.readLine());
				for (int i = 0; i < n; i++) {
					p[i] = Double.parseDouble(tokenizer.nextToken());					
				}
				double result = getMinExpectedNumOfStrokes(n, m, p);
				System.out.println("Case #" + test + ": " + String.format(Locale.US, "%.9f", result));
			}
		}
		catch (Exception e) {
			System.err.println("Error:" + e.getMessage());
		}
	}
}
