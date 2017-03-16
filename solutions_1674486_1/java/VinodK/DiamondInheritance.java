package codeJam.y2012.r1C;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import codeJam.util.IOStream;

public class DiamondInheritance extends IOStream {
	static int[] path;

	public DiamondInheritance(String filename) {
		super(filename);
	}

	public static void main(String[] args) {
		DiamondInheritance diamond = new DiamondInheritance(
				"/Users/vinodkumarchowdary/Desktop/Contest/CodeJam/r1c/DiamondInheritance");
		try {
			setInput();
			setOutput();

			int testCases = Integer.parseInt(bufferedReader.readLine().trim());
			for (int testCase = 1; testCase <= testCases; testCase++) {
				if (diamond.runTestcase()) {
					System.out.println("Case #" + testCase + ": Yes");
					bufferedWriter.write("Case #" + testCase + ": Yes");
					bufferedWriter.newLine();
				} else {
					System.out.println("Case #" + testCase + ": No");
					bufferedWriter.write("Case #" + testCase + ": No");
					bufferedWriter.newLine();
				}

			}
			close();
		} catch (IOException e) {
			e.printStackTrace();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private boolean runTestcase() throws NumberFormatException, IOException {
		int numClasses = Integer.parseInt(bufferedReader.readLine().trim());
		Map<Integer, List<Integer>> map = new HashMap<Integer, List<Integer>>();
		for (int i = 1; i <= numClasses; i++) {
			int[] ithClass = convertString2Int(bufferedReader.readLine().trim().split(" "));
			int ithInheritance = ithClass[0];
			List<Integer> list = new ArrayList<Integer>();
			for (int j = 1; j <= ithInheritance; j++) {
				list.add(ithClass[j]);
			}
			map.put(i, list);
		}

		for (int i : map.keySet()) {
			path = new int[numClasses];
			if (isDiamond(map, i))
				return true;
		}
		return false;
	}

	private boolean isDiamond(Map<Integer, List<Integer>> map, int i) {
		List<Integer> list = map.get(i);
		for (int j : list) {
			if (path[j - 1] == 1)
				return true;
			path[j - 1] = 1;
			if (isDiamond(map, j))
				return true;
		}
		return false;
	}

}
