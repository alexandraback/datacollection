import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class CodeJamC {
	public static void main(String[] args) throws IOException {

		Scanner input = new Scanner(new FileReader("C-small-attempt2.in"));
		try {
			// READ PROBLEM DATA
			Integer testCases = input.nextInt();
			input.nextLine();
			for (int i = 1; i <= testCases; i++) {
				int maxCoinsPerValue = input.nextInt();
				int actualDenominations = input.nextInt();
				int maxValue = input.nextInt();

				List<Integer> currentDenominations = new ArrayList<Integer>();
				List<Integer> obtainableValues = new ArrayList<Integer>();
				
				for (int j = 0; j < actualDenominations; j++) {
					currentDenominations.add(input.nextInt());
				}
				
				for (int currentDenomination : currentDenominations) {
					int obtainableValuesSize = obtainableValues.size();
					obtainableValues.add(currentDenomination);
					for (int pos = 0; pos < obtainableValuesSize; pos++) {
						int alreadyObtainedValue = obtainableValues.get(pos);
						if (!obtainableValues.contains(alreadyObtainedValue + currentDenomination)){
							obtainableValues.add(alreadyObtainedValue + currentDenomination);
						}
					}
				}
				
				List<Integer> unobtainableValues = new ArrayList<Integer>();
				for (int k = 1; k < maxValue; k++) {
					if (!obtainableValues.contains(k)) {
						unobtainableValues.add(k);
					}
				}
				
				if(unobtainableValues.isEmpty()) {
					System.out.println("Case #" + i + ": 0");
				} else if (unobtainableValues.size() == 1){
					System.out.println("Case #" + i + ": 1");
				} else {
					List<Integer> diffs = new ArrayList<Integer>();
					for (int unobtainableValue : unobtainableValues) {
						int diff = findClosestValue(unobtainableValue, obtainableValues, currentDenominations);
						if (!diffs.contains(diff)) {
							diffs.add(diff);
						}
					}
					System.out.println("Case #" + i + ": " + diffs.size());
				}
			}

		} finally {
			input.close();
		}
	}

	private static int findClosestValue(int value, List<Integer> obtainableValues, List<Integer> currentDenominations) {
		int diff = Integer.MAX_VALUE;
		for(int obtainableValue : obtainableValues) {
			int currentDiff = value - obtainableValue;
			if (currentDiff > 0 && currentDiff < diff && !currentDenominations.contains(currentDiff)) {
				diff = currentDiff;
			}
		}
		
		return diff;
	}

}