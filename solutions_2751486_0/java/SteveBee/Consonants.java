package code;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Consonants {
	
	static char[] vowels = { 'a','e','i','o','u' };
	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		
		BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("A-small-attempt0.in")));
		PrintWriter writer = new PrintWriter(new File("output.txt"));

		StringTokenizer tokenizer = null;
		int numLines = Integer.parseInt(reader.readLine());
		for (int i = 1; i <= numLines; i++) {

			tokenizer = new StringTokenizer(reader.readLine());

			String name = tokenizer.nextToken();
			int n = Integer.parseInt(tokenizer.nextToken());
			
			writer.println("Case #" + i + ": " + findNValue(name, n));
		}
		
		writer.flush();
		writer.close();
	}
	
	public static int findNValue(String name, int n) {
		
		int nValue = 0;
		int length = name.length();
		String subString = null;
		
//		System.err.println("name: " + name);
		for (int i = 0; i < length; i++) {
			
			for (int j = length; j >= i; j--) {
				
				if (j-i < n) {
					
					break;
				}
				subString = name.substring(i, j);
//				System.err.println("subString: " + subString);
				
				int subStringLength = subString.length();
				
				int consecutive = 0;
				for (int k = 0; k < subStringLength; k++) {
					
					if ((subStringLength - k + consecutive) < n) {
						
						break;
					}
					
					char letter = subString.charAt(k);
//					System.err.println("letter: " + letter);
//					System.err.println("left: " + subString.substring(k));
					
					if (isConsonant(letter)) {
						
						consecutive++;
					} else {
						
						consecutive = 0;
					}
					
					if (consecutive >= n) {
						
						nValue++;
						break;
					}
				}
			}
		}
		
		return nValue;
	}

	private static boolean isConsonant(char letter) {
		
		for (int l = 0; l < vowels.length; l++) {
			
			if (letter == vowels[l]) {
				
				return false;
			}
		}
		
		return true;
	}
}