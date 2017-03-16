package round1a;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class PasswordProblem {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader reader = new BufferedReader(new FileReader("A-small-attempt0.in"));
		
		int n = Integer.parseInt(reader.readLine());
		
		for (int i = 1; i <= n; i++) {
			System.out.println("Case #" + i + ": " + password_problem(reader));
		}
	}

	private static double password_problem(BufferedReader reader) throws IOException {
		String[] line = reader.readLine().split(" ");
		int a = Integer.parseInt(line[0]), b = Integer.parseInt(line[1]);
		line = reader.readLine().split(" ");
		double[] letterProbs = new double[line.length];
		for (int i = 0; i < line.length; i++)
			letterProbs[i] = Double.parseDouble(line[i]);
		
		double[] correctProbs = new double[letterProbs.length];
		correctProbs[0] = letterProbs[0];
		for (int i = 1; i < correctProbs.length; i++) {
			correctProbs[i] = correctProbs[i-1] * letterProbs[i];
		}
		double min = b + 2.0, tot = 1 >> a;
		for (int i = a - 1, n = 1, s = b - a + 1, f = 2 * b - a + 2; i >= 0; i--, n *= 2, s += 2, f += 2) {
			min = Math.min(min, correctProbs[i] * s + (1.0 - correctProbs[i]) * f);
		}
		return min;
	}

}
