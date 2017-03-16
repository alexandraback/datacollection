package code12.qualification;

import java.io.File;
import java.io.FileWriter;
import java.util.HashMap;
import java.util.Scanner;

public class A {
	public static String solve(String inputLine) {
		StringBuilder result = new StringBuilder();
		
		// From Googlerese to English
		HashMap<String, String> letterMap = new HashMap<String, String>();
		letterMap.put("a", "y");
		letterMap.put("b", "h");
		letterMap.put("c", "e");
		letterMap.put("d", "s");
		letterMap.put("e", "o");
		letterMap.put("f", "c");
		letterMap.put("g", "v");
		letterMap.put("h", "x");
		letterMap.put("i", "d");
		letterMap.put("j", "u");
		letterMap.put("k", "i");
		letterMap.put("l", "g");
		letterMap.put("m", "l");
		letterMap.put("n", "b");
		letterMap.put("o", "k");
		letterMap.put("p", "r");
		letterMap.put("q", "z");
		letterMap.put("r", "t");
		letterMap.put("s", "n");
		letterMap.put("t", "w");
		letterMap.put("u", "j");
		letterMap.put("v", "p");
		letterMap.put("w", "f");
		letterMap.put("x", "m");
		letterMap.put("y", "a");
		letterMap.put("z", "q");
		
		for (char letter : inputLine.toCharArray()) {
			if (letter == ' ') {
				result.append(" ");
			} else {
				result.append(letterMap.get(letter + ""));
			}
		}

		return result.toString();
	}

	public static void main(String[] args) throws Exception {
		// file name
		//String fileName = "Sample";
		String fileName = "A-small";
		//String fileName = "A-large";
		
		// file variable
		File inputFile = new File(fileName + ".in");
		File outputFile = new File(fileName + ".out");
		Scanner scanner = new Scanner(inputFile);
		FileWriter writer = new FileWriter(outputFile);

		// problem variable
		int totalCase;

		// get total case
		totalCase = scanner.nextInt();
		scanner.nextLine();

		for (int caseIndex = 1; caseIndex <= totalCase; caseIndex++) {
			// get input line
			String input = scanner.nextLine();
			String output = "Case #" + caseIndex + ": " + solve(input);
			System.out.println(output);
			writer.write(output + "\n");
		}
		scanner.close();
		writer.close();
	}
}
