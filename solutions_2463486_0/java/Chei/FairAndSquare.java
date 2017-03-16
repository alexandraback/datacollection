import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class FairAndSquare {
	static Scanner scanner;
	
	public static void main(String[] args) throws FileNotFoundException {
		long start = System.currentTimeMillis();
		scanner = new Scanner(new File("C-small-attempt0.in"));
		
		int caseCount = scanner.nextInt();
		for (int caseNumber = 1; caseNumber <= caseCount; caseNumber++) {
			long result = solve();
			System.out.format("Case #%d: %d%n", caseNumber, result);
		}
		System.out.println(System.currentTimeMillis() - start);
	}

	static long solve() {
		long minValue = scanner.nextLong();
		long maxValue = scanner.nextLong();
		
		long minCandidate = (long) Math.ceil( Math.sqrt( (double) minValue));
		long maxCandidate = (long) Math.floor( Math.sqrt( (double) maxValue));
		
		long result = 0;
		
		for (long i = minCandidate; i <= maxCandidate; i++) {
			if (isPalindrome(i) && isPalindrome(i*i)) {
//				System.out.println(i*i);
				result++;
			}
		}
		
		return result;
	}

	static boolean isPalindrome(long number) {
		String numberString = Long.toString(number);
		for (int i = 0; i < numberString.length(); i++) {
			if (numberString.charAt(i) != numberString.charAt(numberString.length() - 1 - i)) {
				return false;
			}
		}
		return true;
	}
}
