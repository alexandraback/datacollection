package codejam2013.round1B;

import java.io.BufferedReader;
import java.io.Closeable;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class ProblemA {

	public static void main(String[] args) {
		BufferedReader reader = null;
		PrintWriter writer = null;
		try {
			String fileName = "A-small-attempt0";
			File folder = new File(new File("files", "codejam2013"), "round1B");
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

	private static String solveIt(int a, int n, int[] motes) {
		Arrays.sort(motes);
		return String.valueOf(solve(a, motes, 0, 0));
	}

	private static int solve(int a, int[] motes, int index, int operations) {
		int bestRemoveMoteResult = Integer.MAX_VALUE;
		while (index < motes.length && bestRemoveMoteResult > operations) {
			if (a > motes[index]) {
				a += motes[index];
				index++;
			} else {
				int removeMoteResult = solve(a, motes, index+1, operations+1);
				if (bestRemoveMoteResult > removeMoteResult) {
					bestRemoveMoteResult = removeMoteResult;
				}
				operations++;
				a += a - 1;
			}
		}
		return Math.min(bestRemoveMoteResult, operations);
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
