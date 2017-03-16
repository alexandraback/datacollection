package net.anzix.learn.codejam.r1a12;

import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class PasswordProblem {

	private InputStream input;
	private PrintStream output;

	public PasswordProblem() {

	}

	public PasswordProblem(InputStream input, PrintStream output) {
		super();
		this.input = input;
		this.output = output;
	}

	public PasswordProblem(File inputFile, File outputFile) throws Exception {
		this.input = new FileInputStream(inputFile);
		output = new PrintStream(outputFile);

	}

	public void run() throws Exception {
		Scanner scanner = new Scanner(input);
		int lines = scanner.nextInt();
		for (int i = 0; i < lines; i++) {
			int f = scanner.nextInt();
			int t = scanner.nextInt();
			double[] d = new double[f];
			for (int j = 0; j < d.length; j++) {
				d[j] = scanner.nextDouble();
			}

			output.println(String.format("Case #%1$d: %2$.6f", i + 1,
					calculate(f, t, d)));

		}
		output.close();
	}

	public double calculate(int f, int t, double[] chances) {
		double e = 0;
		double[] backspaces = new double[f + 1];
		double ch = 1;
		double ok = 1;
		for (int i = 0; i < f; i++) {
			ch = ok * (1 - chances[i]);
			ok -= ch;
			e += (1 + t + 1) * ch;
			for (int b = 0; b <= f; b++) {
				if (b < f - i) {
					backspaces[b] += (b * 2 + t - f + 1 + t + 1) * ch;
				} else {
					backspaces[b] += (b * 2 + t - f + 1) * ch;
				}
			}
		}
		e += (1 + t + 1) * ok;
		for (int b = 0; b <= f; b++) {
			backspaces[b] += (b * 2 + t - f + 1) * ok;
		}

		double min = e;
		for (int b = 0; b <= f; b++) {
			if (backspaces[b] < min) {
				min = backspaces[b];
			}
		}
		return min;

	}

	public static void main(String[] args) {
		try {
			new PasswordProblem(new File(args[0]), new File(args[1])).run();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
