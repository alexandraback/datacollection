import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class start {
	
	static int tCount;
	static int tMax;
	static int tSum;

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File("B-small-attempt0.in"));
		FileWriter fw = new FileWriter(new File("output.txt"));
		int numTestCases = sc.nextInt();
		for (int testCaseNum = 0; testCaseNum < numTestCases; testCaseNum++) {
			int numKeys = sc.nextInt();
			int targetWordLength = sc.nextInt();
			int resultStrLength = sc.nextInt();
			
			String keyboardCharStr = sc.next();
			String[] keyboardChars = keyboardCharStr.split("");
			
			String targetWord = sc.next();
			
			tCount = 0;
			tMax = 0;
			tSum = 0;
			
			buildCharStr(keyboardChars, resultStrLength, targetWord, "");
			
			double result = (double)tMax - (double)tSum/(double)tCount;
			
			fw.write(String.format("Case #%d: %f%n", testCaseNum+1, result));
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
