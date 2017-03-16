package codejam2013;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class FairAndSquare {

	private static final int MAX_SIZE = 10000001;
	private static long[] squares = new long[MAX_SIZE];
	private static long[] cumulativeCount = new long[MAX_SIZE];

	public static long reverse(long number) {
		long reversed = 0;
		while (number > 0) {
			reversed = reversed * 10 + number % 10;
			number /= 10;
		}
		return reversed;
	}

	public static boolean isPalindrome(long number) {
		return number == reverse(number);
	}

	public static void fillSquares() {
		for (int i = 1; i < squares.length; ++i) {
			squares[i] = ((long)i) * i;
		}
	}

	public static void fillCumulativeCount() {
		for (int i = 1; i < squares.length; ++i) {
			cumulativeCount[i] = cumulativeCount[i - 1];
			if (isPalindrome(i) && isPalindrome(squares[i])) {
				cumulativeCount[i]++;
			}
		}
	}

	public static void solve(String fileName, String outputFileName)
			throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(
				new FileInputStream(fileName)));
		PrintWriter writer = new PrintWriter(outputFileName);
		fillSquares();
		fillCumulativeCount();

		int testCases = Integer.parseInt(reader.readLine());
		for (int t = 0; t < testCases; ++t) {
			String[] splits = reader.readLine().split(" ");
			int a = (int) Math.ceil(Math.sqrt(Long.parseLong(splits[0])));
			int b = (int) Math.sqrt(Long.parseLong(splits[1]));
			long result = cumulativeCount[b] - cumulativeCount[a - 1];
			writer.format("Case #%d: %d\n", t + 1, result);
		}

		writer.close();
		reader.close();
	}

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		solve("C-large-1.in", "C.out");
//		fillSquares();
//		fillCumulativeCount();
	}

}
