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
			Scanner lineScanner = new Scanner(theCase);
			int numGooglers = lineScanner.nextInt();
			int surprises = lineScanner.nextInt();
			int p = lineScanner.nextInt();
			int minNotSuprising = getMinNotSurprising(p);
			int minSurprising = getMinSurprising(p);
			int count = 0;
			for ( int j =0; j < numGooglers; j++ ) {
				int totalScore = lineScanner.nextInt();
				if ( totalScore >= minNotSuprising ) {
					count++;
				} else if (totalScore >= minSurprising && surprises > 0) {
					surprises--;
					count++;
				}	
			}
			StringBuilder builder = new StringBuilder("Case #");
			builder.append(i+1).append(": ");
			builder.append(count);
			System.out.println(builder.toString());
		}

	}

	private static int getMinSurprising(int p) {
		return p + (p-2 < 0 ? 0 : p-2)*2;
	}

	private static int getMinNotSurprising(int p) {
		return p + (p-1 < 0 ? 0 : p-1)*2;
	}

}
