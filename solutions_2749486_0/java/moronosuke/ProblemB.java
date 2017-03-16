package codejam2013.round1C;

import java.io.BufferedReader;
import java.io.Closeable;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class ProblemB {

	public static void main(String[] args) {
		BufferedReader reader = null;
		PrintWriter writer = null;
		try {
			String fileName = "B-small-attempt0";
			File folder = new File(new File("files", "codejam2013"), "round1C");
			File inputFile = new File(folder, fileName + ".in");
			File outputFile = new File(folder, fileName + ".out");
			reader = new BufferedReader(new FileReader(inputFile));
			writer = new PrintWriter(new FileWriter(outputFile));
			int count = Integer.parseInt(reader.readLine());
			for (int i = 0; i < count; i++) {
				String[] parameters = reader.readLine().split("\\s");
				writer.printf("Case #%d: %s\n", i+1,
						solveIt(Integer.parseInt(parameters[0]),
								Integer.parseInt(parameters[1])));
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			close(reader);
			close(writer);
		}
		System.out.println("Done.");
	}

	private static String solveIt(int x, int y) {
		StringBuilder solution = new StringBuilder();
		if (x > 0) {
			append(solution, "WE", Math.abs(x));
		} else if (x < 0) {
			append(solution, "EW", Math.abs(x));
		}
		if (y > 0) {
			append(solution, "SN", Math.abs(y));
		} else if (y < 0) {
			append(solution, "NS", Math.abs(y));
		}
		return solution.toString();
	}

	private static void append(StringBuilder path, String movement, int count) {
		for (int i = 0; i < count; i++) {
			path.append(movement);
		}
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
