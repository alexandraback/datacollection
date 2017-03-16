package jam16.digits;

import java.io.*;
import java.util.*;

public class Digits {
	
	private static final String[] NUM_WORDS = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(new File(args[0]));
		PrintWriter output = new PrintWriter(new File(args[1]));
		
		int t = input.nextInt();
		input.nextLine();
		
		for (int i = 0; i < t; ++i) {
			char[] text = input.nextLine().trim().toCharArray();
			output.printf("Case #%d: %s%n", (i + 1), hiddenNumber(text));
		}
		
		input.close();
		output.close();
		
	}
	
	private static void update(int number, char letter, int[] charCounts, int[] numCounts) {
		numCounts[number] = charCounts[letter];
		for (char c : NUM_WORDS[number].toCharArray()) {
			charCounts[c] -= numCounts[number];
		}
	}
	
	private static String hiddenNumber(char[] text) {
		int[] numCounts = new int[10];
		int[] charCounts = new int[128];
		for (char c : text) charCounts[c]++;
		
		update(0, 'Z', charCounts, numCounts);
		update(6, 'X', charCounts, numCounts);
		update(7, 'S', charCounts, numCounts);
		update(5, 'V', charCounts, numCounts);
		update(4, 'F', charCounts, numCounts);
		update(2, 'W', charCounts, numCounts);
		update(1, 'O', charCounts, numCounts);
		update(3, 'R', charCounts, numCounts);
		update(8, 'T', charCounts, numCounts);
		update(9, 'I', charCounts, numCounts);
		
		StringBuilder builder = new StringBuilder();
		for (int i = 0; i <= 9; ++i) {
			for (int j = 0; j < numCounts[i]; ++j) builder.append(Integer.toString(i));
		}
		
		return builder.toString();
	}
	
	
}
