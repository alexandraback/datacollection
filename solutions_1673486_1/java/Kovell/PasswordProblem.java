package codejam;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class PasswordProblem {

	private static int inputLength = 2;

	/**
	 * @param args the command line arguments
	 */
	public static void main(String[] args) {
		String filename = "PasswordProblem/input.txt";
		if (args.length > 0) {
			filename = args[0];
		}

		try {
			Scanner sc = new Scanner(new File(filename));

			String input;
			int testCount = Integer.parseInt(sc.nextLine());
			String out = "";

			// Split the input into separate tests and collect the output.
			for (int i = 0; i < testCount; i++) {
				input = "";
				for (int row = 0; row < inputLength; row++) {
					input += sc.nextLine() + System.lineSeparator();
				}
				out += "Case #" + (i + 1) + ": ";
				out += runTest(input);
				out += System.lineSeparator();
			}
			System.out.println(out);
			BufferedWriter output = new BufferedWriter(new FileWriter(
							"PasswordProblem/output.txt"));
			output.write(out);
			output.close();
		} catch (FileNotFoundException ex) {
			System.err.println("Input file not found");
			System.exit(1);
		} catch (IOException ex) {
		}
	}

	public static String runTest(String input) {
		Scanner sc = new Scanner(input);

		int typed = sc.nextInt();
		int length = sc.nextInt();
		double[] p = new double[typed];

		for (int i = 0; i < typed; i++) {
			p[i] = sc.nextDouble();
		}

		double best = length + 2;
		double cur = 1;
		//backspacing
		for (int i = 0; i < typed; i++) {
			cur = probRight(p, typed - i) * ( length - typed  + 1 + i + i);
			cur += probWrong(p, typed - i) * ( length - typed + length + 2 + i + i);
			
			best = cur < best ? cur : best;
		}
		
		return String.valueOf(best);
	}

	public static double probRight(double[] p, int end) {
		double res = 1;
		for (int i = 0; i < end; i++) {
			res *= p[i];
		}

		return res;
	}
	public static double probWrong(double[] p, int end) {
		return 1 - probRight(p, end);
	}
}
