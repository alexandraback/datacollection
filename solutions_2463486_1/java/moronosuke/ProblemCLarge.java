package codejam2013.qualification;

import java.io.BufferedReader;
import java.io.Closeable;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class ProblemCLarge {

	public static void main(String[] args) {
		BufferedReader reader = null;
		PrintWriter writer = null;
		try {
			findFairNumbers();
			String fileName = "C-large-1";
			File folder = new File(new File("files", "codejam2013"), "qualification");
			File inputFile = new File(folder, fileName + ".in");
			File outputFile = new File(folder, fileName + ".out");
			reader = new BufferedReader(new FileReader(inputFile));
			writer = new PrintWriter(new FileWriter(outputFile));
			int count = Integer.parseInt(reader.readLine());
			for (int i = 0; i < count; i++) {
				String[] parameters = reader.readLine().split("\\s");
				writer.printf("Case #%d: %s\n", i+1,
						solveIt(Long.parseLong(parameters[0]),
								Long.parseLong(parameters[1])));
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			close(reader);
			close(writer);
		}
		System.out.println("Done.");
	}

	private static final List<Long> fairNumbers = new ArrayList<Long>();

	private static void findFairNumbers() {
		long startTime = System.nanoTime();
		for (long i = 1; i < 10000000; i++) {
			if (isPalindrome(i)) {
				long square = i * i;
				if (isPalindrome(square)) {
					fairNumbers .add(square);
				}
			}
		}
		double elapsedTime = (System.nanoTime() - startTime) / 1000000.0;
		System.out.println(fairNumbers.size() + " numeros encontrados em " + elapsedTime + " ms");
		System.out.println(fairNumbers);
	}
	
	private static int solveIt(long from, long to) {
		int amount = fairNumbers.size();
		int i = 0;
		while (i < amount) {
			if (from <= fairNumbers.get(i)) {
				break;
			} else {
				i++;
			}				
		}
		int count = 0;
		while (i < amount) {
			long fairNumber = fairNumbers.get(i);
			if (from <= fairNumber && to >= fairNumber) {
				i++;
				count++;
			} else {
				break;
			}				
		}
		return count;
	}

	private static boolean isPalindrome(long n) {
		String s = String.valueOf(n);
		int last = s.length() - 1;
		int halfLength = s.length() / 2;
		for (int i = 0; i < halfLength; i++) {
			if (s.charAt(i) != s.charAt(last - i)) {
				return false;
			}
		}
		return true;
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
