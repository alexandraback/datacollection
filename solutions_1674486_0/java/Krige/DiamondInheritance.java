package codejam.y2012.round1c.krige;

import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class DiamondInheritance {

	private static final String INPUT_FILE_NAME = "A-small-attempt0.in";
	private static final String OUTPUT_FILE_NAME = "A-small-attempt0.out";

	private static final String ROOT_DIR = "dat";
	private static final String YEAR = "2012";
	private static final String ROUND = "round1c";

	private static final String PATH = ROOT_DIR + File.separator + YEAR
			+ File.separator + ROUND + File.separator;

	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(new BufferedInputStream(
				new FileInputStream(PATH + INPUT_FILE_NAME)));
		PrintWriter output = new PrintWriter(new FileWriter(PATH
				+ OUTPUT_FILE_NAME));

		int numTestCases = input.nextInt();
		for (int i = 1; i <= numTestCases; i++) {
			int numClasses = input.nextInt();
			int[][] matAdj = new int[numClasses][numClasses];
			for (int j = 0; j < numClasses; j++) {
				int numClassesInherit = input.nextInt();
				for (int k = 0; k < numClassesInherit; k++) {
					matAdj[input.nextInt() - 1][j] = 1;
				}
			}

			String outputLine = "Case #" + i + ": " + solve(matAdj);

			System.out.println(outputLine);
			output.println(outputLine);
		}

		output.close();
	}

	private static String solve(int[][] adjMat) {
		ArrayList<Integer> sourceCandidates = new ArrayList<Integer>();
		ArrayList<Integer> targetCandidates = new ArrayList<Integer>();
		for (int i = 0; i < adjMat.length; i++) {
			int sum = 0;
			for (int j = 0; j < adjMat[0].length; j++) {
				sum += adjMat[i][j];
			}
			if (sum > 1) {
				sourceCandidates.add(i);
			}
		}
		if (sourceCandidates.isEmpty()) {
			return "No";
		}
		for (int j = 0; j < adjMat[0].length; j++) {
			int sum = 0;
			for (int i = 0; i < adjMat.length; i++) {
				sum += adjMat[i][j];
			}
			if (sum > 1) {
				targetCandidates.add(j);
			}
		}
		if (targetCandidates.isEmpty()) {
			return "No";
		}
		for (Integer source : sourceCandidates) {
			for (Integer target : targetCandidates) {
				if (twoPathsBetween(source, target, adjMat)) {
					return "Yes";
				}
			}
		}
		return "No";
	}

	private static boolean twoPathsBetween(int source, int target,
			int[][] adjMat) {
		for (int i = 0; i < adjMat.length; i++) {
			for (int j = 0; j < adjMat[0].length; j++) {
				System.out.print(adjMat[i][j]);
			}
			System.out.println();
		}
		int numPaths = 0;
		Queue<Integer> queue = new LinkedList<Integer>();
		queue.add(source);
		while (!queue.isEmpty()) {
			int node = queue.poll();
			if (node == target) {
				numPaths++;
				if (numPaths > 1) {
					return true;
				}
			}
			for (int j = 0; j < adjMat[0].length; j++) {
				if (adjMat[node][j] > 0) {
					queue.add(j);
				}
			}
		}
		return false;
	}
}
