package code12.qualification;

import java.io.File;
import java.io.FileWriter;
import java.util.HashSet;
import java.util.Scanner;

public class C {
	public static String solve(int A, int B) {
		int output = 0;
		
		for (int i = A; i < B; i++) {
			output += findNumOfRecyclePair(i, A, B);
		}
		
		return "" + output;
	}
	
	public static int findNumOfRecyclePair(int x, int min, int max) {
		int output = 0;
		HashSet<Integer> numSet = new HashSet<Integer>();
		char[] charList = (x + "").toCharArray();
		int[] digitList = new int[charList.length];
		
		for (int i = 0; i < digitList.length; i++) {
			digitList[i] = Integer.parseInt(charList[i] + "");
		}
		
		int num = 0;
		for (int i = 0; i < digitList.length; i++) {
			num = 0;
			for (int j = 0; j < digitList.length; j++) {
				num = num * 10 + digitList[(i + j) % digitList.length];
			}
			
			Integer numInt = new Integer(num);
			if (num > x && num <= max && !numSet.contains(numInt)) {
				numSet.add(numInt);
				output++;
//				System.out.println("(" + x + ", " + num + ")");
			}
		}
		
		return output;
	}

	public static void main(String[] args) throws Exception {
		// file name
		//String fileName = "Sample";
		//String fileName = "C-small";
		String fileName = "C-large";
		
		// file variable
		File inputFile = new File(fileName + ".in");
		File outputFile = new File(fileName + ".out");
		Scanner scanner = new Scanner(inputFile);
		FileWriter writer = new FileWriter(outputFile);

		// problem variable
		int totalCase;
		int A, B;

		// get total case
		totalCase = scanner.nextInt();

		for (int caseIndex = 1; caseIndex <= totalCase; caseIndex++) {
			// get input
			A = scanner.nextInt();
			B = scanner.nextInt();

			String output = "Case #" + caseIndex + ": " + solve(A, B);
			System.out.println(output);
			writer.write(output + "\n");
		}
		scanner.close();
		writer.close();
	}
}
