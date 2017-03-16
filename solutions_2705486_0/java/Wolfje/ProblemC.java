import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

import java.util.*;
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
		BufferedReader inDict = new BufferedReader(new FileReader("garbled_email_dictionary.txt"));
		Scanner scanDict = new Scanner(inDict);
		ArrayList<String> wordList = new ArrayList<String>();
		while ( scanDict.hasNext()) {
			wordList.add(scanDict.next());
		}
//		wordList.add("code");
//		wordList.add("jam");
		
		allWords = new char[wordList.size()][];
		for ( int i = 0; i < wordList.size(); i++ ) {
			allWords[i] = wordList.get(i).toCharArray();
		}
		
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			String text = scan.next();
			target = text.toCharArray();
			memo = new int[target.length][6];
			for ( int [] a: memo) Arrays.fill(a, -1);
			
			int z = go(0, 5);
			String resultStr = String.format("Case #%d: %d", test + 1, z);
			// add answer here

			System.out.println(resultStr);
			out.println(resultStr);
		}
		out.close();
		System.out.println("*** in file =  " + getInFileName());
		System.out.println("*** out file = " + getOutFileName());
	}
	
	char[][] allWords;
	int[][] memo;
	char[] target;
	
	public int go(int index, int prevError) {
		if ( index == target.length) return 0;
//		System.out.printf("index = %d prevError %d\n", index, prevError);
		
		if ( memo[index][prevError] >= 0 ) return memo[index][prevError];
		int result = Integer.MAX_VALUE;
		for ( char[] word: allWords) {
//			System.out.println("try word " + new String(word));
			if ( index + word.length > target.length ) continue;
			int[] z = fit(word, index, index - prevError);
			if ( z.length == 0) continue;
//			System.out.printf("changes %d lastError %d\n", z[0], z[1]);
			int nextError = min(5, index + word.length - z[1]);
//			System.out.println("next error " + nextError);
			int rest = go(index + word.length, nextError);
			if ( rest < Integer.MAX_VALUE) {
				int value = z[0] + go(index + word.length, nextError);
				result = min(result, value);
			}
		}
		memo[index][prevError] = result;
		return result;
	}
	
	public int[] fit(char[] w, int index, int lastError) {
		int error = lastError;
		int changes = 0;
		for ( int i = 0; i < w.length; i++) {
			if ( w[i] != target[index+i] ) {
				if ( index + i - error < 5) return new int[] {};
				changes++;
				error = index+i;
			}
		}
		return new int[] {changes, error};
		
	}
	
}
