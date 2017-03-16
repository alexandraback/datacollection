package net.anzix.learn.codejam.r1b12;

import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

import net.anzix.learn.codejam.r1a12.KingdomRush;

public class SafetyInNumbers {
	private InputStream input;
	private PrintStream output;

	public SafetyInNumbers() {

	}

	public SafetyInNumbers(InputStream input, PrintStream output) {
		super();
		this.input = input;
		this.output = output;
	}

	public SafetyInNumbers(File inputFile, File outputFile) throws Exception {
		this.input = new FileInputStream(inputFile);
		output = new PrintStream(outputFile);

	}

	public void run() throws Exception {
		Scanner scanner = new Scanner(input);
		int lines = scanner.nextInt();
		for (int i = 0; i < lines; i++) {
			int l = scanner.nextInt();
			int[] points = new int[l];
			output.print("Case #" + (i + 1) + ":");
			for (int e = 0; e < l; e++) {
				points[e] = scanner.nextInt();
			}
			for (double d : calculate(points)) {
				output.print(" ");
				output.printf("%1$.6f", d * 100);
			}
			output.print("\n");
		}
		output.close();
	}

	public static void main(String[] args) {
		try {
			new SafetyInNumbers(new File(args[0]), new File(args[1])).run();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public double[] calculate(int points[]) {
		double[] res = new double[points.length];
		double sum = 0;
		for (int i = 0; i < points.length; i++) {
			sum += points[i];
		}
		String sep = "";
		double mustHave = sum * 2 / points.length;
		for (int i = 0; i < points.length; i++) {
			double need = mustHave - points[i];
			if (need <= 0) {
				res[i] = 0;
			} else {
				res[i] = need / sum;
			}
		}
		return res;

	}
}
