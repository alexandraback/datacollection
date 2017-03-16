package com.theblind.problem;

import java.util.Scanner;

import com.theblind.utility.FileUtility;

public class KingdomRush {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		String inputFileName = in.next();
		String inputData = FileUtility.readFromFile(inputFileName);
		
		KingdomRush problem = new KingdomRush();
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
			
			int levels = in.nextInt();
			int[] ones = new int[levels];
			int[] twos = new int[levels];
			for (int j = 0; j < levels; ++j) {
				ones[j] = in.nextInt();
				twos[j] = in.nextInt();
			}
			
			int result = calculate(ones, twos);
			if (result == -1) {
				sb.append("Too Bad");
			}
			else {
				sb.append(result);
			}
			sb.append("\n");
		}
		return sb.toString();
	}

	private int calculate(int[] ones, int[] twos) {
		// TODO Auto-generated method stub
		int result = 0;
		int stars = 0;
		while (check(twos)) {
			int index = -1;
			for (int i = 0; i < twos.length; ++i) {
				if (twos[i] <= stars) {
					index = i;
					break;
				}
			}
			
			if (index != -1) {
				if (ones[index] == Integer.MAX_VALUE) {
					stars += 1;
				}
				else {
					stars += 2;
				}
				++result;
				twos[index] = Integer.MAX_VALUE;
				continue;
			}
			
			for (int i = 0; i < ones.length; ++i) {
				if (twos[i] == Integer.MAX_VALUE) {
					continue;
				}
				if (ones[i] <= stars) {
					index = i;
					break;
				}
			}
			
			if (index != -1) {
				stars += 1;
				++result;
				ones[index] = Integer.MAX_VALUE;
			}
			else {
				return -1;
			}
		}
		return result;
	}

	private boolean check(int[] twos) {
		// TODO Auto-generated method stub
		for (int i = 0; i < twos.length; ++i) {
			if (twos[i] != Integer.MAX_VALUE) {
				return true;
			}
		}
		return false;
	}

}
