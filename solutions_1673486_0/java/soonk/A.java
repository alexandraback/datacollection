package codejam.round1A2012;

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;

public class A {

	public A() {

	}

	public double compute(int a, int b, double[] prob) {

		double keepTyping = keepTyping(a, b, prob);
		double bestProb = keepTyping;
		// System.out.println("KT: " + keepTyping);

		double onebs = oneBS(a, b, prob);
		if (onebs < bestProb) {
			bestProb = onebs;
		}
		// System.out.println("1B: " + onebs);

		double twobs = twoBS(a, b, prob);
		if (twobs < bestProb) {
			bestProb = twobs;
		}
		// System.out.println("1B: " + twobs);

		double enterNow = enterNow(a, b, prob);
		if (enterNow < bestProb) {
			bestProb = enterNow;
		}
		// System.out.println("EN: " + enterNow);

		return bestProb;
	}

	private double keepTyping(int a, int b, double[] prob) {
		double probRight = 1.0;
		for (double d : prob) {
			probRight *= d;
		}

		// System.out.println("ProbRight " + probRight);

		return (probRight * (b - a + 1))
				+ ((1 - probRight) * ((b - a) + 1 + b + 1));
	}

	private double oneBS(int a, int b, double[] prob) {
		double probRight = 1.0;
		double onlyLastWrong = 1.0;
		for (int i = 0; i < prob.length; i++) {
			probRight *= prob[i];

			if (i == (prob.length - 1)) {
				onlyLastWrong *= (1 - prob[i]);
			} else {
				onlyLastWrong *= prob[i];
			}
		}

		double probRestWrong = 1.0 - (probRight + onlyLastWrong);

		// System.out.println(probLastWrong + " , " + probRestWrong);

		// System.out.println("R: " + (2 + (b - a) + 1 + b + 1));

		return (probRight * (2 + (b - a) + 1))
				+ (onlyLastWrong * (2 + (b - a) + 1))
				+ (probRestWrong * (2 + (b - a) + 1 + b + 1));
	}

	private double twoBS(int a, int b, double[] prob) {
		double probRight = 1.0;
		double onlyLastWrong = 1.0;
		double only2LastWrong = 1.0;
		double both2LastWrong = 1.0;

		for (int i = 0; i < prob.length; i++) {
			probRight *= prob[i];

			if (i == (prob.length - 1)) {
				onlyLastWrong *= (1 - prob[i]);
				only2LastWrong *= prob[i];
				both2LastWrong *= (1 - prob[i]);
			} else if (i == (prob.length - 2)) {
				onlyLastWrong *= prob[i];
				only2LastWrong *= (1 - prob[i]);
				both2LastWrong *= (1 - prob[i]);
			} else {
				onlyLastWrong *= prob[i];
				only2LastWrong *= prob[i];
				both2LastWrong *= prob[i];
			}
		}

		if (prob.length < 2) {
			only2LastWrong = 0.0;
		}

		double probOk = probRight + onlyLastWrong + only2LastWrong
				+ both2LastWrong;

		double probRestWrong = 1.0 - probOk;

		return ((probOk) * (4 + (b - a) + 1))
				+ (probRestWrong * (2 + (b - a) + 1 + b + 1));
	}

	private double enterNow(int a, int b, double[] prob) {
		return 0.0 + 1 + b + 1;
	}

	public static void main(String[] args) throws IOException {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintStream out = new PrintStream(new BufferedOutputStream(System.out));

		String line = in.readLine();
		int testCases = Integer.parseInt(line);

		A z = new A();

		// Read in all test cases
		for (int testCase = 1; testCase <= testCases; testCase++) {
			line = in.readLine();
			String[] data = line.split(" ");
			int a = Integer.parseInt(data[0]);
			int b = Integer.parseInt(data[1]);

			line = in.readLine();
			data = line.split(" ");

			double[] prob = new double[data.length];
			for (int i = 0; i < prob.length; i++) {
				prob[i] = Double.parseDouble(data[i]);
			}

			out.println("Case #" + testCase + ": " + z.compute(a, b, prob));
		}

		out.flush();
	}

}
