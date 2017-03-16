package codejam2013.qualification;

import java.io.BufferedReader;
import java.io.Closeable;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class ProblemC {

	public static void main(String[] args) {
		BufferedReader reader = null;
		PrintWriter writer = null;
		try {
			String fileName = "C-small-attempt0";
			File folder = new File(new File("files", "codejam2013"), "qualification");
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

	private static String solveIt(int from, int to) {
		int count = 0;
		for (int i = from; i <= to; i++) {
			if (isFair(i)) {
				count++;
			}
		}
		return String.valueOf(count);
	}

	private static boolean isFair(int i) {
		int n = (int) Math.round(Math.sqrt(i));
		if (n * n == i) {
			return isPalindrome(i) && isPalindrome(n);
		}
		return false;
	}

	private static boolean isPalindrome(int n) {
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
