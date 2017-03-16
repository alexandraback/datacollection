import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;


public class start {
	
	static int tCount;
	static int tMax;
	static int tSum;

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File("B-large.in"));
		//Scanner sc = new Scanner(new File("in.txt"));
		FileWriter fw = new FileWriter(new File("output.txt"));
		int numTestCases = sc.nextInt();
		for (int testCaseNum = 0; testCaseNum < numTestCases; testCaseNum++) {
			int numKeys = sc.nextInt();
			int targetWordLength = sc.nextInt();
			int resultStrLength = sc.nextInt();
			
			String keyboardCharStr = sc.next();
			String[] keyboardChars = keyboardCharStr.split("");
			
			String targetWord = sc.next();
			
			// Create alphabet array
			int[] alphaCount = new int[26];
			for (int i = 0; i < keyboardChars.length; i++) {
				alphaCount[keyboardChars[i].codePointAt(0) - 65]++;
			}
			System.out.println(keyboardCharStr + Arrays.toString(alphaCount));
			
			// Get max number
			// Check if target string can be formed or not
			boolean canBeFormed = true;
			for (int i = 0; i < targetWord.length(); i++){
				if (alphaCount[targetWord.codePointAt(i) - 65] == 0) {
					canBeFormed = false;
				}
			}
			int maxNumber = 0;
			if (canBeFormed) {
				String longstr = targetWord;
				while (longstr.length() < resultStrLength) {
					System.out.println(longstr);
					boolean changed = false;
					for (int i = 1; i < targetWordLength; i++) {
						if (longstr.endsWith(targetWord.substring(0, targetWordLength-i))){
							longstr += targetWord.substring(targetWordLength-i, targetWordLength);
							changed = true;
							break;
						}
					}
					if (changed == false) {
						longstr += targetWord;
					}
				}
				longstr = longstr.substring(0, resultStrLength);
				System.out.println("~"+longstr);
				maxNumber = targetWordCount(longstr , targetWord);
				//maxNumber = resultStrLength - targetWordLength+ 1;
			}
			
			// Calculate probability of forming word
			double sumprob = 0;
			for (int i = 0; i < resultStrLength - targetWordLength + 1; i++){
				double prob = 1;
				for (int j = 0; j < targetWord.length(); j++){
					prob *= (double) alphaCount[targetWord.codePointAt(j) - 65] / numKeys;
				}
				sumprob += prob;
			}
			System.out.println(testCaseNum+1 + "\t" + targetWord + " " + maxNumber + " " + sumprob);
			
			fw.write(String.format("Case #%d: %f%n", testCaseNum+1, maxNumber - sumprob));
		}
		
		fw.close();

	}

	private static void buildCharStr(String[] keyboardChars, int resultStrLength, String targetWord, String strSoFar) {
		if (strSoFar.length() == resultStrLength){
			int count = targetWordCount(strSoFar, targetWord);
			tCount++;
			if (tMax < count) {
				tMax = count;
			}
			tSum += count;
			//System.out.println(strSoFar + "\t" + count);
			return;
		}
		
		for (int i = 0; i < keyboardChars.length; i++){
			String str = strSoFar + keyboardChars[i];
			buildCharStr(keyboardChars, resultStrLength, targetWord, str);
		}
	}

	private static int targetWordCount(String strSoFar, String targetWord) {
		int count = 0;
		for (int i = 0; i <= strSoFar.length() - targetWord.length(); i++){
			String substr = strSoFar.substring(i, i + targetWord.length());
			if (substr.equals(targetWord)){
				count++;
			}
		}
		return count;
	}

}
