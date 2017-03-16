import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

import static java.lang.Math.*;

public class ProblemC {
	String PROBLEM_ID = "problemC";

	enum TestType {
		EXAMPLE, SMALL, LARGE
	}

//	 TestType TYPE = TestType.EXAMPLE;
	 TestType TYPE = TestType.SMALL;
//	TestType TYPE = TestType.LARGE;

	public String getFileName() {
		String result = PROBLEM_ID + "_";
		switch (TYPE) {
		case EXAMPLE:
			result += "example";
			break;
		case SMALL:
			result += "small";
			break;
		case LARGE:
			result += "large";
			break;
		}
		return result;
	}

	public String getInFileName() {
		return getFileName() + ".in";
	}

	public String getOutFileName() {
		return getFileName() + ".out";
	}

	public static void main(String[] args) throws Exception {
		new ProblemC();
	}

	public ProblemC() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(getInFileName()));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				getOutFileName())));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			int n = scan.nextInt();
			int[] s = new int[n];
			for ( int i = 0; i < n; i++) s[i] = scan.nextInt();
			HashMap<Integer, ArrayList<Integer>> map = new HashMap<Integer, ArrayList<Integer>>();
			boolean stop = false;
			int mask1 = -1;
			int mask2 = -1;
			for (int mask = 1; (mask < 1 << n) && !stop; mask++) {
				int sum = computeSum(mask, s);
				if ( map.containsKey(sum)) {
					ArrayList<Integer> items = map.get(sum);
					for ( int j = 0; j < items.size(); j++) {
						if ( (mask & items.get(j)) == 0 ) {
							stop = true;
//							System.out.println("found something for sum " + sum);
							mask1 = mask;
							mask2 = items.get(j);
//							System.out.printf("sum 1 = %d sum 2 = %d\n", computeSum(mask1, s), computeSum(mask2, s));
						}
					}
					items.add(mask);
				} else {
					ArrayList<Integer> items = new ArrayList<Integer>();
					items.add(mask);
					map.put(sum, items);
				}
			}
			String resultStr = String.format("Case #%d:\n", test + 1);
			// add answer here
			if ( mask1 != -1) {
				resultStr += maskToString(mask1, s) + "\n" + maskToString(mask2, s);
			} else resultStr += "Impossible";

			System.out.println(resultStr);
			out.println(resultStr);
		}
		out.close();
		System.out.println("*** in file =  " + getInFileName());
		System.out.println("*** out file = " + getOutFileName());
	}
	
	String maskToString(int mask, int[] s) {
		String result = "";
		for (int i = 0; i < s.length; i++) {
			if ((mask & (1 << i)) == 0)	continue;
			result += " " + s[i];
		}
		return result.substring(1);
	}
	
	int computeSum(int mask, int[] s) {
		int result = 0;
		for (int i = 0; i < s.length; i++) {
			if ((mask & (1 << i)) == 0)	continue;
			result += s[i];
		}
		return result;
	}
}

