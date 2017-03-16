import java.io.FileReader;
import java.io.IOException;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Scanner;

public class CodeJamB {
	public static void main(String[] args) throws IOException {

		Scanner input = new Scanner(new FileReader("B-small-attempt3.in"));
		try {
			// READ PROBLEM DATA
			Integer testCases = input.nextInt();
			input.nextLine();
			for (int i = 1; i <= testCases; i++) {
				int keyboardSize = input.nextInt();
				int targetSize = input.nextInt();
				int totalWordSize = input.nextInt();
				
				String keyboard = input.next();
				String targetWord = input.next();
				
				boolean feasible = totalWordSize >= targetWord.length();
				for (char c : targetWord.toCharArray()) {
					if (!keyboard.contains("" + c)) {
						feasible = false;
					}
				}
				
				if (feasible) {
					double percentageForTargetWord = calculatePercentageForWord(targetWord, keyboard);
					double initialBananas = calculateMaxCountForWord(targetWord, totalWordSize);
					int chainSize = calculateChainSize(targetWord);
					if (chainSize > 0) {
						// If we have a chain, we need to calculate the chances of all alternatives ponderated to the counts
						String suffix = targetWord.substring(chainSize);
						String currentWord = targetWord;
						double repetition = 1.0;
						double finalPercentage = 0.0;
						int totalWords = 0;
						while (currentWord.length() <= totalWordSize) {
							double percentageForSubstring = calculatePercentageForWord(currentWord, keyboard);
							if (percentageForSubstring > 10e-6) {
								finalPercentage += (repetition * percentageForSubstring);
							}
							totalWords += repetition;
							repetition++;
							currentWord = currentWord + suffix;
						}
						percentageForTargetWord = finalPercentage / (double) totalWords;
						if (percentageForTargetWord == 1.0) {
							System.out.println("Case #" + i + ": 0.0");
						} else if (percentageForTargetWord > 10e-6) {
							BigDecimal maxCount = new BigDecimal(initialBananas);
							BigDecimal percentage = new BigDecimal(percentageForTargetWord);
							BigDecimal result = maxCount.subtract(percentage);
							if (result.toString().length() > 9) {
								System.out.println("Case #" + i + ": " + result.setScale(6, RoundingMode.HALF_UP));
							} else {
								System.out.println("Case #" + i + ": " + result);
							}
						} else {
							System.out.println("Case #" + i + ": " + initialBananas);
						}
						continue;
					} 
						if (percentageForTargetWord == 1.0) {
							System.out.println("Case #" + i + ": 0.0");
						} else if (percentageForTargetWord > 10e-6) {
							BigDecimal maxCount = new BigDecimal(initialBananas);
							BigDecimal percentage = new BigDecimal(percentageForTargetWord);
							BigDecimal result = maxCount.multiply(BigDecimal.ONE.subtract(percentage));
							if (result.toString().length() > 9) {
								System.out.println("Case #" + i + ": " + result.setScale(6, RoundingMode.HALF_UP));
							} else {
								System.out.println("Case #" + i + ": " + result);
							}
						} else {
							System.out.println("Case #" + i + ": " + initialBananas);
						}

				} else {
					System.out.println("Case #" + i + ": 0.0");
				}
			}

		} finally {
			input.close();
		}
	}

	private static double calculateMaxCountForWord(String targetWord, int finalWordSize) {
		int chainSize = calculateChainSize(targetWord);
		return chainSize == 0 ? finalWordSize / targetWord.length() :  1 + ((finalWordSize - targetWord.length()) / (targetWord.length() - chainSize));
	}

	private static int calculateChainSize(String targetWord) {
		int chainSize = 0;
		for (int i = 0; i < targetWord.length() - 1; i ++) {
			String currentSubString = targetWord.substring(0, i + 1);
			int currentIndex = targetWord.lastIndexOf(currentSubString);
			if (currentIndex == 0) {
				// Only appearance is from start. We won't be able to find any larger substring
				break;
			} else {
				// We need to check if this substring ends by the end of our current string
				if (currentIndex + currentSubString.length() == targetWord.length()) {
					// Good repeating prefix, store size
					chainSize = currentSubString.length();
				}
			}
		}
		return chainSize;
	}

	private static double calculatePercentageForWord(String targetWord, String keyboard) {
		double percentage = 1.0;
		for (char c : targetWord.toCharArray()) {
			double chanceOfLetter = calculatePercentageForLetter(keyboard, c);
			percentage = chanceOfLetter * percentage;
		}
		
		
		return percentage;
	}
	
	private static double calculatePercentageForLetter(String keyboard, char letter) {
		double appearances = 0.0;
		for (char c : keyboard.toCharArray()) {
			if (c == letter) {
				appearances++;
			}
		}
		
		return appearances / (double) keyboard.length();
	}

}