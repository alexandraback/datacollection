package codejam2013.round1C;

import java.io.BufferedReader;
import java.io.Closeable;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class ProblemALarge {

	public static void main(String[] args) {
		BufferedReader reader = null;
		PrintWriter writer = null;
		try {
			String fileName = "A-large";
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

	private static class Pair {
		public int from;
		public int to;
		public Pair(int from, int to) {
			this.from = from;
			this.to = to;
		}
		@Override
		public String toString() {
			return from + "-" + to;
		}
		public int getTotal(int length) {
			return (from + 1) * (length - to);
		}
	}
	private static String solveIt(String name, int n) {
		List<Pair> pairs = new ArrayList<Pair>();
		int total = 0;
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
					Pair newPair = new Pair(from, i);
					total += newPair.getTotal(length);
//					System.out.println("+" + (newPair.getTotal(length)) + " = " + total);
					if (!pairs.isEmpty()) {
						Pair last = pairs.get(pairs.size() - 1);						
						total -= ((last.from + 1) * (length - newPair.to));
//						System.out.println(" -" + ((last.from + 1) * (length - newPair.to)) + " = " + total);
					}
					pairs.add(newPair);
					from++;
				}
			}
		}
		return String.valueOf(total);
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
