import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int numTestCases = Integer.valueOf(scanner.nextLine());
		for ( int i =0; i < numTestCases; i++ ) {
			String theCase = scanner.nextLine();
			//Error checking not necessary for now.

			Scanner lineScanner = new Scanner(theCase);
			int A = lineScanner.nextInt();
			int B = lineScanner.nextInt();
			int numDigits = getNumDigits(A,B);
			int[] powersOf10 = new int[numDigits];
			powersOf10[0] =1;
			for ( int j =1; j < numDigits; j++) {
				powersOf10[j] = powersOf10[j-1]*10;
			}
			//Brute force
			int count=0;
			for ( int number = A; number <=B; number ++ ) {
				int[] acceptedPairs = new int[numDigits]; // Defaults to 0
				for ( int firstDigit = 1; firstDigit < numDigits; firstDigit++ ) {
					//Make a new number.
					int newNum = (number%powersOf10[firstDigit])*powersOf10[numDigits-firstDigit] + number/powersOf10[firstDigit];
					if ( newNum > B || newNum <= number) {
						continue;
					}
					for ( int j=0; j < acceptedPairs.length; j++) {
						if ( acceptedPairs[j] == newNum ) {
							//Duplicate number
							break;
						} else if ( acceptedPairs[j] == 0 ) {
							//New number
							acceptedPairs[j] = newNum;
							break;
						}
					}
				}
				// Count non-zero accepted pairs
				for ( int j = 0; j < acceptedPairs.length; j++ ) {
					if ( acceptedPairs[j] == 0 ) {
						break;
					}
					count++;
				}
			}
			StringBuilder builder = new StringBuilder("Case #");
			builder.append(i+1).append(": ");
			builder.append(count);
			System.out.println(builder.toString());
		}
	}

	private static int getNumDigits(int a, int b) {
		int count = 0;
		while ( a > 0) {
			count++;
			a /= 10;
		}
		return count;
	}

}
