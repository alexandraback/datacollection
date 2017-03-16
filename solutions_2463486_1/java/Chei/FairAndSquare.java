import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class FairAndSquare {
	static Scanner scanner;
	static List<Long> fairAndSquares = new ArrayList<Long>();
	
	public static void main(String[] args) throws FileNotFoundException {
		long start = System.currentTimeMillis();

		preCalculateFairAndSquares();
		
		scanner = new Scanner(new File("C-large-1.in"));
		int caseCount = scanner.nextInt();
		for (int caseNumber = 1; caseNumber <= caseCount; caseNumber++) {
			long result = solve();
			System.out.format("Case #%d: %d%n", caseNumber, result);
		}
		System.out.format("Total time: %d%n", System.currentTimeMillis() - start);
	}

	static long solve() {
		long minValue = scanner.nextLong();
		long maxValue = scanner.nextLong();
		
		int result = 0;
		for (Long fairAndSquareNumber: fairAndSquares) {
			if (minValue <= fairAndSquareNumber && fairAndSquareNumber <= maxValue) {
				result++;
			}
		}
		
		return result;
	}

	static void preCalculateFairAndSquares() {
		for (long i = 1; i <= 10000000; i++) {
			if (isPalindrome(i) && isPalindrome(i*i)) {
				fairAndSquares.add(i*i);
			}
		}
	}

	static boolean isPalindrome(long number) {
		String numberString = Long.toString(number);
		for (int i = 0; i < numberString.length() / 2; i++) {
			if (numberString.charAt(i) != numberString.charAt(numberString.length() - 1 - i)) {
				return false;
			}
		}
		return true;
	}
}
