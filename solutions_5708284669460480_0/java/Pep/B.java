import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;

import com.joseprio.codejam.Solver;

public class B extends Solver {

	@Override
	public void solve(int numCase) {
		int[] params = readInts();
		
		int numKeys = params[0];
		int wordLength = params[1];
		int totalPresses = params[2];
		
		String keyboard = readLine();
		String targetWord = readLine();
		
		int[] currentPresses = new int[totalPresses];
		
		boolean foundEnd = false;
		int maxFoundInLine = -1;
		int totalFound = 0;
		int total = 0;
		do {
			total++;
			
			// Construct current word
			String currentWord = "";
			for (int c=0;c<totalPresses;c++) {
				currentWord += keyboard.charAt(currentPresses[c]);
			}
			
			// Count found
			int pos = -1;
			int foundInLine = 0;
			do {
				if (pos > -1) {
					pos = currentWord.indexOf(targetWord, pos);
				} else {
					pos = currentWord.indexOf(targetWord);
				}
				if (pos > -1) {
					pos++;
					foundInLine++;
					totalFound++;
				}
				if (foundInLine > maxFoundInLine) {
					maxFoundInLine = foundInLine;
				}
			} while (pos > -1);
			
			// Increment presses
			incrementPresses(currentPresses, 0, keyboard.length());
			
			foundEnd = true;
			
			for (int c=0;c<totalPresses&&foundEnd;c++) {
				if (currentPresses[c] > 0) {
					foundEnd = false;
				}
			}
		} while (!foundEnd);
		double result = maxFoundInLine;
		result -= ((double)totalFound)/((double)total);
		printLine(result);
	}
	void incrementPresses(int[] currentPresses, int pos, int max) {
		currentPresses[pos]++;
		if (currentPresses[pos] >= max) {
			currentPresses[pos] = 0;
			if (pos < currentPresses.length-1) {
				incrementPresses(currentPresses, pos+1, max);
			}
		}
	}
}
