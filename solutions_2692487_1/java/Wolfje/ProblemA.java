import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

import java.util.*;
import static java.lang.Math.*;


public class ProblemA {
	String PROBLEM_ID = "problemA";

	enum TestType {
		EXAMPLE, SMALL, LARGE
	}

//	 TestType TYPE = TestType.EXAMPLE;
//	 TestType TYPE = TestType.SMALL;
	TestType TYPE = TestType.LARGE;

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
		new ProblemA();
	}

	public ProblemA() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(getInFileName()));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				getOutFileName())));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			int arminMote = scan.nextInt();
			int n = scan.nextInt();
			int[] motes = new int[n];
			for ( int i = 0; i < n; i++) motes[i] = scan.nextInt();
			Arrays.sort(motes);
			int bestScore = Integer.MAX_VALUE;
			if ( arminMote == 1 ) {
				bestScore = n;
			} else {
				for ( int keep = 0; keep <= n; keep++) {
					int[] newMotes = new int[keep];
					for ( int i = 0; i < keep; i++) newMotes[i] = motes[i];
					int moves = n - keep + go(arminMote, newMotes);
					bestScore = min(bestScore, moves);
				}
			}

			String resultStr = String.format("Case #%d: %d", test + 1, bestScore);
			System.out.println(resultStr);
			out.println(resultStr);
		}
		out.close();
		System.out.println("*** in file =  " + getInFileName());
		System.out.println("*** out file = " + getOutFileName());
	}
	
	public int go(int startMote, int[] motes) {
		int index = 0;
		int changes = 0;
		int strength = startMote;
		
		while ( index < motes.length ) {
			if ( strength > motes[index] ) {
				strength += motes[index];
				index++;
			} else {
				strength += strength - 1;
				changes++;
			}
		}
		return changes;
	}
}
