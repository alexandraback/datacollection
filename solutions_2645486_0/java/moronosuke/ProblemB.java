package codejam2013.round1A;

import java.io.BufferedReader;
import java.io.Closeable;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.TreeSet;

public class ProblemB {

	public static void main(String[] args) {
		BufferedReader reader = null;
		PrintWriter writer = null;
		try {
			String fileName = "B-small-attempt4";
			File folder = new File(new File("files", "codejam2013"), "round1A");
			File inputFile = new File(folder, fileName + ".in");
			File outputFile = new File(folder, fileName + ".out");
			reader = new BufferedReader(new FileReader(inputFile));
			writer = new PrintWriter(new FileWriter(outputFile));
			int count = Integer.parseInt(reader.readLine());
			for (int i = 0; i < count; i++) {
				String[] parameters = reader.readLine().split("\\s");
				writer.printf("Case #%d: %s\n", i+1,
						solveIt(Integer.parseInt(parameters[0]),
								Integer.parseInt(parameters[1]),
								Integer.parseInt(parameters[2]),
								parseIntegers(reader.readLine())));
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			close(reader);
			close(writer);
		}
		System.out.println("Done.");
	}

	private static String solveIt(int e, int r, int n, int[] v) {
		long sum = 0L;
		for (int vi : v) {
			sum += (long) vi;
		}
		long max = max(v);
		long secondMax = secondMax(v);
		return String.valueOf(e * max + (n - 1) * secondMax * Math.min(e, r));
	}

	private static int max(int... numbers) {
		int max = Integer.MIN_VALUE;
		for (int number : numbers) {
			if (number > max) {
				max = number;
			}
		}
		return max;
	}
	
	private static int secondMax(int... numbers) {
		int max = 0;
		int secondMax = 0;
		for (int number : numbers) {
			if (number > max) {
				secondMax = max;
				max = number;
			} else if (number > secondMax) {
				secondMax = number;
			}
		}
		return secondMax;
	}

	public static int[] parseIntegers(String line) {
		String[] strings = line.split("\\s");
		int[] numbers = new int[strings.length];
		for (int i = 0; i < strings.length; i++) {
			numbers[i] = Integer.parseInt(strings[i]);
		}
		return numbers;
	}

	private static void close(Closeable file) {
		if (file != null) {
			try {
				file.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}
