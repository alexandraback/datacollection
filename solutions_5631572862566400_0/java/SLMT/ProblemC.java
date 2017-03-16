package round1;

import java.util.HashSet;
import java.util.Scanner;

public class ProblemC {
	
	public static void main(String[] args) {
		Scanner inputScanner = new Scanner(System.in);
		
		// Get the number of test cases
		int totalCases = inputScanner.nextInt();
		for (int caseId = 1; caseId <= totalCases; caseId++) {
			// Read the word set
			int n = inputScanner.nextInt();
			int[] bff = new int[n];
			for (int i = 0; i < bff.length; i++) {
				bff[i] = inputScanner.nextInt();
			}
			int result = findLargestCircle(bff);
			
			// Print the result
			System.out.println("Case #" + caseId + ": " + result);
		}
		
		inputScanner.close();
	}
	
	private static int findLargestCircle(int[] bff) {
		int largest = 0;
		HashSet<Integer> haveSeen = new HashSet<Integer>();
		
		for (int initId = 0; initId < bff.length; initId++) {
			int last = -1, now = -1, next = initId;
			int size = 0;
			
			while (!haveSeen.contains(next)) {
				last = now;
				now = next;
				next = bff[now] - 1;
				haveSeen.add(now);
				size++;
				//System.out.print(" " + (now + 1));
			}
			
			if (last != -1 && next != initId && next != last) {
				haveSeen.remove(now);
				//System.out.print(", delete: " + (now + 1));
				size--;
				now = last;
			}
			
			for (int i = 0; i < bff.length; i++) {
				if (bff[i] - 1 == initId && !haveSeen.contains(i)) {
					size++;
					haveSeen.add(i);
//					System.out.print(", add before: " + (i + 1));
					break;
				}
			}
			
			for (int i = 0; i < bff.length; i++) {
				if (bff[i] - 1 == now && !haveSeen.contains(i)) {
					size++;
					haveSeen.add(i);
//					System.out.print(", add after: " + (i + 1));
					break;
				}
			}
//			if (size > 0)
//				System.out.println();
			
			if (largest < size)
				largest = size;
		}
		
		return largest;
	}
}
