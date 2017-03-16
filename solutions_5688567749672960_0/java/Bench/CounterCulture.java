import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class CounterCulture {

	public static void main(String[] args) {
		Scanner scanner = null;
		try {
			scanner = new Scanner(new File("input.txt"));
		} catch (FileNotFoundException e) {
			System.out.println("Couldn't open input file.\n" + e.getMessage());
			e.printStackTrace();
		}
		FileWriter writer = null;
		try {
			writer = new FileWriter(new File("output.txt"));
		} catch (IOException e) {
			System.out.println("Couldn't open/make output file."
					+ e.getMessage());
			e.printStackTrace();
		}

		int numTrials = scanner.nextInt();
		for (int i = 0; i < pow10.length; i++) {
			pow10[i] = 1;
			for (int j = 0; j < i; j++)
				pow10[i] *= 10;
		}
		for (int trial = 1; trial <= numTrials; trial++) {
			try {
				System.out.println("Trial #:"+ trial);
				writer.write("Case #" + trial + ": ");
				solveTrial(scanner, writer);
				writer.write("\n");
			} catch (IOException e) {
				System.out.println("Error on trial #" + trial + "\n"
						+ e.getMessage());
				e.printStackTrace();
			}
		}
		try {
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		scanner.close();
		System.out.println("Completed Trials!");
	}

	static long[] pow10 = new long[19];

	static boolean equalsReverse(String s) {
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) != s.charAt(s.length() - 1 - i))
				return false;
		}
		return true;
	}

	static void solveTrial(Scanner scanner, FileWriter writer)
			throws IOException {
		long N = scanner.nextLong();
		long totalSteps = 0;
		while (N >= 1) {
			System.out.println(N );
			if (N <= 20) {
				writer.write((totalSteps + N) + "");
				return;
			}
			String ascii = new Long(N).toString();
			int endLength = (int)Math.ceil(ascii.length() / 2.0);
			long endPart = N % pow10[endLength];
			if (endPart == 0) {
				N -= 1;
				totalSteps++;
			} else if (endPart == 1) {
				if (equalsReverse(ascii)) {
					N -= 2;
					totalSteps += 2;
				} else {
					long newN = 0;
					for (int i = ascii.length() - 1; i >= 0; i--) {
						long digit = N / pow10[i];
						newN += digit * pow10[ascii.length() - i - 1];
						N -= digit * pow10[i];
					}
					N = newN;
					totalSteps++;
				}
			} else {
				N -= endPart - 1;
				totalSteps += endPart - 1; // endPart - 1 + flip
			}
		}
	}
}
