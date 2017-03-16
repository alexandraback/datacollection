package codejam2013.round1C;

import java.io.BufferedReader;
import java.io.Closeable;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;

public class ProblemA {

	public static void main(String[] args) {
		BufferedReader reader = null;
		PrintWriter writer = null;
		try {
			String fileName = "A-small-attempt0";
			File folder = new File(new File("files", "codejam2013"), "round1C");
			File inputFile = new File(folder, fileName + ".in");
			File outputFile = new File(folder, fileName + ".out");
			reader = new BufferedReader(new FileReader(inputFile));
			writer = new PrintWriter(new FileWriter(outputFile));
			int count = Integer.parseInt(reader.readLine());
			for (int i = 0; i < count; i++) {
				String[] parameters = reader.readLine().split("\\s");
				writer.printf("Case #%d: %s\n", i+1,
						solveIt(parameters[0],
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

	private static String solveIt(String name, int n) {
		Set<String> substrings = new HashSet<String>();
		int length = name.length();
		for (int i = 0, from = 0; i < length; i++) {
			switch (name.charAt(i)) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				from = i + 1;
				break;
			default:
				if (i+1 - from == n) {
//					System.out.println(name + ": "+ from + "-" + i);
					for (int j = 0; j <= from; j++) {
						for (int k = i+1; k <= length; k++) {
							substrings.add(j + "-" + k);
//							System.out.println("  " + name.substring(j, k));
						}
					}
					from++;
				}
			}
		}
		return String.valueOf(substrings.size());
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
