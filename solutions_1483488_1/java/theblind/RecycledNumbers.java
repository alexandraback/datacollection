package com.theblind.problem;

import java.util.HashSet;
import java.util.Scanner;

import com.theblind.utility.FileUtility;

public class RecycledNumbers {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		String inputFileName = in.next();
		String inputData = FileUtility.readFromFile(inputFileName);
		
		RecycledNumbers problem = new RecycledNumbers();
		String content = problem.solve(inputData);
		
		FileUtility.writeToFile("output.txt", content);
	}

	private String solve(String inputData) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(inputData);
		StringBuilder sb = new StringBuilder();
		
		int testCases = in.nextInt();
		for (int i = 1; i <= testCases; ++i) {
			sb.append("Case #" + i + ": ");
			
			int A = in.nextInt();
			int B = in.nextInt();
			sb.append(calculate(A, B));
			sb.append("\n");
		}
		return sb.toString();
	}

	private int calculate(int A, int B) {
		// TODO Auto-generated method stub
		int result = 0;
		String b = Integer.toString(B);
		for (int i = A; i < B; ++i) {
			String n = Integer.toString(i);
			HashSet<String> numbers = new HashSet<String>(); 
			for (int k = 1; k < n.length(); ++k) {
				String m = n.substring(k) + n.substring(0, k);
				if (numbers.contains(m)) {
					continue;
				}
				else {
					numbers.add(m);
				}
				
				if (m.compareTo(n) > 0 && m.compareTo(b) <= 0) {
					++result;
				}
			}
		}
		return result;
	}

}
