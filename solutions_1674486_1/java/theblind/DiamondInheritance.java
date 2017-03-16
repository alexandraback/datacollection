package com.theblind.problem;

import java.util.Scanner;

import com.theblind.utility.FileUtility;

public class DiamondInheritance {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		String inputFileName = in.next();
		String inputData = FileUtility.readFromFile(inputFileName);
		
		DiamondInheritance problem = new DiamondInheritance();
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
			
			int nodes = in.nextInt();
			boolean[][] diamond = new boolean[nodes + 1][nodes + 1];
			for (int j = 1; j <= nodes; ++j) {
				int pathes = in.nextInt();
				for (int k = 0; k < pathes; ++k) {
					diamond[j][in.nextInt()] = true;
				}
			}
			
			if (isValid(diamond, nodes)) {
				sb.append("Yes");
			}
			else {
				sb.append("No");
			}
			sb.append("\n");
		}
		return sb.toString();
	}

	private boolean isValid(boolean[][] diamond, int nodes) {
		// TODO Auto-generated method stub
		for (int i = 1; i <= nodes; ++i) {
			boolean[] state = new boolean[nodes + 1];
			if (dfs(diamond, i, state, nodes)) {
				return true;
			}
		}
		return false;
	}

	private boolean dfs(boolean[][] diamond, int index, boolean[] state, int nodes) {
		// TODO Auto-generated method stub
		if (state[index]) {
			return true;
		}
		else {
			state[index] = true;
		}
		
		for (int i = 1; i <= nodes; ++i) {
			if (diamond[index][i] && dfs(diamond, i, state, nodes)) {
				return true;
			}
		}
		return false;
	}

}
