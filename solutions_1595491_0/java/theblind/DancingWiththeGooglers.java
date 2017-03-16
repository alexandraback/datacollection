package com.theblind.problem;

import java.util.ArrayList;
import java.util.Scanner;

import com.theblind.utility.FileUtility;

public class DancingWiththeGooglers {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		String inputFileName = in.next();
		String inputData = FileUtility.readFromFile(inputFileName);
		
		DancingWiththeGooglers problem = new DancingWiththeGooglers();
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
			
			int googlers = in.nextInt();
			int surprisingCase = in.nextInt();
			int target = in.nextInt();
			ArrayList<Integer> scores = new ArrayList<Integer>();
			for (int j = 0; j < googlers; ++j) {
				scores.add(in.nextInt());
			}
			
			int accepted = 0;
			int acceptLine = Math.max(target, target * 3 - 2);
			int limited = 0;
			int limitLine = Math.max(target, target * 3 - 4);
			for (Integer score : scores) {
				if (score >= acceptLine) {
					++accepted;
				}
				else if (score >= limitLine) {
					++limited;
				}
			}
			
			int result = accepted + Math.min(surprisingCase, limited);
			sb.append(result);
			sb.append("\n");
		}
		return sb.toString();
	}

}
