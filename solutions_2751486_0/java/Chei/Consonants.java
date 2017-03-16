import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Consonants {

	static Scanner scanner;
	static final String VOWELS = "aeiou";
	
	public static void main(String[] args) throws FileNotFoundException {
		scanner = new Scanner(new File("A-small-attempt0.in"));
		
		int caseCount = scanner.nextInt();
		for (int caseNumber = 1; caseNumber <= caseCount; caseNumber++) {
			int result = solve();
			System.out.format("Case #%d: %d%n", caseNumber, result);
		}
	}

	static int solve() {
		
		// init
		String name = scanner.next();
		int consecutiveConsonants = scanner.nextInt();
		
		// calculate
		int result = 0;
		
		for (int beginIndex = 0; beginIndex < name.length(); beginIndex++) {
			for (int substringLength = 1; substringLength <= name.length() - beginIndex; substringLength++) {
				String substring = name.substring(beginIndex, beginIndex + substringLength);
				boolean matches = false;
				consecutiveConsonantStart:
				for (int consecutiveConsonantStartIndex = 0; consecutiveConsonantStartIndex <= substringLength - consecutiveConsonants; consecutiveConsonantStartIndex++) {
					for (int i = 0; i < consecutiveConsonants; i++) {
						if (VOWELS.indexOf(substring.charAt(consecutiveConsonantStartIndex + i)) > -1) {
							// vowel found
							continue consecutiveConsonantStart;
						}
					}
					matches = true;
				}
				if (matches) {
//					System.out.println("Found " + substring);
					result++;
				}
			}
		}

		return result;
	}
}
